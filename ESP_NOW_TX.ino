#include <WiFi.h>
#include <esp_now.h>

uint8_t Receivermac[] = {0xE8, 0x6B, 0xEA, 0xDF, 0x85, 0x48};
uint8_t Switches[5] = {13, 12, 26, 25, 15};
uint8_t buzzer = 23;

typedef struct Struct_msg
{
  int data[5];
  int counter[4];
}Struct_msg;

Struct_msg outgoingData;

void onDataSent(const wifi_tx_info_t *info, esp_now_send_status_t status)
{
  //Serial.print("status : ");
  //Serial.println(status == ESP_NOW_SEND_SUCCESS ? "SUCCESS" : "FAIL");
}

void setup() 
{
  Serial.begin(115200);

  for(int j = 0 ; j < 5 ; j++){ pinMode(Switches[j],INPUT_PULLUP); }
  pinMode( buzzer , OUTPUT);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  esp_now_init();

  esp_now_register_send_cb(onDataSent);
  esp_now_peer_info_t peerinfo={};
  memcpy(peerinfo.peer_addr, Receivermac, 6);
  peerinfo.channel = 0;
  peerinfo.encrypt = false;
  esp_now_add_peer(&peerinfo);
}

void loop() 
{
  outgoingData.data[0] = digitalRead(Switches[0]);
  outgoingData.data[1] = digitalRead(Switches[1]);
  outgoingData.data[2] = digitalRead(Switches[2]);
  outgoingData.data[3] = digitalRead(Switches[3]);
  outgoingData.data[4] = digitalRead(Switches[4]);

  if(outgoingData.data[0] == 0)
  {
    tone(buzzer , 1500 , 200);
    outgoingData.counter[0]++ ; 
    Serial.println(outgoingData.counter[0]);
    if(outgoingData.counter[0]==2)
    {
      outgoingData.counter[0] = 0;
    }
    delay(250);
  }

  if(outgoingData.data[1] == 0)
  {
    tone(buzzer , 1500 , 200);
    outgoingData.counter[1]++ ; 
    Serial.println(outgoingData.counter[1]);
    if(outgoingData.counter[1]==2)
    {
      outgoingData.counter[1] = 0;
    }
    delay(250);
  }

  if(outgoingData.data[2] == 0)
  {
    tone(buzzer , 1500 , 200);
    outgoingData.counter[2]++ ; 
    Serial.println(outgoingData.counter[2]);
    if(outgoingData.counter[2]==2)
    {
      outgoingData.counter[2] = 0;
    }
    delay(250);
  }

  if(outgoingData.data[3] == 0)
  {
    tone(buzzer , 1500 , 200);
    outgoingData.counter[3]++ ; 
    Serial.println(outgoingData.counter[3]);
    if(outgoingData.counter[3]==2)
    {
      outgoingData.counter[3] = 0;
    }
    delay(250);
  }

  esp_now_send(Receivermac, (uint8_t *)&outgoingData, sizeof(outgoingData));
}
