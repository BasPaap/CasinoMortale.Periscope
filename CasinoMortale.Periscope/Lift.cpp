#include "Lift.h"

CasinoMortale::Lift::Lift(int directionPin, int stepPin, int stepsPerRevolution = 200, int numMicrostepsPerStep = 1) : directionPin{ directionPin }, stepPin { stepPin }, stepsPerRevolution { stepsPerRevolution }, numMicrostepsPerStep { numMicrostepsPerStep }
{
}

void CasinoMortale::Lift::initialize()
{
}
