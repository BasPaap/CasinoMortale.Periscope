// Lift.h

#ifndef _LIFT_h
#define _LIFT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "A4988Driver.h"

namespace CasinoMortale
{
	class Lift
	{
		Bas::A4988Driver stepperDriver;

	public:
		Lift(int directionPin, int stepPin, int sleepPin);
		void initialize();
		void moveUp();
		void moveDown();
		void sleep();
		void wake();
	};
}
#endif