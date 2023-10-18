/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 21 SEP 2023         */
/* Version      : V01                 */
/**************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define NVIC_ISER0          *((u32*)0xE000E100)     /* Enable External interrupts from 0  to 31 */
#define NVIC_ISER1          *((u32*)0xE000E104)     /* Enable External interrupts from 32 to 63 */

#define NVIC_ICER0          *((u32*)0xE000E180)
#define NVIC_ICER1          *((u32*)0xE000E184)

#define NVIC_ISPR0          *((u32*)0xE000E200)
#define NVIC_ISPR1          *((u32*)0xE000E204)

#define NVIC_ICPR0          *((u32*)0xE000E280)
#define NVIC_ICPR1          *((u32*)0xE000E284)

#define NVIC_IABR0          *((volatile u32*)0xE000E300)    /* because this read only reg so we write volatile */
#define NVIC_IABR1          *((volatile u32*)0xE000E304)    /* because this read only reg so we write volatile */

#define NVIC_IPR            ((volatile u8*)0xE000E400)  /* pointer for choose periorty */

/* check it*/
#define SCB_CPUID           *((volatile u32*)0xE000ED00)
#define SCB_ICSR            *((volatile u32*)0xE000ED04)
#define SCB_VTOR            *((volatile u32*)0xE000ED08)

#define SCB_AIRCR           *((volatile u32*)0xE000ED0C)

#define SCB_SCR             *((volatile u32*)0xE000ED10)
#define SCB_CCR             *((volatile u32*)0xE000ED14)
#define SCB_SHPR1           *((volatile u32*)0xE000ED18)
#define SCB_SHPR2           *((volatile u32*)0xE000ED1C)
#define SCB_SHPR3           *((volatile u32*)0xE000ED20)
#define SCB_SHCRS           *((volatile u32*)0xE000ED24)
#define SCB_CFSR            *((volatile u32*)0xE000ED28)
#define SCB_HFSR            *((volatile u32*)0xE000ED2C)
#define SCB_MMAR            *((volatile u32*)0xE000ED34)
#define SCB_BFAR            *((volatile u32*)0xE000ED38)


#define MNVIC_GROUP_4_SUB_0     0x05FA0300
#define MNVIC_GROUP_3_SUB_1     0x05FA0400
#define MNVIC_GROUP_2_SUB_2     0x05FA0500
#define MNVIC_GROUP_1_SUB_3     0x05FA0600
#define MNVIC_GROUP_0_SUB_4     0x05FA0700

#define NO_SUB_PERIORITY     0

#define PEND_SV             -6
#define SYSTIK              -5
#define SV_CALL             -4
#define MEMORY_MANAGE       -3
#define BUS_FAULT           -2
#define USAGE_FAULT         -1

#endif