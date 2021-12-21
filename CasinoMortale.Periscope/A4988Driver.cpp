#include "A4988Driver.h"

Bas::A4988Driver::A4988Driver(int directionPin, int stepPin, int sleepPin) : directionPin{ directionPin }, stepPin{ stepPin }, sleepPin{ sleepPin }
{
}

void Bas::A4988Driver::initialize()
{
	Serial.println("Initializing A4988Driver.");

	pinMode(stepPin, OUTPUT);
	pinMode(directionPin, OUTPUT);
	pinMode(sleepPin, OUTPUT);
}

void Bas::A4988Driver::move(int numSteps, bool isMovingClockwise, int microstepDurationInMilliseconds)
{
	if (microstepDurationInMilliseconds < 1)
	{
		microstepDurationInMilliseconds = 1;
	}

	Serial.print("Moving stepper motor ");
	Serial.print(numSteps);
	Serial.print(" steps ");
	Serial.print(isMovingClockwise ? "clockwise" : "counterclockwise");
	Serial.print(" at ");
	Serial.print(microstepDurationInMilliseconds);
	Serial.print(" milliseconds per microstep.");

	digitalWrite(directionPin, isMovingClockwise ? HIGH : LOW);

	for (int i = 0; i < numSteps; i++)
	{
		digitalWrite(stepPin, HIGH);
		digitalWrite(stepPin, LOW);
		delay(microstepDurationInMilliseconds);
	}
}