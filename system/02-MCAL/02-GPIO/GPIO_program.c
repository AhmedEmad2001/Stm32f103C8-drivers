/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 14 SEP 2023         */
/* Version      : V01                 */
/**************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_config.h"
#include "GPIO_private.h"

void MGPIO_VoidSetPinDirection(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Mode)
{
    switch(Copy_u8PORT)
    {
        case GPIOA:
            if(Copy_u8PIN <= 7)
            {
                GPIOA_CRL &= ~ ((0b1111) << (Copy_u8PIN * 4));
                GPIOA_CRL |=   ((Copy_u8Mode) << (Copy_u8PIN * 4));
            }
            else if(Copy_u8PIN <= 15)
            {
                Copy_u8PIN -= 8;
                GPIOA_CRH &= ~ ((0b1111) << (Copy_u8PIN * 4));
                GPIOA_CRH |=   ((Copy_u8Mode) << (Copy_u8PIN * 4));
            }
            break;
        case GPIOB:
        if(Copy_u8PIN <= 7)
            {
                GPIOB_CRL &= ~ ((0b1111) << (Copy_u8PIN * 4));
                GPIOB_CRL |=   ((Copy_u8Mode) << (Copy_u8PIN * 4));
            }
            else if(Copy_u8PIN <= 15)
            {
                Copy_u8PIN -= 8;
                GPIOB_CRH &= ~ ((0b1111) << (Copy_u8PIN * 4));
                GPIOB_CRH |=   ((Copy_u8Mode) << (Copy_u8PIN * 4));
            }
            break;
        case GPIOC:
        if(Copy_u8PIN <= 7)
            {
                GPIOC_CRL &= ~ ((0b1111) << (Copy_u8PIN * 4));
                GPIOC_CRL |=   ((Copy_u8Mode) << (Copy_u8PIN * 4));
            }
            else if(Copy_u8PIN <= 15)
            {
                Copy_u8PIN -= 8;
                GPIOC_CRH &= ~ ((0b1111) << (Copy_u8PIN * 4));
                GPIOC_CRH |=   ((Copy_u8Mode) << (Copy_u8PIN * 4));
            }
            break;
        default:
            break;
    }
}

void MGPIO_VoidSetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Value)
{
    switch(Copy_u8PORT)
    {
        case GPIOA:
            if(Copy_u8Value == GPIO_HIGH)
            {
                SET_BIT(GPIOA_ODR, Copy_u8PIN);
            }
            else if(Copy_u8Value == GPIO_LOW)
            {
                CLR_BIT(GPIOA_ODR, Copy_u8PIN);
            }
            break;
        case GPIOB:
            if(Copy_u8Value == GPIO_HIGH)
            {
                SET_BIT(GPIOB_ODR, Copy_u8PIN);
            }
            else if(Copy_u8Value == GPIO_LOW)
            {
                CLR_BIT(GPIOB_ODR, Copy_u8PIN);
            } 
            break;
        case GPIOC:
            if(Copy_u8Value == GPIO_HIGH)
            {
                SET_BIT(GPIOC_ODR, Copy_u8PIN);
            }
            else if(Copy_u8Value == GPIO_LOW)
            {
                CLR_BIT(GPIOC_ODR, Copy_u8PIN);
            }
            break;
        default:
            break;
    }
}

u8 MGPIO_u8GetPinValue(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
    u8 LOC_u8Result = 0;
   
    switch(Copy_u8PORT)
    {
        case GPIOA:
            LOC_u8Result = GET_BIT(GPIOA_IDR, Copy_u8PIN);
            break;
        case GPIOB:
            LOC_u8Result = GET_BIT(GPIOB_IDR, Copy_u8PIN);
            break;
        case GPIOC:
            LOC_u8Result = GET_BIT(GPIOC_IDR, Copy_u8PIN);
            break;
        default:
            break;
    }
    return LOC_u8Result;
}

void MGPIO_VoidSetPortDirection(u8 Copy_u8PORT, u8 Copy_u8Position, u8 Copy_u8Mode)
{
    switch(Copy_u8PORT)
    {
        case GPIOA:
            if (Copy_u8Position == GPIO_LOW)
                {
                    GPIOA_CRL = (0x11111111 * Copy_u8Mode);
                }
            else if (Copy_u8Position == GPIO_HIGH)
                {
                    GPIOA_CRH = (0x11111111 * Copy_u8Mode);
                }
                else
                {
                    /* code */
                }
            break;
        case GPIOB:
            if (Copy_u8Position == GPIO_LOW)
                {
                    GPIOB_CRL = (0x11111111 * Copy_u8Mode);
                }
            else if (Copy_u8Position == GPIO_HIGH)
                {
                    GPIOB_CRH = (0x11111111 * Copy_u8Mode);
                }
                else
                {
                    /* code */
                }
            break;
        case GPIOC:
            if (Copy_u8Position == GPIO_LOW)
                {
                    GPIOC_CRL = (0x11111111 * Copy_u8Mode);
                }
            else if (Copy_u8Position == GPIO_HIGH)
                {
                    GPIOC_CRH = (0x11111111 * Copy_u8Mode);
                }
                else
                {
                    /* code */
                }
            break;
        default   :
            break;
    }
}

void MGPIO_VoidSetPortValue(u8 Copy_u8PORT, u8 Copy_u8Position, u8 Copy_u8Value)
{
    switch(Copy_u8PORT)
    {
        case GPIOA:
            if (Copy_u8Position == GPIO_LOW)    
                {
                    GPIOA_ODR = (GPIOA_ODR & HIGH_PORTH) | Copy_u8Value;
                }
            else if (Copy_u8Position == GPIO_HIGH)    
                {
                    GPIOA_ODR = (GPIOA_ODR & HIGH_PORTL) | Copy_u8Value;
                }
            else
                {
                    /* code */
                }
            break;
        case GPIOB:
            if (Copy_u8Position == GPIO_LOW)    
                {
                    GPIOB_ODR = (GPIOB_ODR & HIGH_PORTH) | Copy_u8Value;
                }
            else if (Copy_u8Position == GPIO_HIGH)    
                {
                    GPIOB_ODR = (GPIOB_ODR & HIGH_PORTL) | Copy_u8Value;
                }
            else
                {
                    /* code */
                }
            break;
        case GPIOC:
            if (Copy_u8Position == GPIO_LOW)    
                {
                    GPIOC_ODR = (GPIOC_ODR & HIGH_PORTH) | Copy_u8Value;
                }
            else if (Copy_u8Position == GPIO_HIGH)    
                {
                    GPIOC_ODR = (GPIOC_ODR & HIGH_PORTL) | Copy_u8Value;
                }
            else
                {
                    /* code */
                }
            break;
        default :
            break;
    }
}

u16 MGPIO_u16GetPortValue(u8 Copy_u8PORT, u8 Copy_u8Position)
{
    u16 Local_u16Result = 0;
    switch (Copy_u8PORT)
    {
        case GPIOA:
        Local_u16Result = GPIOA_IDR;
            if (Copy_u8Position == GPIO_LOW)    
                {
                    Local_u16Result &=  HIGH_PORTL;
                }
            else if (Copy_u8Position == GPIO_HIGH)    
                {
                    Local_u16Result &= HIGH_PORTH;
                }
            else
                {
                    /* code */
                }
            break;
        case GPIOB:
        Local_u16Result = GPIOB_IDR;
            if (Copy_u8Position == GPIO_LOW)    
                {
                    Local_u16Result &=  HIGH_PORTL;
                }
            else if (Copy_u8Position == GPIO_HIGH)    
                {
                    Local_u16Result &= HIGH_PORTH;
                }
            else
                {
                    /* code */
                }
            break;
        case GPIOC:
        Local_u16Result = GPIOC_IDR;
            if (Copy_u8Position == GPIO_LOW)    
                {
                    Local_u16Result &=  HIGH_PORTL;
                }
            else if (Copy_u8Position == GPIO_HIGH)    
                {
                    Local_u16Result &= HIGH_PORTH;
                }
            else
                {
                    /* code */
                }
            break;
        default:
            break;
    }
}

