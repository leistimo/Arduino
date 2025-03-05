/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

// #define Huzzah
#define Clone

#ifdef Huzzah
#define BOTTOM_GREEN 4
#define TOP_RED 12
#endif

#ifdef Clone
#define BOTTOM_GREEN 14
#define TOP_RED 27
#endif

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(115200);
  pinMode(TOP_RED, OUTPUT);
  pinMode(BOTTOM_GREEN, OUTPUT);
  digitalWrite(TOP_RED, LOW);
  digitalWrite(BOTTOM_GREEN, LOW);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(TOP_RED, HIGH);  // turn the LED on (HIGH is the voltage level)
  Serial.println("TOP_RED LED ON");
  delay(2000);                 // wait for 2 seconds
  digitalWrite(TOP_RED, LOW);  // turn the LED off by making the voltage LOW
  Serial.println("TOP_RED LED OFF");
  delay(2000);                       // wait for 2 seconds
  digitalWrite(BOTTOM_GREEN, HIGH);  // turn the LED on (HIGH is the voltage level)
  Serial.println("BOTTOM_GREEN LED ON");
  delay(2000);                      // wait for 2 seconds
  digitalWrite(BOTTOM_GREEN, LOW);  // turn the LED off by making the voltage LOW
  Serial.println("BOTTOM_GREEN LED OFF");
  delay(2000);  // wait for 2 seconds 
}
