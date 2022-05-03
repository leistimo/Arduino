int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT);
pinMode(8,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
buttonState = digitalRead(2);
if (buttonState == HIGH)
{
  //Serial.println("High");
}
else
{ 
  //Serial.println("Low");
  sos(250);
  delay(750);
  sos(1000);
  sos(250);
  delay(2750);
}}
int sos(int blink_delay)
{
  for (int x = 0; x < 3; x++){
  digitalWrite(8,HIGH);
  //Serial.println("High");
  delay(blink_delay);
  digitalWrite(8,LOW);
  //Serial.println("Low");
  delay(blink_delay);
}}
