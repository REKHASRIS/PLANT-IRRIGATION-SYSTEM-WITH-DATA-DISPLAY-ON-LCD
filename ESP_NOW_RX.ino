#include <WiFi.h>
#include <esp_now.h>

uint8_t RELAY[7] = {18, 19, 22, 23, 21, 4, 15};

typedef struct struct_msg
{
  int data[5];
  int counter[5];
}struct_msg;

struct_msg incomingData;

void onDataRecv(const esp_now_recv_info_t *info, const uint8_t *data, int len)
{
  memcpy(&incomingData,data,sizeof(incomingData));
  digitalWrite(RELAY[5], incomingData.counter[0] ? LOW : HIGH );
  digitalWrite(RELAY[4], incomingData.counter[1] ? LOW : HIGH );
  digitalWrite(RELAY[3], incomingData.counter[2] ? LOW : HIGH );
  digitalWrite(RELAY[2], incomingData.counter[3] ? LOW : HIGH );
}

void setup() 
{
  Serial.begin(115200);

  for(int i = 0; i < 6; i++) { pinMode(RELAY[i], OUTPUT); }

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  esp_now_init();
  esp_now_register_recv_cb(onDataRecv);
}

void loop() {


}

