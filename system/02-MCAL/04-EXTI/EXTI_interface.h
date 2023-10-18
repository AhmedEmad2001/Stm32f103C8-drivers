/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 23 SEP 2023         */
/* Version      : V02                 */
/**************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

void MEXTI_voidInit           (void);
void MEXTI_voidEnableEXTI     (u8 Copy_u8Line);
void MEXTI_voidDiableEXTI     (u8 Copy_u8Line);
void MEXTI_voidSWTrigger      (u8 Copy_u8Line);
void MEXTI_voidSetSignalLatch (u8 Copy_u8Line);

void MEXTI_voidSetCallBack    (void (*Copy_Ptr)(void));


#endif