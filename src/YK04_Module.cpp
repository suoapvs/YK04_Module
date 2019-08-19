/**
	Created by Yurii Salimov, February, 2018.
	Released into the public domain.
*/
#include "YK04_Module.h"

YK04_Module::YK04_Module(
	const int A_pin,
	const int B_pin,
	const int C_pin,
	const int D_pin,
	const boolean invertSignal
) {
	pinMode(this->A_pin = A_pin, INPUT_PULLUP);
	pinMode(this->B_pin = B_pin, INPUT_PULLUP);
	pinMode(this->C_pin = C_pin, INPUT_PULLUP);
	pinMode(this->D_pin = D_pin, INPUT_PULLUP);
	if (invertSignal) {
		invert();
	}
}

YK04_Module::Button YK04_Module::singleRead() {
	const Button pressedButton = multipleRead();
	return (pressedButton != this->previousButton) ?
		(this->previousButton = pressedButton) :
		Button::NOT;
}

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

void YK04_Module::invert() {
	this->signal = (this->signal == LOW) ? HIGH : LOW;
}

inline boolean YK04_Module::isPressed(const int pin) {
	return digitalRead(pin) == this->signal;
}
