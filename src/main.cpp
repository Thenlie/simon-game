#include <Arduino.h>
#define RED_LED 8 // Red LED
#define YELLOW_LED 9 // Yellow LED
#define GREEN_LED 10 // Green LED
#define BLUE_LED 11 // Blue LED
#define INPUT_ONE 3 // Button 1
#define INPUT_TWO 4 // Button 2
#define INPUT_THREE 5 // Button 3
#define INPUT_FOUR 6 // Button 4

int val = 0;
int btnCount = 0; // count of button pushes per loop
int level = 1; // count for number of lights in pattern
int patternArr[100]; // pattern the user will repeat

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
  for (int i = 0; i < 100; i++) {
    patternArr[i] = random(4) + 1; 
  }
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

void startGame() {
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

// main loop
void loop() {
  // check for button presses, turn on associated LED
  val = digitalRead(INPUT_ONE);
  if (val == HIGH) {
    btnCount++;
    digitalWrite(RED_LED, HIGH);
  }
  val = digitalRead(INPUT_TWO);
  if (val == HIGH) {
    btnCount++;
    digitalWrite(YELLOW_LED, HIGH);
  }
  val = digitalRead(INPUT_THREE);
  if (val == HIGH) {
    btnCount++;
    digitalWrite(GREEN_LED, HIGH);
  }
  val = digitalRead(INPUT_FOUR);
  if (val == HIGH) {
    btnCount++;
    digitalWrite(BLUE_LED, HIGH);
  }
  // check if all buttons were pushed at once
  if (btnCount == 4) {
    Serial.println("ALL PRESSED!");
    delay(500);
    // all LEDs off
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);

    startGame();
  }
  btnCount = 0;
  // all LEDs off
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
}
