#ifndef _NIMING_H_
#define _NIMING_H_

#include "main.h"


//发送16位/32位数据，需要单独拆分成单字节
//对变量取地址后转为char类型指针，后对所指向的地址取内容
#define BYTE0(VALUE) (*(char*)(&VALUE))
#define BYTE1(VALUE) (*((char*)(&VALUE)+1))
#define BYTE2(VALUE) (*((char*)(&VALUE)+2))
#define BYTE3(VALUE) (*((char*)(&VALUE)+3))

//F1帧发送4个uint16类型的数据
void ANO_DT_Send_F1(uint16_t _a,uint16_t _b,uint16_t _c,uint16_t _d);

//F2帧发送4个int16类型的数据
void ANO_DT_Send_F2(int16_t _a,int16_t _b,int16_t _c,int16_t _d);

//F3帧发送2个int16 + 1个int32 类型的数据
void ANO_DT_Send_F3(int16_t _a,int16_t _b,int32_t _c);


#endif

