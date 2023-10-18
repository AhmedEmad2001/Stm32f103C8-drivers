/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 5 OCT 2023          */
/* Version      : V01                 */
/**************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"

#include "WIFI_interface.h"
#include "WIFI_private.h"
#include "WIFI_config.h"

u8 volatile Iterator = 0;
u8 volatile DataCome[200];

void MUSART_CallBack(void)
{
    /* Receive ESP Response */
    DataCome[Iterator] = MUSART_u8Receive();
    /* ------------- */
    Iterator ++;
    MUSART1_voidClearFlags();
}

void ESP_voidInit(void)
{
    /* Set USART1 CallBack To Receive The Response of ESP */
    MUSART_voidSetCallBack(MUSART_CallBack);

    /* Sending AT Command To Check That ESP is working or not */\
    MUSART_voidSendStringSynch((u8 *)"AT\r\n");

    _delay_ms(3000);

    /* Clear ESP Buffer */
    ESP_voidClearBuffer();

    MUSART_voidSendStringSynch((u8 *)"AT+CWMODE=3\r\n");
    _delay_ms(3000);

    ESP_voidClearBuffer();

    MUSART_voidSendStringSynch((u8 *)"AT+CIPMODE=0\r\n");
    _delay_ms(3000);

}

/*
void ESP_voidInit(void)
{
    u8 Local_u8Result;

    while (Local_u8Result == 1)
    {
       */ /* Stop ECHO */ /*
        MUSART_voidTransmit("ATE0\r\n");
        Local_u8Result = ESPValidateCmd();     
    }
    Local_u8Result = 0;

    while (Local_u8Result == 1)
    {
       */ /* Set station mode*/ /*
        MUSART_voidTransmit("AT+CWMODE=1\r\n");
        Local_u8Result = ESPValidateCmd();     
    }
    Local_u8Result = 0;
}
*/

u8 ESP_u8ValidateCmd(void)
{
    u8 Local_u8Response [100] = {0};
    u8 Local_u8Result;
    u8 i = 0;
    u8 Local_u8Dummy = 0;
    while (Local_u8Dummy != 255)
    {
        Local_u8Dummy = MUSART_u8Receive();
        Local_u8Response[i] = Local_u8Dummy;
        i++;
    }
    /* Check if OK */
    if (Local_u8Response[0] == 'O' && Local_u8Response[1] == 'K')
    {
        Local_u8Result = 1;
    }
    return Local_u8Result;
}

void ESP_voidConnectToWifi(u8 * Copy_u8SSID, u8 * Copy_u8Password)
{
    ESP_voidClearBuffer();

    
    MUSART_voidSendStringSynch((u8 *) "AT+CWJAP=\"");
    MUSART_voidSendStringSynch((u8 *) Copy_u8SSID);
    MUSART_voidSendStringSynch((u8 *) "\",\"");
    MUSART_voidSendStringSynch((u8 *) Copy_u8Password);
    MUSART_voidSendStringSynch((u8 *) "\"\r\n");
    _delay_ms(8000);
}

void ESP_voidConnectToSrvTcp(u8 * Copy_u8Domain, u8 * Copy_u8Port)
{
    ESP_voidClearBuffer();

    MUSART_voidSendStringSynch((u8 *) "AT+CIPSTART=\"TCP\",\"");
    MUSART_voidSendStringSynch((u8 *) Copy_u8Domain);
    MUSART_voidSendStringSynch((u8 *) "\",");
    MUSART_voidSendStringSynch((u8 *) Copy_u8Port);
    MUSART_voidSendStringSynch((u8 *) "\r\n");
    _delay_ms(2000);

}

void ESP_voidSendHttpReq(u8 * Copy_u8Key, u8 * Copy_u8Data, u8 * Copy_u8Length)
{
    ESP_voidClearBuffer();
    MUSART_voidSendStringSynch((u8 *) "AT+CIPSEND=");
    MUSART_voidSendStringSynch((u8 *) Copy_u8Length);
    MUSART_voidSendStringSynch((u8 *) "\r\n");
    _delay_ms(4000);

    ESP_voidClearBuffer();

    MUSART_voidSendStringSynch((u8 *) "GET /update?api_Key=");
    MUSART_voidSendStringSynch((u8 *) Copy_u8Key);
    MUSART_voidSendStringSynch((u8 *) "&field1=");
    MUSART_voidSendStringSynch((u8 *) Copy_u8Data);
    MUSART_voidSendStringSynch((u8 *) "\r\n");
    _delay_ms(20000);

}

u8 ESP_u8ReceiveHttpReq(u8 * Copy_u8ChannelID, u8 * Copy_u8Length)
{
    ESP_voidClearBuffer();

    MUSART_voidSendStringSynch((u8 *) "AT+CIPSEND=");
    MUSART_voidSendStringSynch((u8 *) Copy_u8Length);
    MUSART_voidSendStringSynch((u8 *) "\r\n");
    _delay_ms(4000);
    
    ESP_voidClearBuffer();

    MUSART_voidSendStringSynch((u8 *) "GET http://");
    MUSART_voidSendStringSynch((u8 *) Copy_u8ChannelID);
    MUSART_voidSendStringSynch((u8 *) "/value.txt\r\n");
    _delay_ms(20000);
    
    ESP_voidConnectToSrvTcp((u8 *) "162.253.155.226", (u8 *) "80");

    /* For yrabiot3.freevar.com (Value Array Index) */
    return DataCome[82];
}

void ESP_voidClearBuffer(void)
{
    u8 Local_u8Iterator = 0;
    Iterator = 0;
    for (Local_u8Iterator = 0; Local_u8Iterator < 150; Local_u8Iterator++)
    {
        DataCome[Local_u8Iterator] = 0;
    }
}


