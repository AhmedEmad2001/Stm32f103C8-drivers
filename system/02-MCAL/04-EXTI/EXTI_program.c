/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 23 SEP 2023         */
/* Version      : V02                 */
/**************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

#define NULL    (void *) 0

static void (*EXTI0_CallBack)(void) = NULL;

void MEXTI_voidInit(void)
{
    #if EXTI_MODE == EXTI_LINE0
        SET_BIT(EXTI-> IMR, EXTI_LINE0);
    #elif EXTI_MODE == EXTI_LINE1
        SET_BIT(EXTI-> IMR, EXTI_LINE1);
    #elif EXTI_MODE == EXTI_LINE2
        SET_BIT(EXTI-> IMR, EXTI_LINE2);
    #else
        #error "Wrong Line Choice"
    #endif
    
    #if EXTI_MODE == RISING
        SET_BIT(EXTI-> RTSR, EXTI_LINE);
    #elif EXTI_MODE == FALLING
        SET_BIT(EXTI-> FTSR, EXTI_LINE);
    #elif EXTI_MODE == ON_CHANGE
        SET_BIT(EXTI-> RTSR, EXTI_LINE);
        SET_BIT(EXTI-> FTSR, EXTI_LINE);
    #else
        #error "Wrong Mode Choice"
    #endif
    /* Disable interrupt */
    CLR_BIT(EXTI-> IMR, EXTI_LINE); /* copy_u8Line not found solve it */
}

void MEXTI_voidEnableEXTI(u8 Copy_u8Line)
{
    SET_BIT(EXTI-> IMR, Copy_u8Line);
}

void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
{
    CLR_BIT(EXTI-> IMR, Copy_u8Line);
}

void MEXTI_voidSWTrigger(u8 Copy_u8Line)
{
    SET_BIT(EXTI-> SWIER,  Copy_u8Line);
}

void MEXTI_voidSetSignalLatch(u8 Copy_u8Line)
{
    switch (Copy_u8Line)
    {
        case RISING :
            SET_BIT(EXTI-> RTSR, EXTI_LINE);
            break;
        case FALLING :
            SET_BIT(EXTI-> FTSR, EXTI_LINE);
            break;
        case ON_CHANGE :
            SET_BIT(EXTI-> RTSR, EXTI_LINE);
            SET_BIT(EXTI-> FTSR, EXTI_LINE);
            break;
        default:
            break;
    }
    SET_BIT(EXTI->IMR, Copy_u8Line);
}

void MEXTI_voidSetCallBack    (void (*Copy_Ptr)(void))
{
    EXTI0_CallBack = Copy_Ptr;
}

void EXTI0_IRQHandler(void)
{
    EXTI0_CallBack();
    /* Clear Pending Bit */
    SET_BIT(EXTI-> PR, 0);
}

