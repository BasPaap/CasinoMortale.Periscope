// A4988Driver.h

#ifndef _A4988DRIVER_h
#define _A4988DRIVER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

namespace Bas
{
	class A4988Driver
	{
		int directionPin;
		int stepPin;
		int sleepPin;
		int stepsPerRevolution;
		int numMicrostepsPerStep;
		int numStepsRemaining;
		int currentNumRevolutionsPerMinute;
		long lastUpdateTime;

	public:
		A4988Driver(int directionPin, int stepPin, int sleepPin, int stepsPerRevolution = 200, int numMicrostepsPerSteps = 1);
		void initialize();
		void update();
		void move(int numSteps, bool isMovingClockwise, int speed);
	};
}

#endif