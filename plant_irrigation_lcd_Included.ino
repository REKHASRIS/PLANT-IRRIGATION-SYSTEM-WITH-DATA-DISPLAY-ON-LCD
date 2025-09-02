#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
int soilmoisture_sensor=A1;

void setup() 
{
  lcd.init();
  lcd.backlight();
  pinMode(soilmoisture_sensor,INPUT);
  Serial.begin(9600);
}

void loop() 
{
  int data=analogRead(soilmoisture_sensor);
  Serial.print("sensing : ");
  Serial.println(data);
  delay(1000);
 
 lcd.setCursor(0,0);
 lcd.print("soil_moisture : ");
 lcd.print(data);

 lcd.setCursor(0,1);
 int collect=map(data,0,1023,0,100);
 lcd.print("percentage % : " );
 lcd.print(collect);

  if(collect > 0 && collect < 40)
  {
    Serial.println("Soil Moisture : LOW");
    lcd.setCursor(0, 2);
    lcd.print("Warning : LOW");
  }

  else if(collect > 40 && collect < 80 )
 {
  Serial.println("reading value : Medium");
  lcd.setCursor(0,2);
  lcd.print("Warning : Medium");

 }

else if(collect < 100)
{
  Serial.println("reading value : High");
  lcd.setCursor(0,2);
  lcd.print("Warning : High");
}
  delay(1000);
  lcd.clear();
}