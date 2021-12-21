#include "A4988Driver.h"

Bas::A4988Driver::A4988Driver(int directionPin, int stepPin, int sleepPin, int stepsPerRevolution, int numMicrostepsPerSteps) : directionPin{ directionPin }, stepPin{ stepPin }, sleepPin{ sleepPin }, stepsPerRevolution{ stepsPerRevolution }, numMicrostepsPerStep{ numMicrostepsPerStep }
{
}

void Bas::A4988Driver::initialize()
{
	Serial.println("Initializing A4988Driver.");

	pinMode(stepPin, OUTPUT);
	pinMode(directionPin, OUTPUT);
	pinMode(sleepPin, OUTPUT);

	lastUpdateTime = millis();
}

void Bas::A4988Driver::update()
{
	if (numStepsRemaining > 0)
	{
		digitalWrite(stepPin, HIGH);
		digitalWrite(stepPin, LOW);		
		--numStepsRemaining;
	}

	lastUpdateTime = millis();
}

void Bas::A4988Driver::move(int numSteps, bool isMovingClockwise, int numRevolutionsPerMinute)
{
	Serial.print("Moving stepper motor ");
	Serial.print(numSteps);
	Serial.print(" steps ");
	Serial.print(isMovingClockwise ? "clockwise" : "counterclockwise");
	Serial.print(" at ");
	Serial.print(numRevolutionsPerMinute);
	Serial.print(" RPM.");

	digitalWrite(directionPin, isMovingClockwise ? HIGH : LOW);

	numStepsRemaining = numSteps;
	currentNumRevolutionsPerMinute = numRevolutionsPerMinute;
}
