/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 5  OCT 2023         */
/* Version      : V01                 */
/**************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_config.h"
#include "DMA_private.h"

void (*DMA_CallBackChannel1)(void);

void MDMA_voidChannelInit(void)
{
    /* 
        1- Memory to Memory
        2- very high
        3- Source size, Destinatioin Size = 32 bit
        4- MINC, DINC activated
        5- no circuiler
        6- direction
        7- transfer interrupt enable
    */
    #if CHANNEL_ID == 1
        DMA-> Channel[0].CCR = /* take value from data sheet and but it here */;
    #else
        /* Do No thing */
    #endif
}

void MDMA_voidChannelStart(u32 * Copy_Pu32SourceAdrress, u32 * Copy_Pu32DestinationAdrress, u16 Copy_u16BlockLenght)
{
    /* Make sure that channel is disable */
    CLR_BIT(DMA->Channel[0].CCR, 0);
    /* Write the address */
    DMA->Channel[0].CPAR = Copy_Pu32SourceAdrress;
    DMA->Channel[0].CMAR = Copy_Pu32DestinationAdrress;

    /* Block Length */
    DMA->Channel[0].CNDTR = Copy_u16BlockLenght;

    /* Make sure that channel is enaable */
    SET_BIT(DMA->Channel[0].CCR, 0);
}

void MDMA_voidSetConfiguration(u8 Copy_u8Channel, u8 Copy_u8Direction, u8 Copy_u8DMAMode, u8 Copy_u8PINC,
                               u8 Copy_u8MINC, u8 Copy_u8MEMSize, u8 Copy_u8PERSize, u8 Copy_u8ChannelPriority)
{

}

void MDMA_voidDMAEnable(u8 Copy_u8Channel)
{
    MDMA_voidClearFlag(Copy_u8Channel, DMA_GIF);
    MDMA_voidClearFlag(Copy_u8Channel, DMA_TCIF);
    MDMA_voidClearFlag(Copy_u8Channel, DMA_HTIF);
    MDMA_voidClearFlag(Copy_u8Channel, DMA_TEIF);

    SET_BIT(DMA->Channel[Copy_u8Channel].CCR, DMA_ENABLE);
}

void MDMA_voidDMADisable(u8 Copy_u8Channel)
{
    CLR_BIT(DMA->Channel[Copy_u8Channel].CCR, 0);
}

void MDMA_voidInterruptEnable(u8 Copy_u8Channel, u8 Copy_u8INTSource)
{
    SET_BIT(DMA->Channel[Copy_u8Channel].CCR, Copy_u8INTSource);
}

void MDMA_voidSetAddress(u8 Copy_u8Channel, u32 * Copy_u32PeriphralAddress, u32 * Copy_u32MemoryAddress, u16 Copy_u16NDT)
{
    DMA->Channel[Copy_u8Channel].CPAR = Copy_u32PeriphralAddress;
    DMA->Channel[Copy_u8Channel].CMAR = Copy_u32MemoryAddress;
    DMA->Channel[Copy_u8Channel].CNDTR = Copy_u16NDT;
}

void MDMA_voidClearFlag(u8 Copy_u8Channel, u8 Copy_u8Flag)
{
    Copy_u8Channel *= 4;
    SET_BIT(DMA->IFCR, (Copy_u8Channel + Copy_u8Flag));
}

u8 MDMA_u8GetFlag(u8 Copy_u8Channel, u8 Copy_u8Flag)
{
    u8 Local_u8Result = 0;
    Copy_u8Channel *= 4;
    Local_u8Result = GET_BIT(DMA->ISR, (Copy_u8Channel +Copy_u8Flag));
    return Local_u8Result;
}
/*-------------------------------------------------------------*/
void MDMA_voidSetCallBackChannel1(void(*Copy_Ptr)void)
{
    DMA_CallBackChannel1 = Copy_Ptr;
}

void DMA1_Channel1_IRQHandler(void)
{
    DMA_CallBackChannel1();
}

