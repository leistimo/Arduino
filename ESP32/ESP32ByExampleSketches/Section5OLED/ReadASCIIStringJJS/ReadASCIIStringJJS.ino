/*
  Reading a serial ASCII-encoded string.

  Original Program does this:
  
  This sketch demonstrates the Serial parseInt() function.
  It looks for an ASCII string of comma-separated values.
  It parses them into ints, and uses those to fade an RGB LED.

  Circuit: Common-Cathode RGB LED wired like so:
  - red anode: digital pin 3 through 220 ohm resistor
  - green anode: digital pin 5 through 220 ohm resistor
  - blue anode: digital pin 6 through 220 ohm resistor
  - cathode: GND

  created 13 Apr 2012
  by Tom Igoe
  modified 14 Mar 2016
  by Arturo Guadalupi

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/ReadASCIIString
*/
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 32  // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

void setup() {
  Serial.begin(115200);
  Wire.begin();  // Initialize I2C communication
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }
  display.display();  // Display AdaFruit Logo
  delay(2000);        // Pause for 2 seconds
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setRotation(0);
  display.setCursor(0, 0);
}

void loop() {
  display.clearDisplay();   // Clear the buffer
  display.setCursor(0, 0);  // Set cursor to the top-left corner

  // if there's any serial available, read it:
  while (Serial.available() > 0) {
    String message = Serial.readStringUntil('\n');
    display.println("Message: ");  // Print the header value on OLED display
    display.println(message);      // Print the message value on OLED display
    display.display();             // Update the OLED display 
  }
}

