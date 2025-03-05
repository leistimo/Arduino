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
#define Red1_LED 13
#define Blue_LED 12
#define Green1_LED 14
#define Red2_LED 27
#define Yellow_LED 26
#define Green2_LED 25
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(Red1_LED, OUTPUT);
  pinMode(Blue_LED, OUTPUT);
  pinMode(Green1_LED, OUTPUT);
  pinMode(Red2_LED, OUTPUT);
  pinMode(Yellow_LED, OUTPUT);
  pinMode(Green2_LED, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(Red1_LED, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(Red1_LED, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);    
  digitalWrite(Blue_LED, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(Blue_LED, LOW);
  delay(1000); 
  digitalWrite(Green1_LED, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(Green1_LED, LOW);
  delay(1000);
  digitalWrite(Red2_LED, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(Red2_LED, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);    
  digitalWrite(Yellow_LED, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(Yellow_LED, LOW);
  delay(1000); 
  digitalWrite(Green2_LED, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(Green2_LED, LOW); 
  delay(1000);                // wait for a second
}
