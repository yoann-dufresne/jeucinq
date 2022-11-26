/*
  ESP-NOW Multi Unit Demo
  esp-now-multi.ino
  Broadcasts control messages to all devices in network
  Load script on multiple devices

  DroneBot Workshop 2022
  https://dronebotworkshop.com
*/

// Include Libraries
#include <WifiManager.hpp>
WifiManager wm;


void setup() {
  // Set up Serial Monitor
  Serial.begin(115200);
  delay(1000);

  // Init wifi datastructs
  wm.setVerbose(true);
  wm.init();
}

void loop()
{
}
