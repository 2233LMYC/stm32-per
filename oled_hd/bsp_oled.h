/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : bsp_oled.h
  * @brief          : Header for bsp_oled.c file.
  ******************************************************************************
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_OLED_H
#define __BSP_OLED_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "i2c.h"
 
#define u8 uint8_t
#define u32 uint32_t	

/*! -------------------------------------------------------------------------- */
/*! Public functions list */
/** 
* ʹ���ֲ᣺
		OLED_Init();
		// OLED_Clear();
		OLED_ShowStr(0, 0, (unsigned char* )"hello world", 2);
		
    һЩʹ������
		OLED_ShowStr(0, 0, "hello world", 2);//��ʾ�ַ���
		
		** ʹ��������������TextSize��СΪ 1 ʱ�� ������ʾ8���ַ�
			 ÿһ���ַ�������ʾ21���ַ�
		**
		
	  OLED_ShowStr(0, 2, "hello world", 1);//��ʾ�ַ���
	  OLED_ShowCN_STR(0, 4 , 0 , 8);
		
		sprintf(num_temp_buffer,"show num:%0.2f",num);
		OLED_ShowStr(0, 6, num_temp_buffer, 2);//��ʾ�ַ���
		
		OLED_Clear();  // ����
		OLED_DrawBMP(0,0,128,7,BMP2);  // ��ʾͼƬ
		
		*/
#define OLED_CMD  0	//д����
#define OLED_DATA 1	//д����

#define OLED0561_ADD	0x78  /* OLED��I2C��ַ����ֹ�޸ģ�*/
#define COM				0x00  /* OLED ָ���ֹ�޸ģ�*/
#define DAT 			0x40  /* OLED ���ݣ���ֹ�޸ģ�*/

void OLED_WR_Byte(unsigned char dat,unsigned char cmd);
void OLED_DisplayTurn(unsigned char i);  /* ��Ļ��ת180��*/

void WriteCmd(unsigned char I2C_Command);/* д���� */
void WriteDat(unsigned char I2C_Data);   /* д���� */
void OLED_Init(void);                     /* ��ʼ�� */
void OLED_SetPos(unsigned char x, unsigned char y);
void OLED_Fill(unsigned char fill_Data); /* ȫ����� */
void OLED_Clear(void);
void OLED_ON(void);
void OLED_OFF(void);
void OLED_ShowStr(unsigned char x, unsigned char y, unsigned char ch[], unsigned char TextSize);  /* ��ʾ�ַ��� */
void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N);                               /* ��ʾ���� */
void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]);/* ��ʾͼƬ��ȡģ���������У��棬�������������*/

void OLED_ShowCN_STR(u8 x , u8 y , u8 begin , u8 num);  /* �Լ�д����������ַ��� */

void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 Char_Size);
u32 oled_pow(u8 m,u8 n);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size2);   /* size2(16|12) */

#ifdef __cplusplus
}
#endif

#endif /* __BSP_OLED_H */

