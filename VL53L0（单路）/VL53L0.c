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

//IIC连续写
//addr:器件地址 
//reg:寄存器地址
//len:写入长度
//buf:数据区
//返回值:0,正常
//其他,错误代码
uint8_t VL53L0X_Write_Len(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf)
{
	uint8_t i; 
    IIC_Start(); 
	IIC_Send_Byte((addr<<1)|0);//发送器件地址+写命令	
	if(IIC_Wait_Ack())	//等待应答
	{
		IIC_Stop();		 
		return 1;		
	}
    IIC_Send_Byte(reg);	//写寄存器地址
    IIC_Wait_Ack();		//等待应答
	for(i=0;i<len;i++)
	{
		IIC_Send_Byte(buf[i]);	//发送数据
		if(IIC_Wait_Ack())		//等待ACK
		{
			IIC_Stop();	 
			return 1;		 
		}		
	}    
    IIC_Stop();	 
	return 0;	
} 
//IIC连续读
//addr:器件地址
//reg:要读取的寄存器地址
//len:要读取的长度
//buf:读取到的数据存储区
//返回值:0,正常
//    其他,错误代码
uint8_t VL53L0X_Read_Len(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf)
{ 
 	IIC_Start(); 
	IIC_Send_Byte((addr<<1)|0);//发送器件地址+写命令	
	if(IIC_Wait_Ack())	//等待应答
	{
		IIC_Stop();		 
		return 1;		
	}
    IIC_Send_Byte(reg);	//写寄存器地址
    IIC_Wait_Ack();		//等待应答
    IIC_Start();
	IIC_Send_Byte((addr<<1)|1);//发送器件地址+读命令	
    IIC_Wait_Ack();		//等待应答 
		
 while(len)
	{
		if(len==1)
		{
			*buf=IIC_Read_Byte();//读数据,发送nACK 
			IIC_NAck();
		}
		else 
		{
			*buf=IIC_Read_Byte();		//读数据,发送ACK  
			IIC_Ack();
		}
		len--;
		buf++; 
	}    
    IIC_Stop();	//产生一个停止条件 
	return 0;	
}
//IIC写一个字节 
//reg:寄存器地址
//data:数据
//返回值:0,正常
//    其他,错误代码
uint8_t VL53L0X_Write_Byte(uint8_t reg,uint8_t data) 				 
{ 
  IIC_Start(); 
	IIC_Send_Byte((VL53L0X_Add<<1)|0);//发送器件地址+写命令	
	if(IIC_Wait_Ack())	//等待应答
	{
		IIC_Stop();		 
		return 1;		
	}
    IIC_Send_Byte(reg);	//写寄存器地址
    IIC_Wait_Ack();		//等待应答 
	IIC_Send_Byte(data);//发送数据
	if(IIC_Wait_Ack())	//等待ACK
	{
		IIC_Stop();	 
		return 1;		 
	}		 
    IIC_Stop();	 
	return 0;
}
//IIC读一个字节 
//reg:寄存器地址 
//返回值:读到的数据
uint8_t VL53L0X_Read_Byte(uint8_t reg)
{
	uint8_t res;
    IIC_Start(); 
	//IIC_Send_Byte((VL53L0X_Add<<1)|0);//发送器件地址+写命令	
	IIC_Send_Byte(0x52);//发送器件地址+写命令	
	IIC_Wait_Ack();		//等待应答 
    IIC_Send_Byte(reg);	//写寄存器地址
    IIC_Wait_Ack();		//等待应答
    IIC_Start();
	IIC_Send_Byte(0x53 );//发送器件地址+读命令	
    IIC_Wait_Ack();
 IIC_Send_Byte(reg);	//等待应答 
	res=IIC_Read_Byte();//读取数据,发送nACK 
	IIC_NAck();
    IIC_Stop();			//产生一个停止条件 
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


