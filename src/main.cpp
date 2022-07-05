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
    pinMode(INPUT_ONE, INPUT);
    pinMode(INPUT_TWO, INPUT);
    pinMode(INPUT_THREE, INPUT);
    pinMode(INPUT_FOUR, INPUT);

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

void startGame() {
    // reset variables
    level = 1;
    inputCount = 0;
    btnCount = 0;
    // fill pattern array
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
    displayPattern();
}

void checkButtonRelease() {
    // check for button releases, turn off associated LED
    if (btn1.isPressed()) {
        btnCount--;
        digitalWrite(RED_LED, LOW);
    } if (btn2.isPressed()) {
        btnCount--;
        digitalWrite(YELLOW_LED, LOW);
    } if (btn3.isPressed()) {
        btnCount--;
        digitalWrite(GREEN_LED, LOW);
    } if (btn4.isPressed()) {
        btnCount--;
        digitalWrite(BLUE_LED, LOW);
    }
    // check for button presses, turn on associated LED
    if (btn1.isReleased() && !btn2.getState() && !btn3.getState() && !btn4.getState()) {
        btnCount++;
        digitalWrite(RED_LED, HIGH);
    } if (btn2.isReleased() && !btn1.getState() && !btn3.getState() && !btn4.getState()) {
        btnCount++;
        digitalWrite(YELLOW_LED, HIGH);
    } if (btn3.isReleased() && !btn1.getState() && !btn2.getState() && !btn4.getState()) {
        btnCount++;
        digitalWrite(GREEN_LED, HIGH);
    } if (btn4.isReleased() && !btn1.getState() && !btn2.getState() && !btn3.getState()) {
        btnCount++;
        digitalWrite(BLUE_LED, HIGH);
    }
}

void checkButtonPress() {
    // check for button presses, turn on associated LED
    if (btn1.isReleased()) {
        btnCount++;
        digitalWrite(RED_LED, HIGH);
    } if (btn2.isReleased()) {
        btnCount++;
        digitalWrite(YELLOW_LED, HIGH);
    } if (btn3.isReleased()) {
        btnCount++;
        digitalWrite(GREEN_LED, HIGH);
    } if (btn4.isReleased()) {
        btnCount++;
        digitalWrite(BLUE_LED, HIGH);
    }
}

void checkSingleButtonPress() {
    // check for button presses, turn on associated LED and push to inputArr
    if (btn1.isReleased() && !btn2.getState() && !btn3.getState() && !btn4.getState()) {
        inputArr[inputCount] = 1;
        inputCount++;
        digitalWrite(RED_LED, HIGH);
    } if (btn2.isReleased() && !btn1.getState() && !btn3.getState() && !btn4.getState()) {
        inputArr[inputCount] = 2;
        inputCount++;
        digitalWrite(YELLOW_LED, HIGH);
    } if (btn3.isReleased() && !btn1.getState() && !btn2.getState() && !btn4.getState()) {
        inputArr[inputCount] = 3;
        inputCount++;
        digitalWrite(GREEN_LED, HIGH);
    } if (btn4.isReleased() && !btn1.getState() && !btn2.getState() && !btn3.getState()) {
        inputArr[inputCount] = 4;
        inputCount++;
        digitalWrite(BLUE_LED, HIGH);
    }
}

void gameOver() {
    running = false;
}

void gameWait() {
    checkButtonPress();
    checkButtonRelease();
    // check if all buttons were pushed at once to start game
    if (btnCount == 4) {
        delay(500);
        startGame();
    }
}

void gamePlay() {
    checkSingleButtonPress();
    checkButtonRelease();
    if (inputCount == level) {
        for (int i = 0; i < level; i++) {
            if (inputArr[i] = patternArr[i]) {
                continue;
            } else {
                gameOver();
            }
        }
        // correct guess
        inputCount = 0;
    }
}

// main loop
void loop() {
    btn1.loop();
    btn2.loop();
    btn3.loop();
    btn4.loop();

    if (!running) {
        gameWait();
    } else {
        gamePlay();
    }
}
