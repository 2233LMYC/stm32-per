#include "NIMING.h"
#include "main.h"
#include "usart.h"

uint8_t data_to_send[100];

//F1帧发送4个uint16类型的数据
void ANO_DT_Send_F1(uint16_t _a,uint16_t _b,uint16_t _c,uint16_t _d)
{
	uint8_t _cnt = 0;//计数值
	uint8_t sumcheck = 0;//和校验
	uint8_t addcheck = 0;//附加和校验
	uint8_t i = 0;
	
	data_to_send[_cnt++] = 0xAA;//帧头
	data_to_send[_cnt++] = 0xFF;//目标地址
	data_to_send[_cnt++] = 0xF1;//功能码
	data_to_send[_cnt++] = 8;//数据长度
	
	//单片机为小端，即低地址存低位，匿名上位要求先发低位，所以先放低地址
	data_to_send[_cnt++] = BYTE0(_a);
	data_to_send[_cnt++] = BYTE1(_a);
	
	data_to_send[_cnt++] = BYTE0(_b);
	data_to_send[_cnt++] = BYTE1(_b);
	
	data_to_send[_cnt++] = BYTE0(_c);
	data_to_send[_cnt++] = BYTE1(_c);
	
	data_to_send[_cnt++] = BYTE0(_d);
	data_to_send[_cnt++] = BYTE1(_d);
	
	for(i = 0;i<data_to_send[3]+4;i++)
	{
		sumcheck += data_to_send[i];//和校验
		addcheck += sumcheck;//附加和校验
	}
	data_to_send[_cnt++] = sumcheck;
	data_to_send[_cnt++] = addcheck;
	HAL_UART_Transmit(&huart1,data_to_send,_cnt,1000);
	
}

//F2帧发送4个int16类型的数据
void ANO_DT_Send_F2(int16_t _a,int16_t _b,int16_t _c,int16_t _d)
{
	uint8_t _cnt = 0;//计数值
	uint8_t sumcheck = 0;//和校验
	uint8_t addcheck = 0;//附加和校验
	uint8_t i = 0;
	
	data_to_send[_cnt++] = 0xAA;//帧头
	data_to_send[_cnt++] = 0xFF;//目标地址
	data_to_send[_cnt++] = 0xF2;//功能码
	data_to_send[_cnt++] = 8;//数据长度
	
	//单片机为小端，即低地址存低位，匿名上位要求先发低位，所以先放低地址
	data_to_send[_cnt++] = BYTE0(_a);
	data_to_send[_cnt++] = BYTE1(_a);
	
	data_to_send[_cnt++] = BYTE0(_b);
	data_to_send[_cnt++] = BYTE1(_b);
	
	data_to_send[_cnt++] = BYTE0(_c);
	data_to_send[_cnt++] = BYTE1(_c);
	
	data_to_send[_cnt++] = BYTE0(_d);
	data_to_send[_cnt++] = BYTE1(_d);
	
	for(i = 0;i<data_to_send[3]+4;i++)
	{
		sumcheck += data_to_send[i];//和校验
		addcheck += sumcheck;//附加和校验
	}
	data_to_send[_cnt++] = sumcheck;
	data_to_send[_cnt++] = addcheck;
	HAL_UART_Transmit(&huart1,data_to_send,_cnt,1000);
	
}


//F3帧发送2个int16 + 1个int32 类型的数据
void ANO_DT_Send_F3(int16_t _a,int16_t _b,int32_t _c)
{
	uint8_t _cnt = 0;//计数值
	uint8_t sumcheck = 0;//和校验
	uint8_t addcheck = 0;//附加和校验
	uint8_t i = 0;
	
	data_to_send[_cnt++] = 0xAA;//帧头
	data_to_send[_cnt++] = 0xFF;//目标地址
	data_to_send[_cnt++] = 0xF3;//功能码
	data_to_send[_cnt++] = 8;//数据长度
	
	//单片机为小端，即低地址存低位，匿名上位要求先发低位，所以先放低地址
	data_to_send[_cnt++] = BYTE0(_a);
	data_to_send[_cnt++] = BYTE1(_a);
	
	data_to_send[_cnt++] = BYTE0(_b);
	data_to_send[_cnt++] = BYTE1(_b);
	
	data_to_send[_cnt++] = BYTE0(_c);
	data_to_send[_cnt++] = BYTE1(_c);
	data_to_send[_cnt++] = BYTE2(_c);
	data_to_send[_cnt++] = BYTE3(_c);
	
	for(i = 0;i<data_to_send[3]+4;i++)
	{
		sumcheck += data_to_send[i];//和校验
		addcheck += sumcheck;//附加和校验
	}
	data_to_send[_cnt++] = sumcheck;
	data_to_send[_cnt++] = addcheck;
	HAL_UART_Transmit(&huart1,data_to_send,_cnt,1000);
	
}


