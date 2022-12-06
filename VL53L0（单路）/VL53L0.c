#include "VL53L0.h"

uint8_t Distance_buff[20]={0};
uint16_t Distance = 0;


uint16_t bswap(uint8_t b[])
{
	uint16_t val = ((b[0]<< 8) & b[1]);
	return val;
}

uint16_t VL53L0X_decode_vcsel_period(short vcsel_period_reg)
{
	uint16_t vcsel_period_pclks = (vcsel_period_reg + 1) <<1;
	return vcsel_period_pclks;
}

uint16_t makeuint16(int lsb, int msb)
{
    return ((msb & 0xFF) << 8) | (lsb & 0xFF);
}

//IIC����д
//addr:������ַ 
//reg:�Ĵ�����ַ
//len:д�볤��
//buf:������
//����ֵ:0,����
//����,�������
uint8_t VL53L0X_Write_Len(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf)
{
	uint8_t i; 
    IIC_Start(); 
	IIC_Send_Byte((addr<<1)|0);//����������ַ+д����	
	if(IIC_Wait_Ack())	//�ȴ�Ӧ��
	{
		IIC_Stop();		 
		return 1;		
	}
    IIC_Send_Byte(reg);	//д�Ĵ�����ַ
    IIC_Wait_Ack();		//�ȴ�Ӧ��
	for(i=0;i<len;i++)
	{
		IIC_Send_Byte(buf[i]);	//��������
		if(IIC_Wait_Ack())		//�ȴ�ACK
		{
			IIC_Stop();	 
			return 1;		 
		}		
	}    
    IIC_Stop();	 
	return 0;	
} 
//IIC������
//addr:������ַ
//reg:Ҫ��ȡ�ļĴ�����ַ
//len:Ҫ��ȡ�ĳ���
//buf:��ȡ�������ݴ洢��
//����ֵ:0,����
//    ����,�������
uint8_t VL53L0X_Read_Len(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf)
{ 
 	IIC_Start(); 
	IIC_Send_Byte((addr<<1)|0);//����������ַ+д����	
	if(IIC_Wait_Ack())	//�ȴ�Ӧ��
	{
		IIC_Stop();		 
		return 1;		
	}
    IIC_Send_Byte(reg);	//д�Ĵ�����ַ
    IIC_Wait_Ack();		//�ȴ�Ӧ��
    IIC_Start();
	IIC_Send_Byte((addr<<1)|1);//����������ַ+������	
    IIC_Wait_Ack();		//�ȴ�Ӧ�� 
		
 while(len)
	{
		if(len==1)
		{
			*buf=IIC_Read_Byte();//������,����nACK 
			IIC_NAck();
		}
		else 
		{
			*buf=IIC_Read_Byte();		//������,����ACK  
			IIC_Ack();
		}
		len--;
		buf++; 
	}    
    IIC_Stop();	//����һ��ֹͣ���� 
	return 0;	
}
//IICдһ���ֽ� 
//reg:�Ĵ�����ַ
//data:����
//����ֵ:0,����
//    ����,�������
uint8_t VL53L0X_Write_Byte(uint8_t reg,uint8_t data) 				 
{ 
  IIC_Start(); 
	IIC_Send_Byte((VL53L0X_Add<<1)|0);//����������ַ+д����	
	if(IIC_Wait_Ack())	//�ȴ�Ӧ��
	{
		IIC_Stop();		 
		return 1;		
	}
    IIC_Send_Byte(reg);	//д�Ĵ�����ַ
    IIC_Wait_Ack();		//�ȴ�Ӧ�� 
	IIC_Send_Byte(data);//��������
	if(IIC_Wait_Ack())	//�ȴ�ACK
	{
		IIC_Stop();	 
		return 1;		 
	}		 
    IIC_Stop();	 
	return 0;
}
//IIC��һ���ֽ� 
//reg:�Ĵ�����ַ 
//����ֵ:����������
uint8_t VL53L0X_Read_Byte(uint8_t reg)
{
	uint8_t res;
    IIC_Start(); 
	//IIC_Send_Byte((VL53L0X_Add<<1)|0);//����������ַ+д����	
	IIC_Send_Byte(0x52);//����������ַ+д����	
	IIC_Wait_Ack();		//�ȴ�Ӧ�� 
    IIC_Send_Byte(reg);	//д�Ĵ�����ַ
    IIC_Wait_Ack();		//�ȴ�Ӧ��
    IIC_Start();
	IIC_Send_Byte(0x53 );//����������ַ+������	
    IIC_Wait_Ack();
 IIC_Send_Byte(reg);	//�ȴ�Ӧ�� 
	res=IIC_Read_Byte();//��ȡ����,����nACK 
	IIC_NAck();
    IIC_Stop();			//����һ��ֹͣ���� 
	return res;		
}

int VL53L0_Init(uint8_t addr)
{
	while(!IIC_CheckDevice(addr))
	{
		HAL_Delay(500);
		return 1;
	}
	return 0;

}


int GET_VL53L0(uint8_t addr)
{

		VL53L0X_Write_Byte(VL53L0X_REG_SYSRANGE_START, 0x01);
		if(VL53L0X_Read_Byte(VL53L0X_REG_RESULT_RANGE_STATUS))
		{
			VL53L0X_Read_Len(addr, 0x14 , 12, Distance_buff);
			Distance = makeuint16(Distance_buff[11], Distance_buff[10]);
			if(Distance>1000)	Distance=1000;
			return Distance;
		}
		return 0;
}


