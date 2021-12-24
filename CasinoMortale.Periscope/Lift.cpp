#include "Lift.h"

CasinoMortale::Lift::Lift(int directionPin, int stepPin, int sleepPin) : stepperDriver{ directionPin, stepPin, sleepPin }
{
}

void CasinoMortale::Lift::initialize()
{
	Serial.println("Initializing lift.");
	stepperDriver.initialize();
	stepperDriver.sleep();
}

void CasinoMortale::Lift::moveUp()
{
	Serial.println("Moving lift up.");
	stepperDriver.move(2000, true, 1);
}

void CasinoMortale::Lift::moveDown()
{
	Serial.println("Moving lift down.");
	stepperDriver.move(2000, false, 1);
}

void CasinoMortale::Lift::sleep()
{
	Serial.println("Putting lift to sleep.");
	stepperDriver.sleep();
}

void CasinoMortale::Lift::wake()
{
	Serial.println("Waking lift from sleep.");
	stepperDriver.wake();
}
