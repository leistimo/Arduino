#include <Bluepad32.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>

// #define Clone
#define Huzzah

#ifdef Huzzah
// Define LED Pins Huzzah Board Top Red Blue Top Green Yellow Lower Red Lower Green
// Define LED Pins Huzzah Board LEFT FORWARD RIGHT BACK Brake Throttle
#define LED1_PIN 12
#define LED2_PIN 27
#define LED3_PIN 33
#define LED4_PIN 25
#define LED5_PIN 26
#define LED6_PIN 4
#endif

#ifdef Clone
// Define LED Pins Clone Board Top Red Blue Top Green Yellow Red Lower Green
// Define LED Pins Clone Board LEFT FORWARD RIGHT BACK Brake Throttle
#define LED1_PIN 27
#define LED2_PIN 26
#define LED3_PIN 25
#define LED4_PIN 12
#define LED5_PIN 13
#define LED6_PIN 14
#endif

const int forwardChannel = 0;
const int backChannel = 1;
const int leftChannel = 2;
const int rightChannel = 3;

// Variables to hold LED states
bool led5State = false;
bool led6State = false;

int yaw = 0;
int throttle = 0;
int pitch = 0;
int roll = 0;

String rcCommand = "rc ";
// Modify to define and connect only 1 gamepad at a time

GamepadPtr myGamepad;
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);

// This callback gets called any time a new gamepad is connected.
// Up to 4 gamepads can be connected at the same time.
void onConnectedGamepad(GamepadPtr gp) {
  if (myGamepad == nullptr) {
    Serial.printf("CALLBACK: Gamepad is now connected\n");
    // Additionally, you can get certain gamepad properties like:
    // Model, VID, PID, BTAddr, flags, etc.
    GamepadProperties properties = gp->getProperties();
    Serial.printf("Gamepad model: %s, VID=0x%04x, PID=0x%04x\n",
                  gp->getModelName().c_str(), properties.vendor_id,
                  properties.product_id);
    myGamepad = gp;
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println(gp->getModelName().c_str());
    display.println("connected");
    display.display();
  }
}

void onDisconnectedGamepad(GamepadPtr gp) {
  if (myGamepad == gp) {
    Serial.printf("CALLBACK: Gamepad is disconnected\n");
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println(gp->getModelName().c_str());
    display.println("disconnected");
    display.display();
    myGamepad = nullptr;
  }
}

// Arduino setup function. Runs in CPU 1
void setup() {
  Serial.begin(115200);
  Serial.printf("Firmware: %s\n", BP32.firmwareVersion());
  const uint8_t *addr = BP32.localBdAddress();
  Serial.printf("BD Addr: %2X:%2X:%2X:%2X:%2X:%2X\n", addr[0], addr[1], addr[2],
                addr[3], addr[4], addr[5]);

  // Setup the Bluepad32 callbacks
  BP32.setup(&onConnectedGamepad, &onDisconnectedGamepad);

  // "forgetBluetoothKeys()" should be called when the user performs
  // a "device factory reset", or similar.
  // Calling "forgetBluetoothKeys" in setup() just as an example.
  // Forgetting Bluetooth keys prevents "paired" gamepads to reconnect.
  // But might also fix some connection / re-connection issues.
  BP32.forgetBluetoothKeys();

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }
  display.display();
  delay(2000);  // Pause for 2 seconds
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setRotation(0);
  display.clearDisplay();
  display.setCursor(0, 0);

  // Set LED pins as outputs
  pinMode(LED5_PIN, OUTPUT);
  pinMode(LED6_PIN, OUTPUT);
  digitalWrite(LED5_PIN, LOW);
  digitalWrite(LED6_PIN, LOW);

  // Set LED pins as channels for joystick PWM interaction 
  ledcSetup(forwardChannel, 4000, 8);
  ledcAttachPin(LED2_PIN, forwardChannel);
  ledcWrite(forwardChannel, 0);
  ledcSetup(backChannel, 4000, 8);
  ledcAttachPin(LED4_PIN, backChannel);
  ledcWrite(backChannel, 0);
  ledcSetup(leftChannel, 4000, 8);
  ledcAttachPin(LED1_PIN, leftChannel);
  ledcWrite(leftChannel, 0);
  ledcSetup(rightChannel, 4000, 8);
  ledcAttachPin(LED3_PIN, rightChannel);
  ledcWrite(rightChannel, 0);


  // Print to Serial Monitor
  Serial.println("Ready.");
}

// Arduino loop function. Runs in CPU 1
void loop() {
  // This call fetches all the gamepad info from the NINA (ESP32) module.
  // Just call this function in your main loop.
  // The gamepads pointer (the ones received in the callbacks) gets updated
  // automatically.
  BP32.update();

  if (myGamepad && myGamepad->isConnected()) {
    // There are different ways to query whether a button is pressed.
    // By query each button individually:
    //  a(), b(), x(), y(), l1(), etc...
    if (myGamepad->a()) {
      Serial.println("A/Cross button pressed");
      ledcWrite(backChannel, 255);
      vTaskDelay(2500);
    }

    if (myGamepad->b()) {
      Serial.println("B/Circle button pressed");
      ledcWrite(rightChannel, 255);
      vTaskDelay(2500);
    }

    if (myGamepad->x()) {
      Serial.println("X/Square button pressed");
      ledcWrite(leftChannel, 255);
      vTaskDelay(2500);
    }

    if (myGamepad->y()) {
      Serial.println("Y/Triangle button pressed");
      ledcWrite(forwardChannel, 255);
      vTaskDelay(2500);
    }

    if (myGamepad->brake()) {
      if (!led5State) Serial.println("Left Trigger held");
      led5State = true;
      digitalWrite(LED5_PIN, led5State);
    }
    if (!myGamepad->brake()) {
      if (led5State) Serial.println("Left Trigger released");
      led5State = false;
      digitalWrite(LED5_PIN, led5State);
    }

    if (myGamepad->throttle()) {
      if (!led6State) Serial.println("Right Trigger held");
      led6State = true;
      digitalWrite(LED6_PIN, led6State);
    }
    if (!myGamepad->throttle()) {
      if (led6State) Serial.println("Right Trigger released");
      led6State = false;
      digitalWrite(LED6_PIN, led6State);
    }


    yaw = map(myGamepad->axisX(), -511, 508, -100, 100);
    throttle = map(myGamepad->axisY(), -511, 508, 100, -100);
    roll = map(myGamepad->axisRX(), -511, 508, -100, 100);
    pitch = map(myGamepad->axisRY(), -511, 508, 100, -100);
    if (abs(yaw) <= 15) {
      yaw = 0;
    }
    if (abs(throttle) <= 15) {
      throttle = 0;
    }
    if (abs(pitch) <= 15) {
      pitch = 0;
    }
    if (abs(roll) <= 15) {
      roll = 0;
    }

    if (pitch < 0) {
      ledcWrite(backChannel, map(pitch, -100, 0, 255, 0));
      ledcWrite(forwardChannel, 0);
    } else {
      ledcWrite(forwardChannel, map(pitch, 0, 100, 0, 255));
      ledcWrite(backChannel, 0);
    }
    if (roll < 0) {
      ledcWrite(leftChannel, map(roll, -100, 0, 255, 0));
      ledcWrite(rightChannel, 0);
    } else {
      ledcWrite(rightChannel, map(roll, 0, 100, 0, 255));
      ledcWrite(leftChannel, 0);
    }

    // process dpad values last; they override joystick values
    if (myGamepad->dpad() == 0x01) {
      //Serial.println("go Forward");
      ledcWrite(forwardChannel, 255);
      ledcWrite(backChannel, 0);
      ledcWrite(leftChannel, 0);
      ledcWrite(rightChannel, 0);
    }
    if (myGamepad->dpad() == 0x02) {
      //Serial.println("go Back");
      ledcWrite(forwardChannel, 0);
      ledcWrite(backChannel, 255);
      ledcWrite(leftChannel, 0);
      ledcWrite(rightChannel, 0);
    }
    if (myGamepad->dpad() == 0x04) {
      //Serial.println("go Right");
      ledcWrite(forwardChannel, 0);
      ledcWrite(backChannel, 0);
      ledcWrite(leftChannel, 0);
      ledcWrite(rightChannel, 255);
    }
    if (myGamepad->dpad() == 0x05) {
      //Serial.println("go Forward Right");
      ledcWrite(forwardChannel, 255);
      ledcWrite(backChannel, 0);
      ledcWrite(leftChannel, 0);
      ledcWrite(rightChannel, 255);
    }
    if (myGamepad->dpad() == 0x06) {
      //Serial.println("go Back Right");
      ledcWrite(forwardChannel, 0);
      ledcWrite(backChannel, 255);
      ledcWrite(leftChannel, 0);
      ledcWrite(rightChannel, 255);
    }
    if (myGamepad->dpad() == 0x08) {
      //Serial.println("go Left");
      ledcWrite(forwardChannel, 0);
      ledcWrite(backChannel, 0);
      ledcWrite(leftChannel, 255);
      ledcWrite(rightChannel, 0);
    }
    if (myGamepad->dpad() == 0x09) {
      //Serial.println("go Forward Left");
      ledcWrite(forwardChannel, 255);
      ledcWrite(backChannel, 0);
      ledcWrite(leftChannel, 255);
      ledcWrite(rightChannel, 0);
    }
    if (myGamepad->dpad() == 0x0a) {
      //Serial.println("go Back Left");
      ledcWrite(forwardChannel, 0);
      ledcWrite(backChannel, 255);
      ledcWrite(leftChannel, 255);
      ledcWrite(rightChannel, 0);
    }

    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Yaw: ");
    display.println(yaw);
    display.print("Throttle: ");
    display.println(throttle);
    display.print("Pitch: ");
    display.println(pitch);
    display.print("Roll: ");
    display.println(roll);
    display.display();

    rcCommand = "rc ";
    rcCommand = rcCommand + roll + " " + pitch + " " + throttle + " " + yaw;
    Serial.println(rcCommand);
  }

  // The main loop must have some kind of "yield to lower priority task" event.
  // Otherwise the watchdog will get triggered.
  // If your main loop doesn't have one, just add a simple `vTaskDelay(1)`.
  // Detailed info here:
  // https://stackoverflow.com/questions/66278271/task-watchdog-got-triggered-the-tasks-did-not-reset-the-watchdog-in-time

  // vTaskDelay(1);
  delay(150);
}
