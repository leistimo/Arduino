int my_integers[]= { 1,//Index 0
                     2,//Index 1
                     3,//Index 2
                     4,//Index 3
                     5 //Index 4
                      };
int x = 0;
void setup() {
  Serial.begin(9600);

  while(!Serial)//wait for serial port to open
  {
    ;
  }
  
  
  
  //Serial.println("Your array numbers:");

  //for (int i=0; i<5; i++)
  //{
 // Serial.print("Index ");
  //Serial.print(i);
  //Serial.print(" contains value ");
  //Serial.println(my_integers[i]);
  //}
  //Serial.println();
  //Serial.println("Calculations"); 
  
  //for (int i=0; i<4; i++)
  //{
  //Serial.print(my_integers[i]);
  //Serial.print(" + ");
  //Serial.print(my_integers[i+1]);
  //Serial.print(" = ");
  //Serial.println(my_integers[i] + my_integers[i+1]);
  //}

  //Serial.println();
  //Serial.println("Calculations, and Store the results:");

  //for (int i=0; i<4; i++)
  //{
  //Serial.print(my_integers[i]);
  //Serial.print(" + ");
  //Serial.print(my_integers[i+1]);
  //Serial.print(" = ");
  //int sum = my_integers[i] + my_integers[i+1];
  //my_integers[i]=sum;
  //Serial.print(my_integers[i]);
  //Serial.print(" -> Index ");
  //Serial.print(i);
  //Serial.print(" now contains value ");
  //Serial.println(my_integers[i]);
  
  //}
  //Serial.println();
  //for (int i=0; i<8; i++)
  //{
  //Serial.print("Index ");
 // Serial.print(i);
  //Serial.print(" contains value ");
  //Serial.println(my_integers[i]);
 // }
  //my_integers[7]=100;
 // Serial.println(my_integers[7]);
  //Serial.println(my_integers[5]);
  //Serial.println(my_integers[6]);
  //Serial.println(my_integers[7]);

}

void loop() {
  
  my_integers[x]=1;
  Serial.print("Index ");
  Serial.print(x);
  Serial.print(" = ");
  Serial.print(my_integers[x]);
  Serial.println();
  x=x+1;
  

}
