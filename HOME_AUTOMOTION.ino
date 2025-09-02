#include <SoftwareSerial.h>
SoftwareSerial BLUETOOTH(4,5);
char data;
int CELLING_FAN=6;
int TUBELIGHT=7;
int REFRIDGERATOR=8;
int WASHING_MACHINE=9;
int TELEVISION=10;


void setup() {
  pinMode(CELLING_FAN,OUTPUT);
  pinMode(TUBELIGHT,OUTPUT);
  pinMode(REFRIDGERATOR,OUTPUT);
  pinMode(WASHING_MACHINE,OUTPUT);
  pinMode(TELEVISION,OUTPUT);

  Serial.begin(9600);
  BLUETOOTH.begin(9600);
  

}

void loop() {
  if(BLUETOOTH.available())
  {
    data=BLUETOOTH.read();
    Serial.println(data);
  }

  {
    switch(data)
    {
      case'a': 
      digitalWrite(CELLING_FAN,1);
      break;
      
      case'b':
      digitalWrite(TUBELIGHT,1);
      break;

      case'c':
      digitalWrite(REFRIDGERATOR,1);
      break;

      case'd':
      digitalWrite(WASHING_MACHINE,1);
      break;

      case'e':
      digitalWrite(TELEVISION,1);
      break;

      case'1':
      digitalWrite(1,0);
      break;

      case'2':
      digitalWrite(2,0);
      break;

      case'3':
      digitalWrite(3,0);
      break;

      case'4':
      digitalWrite(4,0);
      break;

      case'5':
      digitalWrite(5,0);
      break;

  }
  }


  
  

}
