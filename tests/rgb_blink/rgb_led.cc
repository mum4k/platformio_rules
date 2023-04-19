#include <rgb_led.h>

RGBLed::RGBLed(int ledPin) : led_(1, ledPin, NEO_GRB + NEO_KHZ800) {}

void RGBLed::SetColor(uint16_t red, uint16_t green, uint16_t blue) {
    led_.setPixelColor(0, red, green, blue);
    led_.show();
}
