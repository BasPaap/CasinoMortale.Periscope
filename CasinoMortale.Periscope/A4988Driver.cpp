#include "A4988Driver.h"

Bas::A4988Driver::A4988Driver(int directionPin, int stepPin, int sleepPin) : directionPin{ directionPin }, stepPin{ stepPin }, sleepPin{ sleepPin }
{
}

void Bas::A4988Driver::initialize()
{
	Serial.print("Initializing A4988Driver. Direction pin: ");
	Serial.print(directionPin);
	Serial.print(", step pin: ");
	Serial.print(stepPin);
	Serial.print(", sleep pin: ");
	Serial.print(sleepPin);
	Serial.println(".");

	pinMode(stepPin, OUTPUT);
	pinMode(directionPin, OUTPUT);
	pinMode(sleepPin, OUTPUT);
}

void Bas::A4988Driver::move(int numSteps, bool isMovingClockwise, int microstepDurationInMilliseconds)
{
	if (microstepDurationInMilliseconds < 2)
	{
		microstepDurationInMilliseconds = 2;
	}

	int halfMicrostepDuration = microstepDurationInMilliseconds / 2;

	Serial.print("Moving stepper motor ");
	Serial.print(numSteps);
	Serial.print(" steps ");
	Serial.print(isMovingClockwise ? "clockwise" : "counterclockwise");
	Serial.print(" at ");
	Serial.print(microstepDurationInMilliseconds);
	Serial.println(" milliseconds per microstep.");

	digitalWrite(directionPin, isMovingClockwise ? LOW : HIGH);
		
	for (int x = 0; x < numSteps; x++)
	{
		digitalWrite(stepPin, HIGH);
		delay(halfMicrostepDuration);
		digitalWrite(stepPin, LOW);
		delay(halfMicrostepDuration);
	}	
}

void Bas::A4988Driver::sleep()
{
	Serial.println("Putting A4988 driver in sleep mode.");
	digitalWrite(sleepPin, LOW);
}

void Bas::A4988Driver::wake()
{
	Serial.println("Waking A4988 driver from sleep mode.");
	digitalWrite(sleepPin, HIGH);
}
