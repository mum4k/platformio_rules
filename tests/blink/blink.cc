#include <Arduino.h>

#ifndef TARGET_PIN
#error TARGET_PIN must be defined
#endif

void setup() {
    pinMode(TARGET_PIN, OUTPUT);
}

void loop () {
    digitalWrite(TARGET_PIN, HIGH);
    delay(1000);
    digitalWrite(TARGET_PIN, LOW);
    delay(1000);
}