#ifndef _IIC_H
#define _IIC_H

#include <inttypes.h>

#define IIC_WR	0		/* Ð´¿ØÖÆbit */
#define IIC_RD	1		/* ¶Á¿ØÖÆbit */


#define MUL  1


#ifdef MUL
/********* IIC 1 **************/
void IIC_Start_1(void);
void IIC_Stop_1(void);
void IIC_Send_Byte_1(uint8_t _ucByte);
uint8_t IIC_Read_Byte_1(void);
uint8_t IIC_Wait_Ack_1(void);
void IIC_Ack_1(void);
void IIC_NAck_1(void);
uint8_t IIC_CheckDevice_1(uint8_t _Address);
void IIC_GPIO_Init_1(void);

/********* IIC 2 **************/
void IIC_Start_2(void);
void IIC_Stop_2(void);
void IIC_Send_Byte_2(uint8_t _ucByte);
uint8_t IIC_Read_Byte_2(void);
uint8_t IIC_Wait_Ack_2(void);
void IIC_Ack_2(void);
void IIC_NAck_2(void);
uint8_t IIC_CheckDevice_2(uint8_t _Address);
void IIC_GPIO_Init_2(void);

/********* IIC 3 **************/
void IIC_Start_3(void);
void IIC_Stop_3(void);
void IIC_Send_Byte_3(uint8_t _ucByte);
uint8_t IIC_Read_Byte_3(void);
uint8_t IIC_Wait_Ack_3(void);
void IIC_Ack_3(void);
void IIC_NAck_3(void);
uint8_t IIC_CheckDevice_3(uint8_t _Address);
void IIC_GPIO_Init_3(void);

/********* IIC 4 **************/
void IIC_Start_4(void);
void IIC_Stop_4(void);
void IIC_Send_Byte_4(uint8_t _ucByte);
uint8_t IIC_Read_Byte_4(void);
uint8_t IIC_Wait_Ack_4(void);
void IIC_Ack_4(void);
void IIC_NAck_4(void);
uint8_t IIC_CheckDevice_4(uint8_t _Address);
void IIC_GPIO_Init_4(void);

///********* IIC 5 **************/
//void IIC_Start_5(void);
//void IIC_Stop_5(void);
//void IIC_Send_Byte_5(uint8_t _ucByte);
//uint8_t IIC_Read_Byte_5(void);
//uint8_t IIC_Wait_Ack_5(void);
//void IIC_Ack_5(void);
//void IIC_NAck_5(void);
//uint8_t IIC_CheckDevice_5(uint8_t _Address);
//void IIC_GPIO_Init_5(void);

#else

void IIC_Start_1(void);
void IIC_Stop_1(void);
void IIC_Send_Byte_1(uint8_t _ucByte);
uint8_t IIC_Read_Byte_1(void);
uint8_t IIC_Wait_Ack_1(void);
void IIC_Ack_1(void);
void IIC_NAck_1(void);
uint8_t IIC_CheckDevice_1(uint8_t _Address);
void IIC_GPIO_Init_1(void);

#endif

#endif
