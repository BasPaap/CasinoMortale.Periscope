/*
 Name:		CasinoMortale.ino
 Created:	12/21/2021 8:31:21 PM
 Author:	Bas Paap
*/

#include <LowPower.h>
#include <Servo.h>
#include "Swivel.h"
#include "Lift.h"

const int directionPin = 2;
const int stepPin = 3;
const int sleepPin = 4;
const int servoPin = 5;
const int endStopTopPin = 6;
const int endStopBottomPin = 7;
const int enableStepperDriverPin = 8;
const int statusLedPin = 9;
const float swivelSpeed = 45.0f;
const int leftPosition = 0;
const int rightPosition = 180;
const int centerPosition = 90;
const int numSecondsToSleep = 60;
const int statusLedDelay = 100;

CasinoMortale::Swivel swivel { servoPin };
CasinoMortale::Lift lift { directionPin, stepPin, sleepPin, enableStepperDriverPin, endStopTopPin, endStopBottomPin };

void setup() {
	// Disable stepper driver as soon as possible.
	pinMode(enableStepperDriverPin, OUTPUT);
	digitalWrite(enableStepperDriverPin, HIGH);

	// Set up status LED
	pinMode(statusLedPin, OUTPUT);
	digitalWrite(statusLedPin, LOW);

	Serial.begin(9600);
	
	swivel.initialize();
	lift.initialize();
}

void loop() {
	Serial.println("Starting sequence.");
	lift.wake();
	lift.moveUp();
	delay(2000);

	swivel.turn(leftPosition, swivelSpeed);
	delay(2000);
	swivel.turn(rightPosition, swivelSpeed);
	delay(2000);
	swivel.turn(centerPosition, swivelSpeed);	
	delay(2000);

	lift.moveDown();
	lift.sleep();

	Serial.println("Sequence finished.");
	sleep();
}

void sleep()
{
	Serial.print("Going to sleep for approximately ");
	Serial.print(numSecondsToSleep);
	Serial.println(" seconds.");
	delay(500);

	for (size_t i = 0; i < numSecondsToSleep / 8; i++)
	{
		digitalWrite(statusLedPin, HIGH);
		delay(statusLedDelay);
		digitalWrite(statusLedPin, LOW);
		LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
	}	

	Serial.println("Awoke!");	
}

