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
	currentPosition = servo.read();
}

void CasinoMortale::Swivel::turn(float destinationPosition, float speed)
{
	Serial.print("Swivelling to ");
	Serial.print(destinationPosition);
	Serial.print(" degrees at ");
	Serial.print(speed);
	Serial.println(" degrees per second.");

	long lastTime = millis();
	currentPosition = servo.read();

	while (currentPosition != destinationPosition)
	{
		if (millis() > lastTime)
		{
			float timeDelta = (millis() - lastTime) / 1000.0f;
			currentPosition += timeDelta * speed * (currentPosition > destinationPosition ? -1 : 1);
			
			if (abs(currentPosition - destinationPosition) < 1.0f)
			{
				currentPosition = destinationPosition;
			}

			servo.write(currentPosition);
			lastTime = millis();
		}
	}

	Serial.print("Servo has reached destination position of ");
	Serial.print(destinationPosition);
	Serial.println(" degrees.");
}

