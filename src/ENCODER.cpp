/*
 Name:		ENCODER.cpp
 Created:	25/08/2019 13:04:56
 Author:	marco
 Editor:	http://www.visualmicro.com
*/

#include "ENCODER.h"

void MY_ENCODER::begin(int PIN_INCREMENTO, int PIN_DECREMENTO, int PIN_PULSANTE, funzione funIn, funzione funDec, funzione funPull = NULL, bool pullUpI = true , bool pullUpD = true, bool pullUpP = true, bool inversione = true)
{
	int stateOld = (inversione == false) ? 1 : 0;

	Incremento.pin = PIN_INCREMENTO;
	Incremento.oldState = stateOld;
	Incremento.PulUp = pullUpI;

	pinMode(Incremento.pin, (pullUpI == true) ? INPUT_PULLUP : INPUT);

	Decremento.pin = PIN_DECREMENTO;
	Decremento.oldState = stateOld;
	Decremento.PulUp = pullUpD;

	pinMode(Decremento.pin, (pullUpD == true) ? INPUT_PULLUP : INPUT);

	Pulsante.pin = PIN_PULSANTE;
	Pulsante.oldState = stateOld;
	Pulsante.PulUp = pullUpP;

	pinMode(Pulsante.pin, (pullUpP == true) ? INPUT_PULLUP : INPUT);

	fI = funIn;
	fD = funDec;
	fP = funPull;

	log_Invers = inversione;

}

void MY_ENCODER::controll_Encoder()
{
	int rotationIncr = digitalRead(Incremento.pin);

	if ((Incremento.oldState == (log_Invers == false) ? LOW : HIGH) && (rotationIncr == (log_Invers == false) ? HIGH : LOW)) {
		if (digitalRead(Decremento.pin) == (log_Invers == false) ? LOW : HIGH) fI();
		else fD();
	}

	Incremento.oldState = rotationIncr;
}

void MY_ENCODER::controll_Button()
{	
	if (fP == NULL) return 0;
	int btstate = digitalRead(Pulsante.pin);

	if ((Pulsante.oldState == (log_Invers == false) ? LOW : HIGH) && (btstate == (log_Invers == false) ? HIGH : LOW)) fP();
	Pulsante.oldState = btstate;
}