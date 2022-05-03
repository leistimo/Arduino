int red = 0;
int blue = 85;
int green = 170;
int red_add = 1;
int blue_add = 1;
int green_add = 1;

void setup() 

{
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  #define RED_PIN 3
  #define BLUE_PIN 5
  #define GREEN_PIN 6
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  
}

void loop () 
 {  
  if (red>=255){ 
    red_add=-1;}
  if (red<=0){
    red_add=1;}
  if (blue>=255){ 
    blue_add=-1;}
  if (blue<=0){ 
     blue_add=1;}
  if (green>=255){ 
    green_add=-1;}
  if (green<=0){ 
    green_add=1;}
  Serial.print(red_add);
  Serial.print(blue_add);
  Serial.println(green_add);
  LED(RED_PIN,red);
  LED(BLUE_PIN,blue);
  LED(GREEN_PIN,green);
  red=red+red_add;
  blue=blue+blue_add;
  green=green+green_add;
  
 }
  
  
  //LED(GREEN_PIN);
  //LED(BLUE_PIN);
 // }


int LED(int Pin, int Intensity)
{
  //digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  analogWrite(Pin, Intensity);
  delay(10);                       // wait for a second
  //digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  //digitalWrite(RED_PIN, Red_Intensity);
  //delay(.1);                       // wait for a second
}
