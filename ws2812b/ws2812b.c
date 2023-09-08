#include "ws2812b.h"
#include "tim.h"

 
/*Some Static Colors------------------------------*/
const RGB_Color_TypeDef RED      = {255,0,0};   //显示红色RGB数据
const RGB_Color_TypeDef GREEN    = {0,255,0};
const RGB_Color_TypeDef BLUE     = {0,0,255};
const RGB_Color_TypeDef BLACK    = {0,0,0};
const RGB_Color_TypeDef WHITE    = {255,255,255};

 
/*二维数组存放最终PWM输出数组，每一行24个
数据代表一个LED，最后一行24个0代表RESET码*/
uint32_t Pixel_Buf[Pixel_NUM+1][24];       
 
/*
功能：设定单个RGB LED的颜色，把结构体中RGB的24BIT转换为0码和1码
参数：LedId为LED序号，Color：定义的颜色结构体
*/
void RGB_SetColor(uint8_t LedId,RGB_Color_TypeDef Color)
{
	uint8_t i; 
	if(LedId > Pixel_NUM)return; //avoid overflow 防止写入ID大于LED总数
	
	for(i=0;i<8;i++) Pixel_Buf[LedId][i]   = ( (Color.G & (1 << (7 -i)))? (CODE_1):CODE_0 );//数组某一行0~7转化存放G
	for(i=8;i<16;i++) Pixel_Buf[LedId][i]  = ( (Color.R & (1 << (15-i)))? (CODE_1):CODE_0 );//数组某一行8~15转化存放R
	for(i=16;i<24;i++) Pixel_Buf[LedId][i] = ( (Color.B & (1 << (23-i)))? (CODE_1):CODE_0 );//数组某一行16~23转化存放B
	
}
 
/*
功能：最后一行装在24个0，输出24个周期占空比为0的PWM波，作为最后reset延时，这里总时长为24*1.2=30us > 24us(要求大于24us)
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
功能：发送数组
参数：(&htim1)定时器1，(TIM_CHANNEL_1)通道1，((uint32_t *)Pixel_Buf)待发送数组，
			(Pixel_NUM+1)*24)发送个数，数组行列相乘
*/
void RGB_SendArray(void)
{
	HAL_TIM_PWM_Start_DMA(&TIMx, TIMx_CHANNEL_x, (uint32_t *)Pixel_Buf,(Pixel_NUM+1)*24);
}
 
/*
功能：显示颜色（直接颜色数组）
参数：Pixel_Len为显示LED个数
*/
void RGB_COLOR(uint16_t Pixel_Len ,RGB_Color_TypeDef Color)
{
	uint16_t i;
	for(i=0;i<Pixel_Len;i++)//给对应个数LED写入红色
	{
		RGB_SetColor(i,Color);
	}
	Reset_Load();
	RGB_SendArray();
}
 

/*
十六进制转十进制，十六进制颜色代码转换为RGB颜色分量
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
功能：显示颜色（HEX）
参数：Pixel_Len为显示LED个数
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
功能：显示颜色（HEX）
参数：LedId 为LED
*/
void RGB_COLOR_ONE_HEX(uint8_t LedId,const char *hexColor)
{
	RGB_Color_TypeDef Color = (RGB_Color_TypeDef)hexToRGB(hexColor);
	RGB_SetColor(LedId,Color);
	Reset_Load();
	RGB_SendArray();
}

/*
功能：关灯
参数：Pixel_Len为显示LED个数
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
 



