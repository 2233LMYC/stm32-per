#ifndef _NIMING_H_
#define _NIMING_H_

#include "main.h"


//����16λ/32λ���ݣ���Ҫ������ֳɵ��ֽ�
//�Ա���ȡ��ַ��תΪchar����ָ�룬�����ָ��ĵ�ַȡ����
#define BYTE0(VALUE) (*(char*)(&VALUE))
#define BYTE1(VALUE) (*((char*)(&VALUE)+1))
#define BYTE2(VALUE) (*((char*)(&VALUE)+2))
#define BYTE3(VALUE) (*((char*)(&VALUE)+3))

//F1֡����4��uint16���͵�����
void ANO_DT_Send_F1(uint16_t _a,uint16_t _b,uint16_t _c,uint16_t _d);

//F2֡����4��int16���͵�����
void ANO_DT_Send_F2(int16_t _a,int16_t _b,int16_t _c,int16_t _d);

//F3֡����2��int16 + 1��int32 ���͵�����
void ANO_DT_Send_F3(int16_t _a,int16_t _b,int32_t _c);


#endif

