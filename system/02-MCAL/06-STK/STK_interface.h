/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 23 SEP 2023         */
/* Version      : V01                 */
/**************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

/* Apply Clock Choice from configuration file
   Disable SysTick interrupt
   Enable Systick interrupt
*/
#define MSTK_INT_EN     1
#define MSTK_INT_DIS    0

void MSTK_voidInit                  (void);

void MSTK_voidSetBusyWait           (u32 Copy_u32Ticks);

void MSTK_voidSetIntervalSingle     (u32 Copy_u32Ticks , void (*Copy_ptr)(void));

void MSTK_voidSetIntervalPeriodic   (u32 Copy_u32Ticks , void (*Copy_ptr)(void));

void MSTK_voidStopInterval          (void);

u32 MSTK_u32GetElapsedTime          (void);

u32 MSTK_u32GetRemainingTime        (void);

   /* check it */
void MSTK_voidSetCallBack           (void(*Copy_Ptr)(void));
void MSTK_voidStart                 (u32 Copy_u32PreLoadValue);
void MSTK_voidINTStatus             (u8 Copy_u8Status);
u8 MSTK_u8ReadFlag                  (void);


#endif