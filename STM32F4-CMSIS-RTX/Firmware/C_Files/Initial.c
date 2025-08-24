/****************************************Copyright (c)****************************************************
**                                    SSES/DGPS Co.,LTD.
**                                      
**                               https://cn.csisolar.com/
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               Initial.c
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
#include "Initial.h"
#include "driver_gpio.h"

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 168000000
  *            HCLK(Hz)                       = 168000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 2
  *            APB2 Prescaler                 = 1
  *            HSE Frequency(Hz)              = 24000000
  *            HSE PREDIV1                    = 1
  *            PLLMUL                         = 9
  *            Flash Latency(WS)              = 2
  * @param  None
  * @retval None
  */
void SystemClock_Config(void)
{
	LL_FLASH_SetLatency(LL_FLASH_LATENCY_5);
	while(LL_FLASH_GetLatency()!= LL_FLASH_LATENCY_5)
	{
	}
	LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE1);
	LL_RCC_HSE_Enable();
	
	/* Wait till HSE is ready */
	while(LL_RCC_HSE_IsReady() != 1)
	{
	}
	LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE, LL_RCC_PLLM_DIV_24, 336, LL_RCC_PLLP_DIV_2);
	LL_RCC_PLL_ConfigDomain_48M(LL_RCC_PLLSOURCE_HSE, LL_RCC_PLLM_DIV_24, 336, LL_RCC_PLLQ_DIV_7);
	LL_RCC_PLL_Enable();
	
	/* Wait till PLL is ready */
	while(LL_RCC_PLL_IsReady() != 1)
	{
	}
	LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
	LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_4);
	LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_2);
	LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);
	
	/* Wait till System clock is ready */
	while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
	{
	}
	
	LL_SetSystemCoreClock(168000000);
}

static void sRCC_Configuration(void)
{
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
    /* Enable PWR clock */
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);
	/* Enable GPIOA clock */
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
	/* Enable GPIOB clock */
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
	/* Enable GPIOC clock */
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
	/* Enable GPIOD clock */
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD);
	/* Enable GPIOE clock */
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOE);
	/* Enable GPIOF clock */
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOF);
	/* Enable GPIOG clock */
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOG);
	/* Enable GPIOH clock */
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOH);
	/* Enable GPIOI clock */
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOI);
#if defined(GPIOJ)
	/* Enable GPIOJ clock */
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOJ);
#endif
#if defined(GPIOK)
	/* Enable GPIOK clock */
	LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOK);
#endif
}

static void sGPIO_Configuration(void)
{
	gpio_init(&gpio_handlers[eGPIO0], pin_config_handlers[eGPIO0]);
	gpio_init(&gpio_handlers[eGPIO1], pin_config_handlers[eGPIO1]);
	gpio_init(&gpio_handlers[eGPIO2], pin_config_handlers[eGPIO2]);
	gpio_init(&gpio_handlers[eGPIO3], pin_config_handlers[eGPIO3]);
}

static void sNVIC_Configuration(void)
{
    /* NVIC configuration */
    /* Configure the Priority Group to 4 bits */
    NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

    LL_RCC_ClocksTypeDef rcc_clocks;
    LL_RCC_GetSystemClocksFreq(&rcc_clocks);
}

/**
  * Override default HAL_GetTick function
  */
uint32_t HAL_GetTick (void) {
	static uint32_t ticks = 0U;
           uint32_t i;
	
	if (osKernelGetState () == osKernelRunning) {
		return ((uint32_t)osKernelGetTickCount ());
	}
	
	/* If Kernel is not running wait approximately 1 ms then increment 
		and return auxiliary tick counter value */
	for (i = (SystemCoreClock >> 14U); i > 0U; i--) {
		__NOP(); __NOP(); __NOP(); __NOP(); __NOP(); __NOP();
		__NOP(); __NOP(); __NOP(); __NOP(); __NOP(); __NOP();
	}
	
	return ++ticks;
}

void sInitMCU(void)
{
    sRCC_Configuration();
    sGPIO_Configuration();
    sNVIC_Configuration();
}
