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

void setup() {
  // put your setup code here, to run once:
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
  digitalWrite(RED_LED, HIGH);
  delay(50);
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);
  delay(50);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  delay(50);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, HIGH);
  delay(50);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(RED_LED, HIGH);
  delay(50);
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);
  delay(50);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  delay(50);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, HIGH);
  delay(50);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(RED_LED, HIGH);
  delay(50);
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);
  delay(50);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  delay(50);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, HIGH);
  delay(50);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(RED_LED, HIGH);
  delay(50);
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);
  delay(50);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  delay(50);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, HIGH);
  delay(50);
  digitalWrite(BLUE_LED, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
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
  if (c == 4) {
    Serial.println("ALL PRESSED!");
    delay(500);
    // all LEDs off
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(BLUE_LED, LOW);

    startGameLights();
  }
  c = 0;
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
}
