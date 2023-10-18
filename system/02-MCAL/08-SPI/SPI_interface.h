/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 4 OCT 2023          */
/* Version      : V01                 */
/**************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void MSPI1_voidInit(void);
void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_u8DataToReceive);

void MSPI1_voidSendReceiveAsynch(u8 Copy_u8DataToTransmit, void(*CallBack)(u8));



#endif
