#include "Lift.h"

CasinoMortale::Lift::Lift(int directionPin, int stepPin, int sleepPin) : directionPin { directionPin }, stepPin { stepPin }, sleepPin { sleepPin }
{
}

void CasinoMortale::Lift::initialize()
{
}

void CasinoMortale::Lift::moveUp()
{
}

void CasinoMortale::Lift::moveDown()
{
}

void CasinoMortale::Lift::sleep()
{
	digitalWrite(sleepPin, LOW);
}

void CasinoMortale::Lift::wake()
{
	digitalWrite(sleepPin, HIGH);
}
