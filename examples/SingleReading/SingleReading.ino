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
  Serial.print("YK04, Single Reading: ");
  Serial.println(buttonTitle(module->singleRead()));

  delay(300); // optionally, only to delay the output of information in the example
}

/**
  Return title of the input button.
*/
String buttonTitle(const YK04_Module::Button button) {
  switch (button) {
    case YK04_Module::Button::NOT:
      return "NOT";
    case YK04_Module::Button::A:
      return "A";
    case YK04_Module::Button::B:
      return "B";
    case YK04_Module::Button::C:
      return "C";
    case YK04_Module::Button::D:
      return "D";
    default:
      return "???";
  }
}
