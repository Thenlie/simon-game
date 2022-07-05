#include <Arduino.h>
#include <ezButton.h>
#define RED_LED 8 // Red LED
#define YELLOW_LED 9 // Yellow LED
#define GREEN_LED 10 // Green LED
#define BLUE_LED 11 // Blue LED
#define INPUT_ONE 3 // Button 1
#define INPUT_TWO 4 // Button 2
#define INPUT_THREE 5 // Button 3
#define INPUT_FOUR 6 // Button 4

ezButton button1(3);
ezButton button2(4);
ezButton button3(5);
ezButton button4(6);

int level = 1; // count for number of lights in pattern
int patternArr[100]; // pattern the user will repeat
int inputCount = 0; // count of user inputs when guessing
int btnCount = 0; // count of button presses at the same time
int ledState = LOW;
int buttonState;
int lastButtonState = LOW;
int btnTarget; // button being tracked for debounce

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

bool running = false; // game state

// run once on setup
void setup() {
    pinMode(RED_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
    pinMode(INPUT_ONE, INPUT);
    pinMode(INPUT_TWO, INPUT);
    pinMode(INPUT_THREE, INPUT);
    pinMode(INPUT_FOUR, INPUT);

    button1.setDebounceTime(50);
    button2.setDebounceTime(50);
    button3.setDebounceTime(50);
    button4.setDebounceTime(50);

    Serial.begin(9600);
}

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

void displayPattern() {
    for (int i = 0; i < level; i++) {
        switch (patternArr[i]) {
            case 1:
                digitalWrite(RED_LED, HIGH);
                delay(100);
                digitalWrite(RED_LED, LOW);
                break;
            case 2:
                digitalWrite(YELLOW_LED, HIGH);
                delay(100);
                digitalWrite(YELLOW_LED, LOW);
                break;
            case 3:
                digitalWrite(GREEN_LED, HIGH);
                delay(100);
                digitalWrite(GREEN_LED, LOW);
                break;
            case 4:
                digitalWrite(BLUE_LED, HIGH);
                delay(100);
                digitalWrite(BLUE_LED, LOW);
                break;
        }
    delay(50);
  }
}

void ledOff() {
    // all LEDs off
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
}

void startGame() {
    // fill pattern array
    for (int i = 0; i < 100; i++) {
        patternArr[i] = random(4) + 1; 
    }
    running = true;
    startGameLights();
    // countdown flashes
    for (int i = 0; i < 3; i++) {
        // all LEDs on
        digitalWrite(RED_LED, HIGH);
        digitalWrite(YELLOW_LED, HIGH);
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(BLUE_LED, HIGH);
        delay(500);
        // all LEDs off
        digitalWrite(RED_LED, LOW);
        digitalWrite(YELLOW_LED, LOW);
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(BLUE_LED, LOW);
        delay(500);
    }
    displayPattern();
}

void gameWait() {
    // check for button presses, turn on associated LED
    if (button1.isPressed()) {
        btnCount--;
        digitalWrite(RED_LED, LOW);
    }
    if (button2.isPressed()) {
        btnCount--;
        digitalWrite(YELLOW_LED, LOW);
    }
    if (button3.isPressed()) {
        btnCount--;
        digitalWrite(GREEN_LED, LOW);
    }
    if (button4.isPressed()) {
        btnCount--;
        digitalWrite(BLUE_LED, LOW);
    }

    if (button1.isReleased()) {
        btnCount++;
        digitalWrite(RED_LED, HIGH);
    }
    if (button2.isReleased()) {
        btnCount++;
        digitalWrite(YELLOW_LED, HIGH);
    }
    if (button3.isReleased()) {
        btnCount++;
        digitalWrite(GREEN_LED, HIGH);
    }
    if (button4.isReleased()) {
        btnCount++;
        digitalWrite(BLUE_LED, HIGH);
    }

    // // check for button presses, turn on associated LED
    // int val = digitalRead(INPUT_ONE);
    // int btnCount = 0;
    // if (val == HIGH) {
    //     btnCount++;
    //     digitalWrite(RED_LED, HIGH);
    // }
    // val = digitalRead(INPUT_TWO);
    // if (val == HIGH) {
    //     btnCount++;
    //     digitalWrite(YELLOW_LED, HIGH);
    // }
    // val = digitalRead(INPUT_THREE);
    // if (val == HIGH) {
    //     btnCount++;
    //     digitalWrite(GREEN_LED, HIGH);
    // }
    // val = digitalRead(INPUT_FOUR);
    // if (val == HIGH) {
    //     btnCount++;
    //     digitalWrite(BLUE_LED, HIGH);
    // }

    // ledOff();

    // check if all buttons were pushed at once
    if (btnCount == 4) {
        Serial.println("ALL PRESSED!");
        delay(500);
        startGame();
    }
}

void gamePlay() {
    // check for button presses, turn on associated LED
    int val = digitalRead(INPUT_ONE);
    if (val == HIGH) {
        Serial.println("RED");
        digitalWrite(RED_LED, HIGH);
        btnTarget = 1;
        delay(50);
        ledOff();
        return;
    }
    val = digitalRead(INPUT_TWO);
    if (val == HIGH) {
        Serial.println("YELLOW");
        digitalWrite(YELLOW_LED, HIGH);
        btnTarget = 2;
        delay(50);
        ledOff();
        return;
    }
    val = digitalRead(INPUT_THREE);
    if (val == HIGH) {
        Serial.println("GREEN");
        digitalWrite(GREEN_LED, HIGH);
        btnTarget = 3;
        delay(50);
        ledOff();
        return;
    }
    val = digitalRead(INPUT_FOUR);
    if (val == HIGH) {
        Serial.println("BLUE");
        digitalWrite(BLUE_LED, HIGH);
        btnTarget = 4;
        delay(50);
        ledOff();
        return;
    }
}

// main loop
void loop() {
    button1.loop();
    button2.loop();
    button3.loop();
    button4.loop();

    // if (button1.isReleased()) {
    //     Serial.println("RED");
    // }
    // if (button2.isReleased()) {
    //     Serial.println("YELLOW");
    // }
    // if (button3.isReleased()) {
    //     Serial.println("GREEN");
    // }
    // if (button4.isReleased()) {
    //     Serial.println("BLUE");
    // }

    if (!running) {
        gameWait();
    } else {
        gamePlay();
    }
}
