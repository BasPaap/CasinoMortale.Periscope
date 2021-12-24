#include "A4988Driver.h"

Bas::A4988Driver::A4988Driver(int directionPin, int stepPin, int sleepPin, int enablePin, int endStopTopPin, int endStopBottomPin) :	directionPin{ directionPin }, 
																																		stepPin{ stepPin }, 
																																		sleepPin{ sleepPin }, 
																																		enablePin{ enablePin },
																																		endStopTopPin{ endStopTopPin }, 
																																		endStopBottomPin { endStopBottomPin }
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
	Serial.print(", enable pin: ");
	Serial.print(enablePin);
	Serial.print(", endstop top pin: ");
	Serial.print(endStopTopPin);
	Serial.print(", endstop bottom pin: ");
	Serial.print(endStopBottomPin);
	Serial.println(".");

	pinMode(stepPin, OUTPUT);
	pinMode(directionPin, OUTPUT);
	pinMode(sleepPin, OUTPUT);
	pinMode(enablePin, OUTPUT);
	pinMode(endStopTopPin, INPUT_PULLUP);
	pinMode(endStopBottomPin, INPUT_PULLUP);
	
	digitalWrite(enablePin, LOW);	// Enable the stepper driver.
	sleep();
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

	bool isMovingUp = isMovingClockwise;
		
	for (int x = 0; x < numSteps; x++)
	{
		if (isMovingUp && digitalRead(endStopTopPin) == LOW)
		{
			Serial.println("Top endstop reached");
			break;
		}

		if (!isMovingUp && digitalRead(endStopBottomPin) == LOW)
		{
			Serial.println("Bottom endstop reached");
			break;
		}

		digitalWrite(stepPin, HIGH);
		delay(halfMicrostepDuration);
		digitalWrite(stepPin, LOW);
		delay(halfMicrostepDuration);
	}	

	Serial.println("Stepper motor reached position.");
}

void Bas::A4988Driver::moveToHomePosition()
{
	Serial.println("Moving stepper motor to home position.");

	wake();
	digitalWrite(directionPin, HIGH);	// Move down.

	while (digitalRead(endStopBottomPin) == HIGH)
	{
		digitalWrite(stepPin, HIGH);
		delay(1);
		digitalWrite(stepPin, LOW);
		delay(1);
	}

	Serial.println("Home position reached.");
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
