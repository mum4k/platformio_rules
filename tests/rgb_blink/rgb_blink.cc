// Blink an LED. The "hello world" of electronics.
//
// By default this will blink an LED connected to pin 13 (standard Arduino)
// with a 1/2 Hz frequency and a 50% duty cycle (1 second on, 1 second off).
//
// You can change the behaviour with the following macros at compile time:
// - TARGET_PIN: The number of the pin where the LED is connected to
// - TIME_HIGH_MS: The number of milliseconds the LED will be on per cycle
// - TIME_LOW_MS: The number of milliseconds the LED will be off per cycle

#include <Arduino.h>
#include <rgb_led.h>

// This is the pin used in the first version of the ESP32-S3 devkit
RGBLed led(48);

void setup() {}

void loop () {
    led.SetColor(255,0,0);
    delay(500);
    led.SetColor(0,255,0);
    delay(500);
    led.SetColor(0,0,255);
    delay(500);
}
