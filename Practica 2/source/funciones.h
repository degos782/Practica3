/*
 * funciones.h
 *
 *  Created on: Feb 28, 2018
 *      Author: Diego Romo C
 */


#ifndef FUNCIONES_H_
#define FUNCIONES_H_
typedef unsigned char  T_UBYTE;
typedef unsigned short T_UWORD;
typedef unsigned int   T_ULONG;
#include "fsl_gpio.h"
#define False ((T_UBYTE)0u)
#define True  ((T_UBYTE)1u)
#define Corto ((T_UBYTE)0u)
#define Largo ((T_UBYTE)1u)

int LonguitudPulso();



#endif /* FUNCIONES_H_ */
