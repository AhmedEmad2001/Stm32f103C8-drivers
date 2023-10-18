/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 5 OCT 2023          */
/* Version      : V02                 */
/**************************************/
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

#define THRESHOLD_VALUE             9000000UL

#define USART1_DISABLE              0
#define USART1_ENABLE               1

#define _8BIT_WORD_LENGTH           0
#define _9BIT_WORD_LENGTH           1

#define PARITY_DISABLE              0
#define Even_PARITY                 1
#define ODD_PARITY                  2

#define INT_DISABLE                 0
#define TXE_INT_ENABLE              1
#define TCE_INT_ENABLE              3
#define RXNE_INT_ENABLE             5

#define TRANSMITTER_DISABLE         0
#define TRANSMITTER_ENABLE          1

#define RECEIVER_DISABLE            0
#define RECEIVER_ENABLE             1

#define ONE_STOP_BIT                0
#define HALF_STOP_BIT               1
#define TWO_STOP_BIT                2
#define ONE_AND_HALF_STOP_BIT       3


void MUSART_voidInit(void);
// void MUSART_voidTransmit(u8 arr[]);
// u8 MUSART_u8Receive(void);

void MUSART_voidSendCharSync(u8 Copy_u8Char);
void MUSART_voidSendStringSynch(u8 * Copy_u8PtrString);
u8 MUSART_u8ReceiveCharSync(void);
u8 * MUSART_PtrReadStringSynch(void);
void MUSART_voidClearFlags(void);
u8 MUSART_u8ReadDataRegister(void);
void MUSART_voidSetCallBack(void(*Copy_Ptr) (void));


#endif
