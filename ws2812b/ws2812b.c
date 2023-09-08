#include "ws2812b.h"
#include "tim.h"

 
/*Some Static Colors------------------------------*/
const RGB_Color_TypeDef RED      = {255,0,0};   //��ʾ��ɫRGB����
const RGB_Color_TypeDef GREEN    = {0,255,0};
const RGB_Color_TypeDef BLUE     = {0,0,255};
const RGB_Color_TypeDef BLACK    = {0,0,0};
const RGB_Color_TypeDef WHITE    = {255,255,255};

 
/*��ά����������PWM������飬ÿһ��24��
���ݴ���һ��LED�����һ��24��0����RESET��*/
uint32_t Pixel_Buf[Pixel_NUM+1][24];       
 
/*
���ܣ��趨����RGB LED����ɫ���ѽṹ����RGB��24BITת��Ϊ0���1��
������LedIdΪLED��ţ�Color���������ɫ�ṹ��
*/
void RGB_SetColor(uint8_t LedId,RGB_Color_TypeDef Color)
{
	uint8_t i; 
	if(LedId > Pixel_NUM)return; //avoid overflow ��ֹд��ID����LED����
	
	for(i=0;i<8;i++) Pixel_Buf[LedId][i]   = ( (Color.G & (1 << (7 -i)))? (CODE_1):CODE_0 );//����ĳһ��0~7ת�����G
	for(i=8;i<16;i++) Pixel_Buf[LedId][i]  = ( (Color.R & (1 << (15-i)))? (CODE_1):CODE_0 );//����ĳһ��8~15ת�����R
	for(i=16;i<24;i++) Pixel_Buf[LedId][i] = ( (Color.B & (1 << (23-i)))? (CODE_1):CODE_0 );//����ĳһ��16~23ת�����B
	
}
 
/*
���ܣ����һ��װ��24��0�����24������ռ�ձ�Ϊ0��PWM������Ϊ���reset��ʱ��������ʱ��Ϊ24*1.2=30us > 24us(Ҫ�����24us)
*/
void Reset_Load(void)
{
	uint8_t i;
	for(i=0;i<24;i++)
	{
		Pixel_Buf[Pixel_NUM][i] = 0;
	}
}
 
/*
���ܣ���������
������(&htim1)��ʱ��1��(TIM_CHANNEL_1)ͨ��1��((uint32_t *)Pixel_Buf)���������飬
			(Pixel_NUM+1)*24)���͸����������������
*/
void RGB_SendArray(void)
{
	HAL_TIM_PWM_Start_DMA(&TIMx, TIMx_CHANNEL_x, (uint32_t *)Pixel_Buf,(Pixel_NUM+1)*24);
}
 
/*
���ܣ���ʾ��ɫ��ֱ����ɫ���飩
������Pixel_LenΪ��ʾLED����
*/
void RGB_COLOR(uint16_t Pixel_Len ,RGB_Color_TypeDef Color)
{
	uint16_t i;
	for(i=0;i<Pixel_Len;i++)//����Ӧ����LEDд���ɫ
	{
		RGB_SetColor(i,Color);
	}
	Reset_Load();
	RGB_SendArray();
}
 

/*
ʮ������תʮ���ƣ�ʮ��������ɫ����ת��ΪRGB��ɫ����
*/
RGB_Color_TypeDef hexToRGB(const char *hexColor) 
{
    RGB_Color_TypeDef color;

    uint32_t hexValue = 0;
    for (int i = 0; i < 6; i++) {
        char c = hexColor[i];
        uint8_t digit = 0;

        if (c >= '0' && c <= '9') {
            digit = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            digit = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            digit = c - 'a' + 10;
        }

        hexValue = (hexValue << 4) | digit;
    }
		
		color.R = (uint8_t)(hexValue >> 16);
    color.G = (uint8_t)(hexValue >> 8);
    color.B = (uint8_t)hexValue;
	
    return color;
}


/*
���ܣ���ʾ��ɫ��HEX��
������Pixel_LenΪ��ʾLED����
*/
void RGB_COLOR_ALL_HEX(uint16_t Pixel_Len,const char *hexColor)
{
	uint16_t i;
	RGB_Color_TypeDef Color = (RGB_Color_TypeDef)hexToRGB(hexColor);
	 
	for(i=0;i<Pixel_Len;i++)
	{
		RGB_SetColor(i,Color);
	}
	Reset_Load();
	RGB_SendArray();
}
 
/*
���ܣ���ʾ��ɫ��HEX��
������LedId ΪLED
*/
void RGB_COLOR_ONE_HEX(uint8_t LedId,const char *hexColor)
{
	RGB_Color_TypeDef Color = (RGB_Color_TypeDef)hexToRGB(hexColor);
	RGB_SetColor(LedId,Color);
	Reset_Load();
	RGB_SendArray();
}

/*
���ܣ��ص�
������Pixel_LenΪ��ʾLED����
*/
void RGB_BLACK(uint16_t Pixel_Len)
{
	uint16_t i;
	for(i=0;i<Pixel_Len;i++)
	{
		RGB_SetColor(i,BLACK);
	}
	Reset_Load();
	RGB_SendArray();
}
 



