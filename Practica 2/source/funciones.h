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
#define Incremento_Boton ((uint32_t)0u)
#define Decremento_Boton ((uint32_t)1u)
#define Reinicio_Boton ((uint32_t)2u)
#define LED_Green ((uint32_t)19u)
#define LED_Red ((uint32_t)18u)
#define LED_Blue ((uint32_t)1u)
#define LED_A ((uint32_t)7u)
#define LED_B ((uint32_t)0u)
#define LED_C ((uint32_t)3u)
#define LED_D ((uint32_t)4u)
#define LED_E ((uint32_t)5u)
#define LED_F ((uint32_t)6u)
#define LED_G ((uint32_t)10u)
#define False ((T_UBYTE)0u)
#define True  ((T_UBYTE)1u)
#define Corto ((T_UBYTE)0u)
#define Largo ((T_UBYTE)1u)

int LonguitudPulso();
void iniciar(void);
void delay(void);

#endif /* FUNCIONES_H_ */
