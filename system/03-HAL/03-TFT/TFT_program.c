/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 4 OCT 2023          */
/* Version      : V01                 */
/**************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"


void HTFT_voidInit(void)
{
    /* Reset Pulse */
    MGPIO_VoidSetPinValue(TFT_RST_PIN, GPIO_HIGH);
    MSTK_voidSetBusyWait(100);
    MGPIO_VoidSetPinValue(TFT_RST_PIN, GPIO_LOW);
    MSTK_voidSetBusyWait(1);
    MGPIO_VoidSetPinValue(TFT_RST_PIN, GPIO_HIGH);
    MSTK_voidSetBusyWait(100);
    MGPIO_VoidSetPinValue(TFT_RST_PIN, GPIO_LOW);
    MSTK_voidSetBusyWait(100);
    MGPIO_VoidSetPinValue(TFT_RST_PIN, GPIO_HIGH);
    MSTK_voidSetBusyWait(120000);

    /* Sleep Out Command */
    voidWriteCommand(0x11);

    /* Wait 150 ms */
    MSTK_voidSetBusyWait(150000);

    /* Color Mode Command */
    voidWriteCommand(0x3A);
    voidWriteData(0x05);

    /* Display On Command */
    voidWriteCommand(0x29);

}

void HTFT_voidDisplayImage(const u16* Copy_u16Image)
{
    u16 Local_u16Counter;
    /* Set X Address */
    voidWriteCommand(0x2A);
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(127);

    /* Set Y Address */
    voidWriteCommand(0x2B);
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(159);

    /* RAM Write */
    voidWriteCommand(0x2C);

    voidWriteData(0x0000);
    voidWriteData(0xf0f0);

    for (Local_u16Counter  = 0; Local_u16Counter < 20480; Local_u16Counter++)
    {
        /* Write the high byte */
        voidWriteData(Copy_u16Image[Local_u16Counter] >> 8);
        /* Write the low byte */
        voidWriteData(Copy_u16Image[Local_u16Counter] & 0x00ff);   
    }
}

void HTFT_voidFillColor(u16 Copy_u16Color)
{
    u16 Local_u16Counter;
    /* Set X Address */
    voidWriteCommand(0x2A);
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(127);

    /* Set Y Address */
    voidWriteCommand(0x2B);
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(159);

    /* RAM Write */
    voidWriteCommand(0x2C);

    voidWriteData(0x0000);
    voidWriteData(0xf0f0);

    for (Local_u16Counter  = 0; Local_u16Counter < 20480; Local_u16Counter++)
    {
        /* Write the high byte */
        voidWriteData(Copy_u16Color >> 8);
        /* Write the low byte */
        voidWriteData(Copy_u16Color & 0x00ff);   
    }
}

void HTFT_voidDrawRect(u8 Copy_u8X1, u8 Copy_u8X2,u8 Copy_u8Y1, u8 Copy_u8Y2, u16 Copy_u16Color)
{
    u16 Local_u16Counter;
    u16 Local_u16Size = (Copy_u8X2 - Copy_u8X1) * (Copy_u8Y2 - Copy_u8Y1);
    /* Set X Address */
    voidWriteCommand(0x2A);
    voidWriteData(0);
    voidWriteData(Copy_u8X1);
    voidWriteData(0);
    voidWriteData(Copy_u8X2);

    /* Set Y Address */
    voidWriteCommand(0x2B);
    voidWriteData(0);
    voidWriteData(Copy_u8Y1);
    voidWriteData(0);
    voidWriteData(Copy_u8Y2);

    /* RAM Write */
    voidWriteCommand(0x2C);

    voidWriteData(0x0000);
    voidWriteData(0xf0f0);

    for (Local_u16Counter  = 0; Local_u16Counter < Local_u16Size; Local_u16Counter++)
    {
        /* Write the high byte */
        voidWriteData(Copy_u16Color >> 8);
        /* Write the low byte */
        voidWriteData(Copy_u16Color & 0x00ff);   
    }
}

static void voidWriteCommand(u8 Copy_u8Command)
{
    u8 Local_u8Temp;
    /* Set A0 pin to Low */
    MGPIO_VoidSetPinValue(TFT_A0_PIN, GPIO_LOW);
    
    /* Send Command over SPI */
    MSPI1_voidSendReceiveSynch(Copy_u8Command, &Local_u8Temp);

}

static void voidWriteData(u8 Copy_u8Data)
{
    u8 Local_u8Temp; 
    /* Set A0 pin to High */
    MGPIO_VoidSetPinValue(TFT_A0_PIN, GPIO_HIGH);
    
    /* Send Data over SPI */
    MSPI1_voidSendReceiveSynch(Copy_u8Data, &Local_u8Temp);


}
