#include "Swivel.h"

CasinoMortale::Swivel::Swivel(int pin) : servoPin(pin)
{
}

void CasinoMortale::Swivel::initialize()
{
	Serial.print("Initializing Swivel on pin");
	Serial.print(servoPin);
	Serial.println(".");

	servo.attach(servoPin, minPulseWidth, maxPulseWidth);
	servo.write(90);	
}

void CasinoMortale::Swivel::turn(int destinationPosition, float speed)
{
	Serial.print("Swivelling to ");
	Serial.print(destinationPosition);
	Serial.print(" degrees at ");
	Serial.print(speed);
	Serial.println(" degrees per second.");

	
}

