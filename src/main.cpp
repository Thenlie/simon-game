#include <Arduino.h>
#include <header.h>
#include <ezButton.h>

#define RED_LED 8 // Red LED
#define YELLOW_LED 9 // Yellow LED
#define GREEN_LED 10 // Green LED
#define BLUE_LED 11 // Blue LED
#define BUZZER 2

ezButton btn1(3);
ezButton btn2(4);
ezButton btn3(5);
ezButton btn4(6);

int level = 1; // count for number of lights in pattern
int patternArr[100]; // pattern the user will repeat
int inputArr[100]; // users input throughout the game
int inputCount = 0; // count of user inputs when guessing
int btnCount = 0; // count of button presses at the same time
long randNum;
bool running = false; // game state

// run once on setup
void setup() {
    pinMode(RED_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BLUE_LED, OUTPUT);
    pinMode(BUZZER, OUTPUT);

    btn1.setDebounceTime(50);
    btn2.setDebounceTime(50);
    btn3.setDebounceTime(50);
    btn4.setDebounceTime(50);

    btn1.setCountMode(COUNT_BOTH);
    btn2.setCountMode(COUNT_BOTH);
    btn3.setCountMode(COUNT_BOTH);
    btn4.setCountMode(COUNT_BOTH);

    Serial.begin(9600);
    randomSeed(analogRead(A0));
}

// show pattern to be repeated by user
void displayPattern() {
    Serial.print("Current level: ");
    Serial.println(level);
    delay(300);
    for (int i = 0; i < level; i++) {
        switch (patternArr[i]) {
            case 1:
                digitalWrite(RED_LED, HIGH);
                tone(BUZZER, 500);
                delay(300);
                digitalWrite(RED_LED, LOW);
                noTone(BUZZER);
                break;
            case 2:
                digitalWrite(YELLOW_LED, HIGH);
                tone(BUZZER, 600);
                delay(300);
                digitalWrite(YELLOW_LED, LOW);
                noTone(BUZZER);
                break;
            case 3:
                digitalWrite(GREEN_LED, HIGH);
                tone(BUZZER, 700);
                delay(300);
                digitalWrite(GREEN_LED, LOW);
                noTone(BUZZER);
                break;
            case 4:
                digitalWrite(BLUE_LED, HIGH);
                tone(BUZZER, 800);
                delay(300);
                digitalWrite(BLUE_LED, LOW);
                noTone(BUZZER);
                break;
        }
        delay(300);
    }
}

// check for button presses, turn on associated LED
void checkButtonPress() {
    if (btn1.isPressed()) {
        if (!running && btn1.getCount() == 1) {
            btnCount++;
        } if (btn2.getState() && btn3.getState() && btn4.getState() && btn1.getCount() == 1) {
            digitalWrite(RED_LED, HIGH);
            tone(BUZZER, 500);
            delay(100);
            inputArr[inputCount] = 1;
            inputCount++;
        }
        Serial.print(btn1.getCount());
        Serial.println(" Input was Red");
    } if (btn2.isPressed()) {
        if (!running && btn2.getCount() == 1) {
            btnCount++;
        } if (btn1.getState() && btn3.getState() && btn4.getState() && btn2.getCount() == 1) {
            digitalWrite(YELLOW_LED, HIGH);
            tone(BUZZER, 600);
            delay(100);
            inputArr[inputCount] = 2;
            inputCount++;
        }
        Serial.print(btn2.getCount());
        Serial.println(" Input was Yellow");  
    } if (btn3.isPressed()) {
        if (!running && btn3.getCount() == 1) {
            btnCount++;
        } if (btn1.getState() && btn2.getState() && btn4.getState() && btn3.getCount() == 1) {
            digitalWrite(GREEN_LED, HIGH);
            tone(BUZZER, 700);
            delay(100);
            inputArr[inputCount] = 3;
            inputCount++;
        }
        Serial.print(btn3.getCount());
        Serial.println(" Input was Green");
    } if (btn4.isPressed()) {
        if (!running && btn4.getCount() == 1) {
            btnCount++;
        } if (btn1.getState() && btn2.getState() && btn3.getState() && btn4.getCount() == 1) {
            digitalWrite(BLUE_LED, HIGH);
            tone(BUZZER, 800);
            delay(100);
            inputArr[inputCount] = 4;
            inputCount++;
        }
        Serial.print(btn4.getCount());
        Serial.println(" Input was Blue");
    }
}

// check for button releases, turn off associated LED
void checkButtonRelease() {
    if (btn1.isReleased()) {
        noTone(BUZZER);
        if (!running) {
            btnCount--;
        }
        btn1.resetCount();
        digitalWrite(RED_LED, LOW);
        Serial.println("Release was Red");
    } if (btn2.isReleased()) {
        noTone(BUZZER);
        if (!running) {
            btnCount--;
        }
        btn2.resetCount();
        digitalWrite(YELLOW_LED, LOW);
        Serial.println("Release was Yellow");
    } if (btn3.isReleased()) {
        noTone(BUZZER);
        if (!running) {
            btnCount--;
        }
        btn3.resetCount();
        digitalWrite(GREEN_LED, LOW);
        Serial.println("Release was Green");
    } if (btn4.isReleased()) {
        noTone(BUZZER);
        if (!running) {
            btnCount--;
        }
        btn4.resetCount();
        digitalWrite(BLUE_LED, LOW);
        Serial.println("Release was Blue");
    }
}

void startGame() {
    // reset variables
    level = 1;
    inputCount = 0;
    btnCount = 0;
    // fill pattern & input array
    for (int i = 0; i < 100; i++) {
        randNum = random(1, 5);
        patternArr[i] = randNum; 
        inputArr[i] = 0;
    }
    for (int i = 0; i < 100; i++) {
        Serial.println(patternArr[i]);
    }
    startGameLights();
    // countdown flashes
    for (int i = 0; i < 3; i++) {
        ledOn();
        delay(500);
        ledOff();
        delay(500);
    }
    Serial.println("Start Game!");
    running = true;
    displayPattern();
}

void gameOver() {
    ledOff();
    running = false;
    btnCount = 0;
    Serial.println("Game Over!");
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

void gameWin() {
    ledOff();
    running = false;
    btnCount = 0;
    Serial.println("You Win!");
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

// waiting for game to start
void gameWait() {
    checkButtonPress();
    checkButtonRelease();
    // check if all buttons were pushed at once to start game
    if (btnCount == 4) {
        Serial.println("All Buttons Pressed!");
        ledOff();
        noTone(BUZZER);
        delay(1000);
        startGame();
    } else if (btnCount > 4 || btnCount < 0) {
        btnCount = 0;
    }
}

// game in progress
void gamePlay() {
    checkButtonRelease();
    checkButtonPress();
    if (inputCount == level) {
        delay(100);
        ledOff();
        noTone(BUZZER);
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
            if (level == 99) {
                gameWin();
            } else {
                level++;
                inputCount = 0;
                displayPattern();
            }
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
