#include <Arduino.h>
#define RED_LED 8 // Red LED
#define YELLOW_LED 9 // Yellow LED
#define GREEN_LED 10 // Green LED
#define BLUE_LED 11 // Blue LED
#define INPUT_ONE 3
#define INPUT_TWO 4
#define INPUT_THREE 5
#define INPUT_FOUR 6

int val = 0;
int c = 0;

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

void startGame() {
  startGameLights();
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
}

// main loop
void loop() {
  // check for button presses, turn on associated LED
  val = digitalRead(INPUT_ONE);
  if (val == HIGH) {
    c++;
    digitalWrite(RED_LED, HIGH);
  }
  val = digitalRead(INPUT_TWO);
  if (val == HIGH) {
    c++;
    digitalWrite(YELLOW_LED, HIGH);
  }
  val = digitalRead(INPUT_THREE);
  if (val == HIGH) {
    c++;
    digitalWrite(GREEN_LED, HIGH);
  }
  val = digitalRead(INPUT_FOUR);
  if (val == HIGH) {
    c++;
    digitalWrite(BLUE_LED, HIGH);
  }
  // check if all buttons were pushed at once
  if (c == 4) {
    Serial.println("ALL PRESSED!");
    delay(500);
    // all LEDs off
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);

    startGame();
  }
  c = 0;
  // all LEDs off
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
}
