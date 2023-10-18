/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 24 SEP 2023         */
/* Version      : V01                 */
/**************************************/
#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H


void SOS_voidCreateTask(u8 Copy_u8Periorty, u16 Copy_u16Priodicity, void(*Copy_Ptr)(void), u8 Copy_u8FirstDelay);
void SOS_voidStart(void);

/* check it */
void SOS_voidSuspendTask(u8 Copy_u8TaskID);
void SOS_voidResumeTask(u8 Copy_u8TaskID);
void SOS_voidDeleteTask(u8 Copy_u8TaskID);


#endif
