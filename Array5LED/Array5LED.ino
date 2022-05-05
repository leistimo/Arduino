const int ledRed =3;
const int ledGreen =6;
const int ledBlue =5;
const int totalStates =11;

int ledState[totalStates];
int ledDuration[totalStates]={200,400,500,600,700,800,100,75,50,50};
void setup() {
  pinMode(ledGreen,OUTPUT);
  pinMode(ledBlue,OUTPUT);
  pinMode(ledRed,OUTPUT);

  Serial.begin(9600);
  while(!Serial)
  {
    ;//wait for serial port to connect.
  }
  for (int i=0;i<totalStates;i++)
  {
    Serial.print("Please type 1 or 0 for pattern step");
    Serial.print(i);
    Serial.print(" out of ");
    Serial.print(totalStates -1);
    Serial.print(" (default is 1): ");
      while (Serial.available()==0)
      {
      }
        char userInput = Serial.read();
        if (userInput=='1')
          ledState[i]=1;
        else if (userInput=='0')
          ledState[i]=0;
        else
          ledState[i]=1;
          
        Serial.println(ledState[i]);
      
  }
  for (int i=0;i<totalStates;i++)
    {
    Serial.print("Step ");
    Serial.print(i);
    Serial.print(" state is: ");
    Serial.print(ledState[i]);
    Serial.print(" with duration ");
    Serial.println(ledDuration[i]);
    }
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
