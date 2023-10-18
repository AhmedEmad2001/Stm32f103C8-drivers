/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 4 OCT 2023          */
/* Version      : V01                 */
/**************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void MSPI1_voidInit(void)
{
    /* CPOL = 1 , CPHA = 1 , Prescaller = CLK / 2 , SPI Enable , MSB First */
    MSPI1->CR1 = 0x0347;
}

void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_u8DataToReceive)
{
    /* Clear for slave selected pin */
    MGPIO_VoidSetPinValue(MSPI1_SLAVE_PIN, GPIO_LOW);

    /* Send Data */
    MSPI1->DR = Copy_u8DataToTransmit;

    /* Wait Busy flag to finish */
    while(GET_BIT(MSPI1->SR, 7) == 1);

    /* Return to received data*/
    *Copy_u8DataToReceive = MSPI1->DR;

    /* Set slave selected pin */
    MGPIO_VoidSetPinValue(MSPI1_SLAVE_PIN, GPIO_HIGH);

}

void MSPI1_voidSendReceiveAsynch(u8 Copy_u8DataToTransmit, void(*CallBack)(u8))
{

}

void SPI1_IRQHandler(void)
{
    CallBack(MSPI1->DR);
}

