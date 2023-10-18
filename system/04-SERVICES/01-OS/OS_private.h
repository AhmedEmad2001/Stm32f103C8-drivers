/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 24 SEP 2023         */
/* Version      : V01                 */
/**************************************/
#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H

typedef struct
{
    u16 Priodicity      ;
    void (*TaskHandler)(void)  ;
    u8 FirstDelay;
    u8 State;
}Task;

/* Check it */
#define TASK_READY       0
#define TASK_SUSPEND     1

static void OS_Scheduler(void);


#endif
