#ifndef TEST_RGB_BLINK_RGB_LED_H
#define TEST_RGB_BLINK_RGB_LED_H

#include <stdint.h>
#include <Adafruit_NeoPixel.h>

class RGBLed {
public:
    RGBLed(int ledPin);

    void SetColor(uint16_t red, uint16_t green, uint16_t blue);

protected:
    Adafruit_NeoPixel led_;
};

#endif // TEST_RGB_BLINK_RGB_LED_H