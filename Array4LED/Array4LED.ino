const int ledRed =3;
const int ledGreen =6;
const int ledBlue =5;
const int totalStates =11;

int ledState[totalStates]={1,0,1,0,1,0,1,0,1,0};
int ledDuration[totalStates]={50,50,100,100,200,200,300,300,400,400};
void setup() {
  pinMode(ledGreen,OUTPUT);
  pinMode(ledBlue,OUTPUT);
  pinMode(ledRed,OUTPUT);
  

}

void loop() {
  for (int i=0;i<totalStates;i++)
  {
    digitalWrite(ledGreen,ledState[i]);
    delay(ledDuration[i]);
  }
  for (int i=0;i<totalStates;i++)
  {
    digitalWrite(ledBlue,ledState[i]);
    delay(ledDuration[i]);
  }
    for (int i=0;i<totalStates;i++)
  {
    digitalWrite(ledRed,ledState[i]);
    delay(ledDuration[i]);
  }
  for (int i=0;i<totalStates;i++)
  {
    digitalWrite(ledRed,ledState[i]);
    delay(ledDuration[i]);
    digitalWrite(ledGreen,ledState[i]);
    delay(ledDuration[i]);
    digitalWrite(ledBlue,ledState[i]);
    delay(ledDuration[i]);
  }
}
