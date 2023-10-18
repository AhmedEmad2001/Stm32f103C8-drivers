/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 4 OCT 2023          */
/* Version      : V01                 */
/**************************************/
#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

void HTFT_voidInit(void);
void HTFT_voidDisplayImage(const u16* Copy_u16Image);
void HTFT_voidFillColor(u16 Copy_u16Color);
void HTFT_voidDrawRect(u8 Copy_u8X1, u8 Copy_u8X2,u8 Copy_u8Y1, u8 Copy_u8Y2, u16 Copy_u16Color);

#endif
