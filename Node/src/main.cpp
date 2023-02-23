#include <Arduino.h>
#include "network.hpp"
#include "node.hpp"

Node node;
Network nw;

void setup() { 
  // Serial port for debugging purposes
  Serial.begin(115200);
  delay(1000);
  nw.run(&node);
}

void loop() { 
  Serial.println("pouette");
  delay(25000);
  
  /*node.color_all(10, 0, 0);
  delay(500);
  
  node.color_all(0, 0, 0);
  delay(500);/**/
}