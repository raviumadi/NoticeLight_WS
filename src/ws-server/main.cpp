#include <WiFi.h>
#include <WebSocketsServer.h>
#include "SPI.h"
#include "tftHandler.h"

const char* apSSID = "ESP32-Server";
const char* apPassword = "12345678"; // Minimum 8 characters

TFTHandler tftHandler;
SPIClass spi(HSPI);

WebSocketsServer webSocket(81);
const int ledPin = 2; // LED connected to GPIO2

void webSocketEvent(uint8_t num, WStype_t type, uint8_t* payload, size_t length) {
    switch (type) {
        case WStype_TEXT:
            if (strcmp((char*)payload, "ON") == 0) {
                digitalWrite(ledPin, HIGH);
                Serial.println("ON");
                tftHandler.clearDisplay();
                tftHandler.fillScreen(COLOR_GREEN);
            } else if (strcmp((char*)payload, "OFF") == 0) {
                digitalWrite(ledPin, LOW);
                Serial.println("OFF");
                // tftHandler.clearDisplay();
                tftHandler.fillScreen(COLOR_RED);
               
            }
            break;
    }
}

void setup() {
    Serial.begin(115200);
    
    // Display
    spi.begin();
    tftHandler.begin(spi);

    // Set up ESP32 as an Access Point (AP)
    WiFi.softAP(apSSID, apPassword);
    Serial.println("Access Point Started");
    Serial.print("AP IP Address: ");
    Serial.println(WiFi.softAPIP()); // Get the AP IP address

    webSocket.begin();
    webSocket.onEvent(webSocketEvent);

    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
}

void loop() {
    webSocket.loop();
}
