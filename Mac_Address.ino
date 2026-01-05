#include<WiFi.h>

void setup() {  
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  delay(3000);
  Serial.print("address");
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.macAddress());
  delay(1000); 
}

void loop() {
 

}
