int counter=0;

void setup() {
  // put your setup code here, to run once:
pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

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
    
  
    
