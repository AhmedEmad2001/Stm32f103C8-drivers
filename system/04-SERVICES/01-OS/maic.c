/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 23 SEP 2023         */
/* Version      : V01                 */
/**************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "STK_interface.h"
#include "GPIO_interface.h"
#include "OS_interface.h"

void LED1(void);
void LED2(void);
void LED3(void);

void main(void)
{
    /* Intialization */
    /* RCC_Intialization */

    /* Enable GPIO RCC PORTA */
    
    /* GPIO Intialization Direction */

    SOS_voidCreateTask(0, 1000, LED1, 0);
    
    SOS_voidCreateTask(1, 2000, LED2, 1);
    
    SOS_voidCreateTask(2, 3000, LED3, 2);
    
    SOS_voidStart();

    while(1)
    {

    }
    return 0;

}

void LED1(void)
{
    static u8 Local_u8Pin0 = 0;
    TOG_BIT(Local_u8Pin0, 0);
    MGPIO_VoidSetPinValue(GPIOA, PIN0, Local_u8Pin0);
}

void LED2(void)
{
    static u8 Local_u8Pin1 = 0;
    TOG_BIT(Local_u8Pin1, 0);
    MGPIO_VoidSetPinValue(GPIOA, PIN1, Local_u8Pin1);
}

void LED3(void)
{
    static u8 Local_u8Pin2 = 0;
    TOG_BIT(Local_u8Pin2, 0);
    MGPIO_VoidSetPinValue(GPIOA, PIN2, Local_u8Pin2);
}

