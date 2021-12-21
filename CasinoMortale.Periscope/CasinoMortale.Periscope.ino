/*
 Name:		CasinoMortale.ino
 Created:	12/21/2021 8:31:21 PM
 Author:	Bas Paap
*/

#include <Servo.h>
#include "Swivel.h"
#include "Lift.h"

const int servoPin = 5;

CasinoMortale::Swivel swivel { servoPin };
CasinoMortale::Lift lift;

void setup() {
	Serial.begin(9600);
	
	swivel.initialize();
	lift.initialize();
}

void loop() {
  
}
