//ESP32 Dev Module
#include <Arduino.h>
        #include <BluetoothSerial.h>

        BluetoothSerial SerialBT;

        #define Top_Red 13

        void setup() {
          SerialBT.begin("ESP32test"); // Name of your ESP32 device
          Serial.begin(115200);
          pinMode(Top_Red, OUTPUT);
          digitalWrite(Top_Red, LOW);
        }

        void loop() {
          if (SerialBT.available()) {
            String receivedData = SerialBT.readStringUntil('\n'); // Read until newline
            Serial.print("Received: ");
            Serial.println(receivedData);
            SerialBT.print("Data received");
            if(receivedData == "1"){
              digitalWrite(Top_Red, HIGH);
            }
              else if(receivedData == "0"){
              digitalWrite(Top_Red, LOW);
             }
              
          }
        }
