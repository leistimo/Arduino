#include <WiFi.h>
#include <WiFiUdp.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>

#define Clone
// #define Huzzah

#ifdef Huzzah
// Define LED Pins Huzzah Board Top Red Blue Top Green Yellow
// Define LED Pins Huzzah Board LEFT FORWARD RIGHT BACK
#define Top_Red 12
#define Blue 27
#define Top_Green 33
#define Bottom_Red 26
#define Yellow 25
#define Bottom_Green 4
#endif

#ifdef Clone
// Define LED Pins Clone Board Top Red Blue Top Green Yellow
// Define LED Pins Clone Board LEFT FORWARD RIGHT BACK
#define Top_Red 13
#define Blue 12
#define Top_Green 14
#define Bottom_Red 27
#define Yellow 26
#define Bottom_Green 25
#endif

WiFiUDP Udp; // Creation of wifi Udp instance

char packetBuffer[255];

unsigned int localPort = 8889;

const char *ssid = "ESP-Udp-Demo";  
const char *password = "ESP-Demo";

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);

void toggle_led(int ledToToggle) {
  // Toggle the state of the LED pin (write the NOT of the current state to the LED pin)
  digitalWrite(ledToToggle, !digitalRead(ledToToggle));
}

void setup() {
  WiFi.softAP(ssid, password);  // ESP-32 as access point
  Serial.begin(115200);
  while (!Serial){
    delay(10);
    if (millis() > 5000) break; // don't wait forever
  }
  if (Serial) Serial.println("\nSerial Connected");

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

  pinMode(Top_Red, OUTPUT);
  pinMode(Blue, OUTPUT);
  pinMode(Top_Green, OUTPUT);
  pinMode(Bottom_Red, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Bottom_Green, OUTPUT);
  digitalWrite(Top_Red, LOW);
  digitalWrite(Blue, LOW);
  digitalWrite(Top_Green, LOW);
  digitalWrite(Bottom_Red, LOW);
  digitalWrite(Yellow, LOW);
  digitalWrite(Bottom_Green, LOW);

  Serial.print("Soft-AP IP address = ");
  Serial.println(WiFi.softAPIP());
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Soft-AP IP address:");
  display.println(WiFi.softAPIP());
  display.println("Waiting...");
  display.display();
  Udp.begin(localPort);
  }

void loop() {
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    int len = Udp.read(packetBuffer, 255);
    if (len > 0) packetBuffer[len] = 0;
    Serial.print("Received(IP/Size/Data): ");
    Serial.print(Udp.remoteIP());Serial.print(" / ");
    Serial.print(packetSize);Serial.print(" / ");
    Serial.println(packetBuffer);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("IP: ");
    display.println(Udp.remoteIP());
    display.print("Size: ");
    display.println(packetSize);
    display.println("Packet:");
    display.println(packetBuffer);
    display.display();
    String command = String((char *)packetBuffer);
    if (command.indexOf("blue") >= 0) {
      toggle_led(Blue);
    } else if (command.indexOf("hello") >= 0) {
      toggle_led(Top_Red);
      delay(1000);
      toggle_led(Blue);
      delay(1000);
      toggle_led(Top_Green);
      delay(1000);
      toggle_led(Bottom_Red);
      delay(1000);
      toggle_led(Yellow);
      delay(1000);
      toggle_led(Bottom_Green);
      delay(1000);
    }

    Udp.beginPacket(Udp.remoteIP(),Udp.remotePort());
    Udp.printf("received: ");
    Udp.printf(packetBuffer);
    Udp.endPacket();
    }
}