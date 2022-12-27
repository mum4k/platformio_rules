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
#include <Arduino_impl.h>
#include <Arduino_interface.h>

using arduino::ArduinoImpl;
using arduino::ArduinoInterface;

#ifndef TARGET_PIN
// If target pin is not defined, use the Arduino standard 13
#define TARGET_PIN 13
#endif
#ifndef TIME_HIGH_MS
#define TIME_HIGH_MS 1000
#endif
#ifndef TIME_LOW_MS
#define TIME_LOW_MS 1000
#endif

// Arduino hardware layer.
const ArduinoImpl ino = ArduinoImpl();

void setup() {
    pinMode(TARGET_PIN, OUTPUT);
}

void loop () {
    ino.DigitalWrite(TARGET_PIN, HIGH);
    ino.Delay(TIME_HIGH_MS);
    ino.DigitalWrite(TARGET_PIN, LOW);
    ino.Delay(TIME_LOW_MS);
}
