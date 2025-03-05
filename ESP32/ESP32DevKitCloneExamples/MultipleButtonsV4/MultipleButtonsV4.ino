/*
  Name:		MultipleButtons.ino
  Created:	3/25/2019 11:45:52 AM
  Author:	Evert Arias
  Description: Example to demostrate how to use the library with more than one button
*/

#include <EasyButton.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>

#define SCREEN_WIDTH 128 //OLED display width
#define SCREEN_HEIGHT 32 // OLED display height

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

// ESP pin where the buttons are connected to
#define BUTTON_TWO_PIN 33
#define BUTTON_ONE_PIN 32
#define BUTTON_THREE_PIN 18
#define BUTTON_FOUR_PIN 15
#define BUTTON_FIVE_PIN 5
#define BUTTON_SIX_PIN 4

//define LEDs
//#define RedTop_LED 13
//#define BlueTop_LED 12
//#define GreenTop_LED 14
//#define RedBottom_LED 27
//#define YellowBottom_LED 26
//#define GreenBottom_LED 25

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


const byte BlueLEDTop = 12;
const byte RedLEDTop = 13; 
const byte GreenLEDTop = 14;
const byte RedLEDBottom = 27;
const byte YellowLEDBottom = 26;
const byte GreenLEDBottom = 25;

int DutyCycle = 0;

void onTRPressed()
{
  display.clearDisplay();
  
  Serial.println("Top Right Button Press, Top Blue LED");
  display.println("Top RB Pressed");
  display.display();
  display.println("Top Blue LED ON");
  display.display();
  //digitalWrite(BlueTop_LED, HIGH);
  
  for (int i=0; i<=3; i++){
  DutyCycle = 0;
  while ( DutyCycle<=100) 
  {
    ledcWrite(BlueLEDTop, DutyCycle);  // set the brightness of the LED 
    delay(7); 
    DutyCycle=DutyCycle+1;  
  }
    while(DutyCycle >=0){
      ledcWrite(BlueLEDTop, DutyCycle);
      delay(7);
      DutyCycle=DutyCycle-1;
    }}
  
  
  //delay(2000);
  //digitalWrite(BlueTop_LED, LOW);
  Serial.println("Top Blue LED OFF");
  display.println("Top Blue LED OFF");
  display.display();
  display.setCursor(0, 0); 
}
// Callback function to be called when Top Left is pressed
void onTLPressed()
{ 
  display.clearDisplay();
  //digitalWrite(RedTop_LED, HIGH);
  Serial.println("Top Left Button Press, Top Red LED");
  display.println("Top LB Pressed");
  display.display();
  display.println("Top Red LED ON");
  display.display();

  for (int i=0; i<=3; i++){
  DutyCycle = 0;
  while ( DutyCycle<=100) 
  {
    ledcWrite(RedLEDTop, DutyCycle);  // set the brightness of the LED 
    delay(7); 
    DutyCycle=DutyCycle+1;  
  }
    while(DutyCycle >=0){
      ledcWrite(RedLEDTop, DutyCycle);
      delay(7);
      DutyCycle=DutyCycle-1;
    }}
  
  //delay(2000);
  //digitalWrite(RedTop_LED, LOW);
  Serial.println("Top Red LED OFF");
  display.println("Top Red LED OFF");
  display.display();
  display.setCursor(0, 0);
}
// Callback function to be called when Middle Left is pressed
void onMLPressed()
{
  display.clearDisplay();
  //digitalWrite(GreenTop_LED, HIGH);
  Serial.println("Middle Left Button Press, Top Green LED");
  display.println("Middle LB Pressed");
  display.display();
  display.println("Top Green LED ON");
  display.display();

  for (int i=0; i<=3; i++){
  DutyCycle = 0;
  while ( DutyCycle<=100) 
  {
    ledcWrite(GreenLEDTop, DutyCycle);  // set the brightness of the LED 
    delay(7); 
    DutyCycle=DutyCycle+1;  
  }
    while(DutyCycle >=0){
      ledcWrite(GreenLEDTop, DutyCycle);
      delay(7);
      DutyCycle=DutyCycle-1;
    }}
  
  //delay(2000);
  //digitalWrite(GreenTop_LED, LOW);
  Serial.println("Top Green LED OFF");
  display.println("Top Green LED OFF");
  display.display();
  display.setCursor(0, 0);
}
// Callback function to be called when Bottom Left Button is pressed
void onBLPressed()
{
  display.clearDisplay();
  //digitalWrite(YellowBottom_LED, HIGH);
  Serial.println("Bottom Left Button Press, Bottom Yellow LED");
  display.println("Bottom LB Pressed");
  display.display();
  display.println("Bottom Yellow LED ON");
  display.display();

  for (int i=0; i<=3; i++){
  DutyCycle = 0;
  while ( DutyCycle<=100) 
  {
    ledcWrite(YellowLEDBottom, DutyCycle);  // set the brightness of the LED 
    delay(7); 
    DutyCycle=DutyCycle+1;  
  }
    while(DutyCycle >=0){
      ledcWrite(YellowLEDBottom, DutyCycle);
      delay(7);
      DutyCycle=DutyCycle-1;
    }}
  
  //delay(2000);
  //digitalWrite(YellowBottom_LED, LOW);
  Serial.println("Bottom Yellow LED OFF");
  display.println("Bottom Yellow LED OFF");
  display.display();
  display.setCursor(0, 0);
}
// Callback function to be called when Middle Right is pressed
void onMRBPressed()
{
  display.clearDisplay();
  //digitalWrite(RedBottom_LED, HIGH);
  Serial.println("Middle Right Button Press, Bottom Red LED");
  display.println("Middle RB Pressed");
  display.display();
  display.println("Bottom Red LED ON");
  display.display();

  for (int i=0; i<=3; i++){
  DutyCycle = 0;
  while ( DutyCycle<=100) 
  {
    ledcWrite(RedLEDBottom, DutyCycle);  // set the brightness of the LED 
    delay(7); 
    DutyCycle=DutyCycle+1;  
  }
    while(DutyCycle >=0){
      ledcWrite(RedLEDBottom, DutyCycle);
      delay(7);
      DutyCycle=DutyCycle-1;
    }}
  
  //delay(2000);
  //digitalWrite(RedBottom_LED, LOW);
  Serial.println("Bottom Red LED OFF");
  display.println("Bottom Red LED OFF");
  display.display();
  display.setCursor(0, 0);
}
// Callback function to be called when ? is pressed
void onBRBPressed()
{
  display.clearDisplay();
  //digitalWrite(GreenBottom_LED, HIGH);
  Serial.println("Bottom Right Button Press, Bottom Green LED");
  display.println("Bottom RB Pressed");
  display.display();
  display.println("Bottom Green LED ON");
  display.display();

  for (int i=0; i<=3; i++){
  DutyCycle = 0;
  while ( DutyCycle<=100) 
  {
    ledcWrite(GreenLEDBottom, DutyCycle);  // set the brightness of the LED 
    delay(7); 
    DutyCycle=DutyCycle+1;  
  }
    while(DutyCycle >=0){
      ledcWrite(GreenLEDBottom, DutyCycle);
      delay(7);
      DutyCycle=DutyCycle-1;
    }}
  
  //delay(2000);
  //digitalWrite(GreenBottom_LED, LOW);
  Serial.println("Bottom Green LED OFF");
  display.println("Bottom Green LED OFF");
  display.display();
  display.setCursor(0, 0);
}

void setup()
{
   ledcAttach(BlueLEDTop,4000,8); //replaced obsolete ledcSetup and ledAttachPin code!!
   ledcAttach(RedLEDTop,4000,8); //replaced obsolete ledcSetup and ledAttachPin code!!
   ledcAttach(GreenLEDTop,4000,8); //replaced obsolete ledcSetup and ledAttachPin code!!
   ledcAttach(RedLEDBottom,4000,8);
   ledcAttach(YellowLEDBottom,4000,8);
   ledcAttach(GreenLEDBottom,4000,8);

  // Initialize Serial for debuging purposes
 //Serial.begin(BAUDRATE);
  Serial.begin(115200);
  // Serial.setTimeout(0);
  Wire.begin();
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }
  display.display();
  delay(2000); // Pause for 2 seconds
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setRotation(0);
  display.clearDisplay();
  display.setCursor(0, 0);

  // Define outputs:
 // pinMode(RedTop_LED, OUTPUT);
 // pinMode(BlueTop_LED, OUTPUT);
  //pinMode(GreenTop_LED, OUTPUT);
  //pinMode(RedBottom_LED, OUTPUT);
  //pinMode(YellowBottom_LED, OUTPUT);
  //pinMode(GreenBottom_LED, OUTPUT);

  //zero LEDs
  //digitalWrite(RedTop_LED, LOW);
  //digitalWrite(BlueTop_LED, LOW);
  //digitalWrite(GreenTop_LED, LOW);
  //digitalWrite(RedBottom_LED, LOW);
  //digitalWrite(YellowBottom_LED, LOW);
  //digitalWrite(GreenBottom_LED, LOW);

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
