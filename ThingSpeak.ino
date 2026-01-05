#include <Wifi.h>
#include <thingSpeak.h>

char SSID[] = "EIOT";
char PASS[] = "GsBt@333";
char API[]  = "D7617J1NQNB8WPG";
unsigned long channelID = "3211016";

WifiClient client;

void setup() 
{
  serial.begin(9600);
  wifi.begin(SSID , PASS);
  ThingSpeak.begin(client);
  
}

void loop()
{
  int data = random(0 , 100);
  ThigSpeak.writeField(channelID, 1, data, API);
}
