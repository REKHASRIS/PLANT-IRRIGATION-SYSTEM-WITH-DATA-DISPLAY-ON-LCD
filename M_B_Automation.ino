#include <WiFi.h>
#include <esp_now.h>
#include <Preferences.h>

Preferences pref;

typedef struct 
{
  int id;
  bool state;
} SwitchMessage;

SwitchMessage msg;

int relayPins[7] = { 18, 19, 22, 23, 21, 4, 15 };

bool relayState[7];
void loadRelayState() 
{
  pref.begin("relays", true);  
  for (int i = 0; i < 7; i++) {
    relayState[i] = pref.getBool(String(i).c_str(), false);
    digitalWrite(relayPins[i], relayState[i] ? LOW : HIGH);
  }
  pref.end();
}

void saveRelayState(int id, bool state) {
  pref.begin("relays", false);
  pref.putBool(String(id).c_str(), state);
  pref.end();
}

void onDataRecv(const esp_now_recv_info_t *info, const uint8_t *incomingData, int len) {
  memcpy(&msg, incomingData, sizeof(msg));
 int index = msg.id - 1;
  if (index >= 0 && index < 7) {
    relayState[index] = msg.state;
    digitalWrite(relayPins[index], msg.state ? LOW : HIGH);

    saveRelayState(index, msg.state);

    Serial.printf("Relay %d -> %s (Saved)\n", msg.id, msg.state ? "ON" : "OFF");
  }
}

void setup() {
    Serial.begin(115200);

  for (int i = 0; i < 7; i++) {
    pinMode(relayPins[i], OUTPUT);
  }

  loadRelayState(); 

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW INIT FAILED!");
    return;
  }
esp_now_register_recv_cb(onDataRecv);
  Serial.println("Receiver Ready (State Restored)");
}


void loop() {
}
