const byte led_gpio = 13;  // the PWM pin the LED is attached to
int brightness = 0;        // how bright the LED is
int fadeAmount = 5;        // how many points to fade the LED by
int DutyCycle = 0;

// the setup routine runs once when you press reset:
void setup() {

  // Initialize channels
  // channels 0-15, resolution 1-16 bits, freq limits depend on resolution
  // ledcSetup(uint8_t channel, uint32_t freq, uint8_t resolution_bits);
  //ledcSetup(0, 4000, 8);       // 12 kHz PWM, 8-bit resolution
  //ledcAttachPin(led_gpio, 0);  // assign a led pins to a channel
  ledcAttach(13,4000,8);
}

// the loop routine runs over and over again forever:
void loop() {
  ledcWrite(13, DutyCycle);  // set the brightness of the LED

  DutyCycle = DutyCycle + 1;
  // change the brightness for next time through the loop:
  //brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
 if (DutyCycle >= 50) {
   DutyCycle = 0;
   ledcWrite(13, DutyCycle);
   delay(500);
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(70);
}