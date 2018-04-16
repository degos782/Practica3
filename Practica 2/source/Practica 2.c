/*
 * Copyright (c) 2017, NXP Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    Practica 2.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "funciones.h"
#include "fsl_gpio.h"
#include "fsl_clock.h"
#include "fsl_port.h"

/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */
int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();
    iniciar();
    T_UBYTE Modo;
    Modo= False;
    T_UBYTE ValorIncremento;
    ValorIncremento=False;
    T_UBYTE ValorDecremento;
    ValorDecremento=False;
    T_UBYTE Reinicio;
    Reinicio=False;

    T_BYTE ValorContadorUnidades;
    ValorContadorUnidades=False;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1)
    {
    //ChecarEntradaIncremento();
    //ChecarEntradaDecremento();
    //ChecarEntradaReinicio();
    	switch(Modo)
    	{
    	case Contador:
    	{
    	GPIO_WritePinOutput(GPIOB,LED_Red,False);
    	GPIO_WritePinOutput(GPIOB,LED_Green,False);
    	ValorIncremento=ChecarEntradaIncremento();
    	ValorDecremento=ChecarEntradaDecremento();
    	ValorContadorUnidades=ValorContadorUnidades+ValorIncremento-ValorDecremento;
    	if(ValorContadorUnidades<0 && ValorDecremento==1 )
    	{
    	ValorContadorUnidades=9;
    	}
    		else if (ValorContadorUnidades>9 && ValorIncremento==1)
    		{
    		ValorContadorUnidades=0;
    		}
    		else
    		{

    		}

    	if (ValorContadorUnidades==0)
    	{
    	Numero0();
    	}
    		else if (ValorContadorUnidades==1)
    		{
    		Numero1();
    		}
    		else if (ValorContadorUnidades==2)
    	    {
    	    Numero2();
    	    }
    		else if (ValorContadorUnidades==3)
    	    {
    	    Numero3();
    	    }
    		else if (ValorContadorUnidades==4)
    	    {
    	    Numero4();
    	    }
    		else if (ValorContadorUnidades==5)
    	    {
    	   	Numero5();
    	    }
    		else if (ValorContadorUnidades==6)
    	    {
    	    Numero6();
    	    }
    		else if (ValorContadorUnidades==7)
    	    {
    	    Numero7();
    	    }
    		else if (ValorContadorUnidades==8)
    	    {
    	    Numero8();
    	    }
    		else if (ValorContadorUnidades==9)
    		{
    		Numero9();
    		}
    		else
    		{

    		}
    	Reinicio=PulsacionReinicio();
    	Modo+=ChecarEntradaReinicio();
    	if(Reinicio==True)
    	{
    	ValorContadorUnidades=0;
    	Reinicio=False;
    	}
    		break;
    	}
    	case Timer:
    	{
    	GPIO_WritePinOutput(GPIOB,LED_Green,True);
    	GPIO_WritePinOutput(GPIOB,LED_Red,False);
    	GPIO_WritePinOutput(GPIOD,LED_Blue,False);
    	Modo+=ChecarEntradaReinicio();
    	break;
    	}
    	case ADC:
    	{
    	GPIO_WritePinOutput(GPIOB,LED_Red,True);
    	GPIO_WritePinOutput(GPIOD,LED_Blue,False);
    	GPIO_WritePinOutput(GPIOB,LED_Green,False);
    	Modo+=ChecarEntradaReinicio();
    		if (Modo>2)
    		{
    		Modo=Contador;
    		}
    	break;
    	}
    	}
    }
    return 0 ;
}
