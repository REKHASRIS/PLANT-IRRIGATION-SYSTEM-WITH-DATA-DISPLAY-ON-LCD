int button1=7;
int button2=4;

void setup() {
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  Serial.begin(9600);

}

void loop() {
 int data1=digitalRead(button1);
 int data2=digitalRead(button2);
 Serial.print("pull up : ");
 Serial.println(data1);
 Serial.print("pull down : ");
 Serial.println(data2);
 delay(200);
 Serial.println();
 
 
  

}
