/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 23 SEP 2023         */
/* Version      : V01                 */
/**************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

typedef struct
{
    volatile u32 CTRL ;
    volatile u32 LOAD ;
    volatile u32 VAL  ;
    volatile u32 CALIB;
}SYSTICK;

#define MSTK    ((volatile SYSTICK*)0xE000E010)


#endif