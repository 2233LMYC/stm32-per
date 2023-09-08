#ifndef __RGB_H__
#define __RGB_H__
 
/* 
 
TIM配置pwm,（针对F103C8T6，不分频，重载值89），总之将PWM配置出 800KHz 
TIM配置DMA定时器通道，内存到外设，mode=Normal,Data Width = Word, 勾选 Memory

可以从		http://zhongguose.com/  获得颜色十六进制代码


#include "ws2812b.h"

修改 ：：
	#define TIMx 								(htim2)	//定时器
	#define TIMx_CHANNEL_x 			(TIM_CHANNEL_1)//定时器通道
	#define Pixel_NUM 12  //LED数量宏定义，这里我使用一个LED，（单词pixel为像素的意思）

	RGB_BLACK(12);//关闭所有灯
	RGB_SetColor(1,BLUE);//设置 1  号灯为蓝色，以十进制颜色（0，0，255）
	Reset_Load();				//设置单个颜色需要重载
	RGB_SendArray();		//发送数据
	
	RGB_COLOR_ONE_HEX(2,"ef3473");//设置单个灯，以十六进制颜色代码
	Reset_Load();				//设置单个颜色需要重载
	RGB_SendArray();		//发送数据
	
	RGB_COLOR(5,WHITE);	//设置从 0—5号为白色
	RGB_COLOR_ALL_HEX(2,"ed2f6a");//设置0-2号为"ed2f6a"颜色
 
*/
 
 
#include "main.h"
 
/*这里是上文计算所得CCR的宏定义*/
#define CODE_1       (58)       //1码定时器计数次数
#define CODE_0       (25)       //0码定时器计数次数




/******************************************
						修改这里为实际参数
******************************************/
#define TIMx 								(htim2)	//定时器
#define TIMx_CHANNEL_x 			(TIM_CHANNEL_1)//定时器通道
#define Pixel_NUM 12  //LED数量宏定义，这里我使用一个LED，（单词pixel为像素的意思）

 
 
 
/*建立一个定义单个LED三原色值大小的结构体*/
typedef struct
{
	uint8_t R;
	uint8_t G;
	uint8_t B;
}RGB_Color_TypeDef;
 
/*Some Static Colors------------------------------*/
extern const RGB_Color_TypeDef RED;   //显示红色RGB数据
extern const RGB_Color_TypeDef GREEN;
extern const RGB_Color_TypeDef BLUE;
extern const RGB_Color_TypeDef BLACK;
extern const RGB_Color_TypeDef WHITE;

 
void RGB_SetColor(uint8_t LedId,RGB_Color_TypeDef Color);//给一个LED装载24个颜色数据码（0码和1码）
void Reset_Load(void); //该函数用于将数组最后24个数据变为0，代表RESET_code
void RGB_SendArray(void);          //发送最终数组
void RGB_COLOR(uint16_t Pixel_Len ,RGB_Color_TypeDef Color);
void RGB_COLOR_ALL_HEX(uint16_t Pixel_Len,const char *hexColor);
void RGB_COLOR_ONE_HEX(uint8_t LedId,const char *hexColor);
void RGB_BLACK(uint16_t Pixel_Len);
 
 
#endif