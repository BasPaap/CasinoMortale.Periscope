/*
 Name:		CasinoMortale.ino
 Created:	12/21/2021 8:31:21 PM
 Author:	Bas Paap
*/

#include <Servo.h>
#include "Swivel.h"
#include "Lift.h"

const int directionPin = 2;
const int stepPin = 3;
const int sleepPin = 4;
const int servoPin = 5;
const float swivelSpeed = 90.0f;
const int leftPosition = 0;
const int rightPosition = 180;
const int centerPosition = 90;

CasinoMortale::Swivel swivel { servoPin };
CasinoMortale::Lift lift { directionPin, stepPin, sleepPin };

void setup() {
	Serial.begin(9600);
	
	swivel.initialize();
	lift.initialize();
}

void loop() {
	lift.wake();
	lift.moveUp();
	/*swivel.turn(leftPosition, swivelSpeed);
	swivel.turn(rightPosition, swivelSpeed);
	swivel.turn(centerPosition, swivelSpeed);*/
	
	delay(2000);

	lift.moveDown();
	lift.sleep();

	delay(10000);
}
