const byte RedLEDTop = 13;  // the PWM pin Red Top LED *changed the resistor to a 1K ohm
int DutyCycle = 0;

// the setup routine runs once when you press reset:
void setup() {

 
  //ledcSetup(0, 4000, 8);       // 12 kHz PWM, 8-bit resolution
  //ledcAttachPin(led_gpio, 0);  // assign a led pins to a channel
  ledcAttach(RedLEDTop,4000,8); //replaced obsolete ledcSetup and ledAttachPin code!!
}

// the loop routine runs over and over again forever:
void loop() {
  ledcWrite(RedLEDTop, DutyCycle);  // set the brightness of the LED
  DutyCycle = DutyCycle + 1; // increment DutyCycle
  
  // reverse the direction of the fading at the ends of the fade:
 if (DutyCycle >= 90) {
   while(DutyCycle>=0) {
   ledcWrite(RedLEDTop, DutyCycle);
   delay(7); // wait for 7 milliseconds to see the dimming effect
   DutyCycle = DutyCycle-1;} //decrement DutyCycle
  }
  // wait for 7 milliseconds to see the dimming effect
  delay(7);
}