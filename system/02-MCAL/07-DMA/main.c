/* main for this project */

int main (void)
{
    u32 Arr1[1000] = {0};
    u32 Arr2[1000] ;
    u32 Arr3[1000] = {0};
    u32 Arr4[1000] ;

    MRCC_voidSyatemClockInit();
    MRCC_voidEnablePeripheralClock(RCC_AHB, 0);
    MDMA_voidChannelInit();

    MNVIC_voidInterruptEnable(11);

    MDMA_voidChannelStart(Arr1, Arr2, 1000);
    
    for(u16 i = 0 ; i < 1000 ; i++)
    {
        Arr4[i] = Arr3[i];
    }

    while(1)
    {

    }
    return 0;

}
/*
void DMA1_Channel1_IRQHandler(void)
{
    /* Clear GIF */
//    DMA-> IFCR = 1 << 0;
    /* Clear TC */
//    DMA-> IFCR = 1 << 1;
//}

