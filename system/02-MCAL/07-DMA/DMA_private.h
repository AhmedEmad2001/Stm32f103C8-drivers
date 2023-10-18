/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 30 SEP 2023         */
/* Version      : V01                 */
/**************************************/
#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

typedef struct
{
    volatile u32 CCR;       //0x000
    volatile u32 CNDTR;     //0x004
    volatile u32 CPAR;      //0x008
    volatile u32 CMAR;      //0x00C
    volatile u32 Reserved;  //0x010
}DMA_Channel;

typedef struct
{
    volatile u32 ISR;       //0x000
    volatile u32 IFCR;      //0x004
    DMA_Channel Channel[7]; //0x008
}DMA_t;

#define  DMA   ((volatile DMA_t*)0x40020000);


#endif