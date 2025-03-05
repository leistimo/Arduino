/* Comment Section:

Blink LEDs
https://docs.arduino.cc/built-in-examples/basics/Blink/

*/
//include librarys 
#include <Wire.h> //https://docs.arduino.cc/language-reference/en/functions/communication/wire/
#include <Adafruit_SSD1306.h> //https://docs.arduino.cc/libraries/adafruit-ssd1306/
#include <Adafruit_Sensor.h> //https://github.com/adafruit/Adafruit_Sensor
#include <EasyButton.h>
//#include <MPU6050_light.h>

//Define OLED
#define SCREEN_WIDTH 128 //OLED display width, in pixels
#define SCREEN_HEIGHT 32 //OLED display height, in pixels
//const unsigned int MAX_MESSAGE_LENGTH = 24;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

//Name Pins
#define RedTop_LED 13
#define BlueTop_LED 12
#define GreenTop_LED 14
#define RedBottom_LED 27
#define YellowBottom_LED 26
#define GreenBottom_LED 25

#define Top_Right 32
#define Top_Left 33

// Button1
EasyButton TR(Top_Right);
// Button2
EasyButton TL(Top_Left);

//Declare variables
String LED = "initialize"; //Declare LED as a Text Variable

//the setup function runs once at power-up or reset.

void setup() {
  Serial.begin(115200);
  Wire.begin(); //Initialize I2C communication
  //SSD1306_SWITCHAPVCC, 0x3C = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }
  display.display();
  delay(2000); // Pause for 2 seconds
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setRotation(0);
  display.setCursor(0,0);

  
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
}


void loop() {
  digitalWrite(RedTop_LED, HIGH);  // turn the LED on (HIGH is the voltage level)
  LED = "Red Top On";
  Serial.println(LED); //write "Red Top On" to the Serial Monitor
  display.println(LED); //OLED "Red Top On"
  display.display();
  delay(2000);                      // wait for a second
  digitalWrite(RedTop_LED, LOW);   // turn the LED off by making the voltage LOW
  LED = "Red Top Off";
  Serial.println(LED); //write "Red Top Off" to the Serial Monitor
  display.println(LED); //OLED "Red Top On"
  display.display();
  delay(2000); 

  display.clearDisplay();// Clear the buffer
  display.setCursor(0,0);// Set Cursor

  digitalWrite(BlueTop_LED, HIGH);  // turn the LED on (HIGH is the voltage level)
  LED = "Blue Top On";
  Serial.println(LED); //write "Red Top On" to the Serial Monitor
  display.println(LED); //OLED "Red Top On"
  display.display();
  delay(2000);                      // wait for a second
  digitalWrite(BlueTop_LED, LOW);   // turn the LED off by making the voltage LOW
  LED = "Blue Top Off";
  Serial.println(LED); //write "Red Top Off" to the Serial Monitor
  display.println(LED); //OLED "Red Top On"
  display.display();
  delay(2000); 

  display.clearDisplay();// Clear the buffer
  display.setCursor(0,0);// Set Cursor

  digitalWrite(GreenTop_LED, HIGH);  // turn the LED on (HIGH is the voltage level)
  LED = "Green Top On";
  Serial.println(LED); //write "Red Top On" to the Serial Monitor
  display.println(LED); //OLED "Red Top On"
  display.display();
  delay(2000);                      // wait for a second
  digitalWrite(GreenTop_LED, LOW);   // turn the LED off by making the voltage LOW
  LED = "Green Top Off";
  Serial.println(LED); //write "Red Top Off" to the Serial Monitor
  display.println(LED); //OLED "Red Top On"
  display.display();
  delay(2000); 

  display.clearDisplay();// Clear the buffer
  display.setCursor(0,0);// Set Cursor

  digitalWrite(RedBottom_LED, HIGH);  // turn the LED on (HIGH is the voltage level)
  LED = "Red Bottom On";
  Serial.println(LED); //write "Red Top On" to the Serial Monitor
  display.println(LED); //OLED "Red Top On"
  display.display();
  delay(2000);                      // wait for a second
  digitalWrite(RedBottom_LED, LOW);   // turn the LED off by making the voltage LOW
  LED = "Red Bottom Off";
  Serial.println(LED); //write "Red Top Off" to the Serial Monitor
  display.println(LED); //OLED "Red Top On"
  display.display();
  delay(2000); 

  display.clearDisplay();// Clear the buffer
  display.setCursor(0,0);// Set Cursor

  digitalWrite(YellowBottom_LED, HIGH);  // turn the LED on (HIGH is the voltage level)
  LED = "Yellow Bottom On";
  Serial.println(LED); //write "Red Top On" to the Serial Monitor
  display.println(LED); //OLED "Red Top On"
  display.display();
  delay(2000);                      // wait for a second
  digitalWrite(YellowBottom_LED, LOW);   // turn the LED off by making the voltage LOW
  LED = "Yellow Bottom Off";
  Serial.println(LED); //write "Red Top Off" to the Serial Monitor
  display.println(LED); //OLED "Red Top On"
  display.display();
  delay(2000); 

  display.clearDisplay();// Clear the buffer
  display.setCursor(0,0);// Set Cursor

  digitalWrite(GreenBottom_LED, HIGH);  // turn the LED on (HIGH is the voltage level)
  LED = "Green Bottom On";
  Serial.println(LED); //write "Red Top On" to the Serial Monitor
  display.println(LED); //OLED "Red Top On"
  display.display();
  delay(2000);                      // wait for a second
  digitalWrite(GreenBottom_LED, LOW);   // turn the LED off by making the voltage LOW
  LED = "Green Bottom Off";
  Serial.println(LED); //write "Red Top Off" to the Serial Monitor
  display.println(LED); //OLED "Red Top On"
  display.display();
  delay(2000); 

  
  display.clearDisplay();// Clear the buffer
  display.setCursor(0,0);// Set Cursor
}
