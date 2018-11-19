/**
	The class implements a set of methods of the YK04_Module.h
	library for working with a remote control sensors based
	on the YK04 driver.

	https://github.com/YuriiSalimov/YK04_Module

	Created by Yurii Salimov, February, 2018.
	Released into the public domain.
*/
#include "YK04_Module.h"

YK04_Module::YK04_Module(
	const int A_pin,
	const int B_pin,
	const int C_pin,
	const int D_pin
) : YK04_Module::YK04_Module(A_pin, B_pin, C_pin, D_pin, false) {
}

YK04_Module::YK04_Module(
	const int A_pin,
	const int B_pin,
	const int C_pin,
	const int D_pin,
	const boolean invertSignal
) {
	this->A_pin = A_pin;
	this->B_pin = B_pin;
	this->C_pin = C_pin;
	this->D_pin = D_pin;
	if (invertSignal) {
		invert();
	}
	init();
}

inline void YK04_Module::init() {
	pinMode(this->A_pin, INPUT_PULLUP);
	pinMode(this->B_pin, INPUT_PULLUP);
	pinMode(this->C_pin, INPUT_PULLUP);
	pinMode(this->D_pin, INPUT_PULLUP);
}

/**
	Single reading of the remote control.
	If the remote control is clamped,
	value of the next pressing - NOT.
	@return value of pressing the remote control:
		Button::A - A button is pressed;
		Button::B - B button is pressed;
		Button::C - C button is pressed;
		Button::D - D button is pressed;
		Button::NOT - not pressed.
*/
YK04_Module::Button YK04_Module::singleRead() {
	const Button currentButton = multipleRead();
	if (currentButton != this->previousButton) {
		this->previousButton = currentButton;
		return currentButton;
	}
	return Button::NOT;
}

/**
	Multiple reading of the remote control.
	If the remote control is clamped,
	returns a pressed button value.
	@return value of pressing the remote control:
		Button::A - A button is pressed;
		Button::B - B button is pressed;
		Button::C - C button is pressed;
		Button::D - D button is pressed;
		Button::NOT - not pressed.
*/
YK04_Module::Button YK04_Module::multipleRead() {
	if (isA()) {
		return Button::A;
	} else if (isB()) {
		return Button::B;
	} else if (isC()) {
		return Button::C;
	} else if (isD()) {
		return Button::D;
	}
	return Button::NOT;
}

boolean YK04_Module::isA() {
	return isPressed(this->A_pin);
}

boolean YK04_Module::isB() {
	return isPressed(this->B_pin);
}

boolean YK04_Module::isC() {
	return isPressed(this->C_pin);
}

boolean YK04_Module::isD() {
	return isPressed(this->D_pin);
}

boolean YK04_Module::isPressed(const int pin) {
	return digitalRead(pin) == this->signal;
}

void YK04_Module::invert() {
  this->signal = (this->signal == LOW) ? HIGH : LOW;
}
