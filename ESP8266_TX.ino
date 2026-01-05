#include <ESP8266WiFi.h>
#include <espnow.h>

// Receiver MAC Address
uint8_t receiverMAC[] = {0xEC, 0xFA, 0xBC, 0x4E, 0xE5, 0x99};

void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
  Serial.print("Send Status: ");
  Serial.println(sendStatus == 0 ? "Success" : "Fail");
}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != 0) {
    Serial.println("ESP-NOW init failed!");
    return;
  }

  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_register_send_cb(OnDataSent);
  esp_now_add_peer(receiverMAC, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}

void loop() {
  const char msg[] = "Hello ESP8266";
  esp_now_send(receiverMAC, (uint8_t *)msg, sizeof(msg));
  delay(1000);
}