// Lift.h

#ifndef _LIFT_h
#define _LIFT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

namespace CasinoMortale
{
	class Lift
	{
		int directionPin;
		int stepPin;
		int stepsPerRevolution;
		int numMicrostepsPerStep;

	public:
		Lift(int directionPin, int stepPin, int stepsPerRevolution = 200, int numMicrostepsPerSteps = 1);
		void initialize();
	};
}

#endif