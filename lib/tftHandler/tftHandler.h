#ifndef TFTHANDLER_H
#define TFTHANDLER_H

#include "TFT_22_ILI9225.h"
#include "SPI.h"

class TFTHandler
{
public:
    TFTHandler();
    void begin(SPIClass &spi);
    void displayCrosshair(float x, float y);
    void fillScreen( uint16_t color); // New function to display text
    void clearDisplay();
private:
    TFT_22_ILI9225 _display;
    
};

#endif