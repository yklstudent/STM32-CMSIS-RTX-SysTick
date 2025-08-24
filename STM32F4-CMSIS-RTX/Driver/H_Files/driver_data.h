#ifndef _DRIVER_DATA_H_
#define _DRIVER_DATA_H_

#include "main.h"

// MLPE主控相关参数
#define cBS_DBGINFO_SIZE	10
typedef union
{
	uint16_t wBSD_Data;
	struct
	{
		uint16_t wBSD_Nums : 14;
		uint16_t wBSD_Flag : 2;
	}sBSD_Data;
} BS_DBGInfo_t;

typedef struct
{
	// 智能组网调试信息
	BS_DBGInfo_t wBSD_Info[cBS_DBGINFO_SIZE];
}mico_system_t;

typedef mico_system_t mico_context_t;

extern mico_context_t mico_system_content;

#endif
