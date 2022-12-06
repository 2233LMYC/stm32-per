#ifndef _TIM_KEY_H_
#define _TIM_KEY_H_

#include "main.h"


#define KEY_TIM 	TIM4

#define key_num   5

typedef struct keys
{
	uint8_t  stap;
	uint8_t key_sta;
	uint8_t short_flag;
	uint8_t long_flag;
	uint16_t  key_time;
}KEYS;

extern KEYS key[6];

#define KEY5 (HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_7))
#define KEY4 (HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6))
#define KEY3 (HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5))
#define KEY2 (HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_4))
#define KEY1 (HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_3))





#endif

