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

	servo.write(destinationPosition);

	delay(2000);


	//unsigned long startTime = millis();
	//float currentPosition = 0;// servo.read();
	//
	//while (currentPosition != destinationPosition)
	//{
	//	float timeDelta = (millis() - startTime) / 1000.0f;
	//	float incrementValue = (currentPosition > destinationPosition ? -1 : 1) * speed * timeDelta;
	//	currentPosition += incrementValue;
	//	servo.write((int)currentPosition);		
	//	startTime = millis();
	//}
}

