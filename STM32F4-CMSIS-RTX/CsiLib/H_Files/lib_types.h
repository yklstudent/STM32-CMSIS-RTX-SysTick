#ifndef _LIB_TYPES_H_
#define _LIB_TYPES_H_

#include "main.h"

typedef void (*LL_DMA_ClearFlag)(DMA_TypeDef *DMAx);
typedef uint32_t (*LL_DMA_IsActiveFlag)(DMA_TypeDef *DMAx);
typedef uint32_t (*LL_DMA_IsEnabledIT)(DMA_TypeDef *DMAx, uint32_t Stream);

typedef enum
{
    eDMA1 = 0,
    eDMA2,
    eDMAn,
}mico_dma_type;

typedef struct
{
    IRQn_Type           	irq_vector;
    uint8_t             	mpriority;
    uint8_t             	spriority;
    DMA_TypeDef         	*controller;    //DMA1/DMA2
	DMA_Stream_TypeDef  	*stream;        //DMA1_Stream0~DMA_Stream7
    uint32_t		  		stream_id;		//DMA1_Stream0~DMA_Stream7
    uint32_t            	channel;        //Channel0~Channel7
    LL_DMA_ClearFlag		clear_flags;
	LL_DMA_IsActiveFlag		isavtive_flags;
	LL_DMA_IsEnabledIT		isenable_it;
}dma_type;

typedef struct _filesystem_info_t
{
	int total_space;
	int free_space;
} filesystem_info;

typedef struct
{
    unsigned char event;
    unsigned char code;
    unsigned char value;
    unsigned char client;
}Event_Type;

typedef struct
{
	unsigned char event;
	unsigned char code;
	unsigned char address;			// 地址
	unsigned char function;			// 功能码
	unsigned short usRegAddr;		// 寄存器地址
	unsigned short usRegValue;		// 寄存器数值
	unsigned short usRegCount;		// 寄存器数量
}MRTU_Type;

typedef struct
{
	unsigned char event;
    unsigned char *rxbuf;
	unsigned char *txbuf;
	unsigned short rxlen;
	unsigned short txlen;
}Comm_Type;

typedef union
{
	unsigned short wFlags;
	struct
	{
		unsigned short bit00_flag:1;	// 位域00
		unsigned short bit01_flag:1;	// 位域01
		unsigned short bit02_flag:1;	// 位域02
		unsigned short bit03_flag:1;	// 位域03
		unsigned short bit04_flag:1;	// 位域04
		unsigned short bit05_flag:1;	// 位域05
		unsigned short bit06_flag:1;	// 位域06
		unsigned short bit07_flag:1;	// 位域07
		unsigned short bit08_flag:1;	// 位域08
		unsigned short bit09_flag:1;	// 位域09
		unsigned short bit10_flag:1;	// 位域10
		unsigned short bit11_flag:1;	// 位域11
		unsigned short bit12_flag:1;	// 位域12
		unsigned short bit13_flag:1;	// 位域13
		unsigned short bit14_flag:1;	// 位域14
		unsigned short bit15_flag:1;	// 位域15
	}bits;
}Flg_Type;

typedef struct
{
	unsigned char sec;	//秒
	unsigned char min;	//分
	unsigned char hor;	//时
	unsigned char day;	//日
	unsigned char mon;	//月
	unsigned char yer;	//年
	unsigned char wek;	//周
}Time_Type;

/* GPIO alternate function */
typedef uint8_t gpio_alternate_function_t;

/* Peripheral clock function */
typedef void (*peripheral_clock_function_t)(uint32_t clock, FunctionalState state );

typedef FunctionalState functional_state_t;
typedef uint32_t peripheral_clock_t;

#endif
