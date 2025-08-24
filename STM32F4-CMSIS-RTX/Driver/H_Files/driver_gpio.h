#ifndef _DRIVER_GPIO_H_
#define _DRIVER_GPIO_H_

#include "main.h"

typedef enum
{
	eGPIOA = 0,
	eGPIOB,
	eGPIOC,
	eGPIOD,
	eGPIOE,
	eGPIOF,
	eGPIOG,
	eGPIOH,
	eGPIOI,
#if defined(GPIOJ)
	eGPIOJ,
#endif
#if defined(GPIOK)
	eGPIOK,
#endif
	eGPIOx,
}mico_gpio_port;

typedef enum
{
    /*LED*/
    eGPIO0      		= 0,
    eGPIO1,
    eGPIO2,
    eGPIO3,
    /*USART1*/
    eUSART1Tx,
    eUSART1Rx,
    /*USART2*/
    eUSART2Tx,
    eUSART2Rx,
    /*USART3*/
    eUSART3Tx,
    eUSART3Rx,
	/*USART4*/
    eUSART4Tx,
    eUSART4Rx,
    /*USART6*/
    eUSART6Tx,
    eUSART6Rx,
	/*eUSART1En*/
    eUSART1En,
	/*eUSART2En*/
	eUSART2En,
	/*eUSART3En*/
	eUSART3En,
	/*eUSART4En*/
	eUSART4En,
	/*eUSART6En*/
	eUSART6En,
	/*SPI*/
	eFLASH_PIN_SPI_CS,
    eFLASH_PIN_SPI_CLK,
	eFLASH_PIN_SPI_MISO,
    eFLASH_PIN_SPI_MOSI,
	/*Reserved*/
    eGPIOn,
}mico_gpio_type;

typedef enum
{
    INPUT_PULL_UP,             /* Input with an internal pull-up resistor - use with devices that actively drive the signal low - e.g. button connected to ground */
    INPUT_PULL_DOWN,           /* Input with an internal pull-down resistor - use with devices that actively drive the signal high - e.g. button connected to a power rail */
    INPUT_HIGH_IMPEDANCE,      /* Input - must always be driven, either actively or by an external pullup resistor */
    OUTPUT_PUSH_PULL,          /* Output actively driven high and actively driven low - must not be connected to other active outputs - e.g. LED output */
    OUTPUT_OPEN_DRAIN_NO_PULL, /* Output actively driven low but is high-impedance when set high - can be connected to other open-drain/open-collector outputs. Needs an external pull-up resistor */
    OUTPUT_OPEN_DRAIN_PULL_UP, /* Output actively driven low and is pulled high with an internal resistor when set high - can be connected to other open-drain/open-collector outputs. */ 
}pin_config_t;

typedef struct
{
    GPIO_TypeDef *port;
    uint32_t pin_number;
}gpio_type;

typedef struct
{
    uint32_t mode;
    uint32_t otype;
    uint32_t speed;
    uint32_t pupd;
	uint32_t alter;
}pin_config_type;

extern const gpio_type gpio_pins[];
extern const gpio_type gpio_handlers[];
extern const pin_config_type pin_config_handlers[];

extern void gpio_init(const gpio_type *gpio, const pin_config_type config);
extern void gpio_deinit(const gpio_type *gpio);
extern void gpio_high(const gpio_type *gpio);
extern void gpio_low(const gpio_type *gpio);
extern void gpio_trigger(const gpio_type *gpio);
extern bool gpio_read(const gpio_type *gpio);
extern bool gpio_enable_clock(const gpio_type* gpio);
extern void gpio_set_alternate_function(const gpio_type *gpio, const pin_config_type config);

extern void RCC_APB1PeriphClockCmd(uint32_t clock, FunctionalState state);
extern void RCC_APB2PeriphClockCmd(uint32_t clock, FunctionalState state);
extern void RCC_AHB1PeriphClockCmd(uint32_t clock, FunctionalState state);
extern void RCC_AHB2PeriphClockCmd(uint32_t clock, FunctionalState state);
extern void RCC_AHB3PeriphClockCmd(uint32_t clock, FunctionalState state);

extern void RCC_APB1PeriphResetCmd(uint32_t clock, FunctionalState state);
extern void RCC_APB2PeriphResetCmd(uint32_t clock, FunctionalState state);
extern void RCC_AHB1PeriphResetCmd(uint32_t clock, FunctionalState state);
extern void RCC_AHB2PeriphResetCmd(uint32_t clock, FunctionalState state);
extern void RCC_AHB3PeriphResetCmd(uint32_t clock, FunctionalState state);

#endif
