#include <WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>

char SSID[] = "NetShare";
char PASS[] = "password";
char API[]  = "HNVV0KLA96W03K4B";
unsigned long ChannelID =  3214717;

WiFiClient client;   

DHT dht(4, DHT11);


void setup() {
  Serial.begin(9600);
  dht.begin();
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASS);
  delay(5000);
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.println("WiFi is not connected");
    Serial.println(WiFi.status());
    delay(500);
  }
  Serial.println("WiFi is Connected");
  Serial.println(WiFi.status());

  ThingSpeak.begin(client);
}

void loop() {
  int hum = dht.readHumidity();
  float temp = dht.readTemperature();
  Serial.println(hum);
  Serial.println(temp);

  ThingSpeak.writeField(ChannelID,1,hum, API);
  ThingSpeak.writeField(ChannelID,2,temp, API);
}