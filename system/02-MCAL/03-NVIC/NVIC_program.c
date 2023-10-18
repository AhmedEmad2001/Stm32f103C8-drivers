/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 21 SEP 2023         */
/* Version      : V01                 */
/**************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_config.h"
#include "NVIC_private.h"

void MNVIC_voidEnableInterrupt  (u8 Copy_u8IntNumber)
{
    if(Copy_u8IntNumber <=31)
    {
        NVIC_ISER0 = (1 << Copy_u8IntNumber);
    }
    else if(Copy_u8IntNumber <=59)
    {
        Copy_u8IntNumber -= 32;
        NVIC_ISER1 = (1 << Copy_u8IntNumber);
    }
    else
    {
        /* Return Error */
    }
}

void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber)
{
    if(Copy_u8IntNumber <=31)
    {
        NVIC_ICER0 = (1 << Copy_u8IntNumber);
    }
    else if(Copy_u8IntNumber <=59)
    {
        Copy_u8IntNumber -= 32;
        NVIC_ICER1 = (1 << Copy_u8IntNumber);
    }
    else
    {
        /* Return Error */
    }
}

void MNVIC_voidSetPendingFlag   (u8 Copy_u8IntNumber)
{
    if(Copy_u8IntNumber <=31)
    {
        NVIC_ISPR0 = (1 << Copy_u8IntNumber);
    }
    else if(Copy_u8IntNumber <=59)
    {
        Copy_u8IntNumber -= 32;
        NVIC_ISPR1 = (1 << Copy_u8IntNumber);
    }
    else
    {
        /* Return Error */
    }
}

void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber)
{
    if(Copy_u8IntNumber <=31)
    {
        NVIC_ICPR0 = (1 << Copy_u8IntNumber);
    }
    else if(Copy_u8IntNumber <=59)
    {
        Copy_u8IntNumber -= 32;
        NVIC_ICPR1 = (1 << Copy_u8IntNumber);
    }
    else
    {
        /* Return Error */
    }
}

u8 MNVIC_u8GetActiveFlag        (u8 Copy_u8IntNumber)
{
    u8 Local_u8Result;
    if(Copy_u8IntNumber <=31)
    {
        Local_u8Result = GET_BIT(NVIC_IABR0, Copy_u8IntNumber);
    }
    else if(Copy_u8IntNumber <=59)
    {
        Copy_u8IntNumber -= 32;
        Local_u8Result = GET_BIT(NVIC_IABR1, Copy_u8IntNumber);
    }
    else
    {
        /* Return Error */
    }
    return Local_u8Result;
}

void MNVIC_voidSetPriorty       (s8 Copy_s8IntID, u8 Copy_u8GroupPriorty, u8 Copy_u8SubPriorty, u32 Copy_u32Group)
{
    u8 Local_u8Priorty = Copy_u8SubPriorty | (Copy_u8GroupPriorty<<((Copy_u32Group - 0x05FA0300) / 256)) ;
    /* Core peripheral or External peripheral */
    /* External peripheral*/
    if(Copy_s8IntID >= 0)
    {
        NVIC_IPR[Copy_s8IntID] = Local_u8Priorty << 4;
    }
    /* Core peripheral */
    else if(Copy_s8IntID < 0)
    {   /* check it */
        if (Copy_s8IntID == MEMORY_MANAGE || Copy_s8IntID == BUS_FAULT || Copy_s8IntID == USAGE_FAULT)
        {
            Copy_s8IntID += 3;
            SCB_SHPR1 = Local_u8Priorty << ((Copy_s8IntID * 8) + 4);
        }
        else if (Copy_s8IntID == SV_CALL)
        {
            Copy_s8IntID += 7;
            SCB_SHPR2 = Local_u8Priorty << ((Copy_s8IntID * 8) + 4);
        }
        else if (Copy_s8IntID == PEND_SV || Copy_s8IntID == SYSTIK)
        {
            Copy_s8IntID += 8;
            SCB_SHPR3 = Local_u8Priorty << ((Copy_s8IntID * 8) + 4);
        }
    }
    else
    {
        /* Return Error */
    }
    SCB_AIRCR = Copy_u32Group;
}

void MNVIC_voidInit(void)
{
    SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;
}

