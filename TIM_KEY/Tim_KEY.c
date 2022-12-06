
#include "Tim_KEY.h"
#include "tim.h"

KEYS key[key_num+1];

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	key[1].key_sta = KEY1;
	key[2].key_sta = KEY2;
	key[3].key_sta = KEY3;
	key[4].key_sta = KEY4;
	key[5].key_sta = KEY5;
	
	if(htim->Instance == KEY_TIM)
	{
		int i = 1;

		for(i=1;i<key_num;i++)
		{
			switch (key[i].stap)
			{
				case 0:
				{
					if(key[i].stap==0) 
					{
						key[i].stap=1;
						key[i].key_time=0;
					}
				}
				break;
				case 1:
				{
					if(key[i].key_sta==0)
					{
						key[i].stap=2;
					}
					else key[i].stap=0;
				}
				break;
				case 2:
				{
					if(key[i].key_sta==1)
					{
						key[i].stap=0;					
						if(key[i].key_time<20) key[i].short_flag=1;
					}
					else 
					{
						key[i].key_time++;
						if(key[i].key_time>20)  key[i].long_flag=1;
					}
				}
				break;	
			}
		}
	}
		
}
