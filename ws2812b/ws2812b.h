#ifndef __RGB_H__
#define __RGB_H__
 
/* 
 
TIM����pwm,�����F103C8T6������Ƶ������ֵ89������֮��PWM���ó� 800KHz 
TIM����DMA��ʱ��ͨ�����ڴ浽���裬mode=Normal,Data Width = Word, ��ѡ Memory

���Դ�		http://zhongguose.com/  �����ɫʮ�����ƴ���


#include "ws2812b.h"

�޸� ����
	#define TIMx 								(htim2)	//��ʱ��
	#define TIMx_CHANNEL_x 			(TIM_CHANNEL_1)//��ʱ��ͨ��
	#define Pixel_NUM 12  //LED�����궨�壬������ʹ��һ��LED��������pixelΪ���ص���˼��

	RGB_BLACK(12);//�ر����е�
	RGB_SetColor(1,BLUE);//���� 1  �ŵ�Ϊ��ɫ����ʮ������ɫ��0��0��255��
	Reset_Load();				//���õ�����ɫ��Ҫ����
	RGB_SendArray();		//��������
	
	RGB_COLOR_ONE_HEX(2,"ef3473");//���õ����ƣ���ʮ��������ɫ����
	Reset_Load();				//���õ�����ɫ��Ҫ����
	RGB_SendArray();		//��������
	
	RGB_COLOR(5,WHITE);	//���ô� 0��5��Ϊ��ɫ
	RGB_COLOR_ALL_HEX(2,"ed2f6a");//����0-2��Ϊ"ed2f6a"��ɫ
 
*/
 
 
#include "main.h"
 
/*���������ļ�������CCR�ĺ궨��*/
#define CODE_1       (58)       //1�붨ʱ����������
#define CODE_0       (25)       //0�붨ʱ����������




/******************************************
						�޸�����Ϊʵ�ʲ���
******************************************/
#define TIMx 								(htim2)	//��ʱ��
#define TIMx_CHANNEL_x 			(TIM_CHANNEL_1)//��ʱ��ͨ��
#define Pixel_NUM 12  //LED�����궨�壬������ʹ��һ��LED��������pixelΪ���ص���˼��

 
 
 
/*����һ�����嵥��LED��ԭɫֵ��С�Ľṹ��*/
typedef struct
{
	uint8_t R;
	uint8_t G;
	uint8_t B;
}RGB_Color_TypeDef;
 
/*Some Static Colors------------------------------*/
extern const RGB_Color_TypeDef RED;   //��ʾ��ɫRGB����
extern const RGB_Color_TypeDef GREEN;
extern const RGB_Color_TypeDef BLUE;
extern const RGB_Color_TypeDef BLACK;
extern const RGB_Color_TypeDef WHITE;

 
void RGB_SetColor(uint8_t LedId,RGB_Color_TypeDef Color);//��һ��LEDװ��24����ɫ�����루0���1�룩
void Reset_Load(void); //�ú������ڽ��������24�����ݱ�Ϊ0������RESET_code
void RGB_SendArray(void);          //������������
void RGB_COLOR(uint16_t Pixel_Len ,RGB_Color_TypeDef Color);
void RGB_COLOR_ALL_HEX(uint16_t Pixel_Len,const char *hexColor);
void RGB_COLOR_ONE_HEX(uint8_t LedId,const char *hexColor);
void RGB_BLACK(uint16_t Pixel_Len);
 
 
#endif