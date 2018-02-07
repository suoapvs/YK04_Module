/*
  YK04 Module

  Reads a press of the remote control based on the YK04 driver
  and displays information in the default Serial.

  https://github.com/YuriiSalimov/YK04_Module

  Created by Yurii Salimov, February, 2018.
  Released into the public domain.
*/
#include <YK04_Module.h>

#define A_PIN  7
#define B_PIN  6
#define C_PIN  5
#define D_PIN  4

YK04_Module* module;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  module = new YK04_Module(A_PIN, B_PIN, C_PIN, D_PIN);
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("YK04: A - " + String(module->isA()));
  Serial.print(" | B - " + String(module->isB()));
  Serial.print(" | C - " + String(module->isC()));
  Serial.println(" | D - " + String(module->isD()));
}