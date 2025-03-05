/*
  Name:		MultipleButtons.ino
  Created:	3/25/2019 11:45:52 AM
  Author:	Evert Arias
  Description: Example to demostrate how to use the library with more than one button
*/

#include <EasyButton.h>

// Arduino pin where the buttons are connected to
#define BUTTON_TWO_PIN 33
#define BUTTON_ONE_PIN 32
#define BUTTON_THREE_PIN 18
#define BUTTON_FOUR_PIN 15
#define BUTTON_FIVE_PIN 5
#define BUTTON_SIX_PIN 4

//define LEDs
#define RedTop_LED 13
#define BlueTop_LED 12
#define GreenTop_LED 14
#define RedBottom_LED 27
#define YellowBottom_LED 26
#define GreenBottom_LED 25

#define BAUDRATE 115200

// Top Right Button
EasyButton TR(BUTTON_ONE_PIN);
// Top Left Button
EasyButton TL(BUTTON_TWO_PIN);
// Middle Left Button
EasyButton ML(BUTTON_THREE_PIN);
// Bottom Left Button
EasyButton BL(BUTTON_FOUR_PIN);
// Bottom Middle Right Button MRB because MR caused a crash (declared something else in the library?)
EasyButton MRB(BUTTON_FIVE_PIN);
// Bottom Right Button
EasyButton BRB(BUTTON_SIX_PIN);

// Callback function to be called when Top Right is pressed
void onTRPressed()
{
  digitalWrite(BlueTop_LED, HIGH);
  Serial.println("Top Right Button Press, Top Blue LED");
  delay(2000);
  digitalWrite(BlueTop_LED, LOW);
  Serial.println("Top Blue LED OFF");
}
// Callback function to be called when Top Left is pressed
void onTLPressed()
{
  digitalWrite(RedTop_LED, HIGH);
  Serial.println("Top Left Button Press, Top Red LED");
  delay(2000);
  digitalWrite(RedTop_LED, LOW);
  Serial.println("Top Red LED OFF");
}
// Callback function to be called when Middle Left is pressed
void onMLPressed()
{
  digitalWrite(GreenTop_LED, HIGH);
  Serial.println("Middle Left Button Press, Top Green LED");
  delay(2000);
  digitalWrite(GreenTop_LED, LOW);
  Serial.println("Top Green LED OFF");
}
// Callback function to be called when ? is pressed
void onBLPressed()
{
  digitalWrite(YellowBottom_LED, HIGH);
  Serial.println("Bottom Left Button Press, Bottom Yellow LED");
  delay(2000);
  digitalWrite(YellowBottom_LED, LOW);
  Serial.println("Bottom Yellow LED OFF");
}
// Callback function to be called when Middle Right is pressed
void onMRBPressed()
{
  digitalWrite(RedBottom_LED, HIGH);
  Serial.println("Middle Right Button Press, Bottom Red LED");
  delay(2000);
  digitalWrite(RedBottom_LED, LOW);
  Serial.println("Bottom Red LED OFF");
}
// Callback function to be called when ? is pressed
void onBRBPressed()
{
  //Serial.println("Bottom Right pressed");
  digitalWrite(GreenBottom_LED, HIGH);
  Serial.println("Bottom Right Button Press, Bottom Green LED");
  delay(2000);
  digitalWrite(GreenBottom_LED, LOW);
  Serial.println("Bottom Green LED OFF");
}

void setup()
{
  // Initialize Serial for debuging purposes
  Serial.begin(BAUDRATE);

  // Define outputs:
  pinMode(RedTop_LED, OUTPUT);
  pinMode(BlueTop_LED, OUTPUT);
  pinMode(GreenTop_LED, OUTPUT);
  pinMode(RedBottom_LED, OUTPUT);
  pinMode(YellowBottom_LED, OUTPUT);
  pinMode(GreenBottom_LED, OUTPUT);

  //zero LEDs
  digitalWrite(RedTop_LED, LOW);
  digitalWrite(BlueTop_LED, LOW);
  digitalWrite(GreenTop_LED, LOW);
  digitalWrite(RedBottom_LED, LOW);
  digitalWrite(YellowBottom_LED, LOW);
  digitalWrite(GreenBottom_LED, LOW);

  Serial.println();
  Serial.println(">>> EasyButton multiple buttons example <<<");

  // Initialize the Top Right
  TR.begin();
  // Initialize the Top Left
  TL.begin();
  // Initialize the Middle Left
  ML.begin();
  // Initialize the Bottom Left
  BL.begin();
  // Initialize the Middle Right
  MRB.begin();
  // Initialize the Bottom Right
  BRB.begin();

  // Add the callback function to be called when the Top Right is pressed.
  TR.onPressed(onTRPressed);
  // Add the callback function to be called when the Top Left is pressed.
  TL.onPressed(onTLPressed);
  // Add the callback function to be called when the Middle Left is pressed.
  ML.onPressed(onMLPressed);
  // Add the callback function to be called when the Bottom Left is pressed.
  BL.onPressed(onBLPressed);
  // Add the callback function to be called when the Middle Right is pressed.
  MRB.onPressed(onMRBPressed);
  // Add the callback function to be called when the Middle Right is pressed.
  BRB.onPressed(onBRBPressed);
}

void loop()
{
  // Continuously read the status of the buttons
  TR.read();
  TL.read();
  ML.read();
  BL.read();
  MRB.read();
  BRB.read();
}
