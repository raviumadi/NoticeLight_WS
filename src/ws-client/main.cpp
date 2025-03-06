#include <WiFi.h>
#include <ArduinoWebsockets.h>

using namespace websockets;

const char* ssid = "ESP32-Server";  // Server ESP32's AP SSID
const char* password = "12345678";  // Server ESP32's AP Password
const char* serverAddress = "ws://192.168.4.1:81"; // Default AP IP for ESP32

WebsocketsClient client;

const int buttonPin = 4; // GPIO0 for the button
bool lastButtonState = HIGH;

void setup() {
    Serial.begin(115200);

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to ESP32-Server...");
    }
    Serial.println("Connected to ESP32 WebSocket Server");

    client.onMessage([](WebsocketsMessage message) {
        Serial.println("Received: " + message.data());
    });

    if (client.connect(serverAddress)) {
        Serial.println("Connected to WebSocket Server");
    }

    pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
    client.poll();

    bool buttonState = digitalRead(buttonPin);
    if (buttonState != lastButtonState) {
        lastButtonState = buttonState;
        if (buttonState == LOW) {
            client.send("ON");
        } else {
            client.send("OFF");
        }
    }
}