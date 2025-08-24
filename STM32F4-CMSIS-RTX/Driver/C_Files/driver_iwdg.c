/****************************************Copyright (c)****************************************************
**                                    SSES/DGPS Co.,LTD.
**                                      
**                               https://cn.csisolar.com/
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               driver_iwdg.c
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
#include "driver_iwdg.h"

void sIWDG_Configuration(void)
{
	if (LL_RCC_IsActiveFlag_IWDGRST())
	{
		/* clear IWDG reset flag */
		LL_RCC_ClearResetFlags();
	}
	/* Enable the peripheral clock of DBG register (uncomment for debug purpose) */
	/* ------------------------------------------------------------------------- */
	/*  LL_DBGMCU_APB1_GRP1_FreezePeriph(LL_DBGMCU_APB1_GRP1_IWDG_STOP); */
	
	/* Enable the peripheral clock IWDG */
	/* -------------------------------- */
	LL_RCC_LSI_Enable();
	while (LL_RCC_LSI_IsReady() != 1)
	{
	}
	
	/* Configure the IWDG with window option disabled */
	/* ------------------------------------------------------- */
	/* (1) Enable the IWDG by writing 0x0000 CCCC in the IWDG_KR register */
	/* (2) Enable register access by writing 0x0000 5555 in the IWDG_KR register */
	/* (3) Write the IWDG prescaler by programming IWDG_PR from 0 to 7 - LL_IWDG_PRESCALER_4 (0) is lowest divider*/
	/* (4) Write the reload register (IWDG_RLR) */
	/* (5) Wait for the registers to be updated (IWDG_SR = 0x0000 0000) */
	/* (6) Refresh the counter value with IWDG_RLR (IWDG_KR = 0x0000 AAAA) */
	LL_IWDG_Enable(IWDG);                             /* (1) */
	LL_IWDG_EnableWriteAccess(IWDG);                  /* (2) */
	LL_IWDG_SetPrescaler(IWDG, LL_IWDG_PRESCALER_4);  /* (3) */
	LL_IWDG_SetReloadCounter(IWDG, 0xFEE);            /* (4) */
	while (LL_IWDG_IsReady(IWDG) != 1)                /* (5) */
	{
	}
	LL_IWDG_ReloadCounter(IWDG);                      /* (6) */
}

void sIWDG_Feed(void)
{
	LL_IWDG_ReloadCounter(IWDG);
}
