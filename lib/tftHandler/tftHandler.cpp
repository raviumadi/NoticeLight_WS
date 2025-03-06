#include "tftHandler.h"

// Define the TFT pins for ESP32
#define TFT_RST 4
#define TFT_RS  2
#define TFT_CLK 14
#define TFT_SDI 13
#define TFT_CS  15
#define TFT_LED 0 // Set to 0 if wired to 5V

#define TFT_BRIGHTNESS 200


// TFT screen dimensions
#define SCREEN_WIDTH 176
#define SCREEN_HEIGHT 220

// Constructor
TFTHandler::TFTHandler()
    : _display(TFT_RST, TFT_RS, TFT_CS, TFT_LED, TFT_BRIGHTNESS) {}

// Initialize the display
void TFTHandler::begin(SPIClass &spi) {
    _display.begin(spi);
    _display.setBackgroundColor(COLOR_BLACK);
    _display.clear();
}

// Clear the display
void TFTHandler::clearDisplay() {
    _display.clear();
}

// Display the crosshair
void TFTHandler::displayCrosshair(float x, float y) {
    clearDisplay();  // Clear the display before drawing the crosshair

    // Calculate circle parameters
    float circleRadius = 50.0;
    float circleCenterX = SCREEN_WIDTH / 2.0;
    float circleCenterY = (SCREEN_HEIGHT / 2.0) + 11;

    // Draw circle
    _display.drawCircle(circleCenterX, circleCenterY, circleRadius, COLOR_WHITE);
}

// New function to draw text on the TFT display
// void TFTHandler::drawText(int x, int y, const char* text, uint16_t color) {
//     // Set a large font size
//     _display.setFont(TFT_FONT_BIG);
//     _display.setBackgroundColor(color);
//     _display.drawText(x, y, text);
// }

void TFTHandler::fillScreen(uint16_t color) {
    _display.fillRectangle(20, 20, 120, 120, color);;
    // _display.clear(); // Clear before writing new text
}