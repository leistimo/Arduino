//ESP32 Dev Module BluePad

#include <Bluepad32.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>

#define Clone

#ifdef Clone
// Define LED Pins Clone Board Top Red Blue Top Green Yellow
// Define LED Pins Clone Board LEFT FORWARD RIGHT BACK
#define Top_Red 13
#define Top_Blue 12
#define Top_Green 14
#define Bottom_Red 27
#define Bottom_Yellow 26
#define Bottom_Green 25
#endif

// Variables to hold LED states
//bool TopRedState = false;
bool TopBlueState = false;
bool BottomYellowState = false;

int Left = 0;
int Right = 0;

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
 pinMode(Top_Red, OUTPUT);
 pinMode(Top_Blue, OUTPUT);
 pinMode(Top_Green, OUTPUT);
 pinMode(Bottom_Red, OUTPUT);
 pinMode(Bottom_Yellow, OUTPUT);
 pinMode(Bottom_Green, OUTPUT);
 
 digitalWrite(Top_Red, LOW);
 digitalWrite(Top_Blue, LOW);
 digitalWrite(Top_Green, LOW);
 digitalWrite(Bottom_Red, LOW);
 digitalWrite(Bottom_Yellow, LOW);
 digitalWrite(Bottom_Green, LOW);

  // Print to Serial Monitor
  Serial.println("Ready.");

}

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

   // if (myGamepad->a()) {
   //   Serial.println("A/Cross button pressed");
      //digitalWrite(Top_Red, 1);
   //   vTaskDelay(2500);
    //}

    //if (myGamepad->b()) {
    //  Serial.println("B/Circle button pressed");
      //digitalWrite(LED3_PIN, 1);
     // vTaskDelay(2500);
    //}

    // if (myGamepad->x()) {
     // Serial.println("X/Square button pressed");
      //digitalWrite(LED1_PIN, 1);
     // vTaskDelay(2500);
    //}

   // if (myGamepad->y()) {
    //  Serial.println("Y/Triangle button pressed");
      //digitalWrite(LED2_PIN, 1);
    //  vTaskDelay(2500);
    //}

    if (myGamepad->brake()) {
      if (!TopBlueState) Serial.println("Left Weapon Press");
      TopBlueState = true;
      digitalWrite(Top_Blue, TopBlueState);
    }
    if (!myGamepad->brake()) {
      if (TopBlueState) Serial.println("Left Weapon Release");
      TopBlueState = false;
      digitalWrite(Top_Blue, TopBlueState);
    }

    if (myGamepad->throttle()) {
      if (!BottomYellowState) Serial.println("Right Weapon Press");
      BottomYellowState = true;
      digitalWrite(Bottom_Yellow, BottomYellowState);
    }
    if (!myGamepad->throttle()) {
      if (BottomYellowState) Serial.println("Right Weapon Released");
      BottomYellowState = false;
      digitalWrite(Bottom_Yellow, BottomYellowState);
    }

    //yaw = map(myGamepad->axisX(), -511, 508, -100, 100);
    Left = map(myGamepad->axisY(), -511, 508, 100, -100);
    //roll = map(myGamepad->axisRX(), -511, 508, -100, 100);
    Right = map(myGamepad->axisRY(), -511, 508, 100, -100);

    if (abs(Left) <= 20) {
      Left = 0;
    }

    if (abs(Right) <= 20) {
      Right = 0;
    }

    if (Left>0){
      digitalWrite(Top_Red, HIGH);
      digitalWrite(Bottom_Red, LOW);
    }
      else if (Left<0){
      digitalWrite(Bottom_Red, HIGH);
      digitalWrite(Top_Red, LOW);
      }
      else {
        digitalWrite(Top_Red, LOW);
        digitalWrite(Bottom_Red, LOW);
      }

      if (Right>0){
      digitalWrite(Top_Green, HIGH);
      digitalWrite(Bottom_Green, LOW);
    }
      else if (Right<0){
      digitalWrite(Bottom_Green, HIGH);
      digitalWrite(Top_Green, LOW);
      }
      else {
        digitalWrite(Top_Green, LOW);
        digitalWrite(Bottom_Green, LOW);
      }



    display.clearDisplay();
    display.setCursor(0, 0);
    //display.print("Yaw: ");
    //display.println(yaw);
    display.print("Left Track: ");
    display.println(Left);
    display.print("Right Track: ");
    display.println(Right);
    //display.println (TopBlueState)
    //display.println (BottomYellowState)
    //display.print("Roll: ");
    //display.println(roll);
    display.display();
    rcCommand = "rc ";
    rcCommand = rcCommand + Left + " " + Right;
    Serial.println(rcCommand);

    
    
    

   }
   //delay (200);

}
