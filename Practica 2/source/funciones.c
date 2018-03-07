/*
 * funciones.c
 *
 *  Created on: Feb 28, 2018
 *      Author: Diego Romo C
 */
#include "funciones.h"



int LonguitudPulso(puertodelectura,pindelectura)
{
T_UBYTE Pulso;
Pulso = 0u;
T_ULONG Debounce;
Debounce =False;
T_UBYTE EstadoPin;
EstadoPin=False;

	while(EstadoPin == False)  //se evalua el valor del pin considerando entradas pull up
	{
		if(Debounce == 30000)
		{
		Pulso=Corto;
		}
		if(Debounce == 150000)
		{
		Pulso=Largo;
		break;
		}
	Debounce+=True;
	EstadoPin = GPIO_ReadPinInput(puertodelectura,pindelectura);
	}
return Pulso;
}
