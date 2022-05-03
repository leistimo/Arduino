int buttonState = 0;
int counter=0;

void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
buttonState = digitalRead(2);
if (buttonState == HIGH)
{
  Serial.println("High");
}
else
{ 
  Serial.println("Low");
  while (counter < 3)
      {digitalWrite(8,HIGH);
      delay(250);
      digitalWrite(8,LOW);
      delay(250);
      counter++;}
  counter = 0;  
  delay(250);   
 while (counter < 3)
      {digitalWrite(8,HIGH);
      delay(1000);
      digitalWrite(8,LOW);
      delay(1000);
      counter++;}
  counter = 0;
  //delay(500);
  while (counter < 3)
      {digitalWrite(8,HIGH);
      delay(250);
      digitalWrite(8,LOW);
      delay(250);
      counter++;}
  counter = 0;   
  delay(2000);  
}
}
