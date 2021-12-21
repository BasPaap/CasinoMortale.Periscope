#include "Swivel.h"

void CasinoMortale::Swivel::initialize()
{
	Serial.print("Initializing Swivel on pin");
	Serial.print(servoPin);
	Serial.println(".");

	servo.attach(servoPin, minPulseWidth, maxPulseWidth);
	servo.write((int)currentServoPosition);
	lastUpdateTime = millis();
}

CasinoMortale::Swivel::Swivel(int pin) : servoPin(pin)
{
}

void CasinoMortale::Swivel::update()
{
	updateServo();
	lastUpdateTime = millis();
}

void CasinoMortale::Swivel::updateServo()
{
	if (currentServoPosition != destinationServoPosition)
	{
		float timeDelta = (millis() - lastUpdateTime) / 1000.0f;
		float incrementAmount = speed * timeDelta;

		if (currentServoPosition < destinationServoPosition)
		{
			currentServoPosition += incrementAmount;
		}
		else if (currentServoPosition > destinationServoPosition)
		{
			currentServoPosition -= incrementAmount;
		}

		if (abs(currentServoPosition - destinationServoPosition) < 1.0f)
		{
			currentServoPosition = destinationServoPosition;
		}

		servo.write((int)currentServoPosition);
	}
}