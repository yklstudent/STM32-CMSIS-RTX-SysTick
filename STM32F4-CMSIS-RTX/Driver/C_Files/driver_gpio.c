/****************************************Copyright (c)****************************************************
**                                    SSES/DGPS Co.,LTD.
**                                      
**                               https://cn.csisolar.com/
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               driver_gpio.c
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
#include "driver_gpio.h"

/* GPIO Peripheral clocks */
const uint32_t gpio_peripheral_clocks[] = 
{
    [eGPIOA] = RCC_AHB1ENR_GPIOAEN,
    [eGPIOB] = RCC_AHB1ENR_GPIOBEN,
    [eGPIOC] = RCC_AHB1ENR_GPIOCEN,
    [eGPIOD] = RCC_AHB1ENR_GPIODEN,
	[eGPIOE] = RCC_AHB1ENR_GPIOEEN,
	[eGPIOF] = RCC_AHB1ENR_GPIOFEN,
	[eGPIOG] = RCC_AHB1ENR_GPIOGEN,
    [eGPIOH] = RCC_AHB1ENR_GPIOHEN,
	[eGPIOI] = RCC_AHB1ENR_GPIOIEN,
#if defined(GPIOJ)
	[eGPIOJ] = RCC_AHB1ENR_GPIOJEN,
#endif
#if defined(GPIOK)
	[eGPIOK] = RCC_AHB1ENR_GPIOKEN,
#endif
};

const gpio_type gpio_handlers[eGPIOn] = 
{
    /*LED*/
    [eGPIO0]    			= {GPIOE, 2},
    [eGPIO1]    			= {GPIOE, 3},
    [eGPIO2]    			= {GPIOE, 4},
    [eGPIO3]    			= {GPIOE, 5},
    /*USART1*/
    [eUSART1Tx] 			= {GPIOA, 9},
    [eUSART1Rx] 			= {GPIOA, 10},
    /*USART2*/
    [eUSART2Tx] 			= {GPIOD, 5},
    [eUSART2Rx] 			= {GPIOD, 6},
    /*USART3*/
#if 0
    [eUSART3Tx] 			= {GPIOD, 8},
    [eUSART3Rx] 			= {GPIOD, 9},
#endif
#if 1
	[eUSART3Tx] 			= {GPIOB, 10},
    [eUSART3Rx] 			= {GPIOB, 11},
#endif
	/*USART4*/
    [eUSART4Tx] 			= {GPIOA, 0},
    [eUSART4Rx] 			= {GPIOA, 1},
    /*USART6*/
    [eUSART6Tx] 			= {GPIOC, 6},
    [eUSART6Rx] 			= {GPIOC, 7},
	/*eUSART1En*/
	[eUSART1En]				= {GPIOA, 8},
	/*eUSART2En*/
	[eUSART2En]				= {GPIOD, 7},
	/*eUSART3En*/
	[eUSART3En]				= {GPIOE, 15},
	/*eUSART4En*/
	[eUSART4En]				= {GPIOA, 2},
	/*eUSART6En*/
	[eUSART6En]				= {GPIOA, 12},
	/*SPI*/
#if 0
	[eFLASH_PIN_SPI_CS] 	= {GPIOB, 12},
	[eFLASH_PIN_SPI_CLK] 	= {GPIOB, 13},
	[eFLASH_PIN_SPI_MISO] 	= {GPIOB, 14},
	[eFLASH_PIN_SPI_MOSI] 	= {GPIOB, 15},
#endif
#if 1
	[eFLASH_PIN_SPI_CS] 	= {GPIOA, 4},
	[eFLASH_PIN_SPI_CLK] 	= {GPIOA, 5},
	[eFLASH_PIN_SPI_MISO] 	= {GPIOA, 6},
	[eFLASH_PIN_SPI_MOSI] 	= {GPIOA, 7},
#endif
};

const pin_config_type pin_config_handlers[eGPIOn] = 
{
    /*LED*/
    [eGPIO0] 				= {LL_GPIO_MODE_OUTPUT, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_UP, LL_GPIO_AF_0},
    [eGPIO1] 				= {LL_GPIO_MODE_OUTPUT, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_UP, LL_GPIO_AF_0},
    [eGPIO2] 				= {LL_GPIO_MODE_OUTPUT, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_UP, LL_GPIO_AF_0},
    [eGPIO3] 				= {LL_GPIO_MODE_OUTPUT, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_UP, LL_GPIO_AF_0},
    /*USART1*/
    [eUSART1Tx] 			= {LL_GPIO_MODE_ALTERNATE, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_UP, LL_GPIO_AF_7},
    [eUSART1Rx] 			= {LL_GPIO_MODE_ALTERNATE, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_UP, LL_GPIO_AF_7},
    /*USART2*/
    [eUSART2Tx] 			= {LL_GPIO_MODE_ALTERNATE, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_UP, LL_GPIO_AF_7},
    [eUSART2Rx] 			= {LL_GPIO_MODE_ALTERNATE, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_UP, LL_GPIO_AF_7},
    /*USART3*/
    [eUSART3Tx] 			= {LL_GPIO_MODE_ALTERNATE, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_UP, LL_GPIO_AF_7},
    [eUSART3Rx] 			= {LL_GPIO_MODE_ALTERNATE, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_UP, LL_GPIO_AF_7},
	/*USART4*/
    [eUSART4Tx] 			= {LL_GPIO_MODE_ALTERNATE, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_UP, LL_GPIO_AF_8},
    [eUSART4Rx] 			= {LL_GPIO_MODE_ALTERNATE, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_UP, LL_GPIO_AF_8},
    /*USART6*/
    [eUSART6Tx] 			= {LL_GPIO_MODE_ALTERNATE, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_UP, LL_GPIO_AF_8},
    [eUSART6Rx] 			= {LL_GPIO_MODE_ALTERNATE, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_UP, LL_GPIO_AF_8},
	/*eUSART1En*/
	[eUSART1En]				= {LL_GPIO_MODE_OUTPUT, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_UP, LL_GPIO_AF_0},
	/*eUSART2En*/
	[eUSART2En]				= {LL_GPIO_MODE_OUTPUT, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_UP, LL_GPIO_AF_0},
	/*eUSART3En*/
	[eUSART3En]				= {LL_GPIO_MODE_OUTPUT, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_UP, LL_GPIO_AF_0},
	/*eUSART4En*/
	[eUSART4En]				= {LL_GPIO_MODE_OUTPUT, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_UP, LL_GPIO_AF_0},
	/*eUSART6En*/
	[eUSART6En]				= {LL_GPIO_MODE_OUTPUT, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_UP, LL_GPIO_AF_0},
	/*SPI*/
#if 0
	[eFLASH_PIN_SPI_CS] 	= {LL_GPIO_MODE_OUTPUT, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_UP, LL_GPIO_AF_0},
    [eFLASH_PIN_SPI_CLK] 	= {LL_GPIO_MODE_ALTERNATE, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_NO, LL_GPIO_AF_5},
    [eFLASH_PIN_SPI_MISO] 	= {LL_GPIO_MODE_ALTERNATE, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_UP, LL_GPIO_AF_5},
    [eFLASH_PIN_SPI_MOSI] 	= {LL_GPIO_MODE_ALTERNATE, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_NO, LL_GPIO_AF_5},
#endif
#if 1
	[eFLASH_PIN_SPI_CS] 	= {LL_GPIO_MODE_OUTPUT, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_UP, LL_GPIO_AF_0},
    [eFLASH_PIN_SPI_CLK] 	= {LL_GPIO_MODE_ALTERNATE, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_NO, LL_GPIO_AF_5},
    [eFLASH_PIN_SPI_MISO] 	= {LL_GPIO_MODE_ALTERNATE, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_UP, LL_GPIO_AF_5},
    [eFLASH_PIN_SPI_MOSI] 	= {LL_GPIO_MODE_ALTERNATE, LL_GPIO_OUTPUT_PUSHPULL, LL_GPIO_SPEED_FREQ_VERY_HIGH, LL_GPIO_PULL_NO, LL_GPIO_AF_5},
#endif
};

static uint8_t gpio_get_port_number(GPIO_TypeDef *gpio_port)
{
    switch( (uint32_t)gpio_port )
    {
        case GPIOA_BASE:
            return eGPIOA;
        case GPIOB_BASE:
            return eGPIOB;
        case GPIOC_BASE:
            return eGPIOC;
        case GPIOD_BASE:
            return eGPIOD;
        case GPIOE_BASE:
            return eGPIOE;
		case GPIOF_BASE:
            return eGPIOF;
		case GPIOG_BASE:
            return eGPIOG;
		case GPIOH_BASE:
            return eGPIOH;
		case GPIOI_BASE:
            return eGPIOI;
#if defined(GPIOJ)
		case GPIOJ_BASE:
            return eGPIOJ;
#endif
#if defined(GPIOK)
		case GPIOK_BASE:
            return eGPIOK;
#endif
        default:
            return 0xFF;
    }
}

void gpio_init(const gpio_type *gpio, const pin_config_type config)
{
    LL_GPIO_InitTypeDef GPIO_InitStructure;
    uint8_t port_number = gpio_get_port_number(gpio->port);
    
    RCC->AHB1ENR |= gpio_peripheral_clocks[port_number];
    
    GPIO_InitStructure.Mode = config.mode;
	GPIO_InitStructure.OutputType = config.otype;
	GPIO_InitStructure.Speed = config.speed;
	GPIO_InitStructure.Pull = config.pupd;
	GPIO_InitStructure.Alternate = config.alter;
    GPIO_InitStructure.Pin = (uint32_t)(0x00000001UL << gpio->pin_number);
	
    LL_GPIO_Init(gpio->port, &GPIO_InitStructure);
}

void gpio_deinit(const gpio_type *gpio)
{
    LL_GPIO_InitTypeDef GPIO_InitStructure;
    
    /* Set to Input high-impedance */
    GPIO_InitStructure.Mode = LL_GPIO_MODE_INPUT;
	GPIO_InitStructure.OutputType = LL_GPIO_OUTPUT_OPENDRAIN;
	GPIO_InitStructure.Speed = LL_GPIO_SPEED_FREQ_LOW;
	GPIO_InitStructure.Pull = LL_GPIO_PULL_NO;
	GPIO_InitStructure.Alternate = LL_GPIO_AF_0;
	GPIO_InitStructure.Pin = LL_GPIO_PIN_ALL;

    LL_GPIO_Init( gpio->port, &GPIO_InitStructure );
}

void gpio_high(const gpio_type *gpio)
{
    //gpio->port->ODR |= (uint32_t)(0x00000001UL << gpio->pin_number);
	gpio->port->BSRR = (uint32_t)(0x00000001UL << gpio->pin_number);
}

void gpio_low(const gpio_type *gpio)
{
    //gpio->port->ODR &= ~(uint32_t)(0x00000001UL << (gpio->pin_number));
	gpio->port->BSRR = (uint32_t)(0x00010000UL << gpio->pin_number);
}

void gpio_trigger(const gpio_type *gpio)
{
    gpio->port->ODR ^= (uint32_t)(0x00000001UL << gpio->pin_number);
}

bool gpio_read(const gpio_type *gpio)
{
    bool result = false;
    
    result = ((gpio->port->IDR & (uint32_t)(0x00000001UL << gpio->pin_number)) != 0)?true:false;
    
    return result;
}

bool gpio_enable_clock(const gpio_type* gpio)
{
    uint8_t     port_number;

    /* Enable peripheral clock for this port */
    port_number = gpio_get_port_number( gpio->port );
    if(port_number == 0xFF)
    {
		return false;
    }

    RCC->AHB1ENR |= gpio_peripheral_clocks[port_number];
    
    return true;
}

void gpio_set_alternate_function(const gpio_type *gpio, const pin_config_type config)
{
    LL_GPIO_InitTypeDef  GPIO_InitStructure;
    uint8_t port_number = gpio_get_port_number(gpio->port);

    /* Enable peripheral clock for this port */
    RCC->AHB1ENR |= gpio_peripheral_clocks[port_number];

	GPIO_InitStructure.Pin = (0x00000001UL << gpio->pin_number);
    GPIO_InitStructure.Mode = config.mode;
	GPIO_InitStructure.OutputType = config.otype;
	GPIO_InitStructure.Speed = config.speed;
	GPIO_InitStructure.Pull = config.pupd;
	GPIO_InitStructure.Alternate = config.alter;
	
    LL_GPIO_Init(gpio->port, &GPIO_InitStructure);
}

void RCC_APB1PeriphClockCmd(uint32_t clock, FunctionalState state)
{
	if (state != DISABLE)
	{
		RCC->APB1ENR |= clock;
	}
	else
	{
		RCC->APB1ENR &= ~clock;
	}
}

void RCC_APB2PeriphClockCmd(uint32_t clock, FunctionalState state)
{
	if (state != DISABLE)
	{
		RCC->APB2ENR |= clock;
	}
	else
	{
		RCC->APB2ENR &= ~clock;
	}
}

void RCC_AHB1PeriphClockCmd(uint32_t clock, FunctionalState state)
{
	if (state != DISABLE)
	{
		RCC->AHB1ENR |= clock;
	}
	else
	{
		RCC->AHB1ENR &= ~clock;
	}
}

void RCC_AHB2PeriphClockCmd(uint32_t clock, FunctionalState state)
{
	if (state != DISABLE)
	{
		RCC->AHB2ENR |= clock;
	}
	else
	{
		RCC->AHB2ENR &= ~clock;
	}
}

void RCC_AHB3PeriphClockCmd(uint32_t clock, FunctionalState state)
{
	if (state != DISABLE)
	{
		RCC->AHB3ENR |= clock;
	}
	else
	{
		RCC->AHB3ENR &= ~clock;
	}
}

void RCC_APB1PeriphResetCmd(uint32_t clock, FunctionalState state)
{
    if (state != DISABLE)
	{
		RCC->APB1RSTR |= clock;
	}
	else
	{
		RCC->APB1RSTR &= ~clock;
	}
}

void RCC_APB2PeriphResetCmd(uint32_t clock, FunctionalState state)
{
    if (state != DISABLE)
	{
		RCC->APB2RSTR |= clock;
	}
	else
	{
		RCC->APB2RSTR &= ~clock;
	}
}

void RCC_AHB1PeriphResetCmd(uint32_t clock, FunctionalState state)
{
    if (state != DISABLE)
	{
		RCC->AHB1RSTR |= clock;
	}
	else
	{
		RCC->AHB1RSTR &= ~clock;
	}
}

void RCC_AHB2PeriphResetCmd(uint32_t clock, FunctionalState state)
{
    if (state != DISABLE)
	{
		RCC->AHB2RSTR |= clock;
	}
	else
	{
		RCC->AHB2RSTR &= ~clock;
	}
}

void RCC_AHB3PeriphResetCmd(uint32_t clock, FunctionalState state)
{
    if (state != DISABLE)
	{
		RCC->AHB3RSTR |= clock;
	}
	else
	{
		RCC->AHB3RSTR &= ~clock;
	}
}
