#include<WiFi.h>
char SSID[]="Vannakam da Mapla";
char Pass[]="12345678";


void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_AP_STA);
  Serial.print("address");
  WiFi.softAP("SSID","Pass");
  WiFi.begin("EIOT","GsBt@333");
    delay(5000);
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.softAPIP());
  //Serial.println(WiFi.macAddress());
  
  }

void loop() {
  

}

