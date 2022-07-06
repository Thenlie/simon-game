#include <Arduino.h>
#include <header.h>

#define RED_LED 8 // Red LED
#define YELLOW_LED 9 // Yellow LED
#define GREEN_LED 10 // Green LED
#define BLUE_LED 11 // Blue LED

// all LEDs on
void ledOn() {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BLUE_LED, HIGH);
}

// all LEDs off
void ledOff() {
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
}

// LED pattern before game starts
void startGameLights() {
    for (int i = 0; i < 5; i++) {
        digitalWrite(RED_LED, HIGH);
        delay(75);
        digitalWrite(RED_LED, LOW);
        digitalWrite(YELLOW_LED, HIGH);
        delay(75);
        digitalWrite(YELLOW_LED, LOW);
        digitalWrite(GREEN_LED, HIGH);
        delay(75);
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(BLUE_LED, HIGH);
        delay(75);
        digitalWrite(BLUE_LED, LOW);
    }
}