// Swivel.h

#ifndef _SWIVEL_h
#define _SWIVEL_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include <Servo.h>

namespace CasinoMortale
{
	class Swivel
	{	
		const int minPulseWidth = 450;
		const int maxPulseWidth = 2450;
		const float speed = 200.0f;
		Servo servo;
		int servoPin;
		float currentPosition;
		
	public:
		Swivel(int pin);
		void initialize();
		void turn(float destinationPosition, float speed);
	};
}

#endif