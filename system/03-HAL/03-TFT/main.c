#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"

#include "TFT_interface.h"

void main(void)
{
    /* Rcc Initilaization */
    RCC_voidInitSysClock();
    RCC_voidEnableClock(RCC_APB2, 2);   /* GPIOA */
    RCC_voidEnableClock(RCC_APB2, 12);   /* SPI1 */

    /* Pin Initializations */
    MGPIO_VoidSetPinDirection(GPIOA, 1, 0b0010);   /* A0    */
    MGPIO_VoidSetPinDirection(GPIOA, 2, 0b0010);   /* RST   */
    MGPIO_VoidSetPinDirection(GPIOA, 5, 0b1001);   /* CLK   */
    MGPIO_VoidSetPinDirection(GPIOA, 7, 0b1001);   /* MOSI  */

    /* Init STK */
    MSTK_voidInit();

    /* Init SPI1 */
    MSPI1_voidInit();
    
    /* Init TFT */
    HTFT_voidInit();

    /* Display Image */
//    HTFT_voidDisplayImage(image); /* image is arr inlude image pixels */
    HTFT_voidFillColor(0xffff);
    HTFT_voidDrawRect(0, 10, 0, 30, 0x0000);

    while (1)
    {
        
    }
    

}

