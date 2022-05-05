int my_integers[6]= { 1,//Index 0
                      2,//Index 1
                      3,//Index 2
                      4,//Index 3
                      5 //Index 4
                      };
void setup() {
  Serial.begin(9600);

  while(!Serial)//wait for serial port to open
  {
    ;
  }
  
  Serial.println("Your array numbers:");

  for (int i=0; i<5; i++)
  {
    Serial.print("Index ");
    Serial.print(i);
    Serial.print(" contains value ");
    Serial.println(my_integers[i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
