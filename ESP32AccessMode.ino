#include<WiFi.h>
char SSID[]="Error";
char Pass[]="rekhaofficial";

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_AP);
  Serial.print("address");
  delay(5000);
  WiFi.softAP("SSID","Pass");
  Serial.println(WiFi.localIP());

  

}

void loop() {

}
