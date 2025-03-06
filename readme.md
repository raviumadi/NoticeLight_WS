# ESP32 WebSocket Button-Controlled Display Status

This project demonstrates WebSocket communication between two ESP32 devices:
- **ESP32 Client**: Sends button press status (`ON`/`OFF`) over WebSockets.
- **ESP32 Server**: Listens for WebSocket messages and changes the color of the rectangle on the display accordingly.

# Showcase
![Status ON](img/esp_ws_on.png)
![Status OFF](img/esp_ws_off.png)

## FeaturesP
- WebSocket-based real-time communication.
- Standalone ESP32 Access Point - for ease of demonstration.
- Uses PlatformIO for development.

## Setup
1. Flash `ws-server/main.cpp` on the ESP32 Server.
2. Flash `ws-client/main.cpp` on the ESP32 Client.
3. Connect the **client** to the server's WiFi (`ESP32-Server`).
4. Press the button on the client, and the server's screen displays a Green or Red filled rectangle.

## Hardware
- **ESP32 Dev Boards - 2**

- **Button (Client)**

- **TFT Screen (Server)**

  