/**************************************/
/* Author       : Ahmed Emad          */
/* Date         : 5 OCT 2023          */
/* Version      : V01                 */
/**************************************/
#ifndef WIFI_INTERFACE_H
#define WIFI_INTERFACE_H

void ESP_voidInit(void);
u8 ESP_u8ValidateCmd(void);

void ESP_voidConnectToWifi(u8 * Copy_u8SSID, u8 * Copy_u8Password);
void ESP_voidConnectToSrvTcp(u8 * Copy_u8Domain, u8 * Copy_u8Port);
void ESP_voidSendHttpReq(u8 * Copy_u8Key, u8 * Copy_u8Data, u8 * Copy_u8Length);
u8 ESP_u8ReceiveHttpReq(u8 * Copy_u8ChannelID, u8 * Copy_u8Length);
void ESP_voidClearBuffer(void);


#endif
