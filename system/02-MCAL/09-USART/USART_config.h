/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 5 OCT 2023          */
/* Version      : V02                 */
/**************************************/
#ifndef USART_CONFIG_H
#define USART_CONFIG_H

/* System Clock */
#define F_CPU                       8000000UL

/* USART1 Configuration */      
#define USART1_STATUS               USART1_ENABLE
#define USART1_BAUD_RATE            (u32)9600

#define USART_WORD_LENGTH           _8BIT_WORD_LENGTH
#define USART1_PARITY               PARITY_DISABLE
#define USART1_INTERRUPT            INT_DISABLE

#define USART1_TRANSMITTER          TRANSMITTER_ENABLE
#define USART1_RECEIVER             RECEIVER_ENABLE

#define USART1_STOP_BITS            ONE_STOP_BIT


#endif
