#include <Bluepad32.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>

// #define Clone
#define Huzzah

#ifdef Huzzah
// Define LED Pins Huzzah Board Top Red Blue Top Green Yello
#define LED1_PIN 12
#define LED2_PIN 27
#define LED3_PIN 33
#define LED4_PIN 25
#endif

#ifdef Clone
// Define LED Pins Clone Board Top Red Blue Top Green Yello
#define LED1_PIN 27
#define LED2_PIN 26
#define LED3_PIN 25
#define LED4_PIN 12
#endif

// Variables to hold LED states
bool led1State = false;
bool led2State = false;
bool led3State = false;
bool led4State = false;

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
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED3_PIN, LOW);
  digitalWrite(LED4_PIN, LOW);

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
      led4State = !led4State;
      digitalWrite(LED4_PIN, led4State);
      vTaskDelay(250);
      }

    if (myGamepad->b()) {
      Serial.println("B/Circle button pressed");
      led2State = !led2State;
      digitalWrite(LED2_PIN, led2State);
      vTaskDelay(250);
    }

    if (myGamepad->x()) {
      Serial.println("X/Square button pressed");
      led3State = true;
      digitalWrite(LED3_PIN, led3State);
    }

    if (myGamepad->y()) {
      Serial.println("Y/Triangle button pressed");
      led3State = false;
      digitalWrite(LED3_PIN, led3State);
    }

    if (myGamepad->r2()) {
      if (!led1State) Serial.println("Throttle paddle held");
      led1State = true;
      digitalWrite(LED1_PIN, led1State);
    }
    if (!myGamepad->r2()) {
      if (led1State) Serial.println("Throttle paddle released");
      led1State = false;
      digitalWrite(LED1_PIN, led1State);
    }
    yaw = map(myGamepad->axisX(),-511,508,-100,100);
    throttle = map(myGamepad->axisY(),-511,508,100,-100);
    roll = map(myGamepad->axisRX(),-511,508,-100,100);
    pitch = map(myGamepad->axisRY(),-511,508,100,-100);
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
