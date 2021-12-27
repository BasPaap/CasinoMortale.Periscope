/*
 Name:		CasinoMortale.ino
 Created:	12/21/2021 8:31:21 PM
 Author:	Bas Paap
*/

#include <Servo.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include "Swivel.h"
#include "Lift.h"

const int directionPin = 2;
const int stepPin = 3;
const int sleepPin = 4;
const int servoPin = 5;
const int endStopTopPin = 6;
const int endStopBottomPin = 7;
const int enableStepperDriverPin = 8;
const float swivelSpeed = 45.0f;
const int leftPosition = 0;
const int rightPosition = 180;
const int centerPosition = 90;

CasinoMortale::Swivel swivel { servoPin };
CasinoMortale::Lift lift { directionPin, stepPin, sleepPin, enableStepperDriverPin, endStopTopPin, endStopBottomPin };

void setup() {
	// Disable stepper driver as soon as possible.
	pinMode(enableStepperDriverPin, OUTPUT);
	digitalWrite(enableStepperDriverPin, HIGH);

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
	Serial.println("Going to sleep.");
	delay(500);
	// allow changes, disable reset
	WDTCSR = bit(WDCE) | bit(WDE);
	// set interrupt mode and an interval 
	WDTCSR = bit(WDIE) | bit(WDP3) | bit(WDP0);    // set WDIE, and 8 seconds delay
	wdt_reset();  // pat the dog

	sleep_enable();
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	sleep_cpu();

	Serial.println("Woke up from sleep.");
	sleep_disable();
}

ISR(WDT_vect)
{
	wdt_disable();
}
