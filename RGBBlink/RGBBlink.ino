void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  #define RED_PIN 3
  #define BLUE_PIN 5
  #define GREEN_PIN 6
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

void loop() {
  
  LED(RED_PIN);
  LED(GREEN_PIN);
  LED(BLUE_PIN);
}
int LED(int SelectPinColor)
  {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(SelectPinColor, HIGH);
    delay(1000);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(SelectPinColor, LOW);
    delay(1000);                       // wait for a second
  }
