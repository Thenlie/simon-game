#include <Arduino.h>
#include <header.h>

#define RED_LED 8 // Red LED
#define YELLOW_LED 9 // Yellow LED
#define GREEN_LED 10 // Green LED
#define BLUE_LED 11 // Blue LED
#define BUZZER 2

// all LEDs on
void ledOn() {
    tone(BUZZER, 900);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BLUE_LED, HIGH);
}

// all LEDs off
void ledOff() {
    noTone(BUZZER);
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
}

// LED pattern before game starts
void startGameLights() {
    for (int i = 0; i < 5; i++) {
        digitalWrite(RED_LED, HIGH);
        tone(BUZZER, 500);
        delay(75);
        digitalWrite(RED_LED, LOW);
        noTone(BUZZER);
        digitalWrite(YELLOW_LED, HIGH);
        tone(BUZZER, 600);
        delay(75);
        digitalWrite(YELLOW_LED, LOW);
        noTone(BUZZER);
        digitalWrite(GREEN_LED, HIGH);
        tone(BUZZER, 700);
        delay(75);
        digitalWrite(GREEN_LED, LOW);
        noTone(BUZZER);
        digitalWrite(BLUE_LED, HIGH);
        tone(BUZZER, 800);
        delay(75);
        digitalWrite(BLUE_LED, LOW);
        noTone(BUZZER);
    }
}

void gameOverLights() {
    for (int i = 0; i < 3; i++) {
        digitalWrite(BLUE_LED, HIGH);
        tone(BUZZER, 700);
        delay(75);
        digitalWrite(BLUE_LED, LOW);
        noTone(BUZZER);
        digitalWrite(GREEN_LED, HIGH);
        tone(BUZZER, 600);
        delay(75);
        digitalWrite(GREEN_LED, LOW);
        noTone(BUZZER);
        digitalWrite(YELLOW_LED, HIGH);
        tone(BUZZER, 500);
        delay(75);
        digitalWrite(YELLOW_LED, LOW);
        noTone(BUZZER);
        digitalWrite(RED_LED, HIGH);
        tone(BUZZER, 400);
        delay(75);
        digitalWrite(RED_LED, LOW);
        noTone(BUZZER);
    }
    delay(200);
    // red light flashes
    for (int i = 0; i < 7; i++) {
        tone(BUZZER, 400);
        digitalWrite(RED_LED, HIGH);
        delay(100);
        noTone(BUZZER);
        digitalWrite(RED_LED, LOW);
        delay(100);
    }
}

void gameWinLights() {
    for (int i = 0; i < 7; i++) {
        digitalWrite(RED_LED, HIGH);
        tone(BUZZER, 500);
        delay(75);
        digitalWrite(RED_LED, LOW);
        noTone(BUZZER);
        digitalWrite(YELLOW_LED, HIGH);
        tone(BUZZER, 600);
        delay(75);
        digitalWrite(YELLOW_LED, LOW);
        noTone(BUZZER);
        digitalWrite(GREEN_LED, HIGH);
        tone(BUZZER, 700);
        delay(75);
        digitalWrite(GREEN_LED, LOW);
        noTone(BUZZER);
        digitalWrite(BLUE_LED, HIGH);
        tone(BUZZER, 800);
        delay(75);
        digitalWrite(BLUE_LED, LOW);
        noTone(BUZZER);
    }
    delay(200);
    // green light flashes
    for (int i = 0; i < 7; i++) {
        tone(BUZZER, 900);
        digitalWrite(GREEN_LED, HIGH);
        delay(100);
        noTone(BUZZER);
        digitalWrite(GREEN_LED, LOW);
        delay(100);
    }
}
