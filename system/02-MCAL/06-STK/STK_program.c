/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 23 SEP 2023         */
/* Version      : V01                 */
/**************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_config.h"
#include "STK_private.h"

void (*MSTK_Callback)(void);

void MSTK_voidInit(void)
{
    /* check it */
    MSTK->CTRL = 0x00000002;
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
    MSTK->LOAD = Copy_u32Ticks;
    /* Enable of interrupt and Enable Systick */
    while (MSTK->CTRL == 0);
}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks , void (*Copy_ptr)(void))
{
    MSTK->LOAD = Copy_u32Ticks;
    /* Enable of interrupt and Enable Systick */
    MSTK_Callback = Copy_ptr;
}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*Copy_ptr)(void))
{

}

void MSTK_voidStopInterval(void)
{

}

u32 MSTK_u32GetElapsedTime(void)
{

}

u32 MSTK_u32GetRemainingTime(void)
{

}

void MSTK_voidSetCallBack           (void(*Copy_Ptr)(void))
{
    MSTK_Callback = Copy_Ptr;
}

void SysTick_Handler(void)
{
    MSTK_Callback();
}


/* check it */
void MSTK_voidStart                 (u32 Copy_u32PreLoadValue)
{
    /*  AHB = EXT = 8MHZ & Clock of MSTK = AHB / 8
        = 8MHZ / 8 = 1MHZ = 1 Micro for each count
    */
    /* Load Reload Vlaue*/
    MSTK->LOAD = Copy_u32PreLoadValue -1;
    /* Clear Val Register */
    MSTK->VAL = 0;
    /* Enable Systick */
    SET_BIT(MSTK->CTRL, 0);
}

void MSTK_voidINTStatus             (u8 Copy_u8Status)
{
    MSTK->CTRL &= ~(1 << 1);
    MSTK->CTRL |= (Copy_u8Status << 1);
}

u8 MSTK_u8ReadFlag                  (void)
{
    u8 Local_u8Result ;
    Local_u8Result = GET_BIT (MSTK->CTRL, 16);
    return  Local_u8Result;
}

