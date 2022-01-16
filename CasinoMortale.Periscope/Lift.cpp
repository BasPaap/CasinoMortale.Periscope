#include "Lift.h"

CasinoMortale::Lift::Lift(int directionPin, int stepPin, int sleepPin, int enablePin, int endStopTopPin, int endStopBottomPin) : stepperDriver{ directionPin, stepPin, sleepPin, enablePin, endStopTopPin, endStopBottomPin }
{
}

void CasinoMortale::Lift::initialize()
{
	Serial.println("Initializing lift.");
	stepperDriver.initialize();
	stepperDriver.moveToHomePosition();
	stepperDriver.sleep();
}

void CasinoMortale::Lift::moveUp()
{
	Serial.println("Moving lift up.");
	stepperDriver.move(5000, true, 1);
}

void CasinoMortale::Lift::moveDown()
{
	Serial.println("Moving lift down.");
	stepperDriver.move(5000, false, 1);
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
