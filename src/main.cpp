#include <Arduino.h>
#define RED_LED 2 // Red LED
#define YELLOW_LED 3 // Yellow LED
#define GREEN_LED 4 // Green LED
#define BLUE_LED 5 // Blue LED
#define INPUT_ONE 8
#define INPUT_TWO 9
#define INPUT_THREE 10
#define INPUT_FOUR 11

int val = 0;

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

void loop() {
  // put your main code here, to run repeatedly:
  
  val = digitalRead(INPUT_ONE);
  if(val == HIGH) {
    Serial.println("HIGH");
  }
  if(val == LOW) {
    Serial.println("LOW");
  }
  delay(1000);
  val = digitalRead(INPUT_TWO);
  if(val == HIGH) {
    Serial.println("HIGH");
  }
  if(val == LOW) {
    Serial.println("LOW");
  }
  delay(1000);
  val = digitalRead(INPUT_THREE);
  if(val == HIGH) {
    Serial.println("HIGH");
  }
  if(val == LOW) {
    Serial.println("LOW");
  }
  delay(1000);
  val = digitalRead(INPUT_FOUR);
  if(val == HIGH) {
    Serial.println("HIGH");
  }
  if(val == LOW) {
    Serial.println("LOW");
  }
  delay(1000);
  
  
  // digitalWrite(RED_LED, HIGH);
  // delay(1000);
  // digitalWrite(RED_LED, LOW);
  // digitalWrite(YELLOW_LED, HIGH);
  // delay(1000);
  // digitalWrite(YELLOW_LED, LOW);
  // digitalWrite(GREEN_LED, HIGH);
  // delay(1000);
  // digitalWrite(GREEN_LED, LOW);
  // digitalWrite(BLUE_LED, HIGH);
  // delay(1000);
  // digitalWrite(BLUE_LED, LOW);
}