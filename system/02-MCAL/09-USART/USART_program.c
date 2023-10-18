/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 5 OCT 2023          */
/* Version      : V02                 */
/**************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_config.h"
#include "USART_private.h"

u8 String[20];

void (*MUSART1_CallBack)(void);

void MUSART_voidInit(void)
{
    u32 Local_u32Mantissa = (F_CPU) /  (16 * USART1_BAUD_RATE);
    u32 Local_u32Fraction = (((F_CPU * 100) / (16 * USART1_BAUD_RATE)) % 100) * 16;
    
    if (Local_u32Fraction > 1500)
    {
        Local_u32Mantissa += 1;
        Local_u32Fraction = 0;
    }
    
    #if USART1_STATUS == USART1_ENABLE

        MUSART1->SR = 0;
    
        #if USART1_WORD_LENGTH == _8BIT_WORD_LENGTH
    
            CLR_BIT(MUSART1->CR1, 12); 
        
        #elif USART1_WORD_LENGTH == _9BIT_WORD_LENGTH
    
            SET_BIT(MUSART1->CR1, 12); 
        
        #endif

        #if USART1_PARITY == PARITY_DISABLE

            CLR_BIT(MUSART1->CR1, 10);

        #elif USART1_PARITY == EVEN_PARITY

            SET_BIT(MUSART1->CR1, 10);
            CLR_BIT(MUSART1->CR1, 11);

        #elif USART1_PARITY == ODD_PARITY

            SET_BIT(MUSART1->CR1, 10);
            SET_BIT(MUSART1->CR1, 11);
        
        #endif

        #if USART1_INTERRUPT == INT_DISABLE

            CLR_BIT(MUSART1->CR1, 5);
            CLR_BIT(MUSART1->CR1, 6);
            CLR_BIT(MUSART1->CR1, 7);
        
        #elif USART1_INTERRUPT == TXE_INT_ENABLE

            SET_BIT(MUSART1->CR1, 7);
        
        #elif USART1_INTERRUPT == TCE_INT_ENABLE

            SET_BIT(MUSART1->CR1, 6);

        #elif USART1_INTERRUPT == RXNE_INT_ENABLE

            SET_BIT(MUSART1->CR1, 5);

        #endif

        #if USART1_TRANSMITTER == TRANSMITTER_ENABLE

            SET_BIT(MUSART1->CR1, 3);

        #elif USART1_TRANSMITTER == TRANSMITTER_DISABLE

            CLR_BIT(MUSART1->CR1, 3);

        #endif

        #if USART1_RECEIVER == RECEIVER_ENABLE

            SET_BIT(MUSART1->CR1, 2);

        #elif USART1_RECEIVER == RECEIVER_DISABLE

            CLR_BIT(MUSART1->CR1, 2);

        #endif

        #if USART1_STOP_BITS == ONE_STOP_BIT

            CLR_BIT(MUSART1->CR2, 12);
            CLR_BIT(MUSART1->CR2, 13);

        #elif USART1_STOP_BITS == HALF_STOP_BIT

            SET_BIT(MUSART1->CR2, 12);
            CLR_BIT(MUSART1->CR2, 13);            

        #elif USART1_STOP_BITS == TWO_STOP_BIT

            CLR_BIT(MUSART1->CR2, 12);
            SET_BIT(MUSART1->CR2, 13);            

        #elif USART1_STOP_BITS == ONE_AND_HALF_STOP_BIT

            SET_BIT(MUSART1->CR2, 12);
            SET_BIT(MUSART1->CR2, 13);            

        #endif

        MUSART1->BRR = (Local_u32Mantissa << 4) | (Local_u32Fraction / 100);
        SET_BIT(MUSART1->CR1, 13);

    #elif USART1_STATUS == USART1_DISABLE

        CLR_BIT(MUSART1->CR1, 0);

    #endif

    /* 9600     BRR = 0x341 */
//    MUSART1->BRR = 0x341;
    /* 115200   BRR = 0x */
    /*  
        1- Enable RX
        2- Enable TX
        3- Enable USART
    */
/*    SET_BIT(MUSART1->CR1, 2);
    SET_BIT(MUSART1->CR1, 3);
    SET_BIT(MUSART1->CR1, 13);
*/
    /* Clear Status Registers */
//    MUSART1->SR = 0;

}

void MUSART_voidSendCharSync(u8 Copy_u8Char)
{
    MUSART1->DR = Copy_u8Char;
    while (GET_BIT(MUSART1->SR, 6) == 0);
    CLR_BIT(MUSART1->SR, 6);
}

void MUSART_voidSendStringSynch(u8 * Copy_u8PtrString)
{
    u8 Local_u8Iterator = 0;
    while (Copy_u8PtrString[Local_u8Iterator] != '\0')
    {
        MUSART1->DR = Copy_u8PtrString[Local_u8Iterator];
        /* while (GET_BIT(MUSART1->SR, 6) == 0); */
        /* Wait till transmation is complete */
     //   while (((MUSART1->SR) & 0x40) == 0);
        MUSART_voidSendCharSync(Copy_u8PtrString[Local_u8Iterator]);
        Local_u8Iterator++;        
    }  
}

u8 MUSART_u8ReceiveCharSync(void)
{
    u8 Local_u8Data = 0;
    u32 Local_u32TimeOut =0;

    CLR_BIT(MUSART1->SR, 5);

    while ((GET_BIT(MUSART1->SR, 5) == 0) && (Local_u32TimeOut < THRESHOLD_VALUE))
    {
        Local_u32TimeOut++;
    }

    if (Local_u32TimeOut == THRESHOLD_VALUE)
    {
        Local_u8Data = 255;
    }
    else
    {
        Local_u8Data = MUSART1->DR;
    }
    return Local_u8Data;
}

u8 * MUSART_PtrReadStringSynch(void)
{
    u8 Local_u8Iterator = 0;
    u8 Local_u8ReceiveData = 0;
    while ((Local_u8ReceiveData = MUSART_u8ReceiveCharSync()) != 13)
    {
        String[Local_u8Iterator] = Local_u8ReceiveData;
        Local_u8Iterator++;
    }
    String[Local_u8ReceiveData] = '\0';
    return String;
}

void MUSART_voidClearFlags(void)
{
    /* Clear all Flags */
    MUSART1->SR = 0;
}

u8 MUSART_u8ReadDataRegister(void)
{
    return MUSART1->DR;
}

void MUSART_void_SetCallBack(void (*Copy_Ptr) (void))
{
    MUSART1_CallBack = Copy_Ptr;
}

void USART1_IRQHandler(void)
{
    MUSART1->SR = 0;
    MUSART1_CallBack();
}

