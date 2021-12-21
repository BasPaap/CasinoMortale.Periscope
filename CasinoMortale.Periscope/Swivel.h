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
		const int minPulseWidth = 900;
		const int maxPulseWidth = 2100;
		const float speed = 200.0f;
		Servo servo;
		int servoPin;
		float destinationServoPosition = 90.0f;
		float currentServoPosition = 90;		
		unsigned long lastUpdateTime;
		void updateServo();
	public:
		Swivel(int pin);
		void initialize();
		void update();
	};
}

#endif