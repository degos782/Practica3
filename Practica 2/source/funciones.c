/*
 * funciones.c
 *
 *  Created on: Feb 28, 2018
 *      Author: Diego Romo C
 */
#include "funciones.h"
#include "fsl_gpio.h"
#include "fsl_clock.h"
#include "fsl_port.h"
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
		if(Debounce <500)
		{
		Pulso=TiempoDebounce;
		}
		else if(Debounce == 1000)
		{
		Pulso=Corto;

		}
		else if(Debounce > 300000)
		{
		Pulso=Largo;

		}
	Debounce+=True;
	EstadoPin = GPIO_ReadPinInput(puertodelectura,pindelectura);
	}
return Pulso;
}
void iniciar(void)
{
	//iniciar reloj de puertos
	CLOCK_EnableClock(kCLOCK_PortB);
	CLOCK_EnableClock(kCLOCK_PortC);
	CLOCK_EnableClock(kCLOCK_PortD);
	//inicializar pines de entrada
	port_pin_config_t ls_BotonEntrada;
	ls_BotonEntrada.mux = kPORT_MuxAsGpio;
	ls_BotonEntrada.pullSelect = kPORT_PullUp;
	PORT_SetPinConfig(PORTB,Incremento_Boton,&ls_BotonEntrada);
	PORT_SetPinConfig(PORTB,Decremento_Boton,&ls_BotonEntrada);
	PORT_SetPinConfig(PORTB,Reinicio_Boton,&ls_BotonEntrada);
	gpio_pin_config_t ls_BotonEntradaConfig;
	ls_BotonEntradaConfig.pinDirection = kGPIO_DigitalInput;
	GPIO_PinInit(GPIOB,Incremento_Boton,&ls_BotonEntradaConfig);
	GPIO_PinInit(GPIOB,Decremento_Boton,&ls_BotonEntradaConfig);
	GPIO_PinInit(GPIOB,Reinicio_Boton,&ls_BotonEntradaConfig);
	//inicializar pines de salida
	port_pin_config_t ls_LEDSalida;
	ls_LEDSalida.mux = kPORT_MuxAsGpio;
	PORT_SetPinConfig(PORTB,LED_Red,&ls_LEDSalida);
	PORT_SetPinConfig(PORTB,LED_Green,&ls_LEDSalida);
	PORT_SetPinConfig(PORTD,LED_Blue,&ls_LEDSalida);
	PORT_SetPinConfig(PORTC,LED_A,&ls_LEDSalida);
	PORT_SetPinConfig(PORTC,LED_B,&ls_LEDSalida);
	PORT_SetPinConfig(PORTC,LED_C,&ls_LEDSalida);
	PORT_SetPinConfig(PORTC,LED_D,&ls_LEDSalida);
	PORT_SetPinConfig(PORTC,LED_E,&ls_LEDSalida);
	PORT_SetPinConfig(PORTC,LED_F,&ls_LEDSalida);
	PORT_SetPinConfig(PORTC,LED_G,&ls_LEDSalida);
	gpio_pin_config_t ls_LEDSalidaConfig,ls_LEDSegmentos;
	ls_LEDSalidaConfig.pinDirection = kGPIO_DigitalOutput;
	ls_LEDSalidaConfig.outputLogic = True;
	ls_LEDSegmentos.pinDirection = kGPIO_DigitalOutput;
	ls_LEDSegmentos.outputLogic = False;
	GPIO_PinInit(GPIOB,LED_Red,&ls_LEDSalidaConfig);
	GPIO_PinInit(GPIOB,LED_Green,&ls_LEDSalidaConfig);
	GPIO_PinInit(GPIOD,LED_Blue,&ls_LEDSalidaConfig);
	GPIO_PinInit(GPIOC,LED_A,&ls_LEDSegmentos);
	GPIO_PinInit(GPIOC,LED_B,&ls_LEDSegmentos);
	GPIO_PinInit(GPIOC,LED_C,&ls_LEDSegmentos);
	GPIO_PinInit(GPIOC,LED_D,&ls_LEDSegmentos);
	GPIO_PinInit(GPIOC,LED_E,&ls_LEDSegmentos);
	GPIO_PinInit(GPIOC,LED_F,&ls_LEDSegmentos);
	GPIO_PinInit(GPIOC,LED_G,&ls_LEDSegmentos);
	return;
}
void delay(void)
{
int i;
	for(i=0;i<=399999;i++)
	{}
}
void ChecarEntradaIncremento(void)
{
T_UBYTE valorpulso;
T_UBYTE BotonIncremento;
BotonIncremento=False;
valorpulso=False;
BotonIncremento=GPIO_ReadPinInput(GPIOB,Incremento_Boton);
	if(BotonIncremento==False)
	{
	valorpulso=LonguitudPulso(GPIOB,Incremento_Boton);
		if(valorpulso==Largo)
	    {
	    GPIO_WritePinOutput(GPIOB,LED_Red,False);
	    delay();
	    GPIO_WritePinOutput(GPIOB,LED_Red,True);
	    }
	    else if(valorpulso==Corto)
	    {
	    GPIO_WritePinOutput(GPIOB,LED_Green,False);
	    delay();
	    GPIO_WritePinOutput(GPIOB,LED_Green,True);
	    }
	 }
	 else
	 {

	 }
return;
}
void ChecarEntradaDecremento(void)
{
T_UBYTE valorpulso;
T_UBYTE BotonDecremento;
BotonDecremento=False;
valorpulso=False;
BotonDecremento=GPIO_ReadPinInput(GPIOB,Decremento_Boton);
	if(BotonDecremento==False)
	{
	valorpulso=LonguitudPulso(GPIOB,Decremento_Boton);
		if(valorpulso==Largo)
	    {
	    GPIO_WritePinOutput(GPIOB,LED_Red,False);
	    delay();
	    GPIO_WritePinOutput(GPIOB,LED_Red,True);
	    }
	    else if(valorpulso==Corto)
	    {
	    GPIO_WritePinOutput(GPIOB,LED_Green,False);
	    delay();
	    GPIO_WritePinOutput(GPIOB,LED_Green,True);
	    }
	 }
	 else
	 {

	 }
return;
}
int ChecarEntradaReinicio(void)
{
T_UBYTE valorpulso;
T_UBYTE BotonReinicio;
T_UBYTE CambioModo;
BotonReinicio=False;
valorpulso=False;
CambioModo=False;
BotonReinicio=GPIO_ReadPinInput(GPIOB,Reinicio_Boton);
	if(BotonReinicio==False)
	{
	valorpulso=LonguitudPulso(GPIOB,Reinicio_Boton);
		if(valorpulso==Largo)
	    {
	    GPIO_WritePinOutput(GPIOB,LED_Red,False);
	    delay();
	    GPIO_WritePinOutput(GPIOB,LED_Red,True);
	    CambioModo=True;
	    }
	    else if(valorpulso==Corto)
	    {
	    GPIO_WritePinOutput(GPIOB,LED_Green,False);
	    delay();
	    GPIO_WritePinOutput(GPIOB,LED_Green,True);
	    CambioModo=False;
	    }
	 }
	 else
	 {

	 }
return CambioModo;
}
void Numero0(void)
{
	GPIO_WritePinOutput(GPIOC,LED_A,False);
	GPIO_WritePinOutput(GPIOC,LED_B,False);
	GPIO_WritePinOutput(GPIOC,LED_C,False);
	GPIO_WritePinOutput(GPIOC,LED_D,False);
	GPIO_WritePinOutput(GPIOC,LED_E,False);
	GPIO_WritePinOutput(GPIOC,LED_F,False);
	GPIO_WritePinOutput(GPIOC,LED_G,True);
return;
}
void Numero1(void)
{
	GPIO_WritePinOutput(GPIOC,LED_A,True);
	GPIO_WritePinOutput(GPIOC,LED_B,False);
	GPIO_WritePinOutput(GPIOC,LED_C,False);
	GPIO_WritePinOutput(GPIOC,LED_D,True);
	GPIO_WritePinOutput(GPIOC,LED_E,True);
	GPIO_WritePinOutput(GPIOC,LED_F,True);
	GPIO_WritePinOutput(GPIOC,LED_G,True);
return;
}
void Numero2(void)
{
	GPIO_WritePinOutput(GPIOC,LED_A,False);
	GPIO_WritePinOutput(GPIOC,LED_B,False);
	GPIO_WritePinOutput(GPIOC,LED_C,True);
	GPIO_WritePinOutput(GPIOC,LED_D,False);
	GPIO_WritePinOutput(GPIOC,LED_E,False);
	GPIO_WritePinOutput(GPIOC,LED_F,True);
	GPIO_WritePinOutput(GPIOC,LED_G,False);
return;
}
