/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 23 SEP 2023         */
/* Version      : V01                 */
/**************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_config.h"
#include "LEDMRX_private.h"


void HLEDMRX_voidInit(void)
{
    MGPIO_VoidSetPinDirection(LEDMRX_ROW0_PIN, 0b0010);
    MGPIO_VoidSetPinDirection(LEDMRX_ROW1_PIN, 0b0010);
    MGPIO_VoidSetPinDirection(LEDMRX_ROW2_PIN, 0b0010);
    MGPIO_VoidSetPinDirection(LEDMRX_ROW3_PIN, 0b0010);
    MGPIO_VoidSetPinDirection(LEDMRX_ROW4_PIN, 0b0010);
    MGPIO_VoidSetPinDirection(LEDMRX_ROW5_PIN, 0b0010);
    MGPIO_VoidSetPinDirection(LEDMRX_ROW6_PIN, 0b0010);
    MGPIO_VoidSetPinDirection(LEDMRX_ROW7_PIN, 0b0010);

    MGPIO_VoidSetPinDirection(LEDMRX_COL0_PIN, 0b0010);
    MGPIO_VoidSetPinDirection(LEDMRX_COL1_PIN, 0b0010);
    MGPIO_VoidSetPinDirection(LEDMRX_COL2_PIN, 0b0010);
    MGPIO_VoidSetPinDirection(LEDMRX_COL3_PIN, 0b0010);
    MGPIO_VoidSetPinDirection(LEDMRX_COL4_PIN, 0b0010);
    MGPIO_VoidSetPinDirection(LEDMRX_COL5_PIN, 0b0010);
    MGPIO_VoidSetPinDirection(LEDMRX_COL6_PIN, 0b0010);
    MGPIO_VoidSetPinDirection(LEDMRX_COL7_PIN, 0b0010);
}

void HLEDMRX_voidDisplay(u8 *Copy_u8Data)
{
    while(1)
    {
        /* Disable All Columns */
        DisableAllCols();    
        SetRowValues(Copy_u8Data[0]);
        /* Enable Column 0*/
        MGPIO_VoidSetPinV(LEDMRX_COL0_PIN, GPIO_LOW);
        MSTK_voidSetBusyWait(2500); /* 2.5 ms */

        /* Disable All Columns */
        DisableAllCols();    
        SetRowValues(Copy_u8Data[1]);
        /* Enable Column 1*/
        MGPIO_VoidSetPinV(LEDMRX_COL1_PIN, GPIO_LOW);
        MSTK_voidSetBusyWait(2500); /* 2.5 ms */

        /* Disable All Columns */
        DisableAllCols();    
        SetRowValues(Copy_u8Data[2]);
        /* Enable Column 2*/
        MGPIO_VoidSetPinV(LEDMRX_COL2_PIN, GPIO_LOW);
        MSTK_voidSetBusyWait(2500); /* 2.5 ms */

        /* Disable All Columns */
        DisableAllCols();    
        SetRowValues(Copy_u8Data[3]);
        /* Enable Column 3*/
        MGPIO_VoidSetPinV(LEDMRX_COL3_PIN, GPIO_LOW);
        MSTK_voidSetBusyWait(2500); /* 2.5 ms */

        /* Disable All Columns */
        DisableAllCols();    
        SetRowValues(Copy_u8Data[4]);
        /* Enable Column 4*/
        MGPIO_VoidSetPinV(LEDMRX_COL4_PIN, GPIO_LOW);
        MSTK_voidSetBusyWait(2500); /* 2.5 ms */

        /* Disable All Columns */
        DisableAllCols();    
        SetRowValues(Copy_u8Data[5]);
        /* Enable Column 5*/
        MGPIO_VoidSetPinV(LEDMRX_COL5_PIN, GPIO_LOW);
        MSTK_voidSetBusyWait(2500); /* 2.5 ms */

        /* Disable All Columns */
        DisableAllCols();    
        SetRowValues(Copy_u8Data[6]);
        /* Enable Column 6*/
        MGPIO_VoidSetPinV(LEDMRX_COL6_PIN, GPIO_LOW);
        MSTK_voidSetBusyWait(2500); /* 2.5 ms */

        /* Disable All Columns */
        DisableAllCols();    
        SetRowValues(Copy_u8Data[7]);
        /* Enable Column 7*/
        MGPIO_VoidSetPinV(LEDMRX_COL7_PIN, GPIO_LOW);
        MSTK_voidSetBusyWait(2500); /* 2.5 ms */
    }
}

static void DisableAllCols(void)
{
     /* Disable All Columns */
    MGPIO_VoidSetPinValue(LEDMRX_COL0_PIN, GPIO_HIGH);
    MGPIO_VoidSetPinValue(LEDMRX_COL1_PIN, GPIO_HIGH);
    MGPIO_VoidSetPinValue(LEDMRX_COL2_PIN, GPIO_HIGH);
    MGPIO_VoidSetPinValue(LEDMRX_COL3_PIN, GPIO_HIGH);
    MGPIO_VoidSetPinValue(LEDMRX_COL4_PIN, GPIO_HIGH);
    MGPIO_VoidSetPinValue(LEDMRX_COL5_PIN, GPIO_HIGH);
    MGPIO_VoidSetPinValue(LEDMRX_COL6_PIN, GPIO_HIGH);
    MGPIO_VoidSetPinValue(LEDMRX_COL7_PIN, GPIO_HIGH);
}

static void SetRowValues(u8 Copy_u8Value)
{
    u8 Local_u8BIT;
    Local_u8BIT = GET_BIT(Copy_u8Value, 0);
    MGPIO_VoidSetPinValue(LEDMRX_ROW0_PIN, Local_u8BIT);
    
    Local_u8BIT = GET_BIT(Copy_u8Value, 1);
    MGPIO_VoidSetPinValue(LEDMRX_ROW1_PIN, Local_u8BIT);

    Local_u8BIT = GET_BIT(Copy_u8Value, 2);
    MGPIO_VoidSetPinValue(LEDMRX_ROW2_PIN, Local_u8BIT);
    
    Local_u8BIT = GET_BIT(Copy_u8Value, 3);
    MGPIO_VoidSetPinValue(LEDMRX_ROW3_PIN, Local_u8BIT);
    
    Local_u8BIT = GET_BIT(Copy_u8Value, 4);
    MGPIO_VoidSetPinValue(LEDMRX_ROW4_PIN, Local_u8BIT);
    
    Local_u8BIT = GET_BIT(Copy_u8Value, 5);
    MGPIO_VoidSetPinValue(LEDMRX_ROW5_PIN, Local_u8BIT);
    
    Local_u8BIT = GET_BIT(Copy_u8Value, 6);
    MGPIO_VoidSetPinValue(LEDMRX_ROW6_PIN, Local_u8BIT);

    Local_u8BIT = GET_BIT(Copy_u8Value, 7);
    MGPIO_VoidSetPinValue(LEDMRX_ROW7_PIN, Local_u8BIT);
}

/* check it */
void HLEDMRX_voidEnable(u8 *Copy_u8arr)
{
    for (u8 i = 0; i < 8 ; i++)
    {
        MGPIO_VoidSetPortValue(GPIOA, GPIO_LOW, Copy_u8arr[i]);
        MGPIO_VoidSetPinValue(GPIOB, i + PIN8, GPIO_LOW);
        _delay_ms(2);
        MGPIO_VoidSetPinValue(GPIOB, i + PIN8, GPIO_HIGH);
    }
}

