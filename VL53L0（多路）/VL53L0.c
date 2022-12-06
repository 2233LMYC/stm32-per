#include "VL53L0.h"

#ifdef MUL
uint8_t Distance_buff_1[20]={0};
uint16_t Distance_1 = 0;

uint8_t Distance_buff_2[20]={0};
uint16_t Distance_2 = 0;

uint8_t Distance_buff_3[20]={0};
uint16_t Distance_3 = 0;

uint8_t Distance_buff_4[20]={0};
uint16_t Distance_4 = 0;

//uint8_t Distance_buff_5[20]={0};
//uint16_t Distance_5 = 0;

#else
uint8_t Distance_buff_1[20]={0};
uint16_t Distance_1 = 0;

#endif

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
#ifdef MUL
uint8_t VL53L0X_Write_Len_1(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf)
{
	uint8_t i; 
  IIC_Start_1(); 
	IIC_Send_Byte_1((addr<<1)|0);//发送器件地址+写命令	
	if(IIC_Wait_Ack_1())	//等待应答
	{
		IIC_Stop_1();		 
		return 1;		
	}
    IIC_Send_Byte_1(reg);	//写寄存器地址
    IIC_Wait_Ack_1();		//等待应答
	for(i=0;i<len;i++)
	{
		IIC_Send_Byte_1(buf[i]);	//发送数据
		if(IIC_Wait_Ack_1())		//等待ACK
		{
			IIC_Stop_1();	 
			return 1;		 
		}		
	}    
    IIC_Stop_1();	 
	return 0;	
} 

uint8_t VL53L0X_Write_Len_2(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf)
{
	uint8_t i; 
  IIC_Start_2(); 
	IIC_Send_Byte_2((addr<<1)|0);//发送器件地址+写命令	
	if(IIC_Wait_Ack_2())	//等待应答
	{
		IIC_Stop_2();		 
		return 1;		
	}
    IIC_Send_Byte_2(reg);	//写寄存器地址
    IIC_Wait_Ack_2();		//等待应答
	for(i=0;i<len;i++)
	{
		IIC_Send_Byte_2(buf[i]);	//发送数据
		if(IIC_Wait_Ack_2())		//等待ACK
		{
			IIC_Stop_2();	 
			return 1;		 
		}		
	}    
    IIC_Stop_2();	 
	return 0;	
}

uint8_t VL53L0X_Write_Len_3(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf)
{
	uint8_t i; 
  IIC_Start_3(); 
	IIC_Send_Byte_3((addr<<1)|0);//发送器件地址+写命令	
	if(IIC_Wait_Ack_3())	//等待应答
	{
		IIC_Stop_3();		 
		return 1;		
	}
    IIC_Send_Byte_3(reg);	//写寄存器地址
    IIC_Wait_Ack_3();		//等待应答
	for(i=0;i<len;i++)
	{
		IIC_Send_Byte_3(buf[i]);	//发送数据
		if(IIC_Wait_Ack_1())		//等待ACK
		{
			IIC_Stop_3();	 
			return 1;		 
		}		
	}    
    IIC_Stop_3();	 
	return 0;	
}

uint8_t VL53L0X_Write_Len_4(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf)
{
	uint8_t i; 
  IIC_Start_4(); 
	IIC_Send_Byte_4((addr<<1)|0);//发送器件地址+写命令	
	if(IIC_Wait_Ack_4())	//等待应答
	{
		IIC_Stop_4();		 
		return 1;		
	}
    IIC_Send_Byte_4(reg);	//写寄存器地址
    IIC_Wait_Ack_4();		//等待应答
	for(i=0;i<len;i++)
	{
		IIC_Send_Byte_4(buf[i]);	//发送数据
		if(IIC_Wait_Ack_4())		//等待ACK
		{
			IIC_Stop_4();	 
			return 1;		 
		}		
	}    
    IIC_Stop_4();	 
	return 0;	
}

//uint8_t VL53L0X_Write_Len_5(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf)
//{
//	uint8_t i; 
//  IIC_Start_5(); 
//	IIC_Send_Byte_5((addr<<1)|0);//发送器件地址+写命令	
//	if(IIC_Wait_Ack_5())	//等待应答
//	{
//		IIC_Stop_5();		 
//		return 1;		
//	}
//    IIC_Send_Byte_5(reg);	//写寄存器地址
//    IIC_Wait_Ack_5();		//等待应答
//	for(i=0;i<len;i++)
//	{
//		IIC_Send_Byte_5(buf[i]);	//发送数据
//		if(IIC_Wait_Ack_5())		//等待ACK
//		{
//			IIC_Stop_5();	 
//			return 1;		 
//		}		
//	}    
//    IIC_Stop_5();	 
//	return 0;	
//}

#else
uint8_t VL53L0X_Write_Len_1(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf)
{
	uint8_t i; 
  IIC_Start_1(); 
	IIC_Send_Byte_1((addr<<1)|0);//发送器件地址+写命令	
	if(IIC_Wait_Ack_1())	//等待应答
	{
		IIC_Stop_1();		 
		return 1;		
	}
    IIC_Send_Byte_1(reg);	//写寄存器地址
    IIC_Wait_Ack_1();		//等待应答
	for(i=0;i<len;i++)
	{
		IIC_Send_Byte_1(buf[i]);	//发送数据
		if(IIC_Wait_Ack_1())		//等待ACK
		{
			IIC_Stop_1();	 
			return 1;		 
		}		
	}    
    IIC_Stop_1();	 
	return 0;	
}

#endif
//IIC连续读
//addr:器件地址
//reg:要读取的寄存器地址
//len:要读取的长度
//buf:读取到的数据存储区
//返回值:0,正常
//    其他,错误代码
#ifdef MUL
uint8_t VL53L0X_Read_Len_1(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf)
{ 
 	IIC_Start_1(); 
	IIC_Send_Byte_1((addr<<1)|0);//发送器件地址+写命令	
	if(IIC_Wait_Ack_1())	//等待应答
	{
		IIC_Stop_1();		 
		return 1;		
	}
    IIC_Send_Byte_1(reg);	//写寄存器地址
    IIC_Wait_Ack_1();		//等待应答
    IIC_Start_1();
	IIC_Send_Byte_1((addr<<1)|1);//发送器件地址+读命令	
    IIC_Wait_Ack_1();		//等待应答 
		
 while(len)
	{
		if(len==1)
		{
			*buf=IIC_Read_Byte_1();//读数据,发送nACK 
			IIC_NAck_1();
		}
		else 
		{
			*buf=IIC_Read_Byte_1();		//读数据,发送ACK  
			IIC_Ack_1();
		}
		len--;
		buf++; 
	}    
    IIC_Stop_1();	//产生一个停止条件 
	return 0;	
}

uint8_t VL53L0X_Read_Len_2(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf)
{ 
 	IIC_Start_2(); 
	IIC_Send_Byte_2((addr<<1)|0);//发送器件地址+写命令	
	if(IIC_Wait_Ack_2())	//等待应答
	{
		IIC_Stop_2();		 
		return 1;		
	}
    IIC_Send_Byte_2(reg);	//写寄存器地址
    IIC_Wait_Ack_2();		//等待应答
    IIC_Start_2();
	IIC_Send_Byte_2((addr<<1)|1);//发送器件地址+读命令	
    IIC_Wait_Ack_2();		//等待应答 
		
 while(len)
	{
		if(len==1)
		{
			*buf=IIC_Read_Byte_2();//读数据,发送nACK 
			IIC_NAck_2();
		}
		else 
		{
			*buf=IIC_Read_Byte_2();		//读数据,发送ACK  
			IIC_Ack_2();
		}
		len--;
		buf++; 
	}    
    IIC_Stop_2();	//产生一个停止条件 
	return 0;	
}

uint8_t VL53L0X_Read_Len_3(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf)
{ 
 	IIC_Start_3(); 
	IIC_Send_Byte_3((addr<<1)|0);//发送器件地址+写命令	
	if(IIC_Wait_Ack_3())	//等待应答
	{
		IIC_Stop_3();		 
		return 1;		
	}
    IIC_Send_Byte_3(reg);	//写寄存器地址
    IIC_Wait_Ack_3();		//等待应答
    IIC_Start_3();
	IIC_Send_Byte_3((addr<<1)|1);//发送器件地址+读命令	
    IIC_Wait_Ack_3();		//等待应答 
		
 while(len)
	{
		if(len==1)
		{
			*buf=IIC_Read_Byte_3();//读数据,发送nACK 
			IIC_NAck_3();
		}
		else 
		{
			*buf=IIC_Read_Byte_3();		//读数据,发送ACK  
			IIC_Ack_3();
		}
		len--;
		buf++; 
	}    
    IIC_Stop_3();	//产生一个停止条件 
	return 0;	
}

uint8_t VL53L0X_Read_Len_4(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf)
{ 
 	IIC_Start_4(); 
	IIC_Send_Byte_4((addr<<1)|0);//发送器件地址+写命令	
	if(IIC_Wait_Ack_4())	//等待应答
	{
		IIC_Stop_4();		 
		return 1;		
	}
    IIC_Send_Byte_4(reg);	//写寄存器地址
    IIC_Wait_Ack_4();		//等待应答
    IIC_Start_4();
	IIC_Send_Byte_4((addr<<1)|1);//发送器件地址+读命令	
    IIC_Wait_Ack_4();		//等待应答 
		
 while(len)
	{
		if(len==1)
		{
			*buf=IIC_Read_Byte_4();//读数据,发送nACK 
			IIC_NAck_4();
		}
		else 
		{
			*buf=IIC_Read_Byte_4();		//读数据,发送ACK  
			IIC_Ack_4();
		}
		len--;
		buf++; 
	}    
    IIC_Stop_4();	//产生一个停止条件 
	return 0;	
}

//uint8_t VL53L0X_Read_Len_5(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf)
//{ 
// 	IIC_Start_5(); 
//	IIC_Send_Byte_5((addr<<1)|0);//发送器件地址+写命令	
//	if(IIC_Wait_Ack_5())	//等待应答
//	{
//		IIC_Stop_5();		 
//		return 1;		
//	}
//    IIC_Send_Byte_5(reg);	//写寄存器地址
//    IIC_Wait_Ack_5();		//等待应答
//    IIC_Start_5();
//	IIC_Send_Byte_5((addr<<1)|1);//发送器件地址+读命令	
//    IIC_Wait_Ack_5();		//等待应答 
//		
// while(len)
//	{
//		if(len==1)
//		{
//			*buf=IIC_Read_Byte_5();//读数据,发送nACK 
//			IIC_NAck_5();
//		}
//		else 
//		{
//			*buf=IIC_Read_Byte_5();		//读数据,发送ACK  
//			IIC_Ack_5();
//		}
//		len--;
//		buf++; 
//	}    
//    IIC_Stop_5();	//产生一个停止条件 
//	return 0;	
//}

#else
uint8_t VL53L0X_Read_Len_1(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf)
{ 
 	IIC_Start_1(); 
	IIC_Send_Byte_1((addr<<1)|0);//发送器件地址+写命令	
	if(IIC_Wait_Ack_1())	//等待应答
	{
		IIC_Stop_1();		 
		return 1;		
	}
    IIC_Send_Byte_1(reg);	//写寄存器地址
    IIC_Wait_Ack_1();		//等待应答
    IIC_Start_1();
	IIC_Send_Byte_1((addr<<1)|1);//发送器件地址+读命令	
    IIC_Wait_Ack_1();		//等待应答 
		
 while(len)
	{
		if(len==1)
		{
			*buf=IIC_Read_Byte_1();//读数据,发送nACK 
			IIC_NAck_1();
		}
		else 
		{
			*buf=IIC_Read_Byte_1();		//读数据,发送ACK  
			IIC_Ack_1();
		}
		len--;
		buf++; 
	}    
    IIC_Stop_1();	//产生一个停止条件 
	return 0;	
}

#endif
//IIC写一个字节 
//reg:寄存器地址
//data:数据
//返回值:0,正常
//    其他,错误代码
#ifdef MUL
uint8_t VL53L0X_Write_Byte_1(uint8_t reg,uint8_t data) 				 
{ 
  IIC_Start_1(); 
	IIC_Send_Byte_1((VL53L0X_Add<<1)|0);//发送器件地址+写命令	
	if(IIC_Wait_Ack_1())	//等待应答
	{
		IIC_Stop_1();		 
		return 1;		
	}
    IIC_Send_Byte_1(reg);	//写寄存器地址
    IIC_Wait_Ack_1();		//等待应答 
	IIC_Send_Byte_1(data);//发送数据
	if(IIC_Wait_Ack_1())	//等待ACK
	{
		IIC_Stop_1();	 
		return 1;		 
	}		 
    IIC_Stop_1();	 
	return 0;
}

uint8_t VL53L0X_Write_Byte_2(uint8_t reg,uint8_t data) 				 
{ 
  IIC_Start_2(); 
	IIC_Send_Byte_2((VL53L0X_Add<<1)|0);//发送器件地址+写命令	
	if(IIC_Wait_Ack_2())	//等待应答
	{
		IIC_Stop_2();		 
		return 1;		
	}
    IIC_Send_Byte_2(reg);	//写寄存器地址
    IIC_Wait_Ack_2();		//等待应答 
	IIC_Send_Byte_2(data);//发送数据
	if(IIC_Wait_Ack_2())	//等待ACK
	{
		IIC_Stop_2();	 
		return 1;		 
	}		 
    IIC_Stop_2();	 
	return 0;
}
uint8_t VL53L0X_Write_Byte_3(uint8_t reg,uint8_t data) 				 
{ 
  IIC_Start_3(); 
	IIC_Send_Byte_3((VL53L0X_Add<<1)|0);//发送器件地址+写命令	
	if(IIC_Wait_Ack_3())	//等待应答
	{
		IIC_Stop_3();		 
		return 1;		
	}
    IIC_Send_Byte_3(reg);	//写寄存器地址
    IIC_Wait_Ack_3();		//等待应答 
	IIC_Send_Byte_3(data);//发送数据
	if(IIC_Wait_Ack_3())	//等待ACK
	{
		IIC_Stop_3();	 
		return 1;		 
	}		 
    IIC_Stop_3();	 
	return 0;
}

uint8_t VL53L0X_Write_Byte_4(uint8_t reg,uint8_t data) 				 
{ 
  IIC_Start_4(); 
	IIC_Send_Byte_4((VL53L0X_Add<<1)|0);//发送器件地址+写命令	
	if(IIC_Wait_Ack_4())	//等待应答
	{
		IIC_Stop_4();		 
		return 1;		
	}
    IIC_Send_Byte_4(reg);	//写寄存器地址
    IIC_Wait_Ack_4();		//等待应答 
	IIC_Send_Byte_4(data);//发送数据
	if(IIC_Wait_Ack_4())	//等待ACK
	{
		IIC_Stop_4();	 
		return 1;		 
	}		 
    IIC_Stop_4();	 
	return 0;
}

//uint8_t VL53L0X_Write_Byte_5(uint8_t reg,uint8_t data) 				 
//{ 
//  IIC_Start_5(); 
//	IIC_Send_Byte_5((VL53L0X_Add<<1)|0);//发送器件地址+写命令	
//	if(IIC_Wait_Ack_5())	//等待应答
//	{
//		IIC_Stop_5();		 
//		return 1;		
//	}
//    IIC_Send_Byte_5(reg);	//写寄存器地址
//    IIC_Wait_Ack_5();		//等待应答 
//	IIC_Send_Byte_5(data);//发送数据
//	if(IIC_Wait_Ack_5())	//等待ACK
//	{
//		IIC_Stop_5();	 
//		return 1;		 
//	}		 
//    IIC_Stop_5();	 
//	return 0;
//}


#else
uint8_t VL53L0X_Write_Byte_1(uint8_t reg,uint8_t data) 				 
{ 
  IIC_Start_1(); 
	IIC_Send_Byte_1((VL53L0X_Add<<1)|0);//发送器件地址+写命令	
	if(IIC_Wait_Ack_1())	//等待应答
	{
		IIC_Stop_1();		 
		return 1;		
	}
    IIC_Send_Byte_1(reg);	//写寄存器地址
    IIC_Wait_Ack_1();		//等待应答 
	IIC_Send_Byte_1(data);//发送数据
	if(IIC_Wait_Ack_1())	//等待ACK
	{
		IIC_Stop_1();	 
		return 1;		 
	}		 
    IIC_Stop_1();	 
	return 0;
}

#endif

//IIC读一个字节 
//reg:寄存器地址 
//返回值:读到的数据
#ifdef MUL
uint8_t VL53L0X_Read_Byte_1(uint8_t reg)
{
	uint8_t res;
    IIC_Start_1(); 
	//IIC_Send_Byte_1((VL53L0X_Add<<1)|0);//发送器件地址+写命令	
	IIC_Send_Byte_1(0x52);//发送器件地址+写命令	
	IIC_Wait_Ack_1();		//等待应答 
    IIC_Send_Byte_1(reg);	//写寄存器地址
    IIC_Wait_Ack_1();		//等待应答
    IIC_Start_1();
	IIC_Send_Byte_1(0x53 );//发送器件地址+读命令	
    IIC_Wait_Ack_1();
 IIC_Send_Byte_1(reg);	//等待应答 
	res=IIC_Read_Byte_1();//读取数据,发送nACK 
	IIC_NAck_1();
    IIC_Stop_1();			//产生一个停止条件 
	return res;		
}


uint8_t VL53L0X_Read_Byte_2(uint8_t reg)
{
	uint8_t res;
    IIC_Start_2(); 
	//IIC_Send_Byte_2((VL53L0X_Add<<1)|0);//发送器件地址+写命令	
	IIC_Send_Byte_2(0x52);//发送器件地址+写命令	
	IIC_Wait_Ack_2();		//等待应答 
    IIC_Send_Byte_2(reg);	//写寄存器地址
    IIC_Wait_Ack_2();		//等待应答
    IIC_Start_2();
	IIC_Send_Byte_2(0x53 );//发送器件地址+读命令	
    IIC_Wait_Ack_2();
 IIC_Send_Byte_2(reg);	//等待应答 
	res=IIC_Read_Byte_2();//读取数据,发送nACK 
	IIC_NAck_2();
    IIC_Stop_2();			//产生一个停止条件 
	return res;		
}

uint8_t VL53L0X_Read_Byte_3(uint8_t reg)
{
	uint8_t res;
    IIC_Start_3(); 
	//IIC_Send_Byte_3((VL53L0X_Add<<1)|0);//发送器件地址+写命令	
	IIC_Send_Byte_3(0x52);//发送器件地址+写命令	
	IIC_Wait_Ack_3();		//等待应答 
    IIC_Send_Byte_3(reg);	//写寄存器地址
    IIC_Wait_Ack_3();		//等待应答
    IIC_Start_3();
	IIC_Send_Byte_3(0x53 );//发送器件地址+读命令	
    IIC_Wait_Ack_3();
 IIC_Send_Byte_3(reg);	//等待应答 
	res=IIC_Read_Byte_3();//读取数据,发送nACK 
	IIC_NAck_3();
    IIC_Stop_3();			//产生一个停止条件 
	return res;		
}

uint8_t VL53L0X_Read_Byte_4(uint8_t reg)
{
	uint8_t res;
    IIC_Start_4(); 
	//IIC_Send_Byte_4((VL53L0X_Add<<1)|0);//发送器件地址+写命令	
	IIC_Send_Byte_4(0x52);//发送器件地址+写命令	
	IIC_Wait_Ack_4();		//等待应答 
    IIC_Send_Byte_4(reg);	//写寄存器地址
    IIC_Wait_Ack_4();		//等待应答
    IIC_Start_4();
	IIC_Send_Byte_4(0x53 );//发送器件地址+读命令	
    IIC_Wait_Ack_4();
 IIC_Send_Byte_4(reg);	//等待应答 
	res=IIC_Read_Byte_4();//读取数据,发送nACK 
	IIC_NAck_4();
    IIC_Stop_4();			//产生一个停止条件 
	return res;		
}

//uint8_t VL53L0X_Read_Byte_5(uint8_t reg)
//{
//	uint8_t res;
//    IIC_Start_5(); 
//	//IIC_Send_Byte_5((VL53L0X_Add<<1)|0);//发送器件地址+写命令	
//	IIC_Send_Byte_5(0x52);//发送器件地址+写命令	
//	IIC_Wait_Ack_5();		//等待应答 
//    IIC_Send_Byte_5(reg);	//写寄存器地址
//    IIC_Wait_Ack_5();		//等待应答
//    IIC_Start_5();
//	IIC_Send_Byte_5(0x53 );//发送器件地址+读命令	
//    IIC_Wait_Ack_5();
// IIC_Send_Byte_5(reg);	//等待应答 
//	res=IIC_Read_Byte_5();//读取数据,发送nACK 
//	IIC_NAck_5();
//    IIC_Stop_5();			//产生一个停止条件 
//	return res;		
//}

#else
uint8_t VL53L0X_Read_Byte_1(uint8_t reg)
{
	uint8_t res;
    IIC_Start_1(); 
	//IIC_Send_Byte_1((VL53L0X_Add<<1)|0);//发送器件地址+写命令	
	IIC_Send_Byte_1(0x52);//发送器件地址+写命令	
	IIC_Wait_Ack_1();		//等待应答 
    IIC_Send_Byte_1(reg);	//写寄存器地址
    IIC_Wait_Ack_1();		//等待应答
    IIC_Start_1();
	IIC_Send_Byte_1(0x53 );//发送器件地址+读命令	
    IIC_Wait_Ack_1();
 IIC_Send_Byte_1(reg);	//等待应答 
	res=IIC_Read_Byte_1();//读取数据,发送nACK 
	IIC_NAck_1();
    IIC_Stop_1();			//产生一个停止条件 
	return res;		
}


#endif



//VL53L0初始化
//初始化成功返回0.失败返回1
#ifdef MUL
int VL53L0_Init_1(uint8_t addr)
{
	while(!IIC_CheckDevice_1(addr))
	{
		HAL_Delay(500);
		return 1;
	}
	return 0;
}

int VL53L0_Init_2(uint8_t addr)
{
	while(!IIC_CheckDevice_2(addr))
	{
		HAL_Delay(500);
		return 1;
	}
	return 0;
}
int VL53L0_Init_3(uint8_t addr)
{
	while(!IIC_CheckDevice_3(addr))
	{
		HAL_Delay(500);
		return 1;
	}
	return 0;
}

int VL53L0_Init_4(uint8_t addr)
{
	while(!IIC_CheckDevice_4(addr))
	{
		HAL_Delay(500);
		return 1;
	}
	return 0;
}

//int VL53L0_Init_5(uint8_t addr)
//{
//	while(!IIC_CheckDevice_5(addr))
//	{
//		HAL_Delay(500);
//		return 1;
//	}
//	return 0;
//}

#else 
int VL53L0_Init_1(uint8_t addr)
{
	while(!IIC_CheckDevice_1(addr))
	{
		HAL_Delay(500);
		return 1;
	}
	return 0;
}


#endif


//获取激光测距值 单位:mm
#ifdef MUL
int GET_VL53L0_1(uint8_t addr)
{
	VL53L0X_Write_Byte_1(VL53L0X_REG_SYSRANGE_START, 0x01);
	if(VL53L0X_Read_Byte_1(VL53L0X_REG_RESULT_RANGE_STATUS))
	{
		VL53L0X_Read_Len_1(addr, 0x14 , 12, Distance_buff_1);
		Distance_1 = makeuint16(Distance_buff_1[11], Distance_buff_1[10]);
		if(Distance_1>1000)	Distance_1=1000;
		return Distance_1;
	}
	return 0;
}

int GET_VL53L0_2(uint8_t addr)
{
	VL53L0X_Write_Byte_2(VL53L0X_REG_SYSRANGE_START, 0x01);
	if(VL53L0X_Read_Byte_2(VL53L0X_REG_RESULT_RANGE_STATUS))
	{
		VL53L0X_Read_Len_2(addr, 0x14 , 12, Distance_buff_2);
		Distance_2 = makeuint16(Distance_buff_2[11], Distance_buff_2[10]);
		if(Distance_2>1000)	Distance_2=1000;
		return Distance_2;
	}
	return 0;
}
int GET_VL53L0_3(uint8_t addr)
{
	VL53L0X_Write_Byte_3(VL53L0X_REG_SYSRANGE_START, 0x01);
	if(VL53L0X_Read_Byte_3(VL53L0X_REG_RESULT_RANGE_STATUS))
	{
		VL53L0X_Read_Len_3(addr, 0x14 , 12, Distance_buff_3);
		Distance_3 = makeuint16(Distance_buff_3[11], Distance_buff_3[10]);
		if(Distance_3>1000)	Distance_3=1000;
		return Distance_3;
	}
	return 0;
}
int GET_VL53L0_4(uint8_t addr)
{
	VL53L0X_Write_Byte_4(VL53L0X_REG_SYSRANGE_START, 0x01);
	if(VL53L0X_Read_Byte_4(VL53L0X_REG_RESULT_RANGE_STATUS))
	{
		VL53L0X_Read_Len_4(addr, 0x14 , 12, Distance_buff_4);
		Distance_4 = makeuint16(Distance_buff_4[11], Distance_buff_4[10]);
		if(Distance_4>1000)	Distance_4=1000;
		return Distance_4;
	}
	return 0;
}

//int GET_VL53L0_5(uint8_t addr)
//{
//	VL53L0X_Write_Byte_5(VL53L0X_REG_SYSRANGE_START, 0x01);
//	if(VL53L0X_Read_Byte_5(VL53L0X_REG_RESULT_RANGE_STATUS))
//	{
//		VL53L0X_Read_Len_5(addr, 0x14 , 12, Distance_buff_5);
//		Distance_5 = makeuint16(Distance_buff_5[11], Distance_buff_5[10]);
//		if(Distance_5>1000)	Distance_1=1000;
//		return Distance_5;
//	}
//	return 0;
//}

#else



#endif

