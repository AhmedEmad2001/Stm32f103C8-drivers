/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 21 SEP 2023         */
/* Version      : V01                 */
/**************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void MNVIC_voidEnableInterrupt  (u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag   (u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber);
u8 MNVIC_u8GetActiveFlag        (u8 Copy_u8IntNumber);
void MNVIC_voidSetPriorty       (s8 Copy_s8IntID, u8 Copy_u8GroupPriorty, u8 Copy_u8SubPriorty, u32 Copy_u32Group);

void MNVIC_voidInit(void);

#define Group3                  0x05FA0300  /* 4 bits for group (IPR)=> group and 0 bit for sub priorty */
#define Group4                  0x05FA0400  /* 3 bits for group and 1 bit for sub priorty */
#define Group5                  0x05FA0500  /* 2 bits for group and 2 bit for sub priorty */
#define Group6                  0x05FA0600  /* 1 bits for group and 3 bit for sub priorty */
#define Group7                  0x05FA0700  /* 0 bits for group and 4 bit for sub priorty */


#endif