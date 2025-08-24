/****************************************Copyright (c)****************************************************
**                                    SSES/DGPS Co.,LTD.
**                                      
**                               https://cn.csisolar.com/
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               driver_data.c
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
#include "driver_data.h"
#include "driver_iwdg.h"

#if (defined (__CC_ARM))
mico_context_t mico_system_content __attribute__((at(0x20000000)));
#elif (defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
mico_context_t mico_system_content __attribute__((section(".ARM.__at_0x20000000")));
#endif

#if (defined (__CC_ARM))
//uint8_t buf[4096] __attribute__((at(0x10000000)));
#elif (defined (__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
//uint8_t buf[4096] __attribute__((section(".ARM.__at_0x10000000")));
#endif
#if 0
const uint8_t mcu_version[] __attribute__((section(".ARM.__at_0xC0000000"))) = 
{
	"VERSION 00.01"
};
#endif
