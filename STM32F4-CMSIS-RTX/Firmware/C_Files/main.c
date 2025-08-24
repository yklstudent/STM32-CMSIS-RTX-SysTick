/****************************************Copyright (c)****************************************************
**                                    SSES/DGPS Co.,LTD.
**                                      
**                               https://cn.csisolar.com/
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               mian.c
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
#include "main.h"
#include "driver_data.h"
#include "driver_gpio.h"
#include "driver_iwdg.h"
#include "driver_printf.h"

#include "EventRecorder.h"
#include "RTE_Components.h"
#include CMSIS_device_header

const osThreadAttr_t ThreadStart_Attr = 
{
	.name = "osRtxStartThread",
	.attr_bits = osThreadDetached, 
	.priority = osPriorityNormal6,
	.stack_size = 2048,
};

osThreadId_t ThreadIdStart = NULL;

void thread_start_task(void *argument);

int main(int argc, char **argv)
{
	/* STM32F4xx HAL library initialization:
       - Configure the Flash prefetch, instruction and Data caches
       - Configure the Systick to generate an interrupt each 1 msec
       - Set NVIC Group Priority to 4
       - Global MSP (MCU Support Package) initialization
     */
	HAL_Init();
	
	/* Configuration system clock */
    SystemClock_Config();
	
	HAL_SuspendTick();
	
    osKernelInitialize();  

	ThreadIdStart = osThreadNew(thread_start_task, (void *)&mico_system_content, &ThreadStart_Attr);
	
	osKernelStart();
}

void thread_start_task(void *argument)
{
    const uint16_t usFrequency = 200;
	uint32_t tick;
	
	mico_context_t *mico_content = (mico_context_t *)(argument);
	
	HAL_ResumeTick();
	
	/* Setup the hardware. */
	sInitMCU();
	
#if (defined(RTE_CMSIS_Compiler_STDOUT_Event_Recorder))
	EventRecorderInitialize (EventRecordAll, 1U); // Initialize and start Event Recorder
	EventRecorderClockUpdate();
#elif (defined(RTE_CMSIS_Compiler_STDOUT_Custom))
	extern int stdout_init (void);
	stdout_init();
#else
	sPRINTF_Configuration();
#endif
	
	printf("STM32-TI的DSP定点库IQmath移植模板.\r\n");
	
	tick = osKernelGetTickCount();
	
	/* This thread simply sits in while-forever-sleep loop.  */
	while (1)
	{
		printf("osKernelGetTickCount () is %010d.\r\n", osKernelGetTickCount ());
		mico_content->wBSD_Info[0].wBSD_Data++;
		gpio_trigger(&gpio_handlers[eGPIO0]);
		gpio_trigger(&gpio_handlers[eGPIO1]);
		gpio_trigger(&gpio_handlers[eGPIO2]);
		gpio_trigger(&gpio_handlers[eGPIO3]);
		tick += usFrequency;
		osDelayUntil(tick);
	}
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{
    while (1)
    {
    }
}
#endif

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
