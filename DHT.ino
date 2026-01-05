#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL3bIkRJQz8"
#define BLYNK_TEMPLATE_NAME "DHT11"
#define BLYNK_AUTH_TOKEN "3eKFlLhJlJuZ_yRgtP9osK7EhVfCl3Uj"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

DHT dht(2,DHT11);

char SSID[] = "EIOT";
char PASS[] = "GsBt@333";
char AUTH[] = BLYNK_AUTH_TOKEN;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(AUTH, SSID, PASS);
  dht.begin();
  
  
}

void loop()
{
  Blynk.run();
  int hum = dht.readHumidity();
  float temp = dht.readTemperature();
  Serial.println(hum);
  Serial.println(temp);
  Blynk.virtualWrite(V0,hum);
  Blynk.virtualWrite(V1,temp);
  delay(1000);
}