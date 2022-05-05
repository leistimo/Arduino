char my_char[6]={'a','b','c','d','e'};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial)
  {
    ;
  }
  
  Serial.println("Your array char:");
  for (int i=0;i<5;i++)
  {
    Serial.print("Index ");
    Serial.print(i);
    Serial.print(", contains char ");
    Serial.print(my_char[i]);
    Serial.print(", ASCII decimal ");
    Serial.println(my_char[i], DEC);
  }
  for (int x=0;x<4;x++)
  {
    Serial.print(my_char[x]);
    Serial.print(" + ");
    Serial.print(my_char[x+1]);
    Serial.print(" = ");
    Serial.println(my_char[x] + my_char[x+1]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
