/*
  YK04 Module, Single Reading

  Reads a press of the remote control based on the YK04 driver
  and displays information in the default Serial.

  Single reading of the remote control.
  If the remote control is clamped, 
  value of the next pressing - NOT.
  Return value of pressing the remote control:
    Button::A - A button is pressed;
    Button::B - B button is pressed;
    Button::C - C button is pressed;
    Button::D - D button is pressed;
    Button::NOT - not pressed.

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
  const YK04_Module::Button button = module->singleRead();
  String buttonTitle;
  if (button == YK04_Module::Button::A) {
    buttonTitle = "A";
  } else if (button == YK04_Module::Button::B) {
    buttonTitle = "B";
  } else if (button == YK04_Module::Button::C) {
    buttonTitle = "C";
  } else if (button == YK04_Module::Button::D) {
    buttonTitle = "D";
  } else {
    buttonTitle = "NOT";
  }
  Serial.println("YK04, Single Reading: " + buttonTitle);
  delay(500); // To delay the output of information.
}
