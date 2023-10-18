#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "USART_interface.h"

void main(void)
{
    /* 8 MHZ */
    RCC_voidInitSysClock();
    
    RCC_voidEnableClock(RCC_APB2, 2);
    RCC_voidEnableClock(RCC_APB2, 14);
    
    /* A9 = TX out 50 MHZ */
    MGPIO_VoidSetPinDirection(GPIOA, PIN9, OUTPUT_SPEED_50MHZ_PP);
    /* A10 = RX input floating */
    MGPIO_VoidSetPinDirection(GPIOA, PIN10, INPUT_FLOATING);

    MGPIO_VoidSetPinDirection(GPIOA, PIN0, OUTPUT_SPEED_2MHZ_PP);

    MUSART_voidInit();
    
    u8 x;
    while (1)
    {
        MUSART_voidSendStringSynch("97");
        x = MUSART_u8ReceiveCharSync();
        if (x == '5')
        {
            MGPIO_VoidSetPinValue(GPIOA, PIN0, GPIO_HIGH);
        }
        else if(x == 'R')
        {
            MGPIO_VoidSetPinValue(GPIOA, PIN0, GPIO_LOW);
        }
    }
   
}

