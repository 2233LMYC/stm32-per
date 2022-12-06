
/*
	应用说明：
	在访问IIC设备前，请先调用 IIC_CheckDevice() 检测IIC设备是否正常，该函数会配置GPIO
*/

#include "stm32f1xx_hal.h"
#include "IIC.h"

#ifdef MUL
/************  IIC 1  *************/
#define SDA_PORT_IIC_1     GPIOB                       /* GPIO端口 */
#define SCL_PORT_IIC_1     GPIOB                       /* GPIO端口 */
#define RCC_IIC_ENABLE_1    __HAL_RCC_GPIOB_CLK_ENABLE()       /* GPIO端口时钟 */
#define IIC_SCL_PIN_1       GPIO_PIN_11                 /* 连接到SCL时钟线的GPIO */
#define IIC_SDA_PIN_1       GPIO_PIN_10                  /* 连接到SDA数据线的GPIO */
#define IIC_SCL_H_1()  HAL_GPIO_WritePin(SCL_PORT_IIC_1, IIC_SCL_PIN_1, GPIO_PIN_SET)		/* SCL = 1 */
#define IIC_SCL_L_1()  HAL_GPIO_WritePin(SCL_PORT_IIC_1, IIC_SCL_PIN_1, GPIO_PIN_RESET)		/* SCL = 0 */
#define IIC_SDA_H_1()  HAL_GPIO_WritePin(SDA_PORT_IIC_1, IIC_SDA_PIN_1, GPIO_PIN_SET)		/* SDA = 1 */
#define IIC_SDA_L_1()  HAL_GPIO_WritePin(SDA_PORT_IIC_1, IIC_SDA_PIN_1, GPIO_PIN_RESET)		/* SDA = 0 */
#define IIC_SDA_READ_1()  HAL_GPIO_ReadPin(SDA_PORT_IIC_1, IIC_SDA_PIN_1)	/* 读SDA口线状态 */

/************  IIC 2  *************/
#define SDA_PORT_IIC_2     GPIOB                       /* GPIO端口 */
#define SCL_PORT_IIC_2     GPIOB                       /* GPIO端口 */
#define RCC_IIC_ENABLE_2    __HAL_RCC_GPIOB_CLK_ENABLE()       /* GPIO端口时钟 */
#define IIC_SCL_PIN_2       GPIO_PIN_1                 /* 连接到SCL时钟线的GPIO */
#define IIC_SDA_PIN_2       GPIO_PIN_0                  /* 连接到SDA数据线的GPIO */
#define IIC_SCL_H_2()  HAL_GPIO_WritePin(SCL_PORT_IIC_2, IIC_SCL_PIN_2, GPIO_PIN_SET)		/* SCL = 1 */
#define IIC_SCL_L_2()  HAL_GPIO_WritePin(SCL_PORT_IIC_2, IIC_SCL_PIN_2, GPIO_PIN_RESET)		/* SCL = 0 */
#define IIC_SDA_H_2()  HAL_GPIO_WritePin(SDA_PORT_IIC_2, IIC_SDA_PIN_2, GPIO_PIN_SET)		/* SDA = 1 */
#define IIC_SDA_L_2()  HAL_GPIO_WritePin(SDA_PORT_IIC_2, IIC_SDA_PIN_2, GPIO_PIN_RESET)		/* SDA = 0 */
#define IIC_SDA_READ_2()  HAL_GPIO_ReadPin(SDA_PORT_IIC_2, IIC_SDA_PIN_2)	/* 读SDA口线状态 */

/************  IIC 3  *************/
#define SDA_PORT_IIC_3     GPIOB                       /* GPIO端口 */
#define SCL_PORT_IIC_3     GPIOB                       /* GPIO端口 */
#define RCC_IIC_ENABLE_3    __HAL_RCC_GPIOA_CLK_ENABLE()       /* GPIO端口时钟 */
#define IIC_SCL_PIN_3       GPIO_PIN_5                 /* 连接到SCL时钟线的GPIO */
#define IIC_SDA_PIN_3       GPIO_PIN_6                  /* 连接到SDA数据线的GPIO */
#define IIC_SCL_H_3()  HAL_GPIO_WritePin(SCL_PORT_IIC_3, IIC_SCL_PIN_3, GPIO_PIN_SET)		/* SCL = 1 */
#define IIC_SCL_L_3()  HAL_GPIO_WritePin(SCL_PORT_IIC_3, IIC_SCL_PIN_3, GPIO_PIN_RESET)		/* SCL = 0 */
#define IIC_SDA_H_3()  HAL_GPIO_WritePin(SDA_PORT_IIC_3, IIC_SDA_PIN_3, GPIO_PIN_SET)		/* SDA = 1 */
#define IIC_SDA_L_3()  HAL_GPIO_WritePin(SDA_PORT_IIC_3, IIC_SDA_PIN_3, GPIO_PIN_RESET)		/* SDA = 0 */
#define IIC_SDA_READ_3()  HAL_GPIO_ReadPin(SDA_PORT_IIC_3, IIC_SDA_PIN_3)	/* 读SDA口线状态 */

/************  IIC 4  *************/
#define SDA_PORT_IIC_4     GPIOA                       /* GPIO端口 */
#define SCL_PORT_IIC_4     GPIOA                       /* GPIO端口 */
#define RCC_IIC_ENABLE_4    __HAL_RCC_GPIOA_CLK_ENABLE()       /* GPIO端口时钟 */
#define IIC_SCL_PIN_4       GPIO_PIN_11                 /* 连接到SCL时钟线的GPIO */
#define IIC_SDA_PIN_4       GPIO_PIN_12                  /* 连接到SDA数据线的GPIO */
#define IIC_SCL_H_4()  HAL_GPIO_WritePin(SCL_PORT_IIC_4, IIC_SCL_PIN_4, GPIO_PIN_SET)		/* SCL = 1 */
#define IIC_SCL_L_4()  HAL_GPIO_WritePin(SCL_PORT_IIC_4, IIC_SCL_PIN_4, GPIO_PIN_RESET)		/* SCL = 0 */
#define IIC_SDA_H_4()  HAL_GPIO_WritePin(SDA_PORT_IIC_4, IIC_SDA_PIN_4, GPIO_PIN_SET)		/* SDA = 1 */
#define IIC_SDA_L_4()  HAL_GPIO_WritePin(SDA_PORT_IIC_4, IIC_SDA_PIN_4, GPIO_PIN_RESET)		/* SDA = 0 */
#define IIC_SDA_READ_4()  HAL_GPIO_ReadPin(SDA_PORT_IIC_4, IIC_SDA_PIN_4)	/* 读SDA口线状态 */

///************  IIC 5  *************/
//#define SDA_PORT_IIC_5     GPIOB                       /* GPIO端口 */
//#define SCL_PORT_IIC_5     GPIOB                       /* GPIO端口 */
//#define RCC_IIC_ENABLE_5    __HAL_RCC_GPIOB_CLK_ENABLE()       /* GPIO端口时钟 */
//#define IIC_SCL_PIN_5       GPIO_PIN_11                 /* 连接到SCL时钟线的GPIO */
//#define IIC_SDA_PIN_5       GPIO_PIN_10                  /* 连接到SDA数据线的GPIO */
//#define IIC_SCL_H_5()  HAL_GPIO_WritePin(SCL_PORT_IIC_5, IIC_SCL_PIN_5, GPIO_PIN_SET)		/* SCL = 1 */
//#define IIC_SCL_L_5()  HAL_GPIO_WritePin(SCL_PORT_IIC_5, IIC_SCL_PIN_5, GPIO_PIN_RESET)		/* SCL = 0 */
//#define IIC_SDA_H_5()  HAL_GPIO_WritePin(SDA_PORT_IIC_5, IIC_SDA_PIN_5, GPIO_PIN_SET)		/* SDA = 1 */
//#define IIC_SDA_L_5()  HAL_GPIO_WritePin(SDA_PORT_IIC_5, IIC_SDA_PIN_5, GPIO_PIN_RESET)		/* SDA = 0 */
//#define IIC_SDA_READ_5()  HAL_GPIO_ReadPin(SDA_PORT_IIC_5, IIC_SDA_PIN_5)	/* 读SDA口线状态 */

#else
/*****************************************************************************************/
/* 定义IIC总线连接的GPIO端口, 用户只需要修改下面4行代码即可任意改变SCL和SDA的引脚 */
#define SDA_PORT_IIC_1     GPIOB                       /* GPIO端口 */
#define SCL_PORT_IIC_1     GPIOB                       /* GPIO端口 */
#define RCC_IIC_ENABLE_1    __HAL_RCC_GPIOB_CLK_ENABLE()       /* GPIO端口时钟 */
#define IIC_SCL_PIN_1       GPIO_PIN_11                 /* 连接到SCL时钟线的GPIO */
#define IIC_SDA_PIN_1       GPIO_PIN_10                  /* 连接到SDA数据线的GPIO */
/********************************************************************************************/

/* 定义读写SCL和SDA的宏，已增加代码的可移植性和可阅读性 */
#define IIC_SCL_H_1()  HAL_GPIO_WritePin(SCL_PORT_IIC_1, IIC_SCL_PIN_1, GPIO_PIN_SET)		/* SCL = 1 */
#define IIC_SCL_L_1()  HAL_GPIO_WritePin(SCL_PORT_IIC_1, IIC_SCL_PIN_1, GPIO_PIN_RESET)		/* SCL = 0 */

#define IIC_SDA_H_1()  HAL_GPIO_WritePin(SDA_PORT_IIC_1, IIC_SDA_PIN_1, GPIO_PIN_SET)		/* SDA = 1 */
#define IIC_SDA_L_1()  HAL_GPIO_WritePin(SDA_PORT_IIC_1, IIC_SDA_PIN_1, GPIO_PIN_RESET)		/* SDA = 0 */

#define IIC_SDA_READ_1()  HAL_GPIO_ReadPin(SDA_PORT_IIC_1, IIC_SDA_PIN_1)	/* 读SDA口线状态 */

#endif


void IIC_GPIO_Init(void);
   
/*
*********************************************************************************************************
*	函 数 名: IIC_Delay
*	功能说明: IIC总线位延迟，最快400KHz
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
static void IIC_Delay(void)
{
    uint8_t i;

    /*　
     	下面的时间是通过安富莱AX-Pro逻辑分析仪测试得到的。
    	CPU主频72MHz时，在内部Flash运行, MDK工程不优化
    	循环次数为10时，SCL频率 = 205KHz
    	循环次数为7时，SCL频率 = 347KHz， SCL高电平时间1.5us，SCL低电平时间2.87us
     	循环次数为5时，SCL频率 = 421KHz， SCL高电平时间1.25us，SCL低电平时间2.375us

    IAR工程编译效率高，不能设置为7
    */
    for (i = 0; i < 10; i++);
}

/*
*********************************************************************************************************
*	函 数 名: IIC_Start
*	功能说明: CPU发起IIC总线启动信号
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
#ifdef MUL
void IIC_Start_1(void)
{
    IIC_SDA_H_1();
    IIC_SCL_H_1();
    IIC_Delay();
    IIC_SDA_L_1();
    IIC_Delay();
    IIC_SCL_L_1();
    IIC_Delay();
}
void IIC_Start_2(void)
{
    IIC_SDA_H_2();
    IIC_SCL_H_2();
    IIC_Delay();
    IIC_SDA_L_2();
    IIC_Delay();
    IIC_SCL_L_2();
    IIC_Delay();
}
void IIC_Start_3(void)
{
    IIC_SDA_H_3();
    IIC_SCL_H_3();
    IIC_Delay();
    IIC_SDA_L_3();
    IIC_Delay();
    IIC_SCL_L_3();
    IIC_Delay();
}
void IIC_Start_4(void)
{
    IIC_SDA_H_4();
    IIC_SCL_H_4();
    IIC_Delay();
    IIC_SDA_L_4();
    IIC_Delay();
    IIC_SCL_L_4();
    IIC_Delay();
}
//void IIC_Start_5(void)
//{
//    IIC_SDA_H_5();
//    IIC_SCL_H_5();
//    IIC_Delay();
//    IIC_SDA_L_5();
//    IIC_Delay();
//    IIC_SCL_L_5();
//    IIC_Delay();
//}


#else

void IIC_Start(void)
{
    /* 当SCL高电平时，SDA出现一个下跳沿表示IIC总线启动信号 */
    IIC_SDA_H_1();
    IIC_SCL_H_1();
    IIC_Delay();
    IIC_SDA_L_1();
    IIC_Delay();
    IIC_SCL_L_1();
    IIC_Delay();
}

#endif
/*
*********************************************************************************************************
*	函 数 名: IIC_Stop
*	功能说明: CPU发起IIC总线停止信号
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
#ifdef MUL
void IIC_Stop_1(void)
{
    IIC_SDA_L_1();
    IIC_SCL_H_1();
    IIC_Delay();
    IIC_SDA_H_1();
}

void IIC_Stop_2(void)
{
    IIC_SDA_L_2();
    IIC_SCL_H_2();
    IIC_Delay();
    IIC_SDA_H_2();
}
void IIC_Stop_3(void)
{
    IIC_SDA_L_3();
    IIC_SCL_H_3();
    IIC_Delay();
    IIC_SDA_H_3();
}
void IIC_Stop_4(void)
{
    IIC_SDA_L_4();
    IIC_SCL_H_4();
    IIC_Delay();
    IIC_SDA_H_4();
}
//void IIC_Stop_5(void)
//{
//    IIC_SDA_L_5();
//    IIC_SCL_H_5();
//    IIC_Delay();
//    IIC_SDA_H_5();
//}
#else
void IIC_Stop_1(void)
{
    IIC_SDA_L_1();
    IIC_SCL_H_1();
    IIC_Delay();
    IIC_SDA_H_1();
}

#endif
/*
*********************************************************************************************************
*	函 数 名: IIC_SendByte
*	功能说明: CPU向IIC总线设备发送8bit数据
*	形    参：_ucByte ： 等待发送的字节
*	返 回 值: 无
*********************************************************************************************************
*/
#ifdef MUL
void IIC_Send_Byte_1(uint8_t _ucByte)
{
    uint8_t i;
    /* 先发送字节的高位bit7 */
    for (i = 0; i < 8; i++)
    {
        if (_ucByte & 0x80)
        {
            IIC_SDA_H_1();
        }
        else
        {
            IIC_SDA_L_1();
        }
        IIC_Delay();
        IIC_SCL_H_1();
        IIC_Delay();
        IIC_SCL_L_1();
        if (i == 7)
        {
            IIC_SDA_H_1(); // 释放总线
        }
        _ucByte <<= 1;	/* 左移一个bit */
        IIC_Delay();
    }
}

void IIC_Send_Byte_2(uint8_t _ucByte)
{
    uint8_t i;
    /* 先发送字节的高位bit7 */
    for (i = 0; i < 8; i++)
    {
        if (_ucByte & 0x80)
        {
            IIC_SDA_H_2();
        }
        else
        {
            IIC_SDA_L_2();
        }
        IIC_Delay();
        IIC_SCL_H_2();
        IIC_Delay();
        IIC_SCL_L_2();
        if (i == 7)
        {
            IIC_SDA_H_2(); // 释放总线
        }
        _ucByte <<= 1;	/* 左移一个bit */
        IIC_Delay();
    }
}

void IIC_Send_Byte_3(uint8_t _ucByte)
{
    uint8_t i;
    /* 先发送字节的高位bit7 */
    for (i = 0; i < 8; i++)
    {
        if (_ucByte & 0x80)
        {
            IIC_SDA_H_3();
        }
        else
        {
            IIC_SDA_L_3();
        }
        IIC_Delay();
        IIC_SCL_H_3();
        IIC_Delay();
        IIC_SCL_L_3();
        if (i == 7)
        {
            IIC_SDA_H_3(); // 释放总线
        }
        _ucByte <<= 1;	/* 左移一个bit */
        IIC_Delay();
    }
}

void IIC_Send_Byte_4(uint8_t _ucByte)
{
    uint8_t i;
    /* 先发送字节的高位bit7 */
    for (i = 0; i < 8; i++)
    {
        if (_ucByte & 0x80)
        {
            IIC_SDA_H_4();
        }
        else
        {
            IIC_SDA_L_4();
        }
        IIC_Delay();
        IIC_SCL_H_4();
        IIC_Delay();
        IIC_SCL_L_4();
        if (i == 7)
        {
            IIC_SDA_H_4(); // 释放总线
        }
        _ucByte <<= 1;	/* 左移一个bit */
        IIC_Delay();
    }
}

//void IIC_Send_Byte_5(uint8_t _ucByte)
//{
//    uint8_t i;
//    /* 先发送字节的高位bit7 */
//    for (i = 0; i < 8; i++)
//    {
//        if (_ucByte & 0x80)
//        {
//            IIC_SDA_H_5();
//        }
//        else
//        {
//            IIC_SDA_L_5();
//        }
//        IIC_Delay();
//        IIC_SCL_H_5();
//        IIC_Delay();
//        IIC_SCL_L_5();
//        if (i == 7)
//        {
//            IIC_SDA_H_5(); // 释放总线
//        }
//        _ucByte <<= 1;	/* 左移一个bit */
//        IIC_Delay();
//    }
//}


#else

void IIC_Send_Byte_1(uint8_t _ucByte)
{
    uint8_t i;
    /* 先发送字节的高位bit7 */
    for (i = 0; i < 8; i++)
    {
        if (_ucByte & 0x80)
        {
            IIC_SDA_H_1();
        }
        else
        {
            IIC_SDA_L_1();
        }
        IIC_Delay();
        IIC_SCL_H_1();
        IIC_Delay();
        IIC_SCL_L_1();
        if (i == 7)
        {
            IIC_SDA_H_1(); // 释放总线
        }
        _ucByte <<= 1;	/* 左移一个bit */
        IIC_Delay();
    }
}


#endif
/*
*********************************************************************************************************
*	函 数 名: IIC_ReadByte
*	功能说明: CPU从IIC总线设备读取8bit数据
*	形    参：无
*	返 回 值: 读到的数据
*********************************************************************************************************
*/
#ifdef MUL
uint8_t IIC_Read_Byte_1(void)
{
    uint8_t i;
    uint8_t value;
    /* 读到第1个bit为数据的bit7 */
    value = 0;
    for (i = 0; i < 8; i++)
    {
        value <<= 1;
        IIC_SCL_H_1();
        IIC_Delay();
        if (IIC_SDA_READ_1())
        {
            value++;
        }
        IIC_SCL_L_1();
        IIC_Delay();
    }
		return value;
}

uint8_t IIC_Read_Byte_2(void)
{
    uint8_t i;
    uint8_t value;
    /* 读到第1个bit为数据的bit7 */
    value = 0;
    for (i = 0; i < 8; i++)
    {
        value <<= 1;
        IIC_SCL_H_2();
        IIC_Delay();
        if (IIC_SDA_READ_2())
        {
            value++;
        }
        IIC_SCL_L_2();
        IIC_Delay();
    }
		return value;
}

uint8_t IIC_Read_Byte_3(void)
{
    uint8_t i;
    uint8_t value;
    /* 读到第1个bit为数据的bit7 */
    value = 0;
    for (i = 0; i < 8; i++)
    {
        value <<= 1;
        IIC_SCL_H_3();
        IIC_Delay();
        if (IIC_SDA_READ_3())
        {
            value++;
        }
        IIC_SCL_L_3();
        IIC_Delay();
    }
		return value;
}

uint8_t IIC_Read_Byte_4(void)
{
    uint8_t i;
    uint8_t value;
    /* 读到第1个bit为数据的bit7 */
    value = 0;
    for (i = 0; i < 8; i++)
    {
        value <<= 1;
        IIC_SCL_H_4();
        IIC_Delay();
        if (IIC_SDA_READ_4())
        {
            value++;
        }
        IIC_SCL_L_4();
        IIC_Delay();
    }
		return value;
}

//uint8_t IIC_Read_Byte_5(void)
//{
//    uint8_t i;
//    uint8_t value;
//    /* 读到第1个bit为数据的bit7 */
//    value = 0;
//    for (i = 0; i < 8; i++)
//    {
//        value <<= 1;
//        IIC_SCL_H_5();
//        IIC_Delay();
//        if (IIC_SDA_READ_5())
//        {
//            value++;
//        }
//        IIC_SCL_L_5();
//        IIC_Delay();
//    }
//		return value;
//}

#else

uint8_t IIC_Read_Byte_1(void)
{
    uint8_t i;
    uint8_t value;
    /* 读到第1个bit为数据的bit7 */
    value = 0;
    for (i = 0; i < 8; i++)
    {
        value <<= 1;
        IIC_SCL_H_1();
        IIC_Delay();
        if (IIC_SDA_READ_1())
        {
            value++;
        }
        IIC_SCL_L_1();
        IIC_Delay();
    }
		return value;
}



#endif

/*
*********************************************************************************************************
*	函 数 名: IIC_WaitAck
*	功能说明: CPU产生一个时钟，并读取器件的ACK应答信号
*	形    参：无
*	返 回 值: 返回0表示正确应答，1表示无器件响应
*********************************************************************************************************
*/
#ifdef MUL
uint8_t IIC_Wait_Ack_1(void)
{
    uint8_t re;
    IIC_SDA_H_1();	/* CPU释放SDA总线 */
    IIC_Delay();
    IIC_SCL_H_1();	/* CPU驱动SCL = 1, 此时器件会返回ACK应答 */
    IIC_Delay();
    if (IIC_SDA_READ_1())	/* CPU读取SDA口线状态 */
    {
        re = 1;
    }
    else
    {
        re = 0;
    }
    IIC_SCL_L_1();
    IIC_Delay();
    return re;
}

uint8_t IIC_Wait_Ack_2(void)
{
    uint8_t re;
    IIC_SDA_H_2();	/* CPU释放SDA总线 */
    IIC_Delay();
    IIC_SCL_H_2();	/* CPU驱动SCL = 1, 此时器件会返回ACK应答 */
    IIC_Delay();
    if (IIC_SDA_READ_2())	/* CPU读取SDA口线状态 */
    {
        re = 1;
    }
    else
    {
        re = 0;
    }
    IIC_SCL_L_2();
    IIC_Delay();
    return re;
}
uint8_t IIC_Wait_Ack_3(void)
{
    uint8_t re;
    IIC_SDA_H_3();	/* CPU释放SDA总线 */
    IIC_Delay();
    IIC_SCL_H_3();	/* CPU驱动SCL = 1, 此时器件会返回ACK应答 */
    IIC_Delay();
    if (IIC_SDA_READ_3())	/* CPU读取SDA口线状态 */
    {
        re = 1;
    }
    else
    {
        re = 0;
    }
    IIC_SCL_L_3();
    IIC_Delay();
    return re;
}

uint8_t IIC_Wait_Ack_4(void)
{
    uint8_t re;
    IIC_SDA_H_4();	/* CPU释放SDA总线 */
    IIC_Delay();
    IIC_SCL_H_4();	/* CPU驱动SCL = 1, 此时器件会返回ACK应答 */
    IIC_Delay();
    if (IIC_SDA_READ_4())	/* CPU读取SDA口线状态 */
    {
        re = 1;
    }
    else
    {
        re = 0;
    }
    IIC_SCL_L_4();
    IIC_Delay();
    return re;
}

//uint8_t IIC_Wait_Ack_5(void)
//{
//    uint8_t re;
//    IIC_SDA_H_5();	/* CPU释放SDA总线 */
//    IIC_Delay();
//    IIC_SCL_H_5();	/* CPU驱动SCL = 1, 此时器件会返回ACK应答 */
//    IIC_Delay();
//    if (IIC_SDA_READ_5())	/* CPU读取SDA口线状态 */
//    {
//        re = 1;
//    }
//    else
//    {
//        re = 0;
//    }
//    IIC_SCL_L_5();
//    IIC_Delay();
//    return re;
//}


#else 
uint8_t IIC_Wait_Ack_1(void)
{
    uint8_t re;
    IIC_SDA_H_1();	/* CPU释放SDA总线 */
    IIC_Delay();
    IIC_SCL_H_1();	/* CPU驱动SCL = 1, 此时器件会返回ACK应答 */
    IIC_Delay();
    if (IIC_SDA_READ_1())	/* CPU读取SDA口线状态 */
    {
        re = 1;
    }
    else
    {
        re = 0;
    }
    IIC_SCL_L_1();
    IIC_Delay();
    return re;
}



#endif
/*
*********************************************************************************************************
*	函 数 名: IIC_Ack
*	功能说明: CPU产生一个ACK信号
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
#ifdef MUL
void IIC_Ack_1(void)
{
    IIC_SDA_L_1();	/* CPU驱动SDA = 0 */
    IIC_Delay();
    IIC_SCL_H_1();	/* CPU产生1个时钟 */
    IIC_Delay();
    IIC_SCL_L_1();
    IIC_Delay();
    IIC_SDA_H_1();	/* CPU释放SDA总线 */
}

void IIC_Ack_2(void)
{
    IIC_SDA_L_2();	/* CPU驱动SDA = 0 */
    IIC_Delay();
    IIC_SCL_H_2();	/* CPU产生1个时钟 */
    IIC_Delay();
    IIC_SCL_L_2();
    IIC_Delay();
    IIC_SDA_H_2();	/* CPU释放SDA总线 */
}

void IIC_Ack_3(void)
{
    IIC_SDA_L_3();	/* CPU驱动SDA = 0 */
    IIC_Delay();
    IIC_SCL_H_3();	/* CPU产生1个时钟 */
    IIC_Delay();
    IIC_SCL_L_3();
    IIC_Delay();
    IIC_SDA_H_3();	/* CPU释放SDA总线 */
}

void IIC_Ack_4(void)
{
    IIC_SDA_L_4();	/* CPU驱动SDA = 0 */
    IIC_Delay();
    IIC_SCL_H_4();	/* CPU产生1个时钟 */
    IIC_Delay();
    IIC_SCL_L_4();
    IIC_Delay();
    IIC_SDA_H_4();	/* CPU释放SDA总线 */
}

//void IIC_Ack_5(void)
//{
//    IIC_SDA_L_5();	/* CPU驱动SDA = 0 */
//    IIC_Delay();
//    IIC_SCL_H_5();	/* CPU产生1个时钟 */
//    IIC_Delay();
//    IIC_SCL_L_5();
//    IIC_Delay();
//    IIC_SDA_H_5();	/* CPU释放SDA总线 */
//}



#else
void IIC_Ack_1(void)
{
    IIC_SDA_L_1();	/* CPU驱动SDA = 0 */
    IIC_Delay();
    IIC_SCL_H_1();	/* CPU产生1个时钟 */
    IIC_Delay();
    IIC_SCL_L_1();
    IIC_Delay();
    IIC_SDA_H_1();	/* CPU释放SDA总线 */
}

#endif

/*
*********************************************************************************************************
*	函 数 名: IIC_NAck
*	功能说明: CPU产生1个NACK信号
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
#ifdef MUL
void IIC_NAck_1(void)
{
    IIC_SDA_H_1();	/* CPU驱动SDA = 1 */
    IIC_Delay();
    IIC_SCL_H_1();	/* CPU产生1个时钟 */
    IIC_Delay();
    IIC_SCL_L_1();
    IIC_Delay();
}

void IIC_NAck_2(void)
{
    IIC_SDA_H_2();	/* CPU驱动SDA = 1 */
    IIC_Delay();
    IIC_SCL_H_2();	/* CPU产生1个时钟 */
    IIC_Delay();
    IIC_SCL_L_2();
    IIC_Delay();
}


void IIC_NAck_3(void)
{
    IIC_SDA_H_3();	/* CPU驱动SDA = 1 */
    IIC_Delay();
    IIC_SCL_H_3();	/* CPU产生1个时钟 */
    IIC_Delay();
    IIC_SCL_L_3();
    IIC_Delay();
}


void IIC_NAck_4(void)
{
    IIC_SDA_H_4();	/* CPU驱动SDA = 1 */
    IIC_Delay();
    IIC_SCL_H_4();	/* CPU产生1个时钟 */
    IIC_Delay();
    IIC_SCL_L_4();
    IIC_Delay();
}


//void IIC_NAck_5(void)
//{
//    IIC_SDA_H_5();	/* CPU驱动SDA = 1 */
//    IIC_Delay();
//    IIC_SCL_H_5();	/* CPU产生1个时钟 */
//    IIC_Delay();
//    IIC_SCL_L_5();
//    IIC_Delay();
//}


#else
void IIC_NAck_1(void)
{
    IIC_SDA_H_1();	/* CPU驱动SDA = 1 */
    IIC_Delay();
    IIC_SCL_H_1();	/* CPU产生1个时钟 */
    IIC_Delay();
    IIC_SCL_L_1();
    IIC_Delay();
}


#endif
/*
*********************************************************************************************************
*	函 数 名: IIC_GPIO_Config
*	功能说明: 配置IIC总线的GPIO，采用模拟IO的方式实现
*	形    参：无
*	返 回 值: 无
*********************************************************************************************************
*/
#ifdef MUL
void IIC_GPIO_Init_1(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_IIC_ENABLE_1;	/* 打开GPIO时钟 */
    GPIO_InitStructure.Pin = IIC_SCL_PIN_1;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* 开漏输出 */
    HAL_GPIO_Init(SCL_PORT_IIC_1, &GPIO_InitStructure);
		GPIO_InitStructure.Pin = IIC_SDA_PIN_1;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* 开漏输出 */
    HAL_GPIO_Init(SDA_PORT_IIC_1, &GPIO_InitStructure);
    IIC_Stop_1();
}

void IIC_GPIO_Init_2(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_IIC_ENABLE_2;	/* 打开GPIO时钟 */
    GPIO_InitStructure.Pin = IIC_SCL_PIN_2;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* 开漏输出 */
    HAL_GPIO_Init(SCL_PORT_IIC_2, &GPIO_InitStructure);
		GPIO_InitStructure.Pin = IIC_SDA_PIN_2;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* 开漏输出 */
    HAL_GPIO_Init(SDA_PORT_IIC_2, &GPIO_InitStructure);
    IIC_Stop_2();
}

void IIC_GPIO_Init_3(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_IIC_ENABLE_3;	/* 打开GPIO时钟 */
    GPIO_InitStructure.Pin = IIC_SCL_PIN_3;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* 开漏输出 */
    HAL_GPIO_Init(SCL_PORT_IIC_3, &GPIO_InitStructure);
		GPIO_InitStructure.Pin = IIC_SDA_PIN_3;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* 开漏输出 */
    HAL_GPIO_Init(SDA_PORT_IIC_3, &GPIO_InitStructure);
    IIC_Stop_3();
}

void IIC_GPIO_Init_4(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_IIC_ENABLE_4;	/* 打开GPIO时钟 */
    GPIO_InitStructure.Pin = IIC_SCL_PIN_4;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* 开漏输出 */
    HAL_GPIO_Init(SCL_PORT_IIC_4, &GPIO_InitStructure);
		GPIO_InitStructure.Pin = IIC_SDA_PIN_4;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* 开漏输出 */
    HAL_GPIO_Init(SDA_PORT_IIC_4, &GPIO_InitStructure);
    IIC_Stop_4();
}

//void IIC_GPIO_Init_5(void)
//{
//    GPIO_InitTypeDef GPIO_InitStructure;
//    RCC_IIC_ENABLE_5;	/* 打开GPIO时钟 */
//    GPIO_InitStructure.Pin = IIC_SCL_PIN_5;
//    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
//    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* 开漏输出 */
//    HAL_GPIO_Init(SCL_PORT_IIC_5, &GPIO_InitStructure);
//		GPIO_InitStructure.Pin = IIC_SDA_PIN_5;
//    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
//    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* 开漏输出 */
//    HAL_GPIO_Init(SDA_PORT_IIC_5, &GPIO_InitStructure);
//    IIC_Stop_5();
//}

#else
void IIC_GPIO_Init_1(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_IIC_ENABLE_1;	/* 打开GPIO时钟 */
    GPIO_InitStructure.Pin = IIC_SCL_PIN_1;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* 开漏输出 */
    HAL_GPIO_Init(SCL_PORT_IIC_1, &GPIO_InitStructure);
		GPIO_InitStructure.Pin = IIC_SDA_PIN_1;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* 开漏输出 */
    HAL_GPIO_Init(SDA_PORT_IIC_1, &GPIO_InitStructure);
    IIC_Stop_1();
}

#endif


/*
*********************************************************************************************************
*	函 数 名: IIC_CheckDevice
*	功能说明: 检测IIC总线设备，CPU向发送设备地址，然后读取设备应答来判断该设备是否存在
*	形    参：_Address：设备的IIC总线地址
*	返 回 值: 返回值 0 表示正确， 返回1表示未探测到
*********************************************************************************************************
*/

#ifdef MUL

uint8_t IIC_CheckDevice_1(uint8_t _Address)
{
    uint8_t ucAck;
    IIC_GPIO_Init_1();		/* 配置GPIO */
    IIC_Start_1();		/* 发送启动信号 */
    /* 发送设备地址+读写控制bit（0 = w， 1 = r) bit7 先传 */
    IIC_Send_Byte_1(_Address|IIC_WR);
    ucAck = IIC_Wait_Ack_1();	/* 检测设备的ACK应答 */
    IIC_Stop_1();			/* 发送停止信号 */
    return ucAck;
}

uint8_t IIC_CheckDevice_2(uint8_t _Address)
{
    uint8_t ucAck;
    IIC_GPIO_Init_2();		/* 配置GPIO */
    IIC_Start_2();		/* 发送启动信号 */
    /* 发送设备地址+读写控制bit（0 = w， 1 = r) bit7 先传 */
    IIC_Send_Byte_2(_Address|IIC_WR);
    ucAck = IIC_Wait_Ack_2();	/* 检测设备的ACK应答 */
    IIC_Stop_2();			/* 发送停止信号 */
    return ucAck;
}

uint8_t IIC_CheckDevice_3(uint8_t _Address)
{
    uint8_t ucAck;
    IIC_GPIO_Init_3();		/* 配置GPIO */
    IIC_Start_3();		/* 发送启动信号 */
    /* 发送设备地址+读写控制bit（0 = w， 1 = r) bit7 先传 */
    IIC_Send_Byte_3(_Address|IIC_WR);
    ucAck = IIC_Wait_Ack_3();	/* 检测设备的ACK应答 */
    IIC_Stop_3();			/* 发送停止信号 */
    return ucAck;
}

uint8_t IIC_CheckDevice_4(uint8_t _Address)
{
    uint8_t ucAck;
    IIC_GPIO_Init_4();		/* 配置GPIO */
    IIC_Start_4();		/* 发送启动信号 */
    /* 发送设备地址+读写控制bit（0 = w， 1 = r) bit7 先传 */
    IIC_Send_Byte_4(_Address|IIC_WR);
    ucAck = IIC_Wait_Ack_4();	/* 检测设备的ACK应答 */
    IIC_Stop_4();			/* 发送停止信号 */
    return ucAck;
}

//uint8_t IIC_CheckDevice_5(uint8_t _Address)
//{
//    uint8_t ucAck;
//    IIC_GPIO_Init_5();		/* 配置GPIO */
//    IIC_Start_5();		/* 发送启动信号 */
//    /* 发送设备地址+读写控制bit（0 = w， 1 = r) bit7 先传 */
//    IIC_Send_Byte_5(_Address|IIC_WR);
//    ucAck = IIC_Wait_Ack_5();	/* 检测设备的ACK应答 */
//    IIC_Stop_5();			/* 发送停止信号 */
//    return ucAck;
//}

#else 
uint8_t IIC_CheckDevice_1(uint8_t _Address)
{
    uint8_t ucAck;
    IIC_GPIO_Init_1();		/* 配置GPIO */
    IIC_Start_1();		/* 发送启动信号 */
    /* 发送设备地址+读写控制bit（0 = w， 1 = r) bit7 先传 */
    IIC_Send_Byte_1(_Address|IIC_WR);
    ucAck = IIC_Wait_Ack_1();	/* 检测设备的ACK应答 */
    IIC_Stop_1();			/* 发送停止信号 */
    return ucAck;
}

#endif



