/*
  YK04 Module

  Reads a press of the remote control based on the YK04 driver
  and displays information in the default Serial.

  https://github.com/YuriiSalimov/YK04_Module

  Created by Yurii Salimov, February, 2018.
  Released into the public domain.
*/
#include <YK04_Module.h>

#define A_PIN 4 // (D0)
#define B_PIN 5 // (D1)
#define C_PIN 6 // (D2)
#define D_PIN 7 // (D3)

YK04_Module* module;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);

  module = new YK04_Module(A_PIN, B_PIN, C_PIN, D_PIN);
  /* Or if you need to invert a signal of buttons pressing
    module = new YK04_Module(A_PIN, B_PIN, C_PIN, D_PIN, true);
  */
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("YK04: A - " + String(module->isA()));
  Serial.print(" | B - " + String(module->isB()));
  Serial.print(" | C - " + String(module->isC()));
  Serial.println(" | D - " + String(module->isD()));

  delay(200); // optionally, only to delay the output of information in the example
}
