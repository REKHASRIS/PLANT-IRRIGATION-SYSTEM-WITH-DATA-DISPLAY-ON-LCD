int data;
int LDR=A1;
int RELAY=8;

void setup() 
{
  pinMode(LDR,INPUT);
  pinMode(RELAY,OUTPUT);
  Serial.begin(9600);

}

void loop()
{
 
   light();

  if (data > 0 && data < 900)
  {
    digitalWrite(RELAY,1);
  }
  else if(data > 900 && data < 1000)
  {
    digitalWrite(RELAY,0);

  }

}



void light()
{
  int data=analogRead(LDR);
  Serial.print("Sensing : ");
  Serial.println(data);
  Serial.print("");
  delay(1000);
 

 

}