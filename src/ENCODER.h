/*
 Name:		ENCODER.h
 Created:	25/08/2019 13:04:56
 Author:	marco
 Editor:	http://www.visualmicro.com
*/

#ifndef _ENCODER_h
#define _ENCODER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

typedef void(*funzione)();

typedef struct {
	int pin;
	int oldState;
	bool PulUp;
} button;

class MY_ENCODER {
private:
	button Incremento;	//Pin di incremento
	button Decremento;	//Pin di decremento
	button Pulsante;	//Pin pulsante
	
	bool log_Invers;

	funzione fI;	//Funzione di incremento
	funzione fD;	//Funzione di decremento
	funzione fP;	//Funzione alla pressione del pulsante

public:
	void begin(int PIN_INCREMENTO, int PIN_DECREMENTO, int PIN_PULSANTE, funzione funIn, funzione funDec, funzione funPull = NULL, bool pullUpI = true , bool pullUpD = true, bool pullUpP = true, bool inversione = true);
	void controll_Encoder();
	void controll_Button();
};
#endif

