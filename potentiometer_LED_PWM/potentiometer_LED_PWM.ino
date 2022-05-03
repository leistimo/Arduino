void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(6,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(analogRead(A0));
//delay(500);
int potValue = analogRead(A0);
int mappedValue = map(potValue,0, 993, 0, 255);
//normally the 993 would be 1023 but my voltage is low
analogWrite(6,mappedValue);
}
