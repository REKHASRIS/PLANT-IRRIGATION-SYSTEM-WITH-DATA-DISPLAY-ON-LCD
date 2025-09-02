int button=7;
int led=4;


void setup() {
  pinMode(button,INPUT_PULLUP);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
  int data1=digitalRead(button);
  Serial.print("pull up");
  Serial.println(data1);

  if(data1==0)
  {
  digitalWrite(led,1);
  Serial.print("ON");
}

  else
  {
  digitalWrite(led,0);
  Serial.print("OFF");
}
 
}
