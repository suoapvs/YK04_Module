/**
	YK04_Module.h - The library describes
	a set of methods for working with a remote control
	sensors based on the YK04 driver.

	v.1.0.2:
	- optimized call of the init() method.

	https://github.com/YuriiSalimov/YK04_Module

	Created by Yurii Salimov, February, 2018.
	Released into the public domain.
*/
#ifndef YK04_MODULE_H
#define YK04_MODULE_H

#if defined(ARDUINO) && (ARDUINO >= 100)
	#include <Arduino.h>
#else
	#include <WProgram.h>
#endif

class YK04_Module final {

	public:
		/**
			Enums of a possible pressings
			of the remote controller:
				A - A button is pressed;
				B - B button is pressed;
				C - C button is pressed;
				D - D button is pressed;
				NOT - not pressed.
		*/
		enum Button {
			A, B, C, D, NOT
		};

	private:
		int A_pin;
		int B_pin;
		int C_pin;
		int D_pin;

		/**
			Actuation signal: LOW or HIGH.
		*/
		volatile int signal = LOW;

		/**
			The value for the temporary storage
			of the previous pressing of the remote
			controller.
		*/
		Button previousButton = Button::NOT;

	public:
		/**
			Constructor.
			Digital ports pins:
			@param A_pin - A button (D0).
			@param B_pin - B button (D1).
			@param C_pin - C button (D2).
			@param D_pin - D button (D3).
		*/
		YK04_Module(
			int A_pin,
			int B_pin,
			int C_pin,
			int D_pin
		);

		/**
			Constructor.
			Digital ports pins:
			@param A_pin - A button (D0).
			@param B_pin - B button (D1).
			@param C_pin - C button (D2).
			@param D_pin - D button (D3).
			@param invertSignal - invert a sensors actuation signal.
		*/
		YK04_Module(
			int A_pin,
			int B_pin,
			int C_pin,
			int D_pin,
			boolean invertSignal
		);

		/**
			Single reading of the remote control.
			If the remote control is clamped,
			value of the next pressing - NOT.
			@return value of pressing the remote control.
		*/
		Button singleRead();

		/**
			Multiple reading of the remote control.
			If the remote control is clamped,
			returns a pressed button value.
			@return value of pressing the remote control.
		*/
		Button multipleRead();

		/**
			Checks if the A button is pressed.
			@return true - button is pressed,
			false - button is not pressed.
		*/
		boolean isA();

		/**
			Checks if the B button is pressed.
			@return true - button is pressed,
			false - button is not pressed.
		*/
		boolean isB();

		/**
			Checks if the C button is pressed.
			@return true - button is pressed,
			false - button is not pressed.
		*/
		boolean isC();

		/**
			Checks if the D button is pressed.
			@return true - button is pressed,
			false - button is not pressed.
		*/
		boolean isD();

		/**
			Inverts signal.
			If invert signal:
				onSignal = LOW
			If not invert signal:
				onSignal = HIGH
		*/
		void invert();

	private:
		/**
			Initialization of the module.
		*/
		inline void init();

		/**
			Checks if a button is pressed.
			@param pin - port pin of a button.
			@return true - button is pressed,
			false - button is not pressed.
		*/
		boolean isPressed(int pin);
};

#endif
