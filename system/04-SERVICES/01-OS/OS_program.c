/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 24 SEP 2023         */
/* Version      : V01                 */
/**************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

#define NULL    (void *)0

volatile u16 TickCount = 0;

/* Array of Tasks       " Array of Structure "  */
static Task OS_Tasks[NUMBER_OF_TASKES] = { NULL };

void SOS_voidCreateTask(u8 Copy_u8Periorty, u16 Copy_u16Priodicity, void(*Copy_Ptr)(void), u8 Copy_u8FirstDelay)
{
    if(OS_Tasks[Copy_u8Periorty].TaskHandler == NULL)
    {
        OS_Tasks[Copy_u8Periorty].Priodicity    = Copy_u16Priodicity;
        OS_Tasks[Copy_u8Periorty].TaskHandler   = Copy_Ptr;
        /* check it */  
        OS_Tasks[Copy_u8Periorty].FirstDelay    = Copy_u8FirstDelay;
        OS_Tasks[Copy_u8Periorty].State         = TASK_READY;
    }
    else
    {
        /* Do Nothing */
    } 
}
void SOS_voidStart(void)
{
    /* Intialization */
    MSTK_voidInit();
    /* Tick => 1 mSec */
    /* HSE 8MHZ/8 => 1000 Micro Sec ==> 1 mSec */
    MSTK_voidSetIntervalPeriodic(TICK_TIME, OS_Scheduler);

}

/*ordering tasks (told which task should do now) */
/*
static void Scheduler(void)
 { 
    for (u8 i = 0; i < NUMBER_OF_TASKES ; i++)
    {
        if (TickCount % OS_Tasks[i].Priodicity == 0)
        {
            OS_Tasks[i].TaskHandler();
        }   
    }
    TickCount++;
}
*/

static void OS_Scheduler(void)
 { 
    for (u8 i = 0; i < NUMBER_OF_TASKES ; i++)
    {
        if ((OS_Tasks[i].TaskHandler != NULL) && (OS_Tasks[i].State == TASK_READY))
        {
            if(OS_Tasks[i].FirstDelay == 0)
            {   
                OS_Tasks[i].FirstDelay = OS_Tasks[i].Priodicity - 1 ;
                OS_Tasks[i].TaskHandler();   
            }   
            else
            {
                OS_Tasks[i].FirstDelay--;
            }
        }
        else
        {
            /* Do No Thing */
        }   
    }
}

/* check it */
void SOS_voidSuspendTask(u8 Copy_u8TaskID)
{
    OS_Tasks[Copy_u8TaskID].State = TASK_SUSPEND;
}
void SOS_voidResumeTask(u8 Copy_u8TaskID)
{
    OS_Tasks[Copy_u8TaskID].State = TASK_READY;
}
void SOS_voidDeleteTask(u8 Copy_u8TaskID)
{
    OS_Tasks[Copy_u8TaskID].TaskHandler = NULL;
}

