#include <Arduino.h>
#include <ezButton.h>
#define RED_LED 8 // Red LED
#define YELLOW_LED 9 // Yellow LED
#define GREEN_LED 10 // Green LED
#define BLUE_LED 11 // Blue LED

ezButton btn1(3);
ezButton btn2(4);
ezButton btn3(5);
ezButton btn4(6);

int level = 1; // count for number of lights in pattern
int patternArr[100]; // pattern the user will repeat
int inputArr[100]; // users input throughout the game
int inputCount = 0; // count of user inputs when guessing
int btnCount = 0; // count of button presses at the same time

bool running = false; // game state

// run once on setup
void setup() {
    pinMode(RED_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);

    btn1.setDebounceTime(50);
    btn2.setDebounceTime(50);
    btn3.setDebounceTime(50);
    btn4.setDebounceTime(50);

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
    Serial.print("Current level: ");
    Serial.println(level);
    for (int i = 0; i < level; i++) {
        switch (patternArr[i]) {
            case 1:
                digitalWrite(RED_LED, HIGH);
                delay(300);
                digitalWrite(RED_LED, LOW);
                break;
            case 2:
                digitalWrite(YELLOW_LED, HIGH);
                delay(300);
                digitalWrite(YELLOW_LED, LOW);
                break;
            case 3:
                digitalWrite(GREEN_LED, HIGH);
                delay(300);
                digitalWrite(GREEN_LED, LOW);
                break;
            case 4:
                digitalWrite(BLUE_LED, HIGH);
                delay(300);
                digitalWrite(BLUE_LED, LOW);
                break;
        }
        delay(300);
    }
}

void ledOn() {
    // all LEDs on
    digitalWrite(RED_LED, HIGH);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(BLUE_LED, HIGH);
}

void ledOff() {
    // all LEDs off
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
}

void checkButtonPress() {
    // check for button presses, turn on associated LED
    if (btn1.isPressed()) {
        if (!running) {
            btnCount++;
            digitalWrite(RED_LED, HIGH);
        } else if (btn2.getState() && btn3.getState() && btn4.getState()) {
            digitalWrite(RED_LED, HIGH);
            inputArr[inputCount] = 1;
            inputCount++;
            Serial.println("Red");
        }
        Serial.println("Input was Red");
    } if (btn2.isPressed()) {
        if (!running) {
            btnCount++;
            digitalWrite(YELLOW_LED, HIGH);
        } else if (btn1.getState() && btn3.getState() && btn4.getState()) {
            digitalWrite(YELLOW_LED, HIGH);
            inputArr[inputCount] = 2;
            inputCount++;
        }
        Serial.println("Input was Yellow");  
    } if (btn3.isPressed()) {
        if (!running) {
            btnCount++;
            digitalWrite(GREEN_LED, HIGH);
        } else if (btn1.getState() && btn2.getState() && btn4.getState()) {
            digitalWrite(GREEN_LED, HIGH);
            inputArr[inputCount] = 3;
            inputCount++;
            Serial.println("Green");
        }
        Serial.println("Input was Green");
    } if (btn4.isPressed()) {
        if (!running) {
            btnCount++;
            digitalWrite(BLUE_LED, HIGH);
        } else if (btn1.getState() && btn2.getState() && btn3.getState()) {
            digitalWrite(BLUE_LED, HIGH);
            inputArr[inputCount] = 4;
            inputCount++;
        }
        Serial.println("Input was Blue");
    }
}

void checkButtonRelease() {
    // check for button releases, turn off associated LED
    if (btn1.isReleased()) {
        if (!running) {
            btnCount--;
        }
        digitalWrite(RED_LED, LOW);
        Serial.println("Release was Red");
    } if (btn2.isReleased()) {
        if (!running) {
            btnCount--;
        }
        digitalWrite(YELLOW_LED, LOW);
        Serial.println("Release was Yellow");
    } if (btn3.isReleased()) {
        if (!running) {
            btnCount--;
        }
        digitalWrite(GREEN_LED, LOW);
        Serial.println("Release was Green");
    } if (btn4.isReleased()) {
        if (!running) {
            btnCount--;
        }
        digitalWrite(BLUE_LED, LOW);
        Serial.println("Release was Blue");
    }
}

void startGame() {
    checkButtonRelease();
    // reset variables
    level = 5;
    inputCount = 0;
    btnCount = 0;
    // fill pattern & input array
    for (int i = 0; i < 100; i++) {
        patternArr[i] = random(4) + 1; 
        inputArr[i] = 0;
    }
    running = true;
    startGameLights();
    // countdown flashes
    for (int i = 0; i < 3; i++) {
        ledOn();
        delay(500);
        ledOff();
        delay(500);
    }
    Serial.println("Start Game!");
    displayPattern();
}

void gameOver() {
    running = false;
    btnCount = 0;
    Serial.println("Game Over!");
    for (int i = 0; i < 7; i++) {
        digitalWrite(RED_LED, HIGH);
        delay(100);
        digitalWrite(RED_LED, LOW);
        delay(100);
    }
}

void gameWait() {
    checkButtonPress();
    checkButtonRelease();
    // check if all buttons were pushed at once to start game
    if (btnCount == 4) {
        Serial.println("All Buttons Pressed!");
        ledOff();
        delay(1000);
        startGame();
    }
}

void gamePlay() {
    checkButtonRelease();
    checkButtonPress();
    if (inputCount == level) {
        Serial.println("Checking guess...");
        for (int i = 0; i < level; i++) {
            Serial.println(inputArr[i]);
            Serial.println(patternArr[i]);
            if (inputArr[i] == patternArr[i]) {
                continue;
            } else {
                gameOver();
                break;
            }
        }
        if (running) {
            // correct pattern was entered
            level++;
            inputCount = 0;
            displayPattern();
        }
    }
}

// main loop
void loop() {
    btn1.loop();
    btn2.loop();
    btn3.loop();
    btn4.loop();

    if (running) {
        gamePlay();
    } else {
        gameWait();
    }
}
