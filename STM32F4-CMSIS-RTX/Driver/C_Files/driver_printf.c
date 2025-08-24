/****************************************Copyright (c)****************************************************
**                                    SSES/DGPS Co.,LTD.
**                                      
**                               https://cn.csisolar.com/
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               driver_printf.c
** Latest modified Date:    2022-xx-xx
** Latest Version:          0.0
** Descriptions:            
**
**--------------------------------------------------------------------------------------------------------
** Created by:              kl.yao
** Created date:            2022-xx-xx
** Version:                 0.0
** Descriptions:            The original version
**
**--------------------------------------------------------------------------------------------------------
** Modified by:             
** Modified date:           
** Version:                 
** Descriptions:            
**
*********************************************************************************************************/
#include "driver_printf.h"

void sPRINTF_Configuration(void)
{
	LL_GPIO_InitTypeDef GPIO_InitStructure = {0};
	LL_USART_InitTypeDef USART_InitStructure = {0};
	
	/* Enable GPIO clock */
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);

	/* Enable USART clock */
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_USART1);
  
	/* Configure USART Tx as alternate function push-pull */
	/* Configure USART Rx as alternate function push-pull */
	GPIO_InitStructure.Pin = LL_GPIO_PIN_9 | LL_GPIO_PIN_10;
	GPIO_InitStructure.Mode = LL_GPIO_MODE_ALTERNATE;
	GPIO_InitStructure.Speed = LL_GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStructure.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
	GPIO_InitStructure.Pull = LL_GPIO_PULL_UP;
	GPIO_InitStructure.Alternate = LL_GPIO_AF_7;
	LL_GPIO_Init(GPIOA, &GPIO_InitStructure);
    
	USART_InitStructure.BaudRate = 115200;
	USART_InitStructure.DataWidth = LL_USART_DATAWIDTH_8B;
	USART_InitStructure.StopBits = LL_USART_STOPBITS_1;
	USART_InitStructure.Parity = LL_USART_PARITY_NONE;
	USART_InitStructure.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
	USART_InitStructure.TransferDirection = LL_USART_DIRECTION_TX_RX;
	USART_InitStructure.OverSampling = LL_USART_OVERSAMPLING_16;
	
	/* USART configuration */
	LL_USART_Init(USART1, &USART_InitStructure);
	
    LL_USART_ConfigAsyncMode(USART1);
	
	/* Enable USART */
	LL_USART_Enable(USART1);
}

#if defined ( __CC_ARM ) || (defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
#if defined ( __CC_ARM )
#pragma import(__use_no_semihosting_swi)

struct __FILE
{
	int handler;
};
#endif
FILE __stdout;
FILE __stdin;
FILE __stderr;

int fputc(int c, FILE *stream)
{
	//Standard output or error output?
	if(stream == stdout || stream == stderr)
	{
		//Character to be written
		LL_USART_TransmitData8(USART1, (uint8_t) c);
		
		//Transmit data
		while (!LL_USART_IsActiveFlag_TXE(USART1))
		{}
		
		//On success, the character written us returned
		return c;
	}
	//Unknown output?
	else
	{
		//If a writting error occurs, EOF is returned
		return EOF;
	}
}

/*
int fput(int c, FILE *stream)
{
	return c;
}
*/

int fgetc(FILE *stream)
{
	return EOF;
}

int ferror(FILE *stream)
{
	return EOF;
}

void _ttywrch(int c)
{
	fputc(c, stdout);
}

void _sys_exit(int code)
{
	while(1);
}
#endif
