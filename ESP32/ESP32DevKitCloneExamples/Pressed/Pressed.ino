/*
 Name:		Pressed.ino
 Created:	9/5/2018 10:49:52 AM
 Author:	Evert Arias
 Description: Example to demostrate how to use the library to detect a single pressed on a button.
*/

#include <EasyButton.h>

// Arduino pin where the button is connected to.
#define BUTTON_TR 32
#define BUTTON_TL 33

#define BAUDRATE 115200

// Instance of the button.
EasyButton button(BUTTON_TR);
EasyButton button(BUTTON_TL)

// Callback function to be called when the button is pressed.
void onTRPressed()
{
  Serial.println("Top Right Button pressed");
}

void onTLPressed()
{
  Serial.println("Top Right Button pressed");
}

void setup()
{
  // Initialize Serial for debuging purposes.
  Serial.begin(BAUDRATE);

  Serial.println();
  Serial.println(">>> EasyButton pressed example <<<");

  // Initialize the button.
  button.begin();
  // Add the callback function to be called when the button is pressed.
  button.onPressed(onPressed);
}

void loop()
{
  // Continuously read the status of the button.
  button.read();
}
