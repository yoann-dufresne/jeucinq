#include <Arduino.h>
#include <string.h>
#include <WiFiManager.h>
#include <ESPAsyncWebServer.h>
#include "node.hpp"

#ifndef NETWORK_H
#define NETWORK_H

bool led_on = false;

class Network
{
public:
    Node *node;
    WiFiManager wifiManager;
    AsyncWebServer * server;

    Network() {
        this->server = nullptr;
    };

    ~Network() {
        delete this->server;
    }

    void run (Node *n)
    {
        this->node = n;

        WiFi.mode(WIFI_STA);
        bool res = wifiManager.autoConnect("AutoConnectAP","password"); // password protected ap

        if(!res) {
            Serial.println("Failed to connect");
            // ESP.restart();
        } 
        else {
            //if you get here you have connected to the WiFi    
            Serial.println("connected...yeey :)");
        }

        // Create AsyncWebServer object on port 80
        this->server = new AsyncWebServer(80);

        this->server->on("/blink", HTTP_GET, [&](AsyncWebServerRequest *request){
            Serial.printf("blink %d \n", led_on);
            if (led_on)
                node->color_all(0, 0, 0);
            else
                node->color_all(10, 0, 0);
    
            led_on=!led_on;
            request->send_P(200, "text/plain", "blink");
        });
        
        // /color?d=ring&num=0&color=red

        this->server->on("/color", HTTP_GET, [&](AsyncWebServerRequest *request){
            int params = request->params();

            String device = request->getParam(0)->value().c_str();
            int num = atoi(request->getParam(1)->value().c_str());
            int colorid = atoi(request->getParam(2)->value().c_str());

            node->color_led(device, num, colorid);
            node->show();
            request->send_P(200, "text/plain", "color");
        });
        
        // Start server
        this->server->begin();/**/
                
    }
};
#endif

