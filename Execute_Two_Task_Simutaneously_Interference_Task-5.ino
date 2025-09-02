int LED1=3;
int LED2=12;
int LED3=8;
int IR_Sensor=7;
unsigned long interval1=1000;
unsigned long interval2=200;
unsigned long previous1=0;
unsigned long previous2=0;

void setup() {
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(IR_Sensor,INPUT);
  Serial.begin(9600);
  
}

void loop(){
  unsigned long current_milli=millis();
  if(current_milli-previous1>=interval1)
  {
    previous1=current_milli;
    if(digitalRead(LED1)==LOW)
    {
      digitalWrite(LED1,1);
    }
    else
    {
      digitalWrite(LED1,0);
    }
  }
    if(current_milli-previous2>=interval2)
    {
      previous2=current_milli;
      if(digitalRead(LED2)==LOW)
      {
        digitalWrite(LED2,1);
      }
      else
      {
       digitalWrite(LED2,0);
    }
    int data=digitalRead(IR_Sensor);
    if(data==0)
    {
      digitalWrite(LED3,0);
    }
    else
    {
      digitalWrite(LED3,1);
    }
    }

  }
