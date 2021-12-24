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
		int enablePin;
		int endStopTopPin;
		int endStopBottomPin;
		
	public:
		A4988Driver(int directionPin, int stepPin, int sleepPin, int enablePin, int endStopTopPin, int endStopBottomPin);
		void initialize();		
		void move(int numMicrosteps, bool isMovingClockwise, int microstepDurationInMilliseconds);
		void moveToHomePosition();
		void sleep();
		void wake();
	};
}

#endif