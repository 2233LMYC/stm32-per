
/*
	Ӧ��˵����
	�ڷ���IIC�豸ǰ�����ȵ��� IIC_CheckDevice() ���IIC�豸�Ƿ��������ú���������GPIO
*/

#include "stm32f1xx_hal.h"
#include "IIC.h"

#ifdef MUL
/************  IIC 1  *************/
#define SDA_PORT_IIC_1     GPIOB                       /* GPIO�˿� */
#define SCL_PORT_IIC_1     GPIOB                       /* GPIO�˿� */
#define RCC_IIC_ENABLE_1    __HAL_RCC_GPIOB_CLK_ENABLE()       /* GPIO�˿�ʱ�� */
#define IIC_SCL_PIN_1       GPIO_PIN_11                 /* ���ӵ�SCLʱ���ߵ�GPIO */
#define IIC_SDA_PIN_1       GPIO_PIN_10                  /* ���ӵ�SDA�����ߵ�GPIO */
#define IIC_SCL_H_1()  HAL_GPIO_WritePin(SCL_PORT_IIC_1, IIC_SCL_PIN_1, GPIO_PIN_SET)		/* SCL = 1 */
#define IIC_SCL_L_1()  HAL_GPIO_WritePin(SCL_PORT_IIC_1, IIC_SCL_PIN_1, GPIO_PIN_RESET)		/* SCL = 0 */
#define IIC_SDA_H_1()  HAL_GPIO_WritePin(SDA_PORT_IIC_1, IIC_SDA_PIN_1, GPIO_PIN_SET)		/* SDA = 1 */
#define IIC_SDA_L_1()  HAL_GPIO_WritePin(SDA_PORT_IIC_1, IIC_SDA_PIN_1, GPIO_PIN_RESET)		/* SDA = 0 */
#define IIC_SDA_READ_1()  HAL_GPIO_ReadPin(SDA_PORT_IIC_1, IIC_SDA_PIN_1)	/* ��SDA����״̬ */

/************  IIC 2  *************/
#define SDA_PORT_IIC_2     GPIOB                       /* GPIO�˿� */
#define SCL_PORT_IIC_2     GPIOB                       /* GPIO�˿� */
#define RCC_IIC_ENABLE_2    __HAL_RCC_GPIOB_CLK_ENABLE()       /* GPIO�˿�ʱ�� */
#define IIC_SCL_PIN_2       GPIO_PIN_1                 /* ���ӵ�SCLʱ���ߵ�GPIO */
#define IIC_SDA_PIN_2       GPIO_PIN_0                  /* ���ӵ�SDA�����ߵ�GPIO */
#define IIC_SCL_H_2()  HAL_GPIO_WritePin(SCL_PORT_IIC_2, IIC_SCL_PIN_2, GPIO_PIN_SET)		/* SCL = 1 */
#define IIC_SCL_L_2()  HAL_GPIO_WritePin(SCL_PORT_IIC_2, IIC_SCL_PIN_2, GPIO_PIN_RESET)		/* SCL = 0 */
#define IIC_SDA_H_2()  HAL_GPIO_WritePin(SDA_PORT_IIC_2, IIC_SDA_PIN_2, GPIO_PIN_SET)		/* SDA = 1 */
#define IIC_SDA_L_2()  HAL_GPIO_WritePin(SDA_PORT_IIC_2, IIC_SDA_PIN_2, GPIO_PIN_RESET)		/* SDA = 0 */
#define IIC_SDA_READ_2()  HAL_GPIO_ReadPin(SDA_PORT_IIC_2, IIC_SDA_PIN_2)	/* ��SDA����״̬ */

/************  IIC 3  *************/
#define SDA_PORT_IIC_3     GPIOB                       /* GPIO�˿� */
#define SCL_PORT_IIC_3     GPIOB                       /* GPIO�˿� */
#define RCC_IIC_ENABLE_3    __HAL_RCC_GPIOA_CLK_ENABLE()       /* GPIO�˿�ʱ�� */
#define IIC_SCL_PIN_3       GPIO_PIN_5                 /* ���ӵ�SCLʱ���ߵ�GPIO */
#define IIC_SDA_PIN_3       GPIO_PIN_6                  /* ���ӵ�SDA�����ߵ�GPIO */
#define IIC_SCL_H_3()  HAL_GPIO_WritePin(SCL_PORT_IIC_3, IIC_SCL_PIN_3, GPIO_PIN_SET)		/* SCL = 1 */
#define IIC_SCL_L_3()  HAL_GPIO_WritePin(SCL_PORT_IIC_3, IIC_SCL_PIN_3, GPIO_PIN_RESET)		/* SCL = 0 */
#define IIC_SDA_H_3()  HAL_GPIO_WritePin(SDA_PORT_IIC_3, IIC_SDA_PIN_3, GPIO_PIN_SET)		/* SDA = 1 */
#define IIC_SDA_L_3()  HAL_GPIO_WritePin(SDA_PORT_IIC_3, IIC_SDA_PIN_3, GPIO_PIN_RESET)		/* SDA = 0 */
#define IIC_SDA_READ_3()  HAL_GPIO_ReadPin(SDA_PORT_IIC_3, IIC_SDA_PIN_3)	/* ��SDA����״̬ */

/************  IIC 4  *************/
#define SDA_PORT_IIC_4     GPIOA                       /* GPIO�˿� */
#define SCL_PORT_IIC_4     GPIOA                       /* GPIO�˿� */
#define RCC_IIC_ENABLE_4    __HAL_RCC_GPIOA_CLK_ENABLE()       /* GPIO�˿�ʱ�� */
#define IIC_SCL_PIN_4       GPIO_PIN_11                 /* ���ӵ�SCLʱ���ߵ�GPIO */
#define IIC_SDA_PIN_4       GPIO_PIN_12                  /* ���ӵ�SDA�����ߵ�GPIO */
#define IIC_SCL_H_4()  HAL_GPIO_WritePin(SCL_PORT_IIC_4, IIC_SCL_PIN_4, GPIO_PIN_SET)		/* SCL = 1 */
#define IIC_SCL_L_4()  HAL_GPIO_WritePin(SCL_PORT_IIC_4, IIC_SCL_PIN_4, GPIO_PIN_RESET)		/* SCL = 0 */
#define IIC_SDA_H_4()  HAL_GPIO_WritePin(SDA_PORT_IIC_4, IIC_SDA_PIN_4, GPIO_PIN_SET)		/* SDA = 1 */
#define IIC_SDA_L_4()  HAL_GPIO_WritePin(SDA_PORT_IIC_4, IIC_SDA_PIN_4, GPIO_PIN_RESET)		/* SDA = 0 */
#define IIC_SDA_READ_4()  HAL_GPIO_ReadPin(SDA_PORT_IIC_4, IIC_SDA_PIN_4)	/* ��SDA����״̬ */

///************  IIC 5  *************/
//#define SDA_PORT_IIC_5     GPIOB                       /* GPIO�˿� */
//#define SCL_PORT_IIC_5     GPIOB                       /* GPIO�˿� */
//#define RCC_IIC_ENABLE_5    __HAL_RCC_GPIOB_CLK_ENABLE()       /* GPIO�˿�ʱ�� */
//#define IIC_SCL_PIN_5       GPIO_PIN_11                 /* ���ӵ�SCLʱ���ߵ�GPIO */
//#define IIC_SDA_PIN_5       GPIO_PIN_10                  /* ���ӵ�SDA�����ߵ�GPIO */
//#define IIC_SCL_H_5()  HAL_GPIO_WritePin(SCL_PORT_IIC_5, IIC_SCL_PIN_5, GPIO_PIN_SET)		/* SCL = 1 */
//#define IIC_SCL_L_5()  HAL_GPIO_WritePin(SCL_PORT_IIC_5, IIC_SCL_PIN_5, GPIO_PIN_RESET)		/* SCL = 0 */
//#define IIC_SDA_H_5()  HAL_GPIO_WritePin(SDA_PORT_IIC_5, IIC_SDA_PIN_5, GPIO_PIN_SET)		/* SDA = 1 */
//#define IIC_SDA_L_5()  HAL_GPIO_WritePin(SDA_PORT_IIC_5, IIC_SDA_PIN_5, GPIO_PIN_RESET)		/* SDA = 0 */
//#define IIC_SDA_READ_5()  HAL_GPIO_ReadPin(SDA_PORT_IIC_5, IIC_SDA_PIN_5)	/* ��SDA����״̬ */

#else
/*****************************************************************************************/
/* ����IIC�������ӵ�GPIO�˿�, �û�ֻ��Ҫ�޸�����4�д��뼴������ı�SCL��SDA������ */
#define SDA_PORT_IIC_1     GPIOB                       /* GPIO�˿� */
#define SCL_PORT_IIC_1     GPIOB                       /* GPIO�˿� */
#define RCC_IIC_ENABLE_1    __HAL_RCC_GPIOB_CLK_ENABLE()       /* GPIO�˿�ʱ�� */
#define IIC_SCL_PIN_1       GPIO_PIN_11                 /* ���ӵ�SCLʱ���ߵ�GPIO */
#define IIC_SDA_PIN_1       GPIO_PIN_10                  /* ���ӵ�SDA�����ߵ�GPIO */
/********************************************************************************************/

/* �����дSCL��SDA�ĺ꣬�����Ӵ���Ŀ���ֲ�ԺͿ��Ķ��� */
#define IIC_SCL_H_1()  HAL_GPIO_WritePin(SCL_PORT_IIC_1, IIC_SCL_PIN_1, GPIO_PIN_SET)		/* SCL = 1 */
#define IIC_SCL_L_1()  HAL_GPIO_WritePin(SCL_PORT_IIC_1, IIC_SCL_PIN_1, GPIO_PIN_RESET)		/* SCL = 0 */

#define IIC_SDA_H_1()  HAL_GPIO_WritePin(SDA_PORT_IIC_1, IIC_SDA_PIN_1, GPIO_PIN_SET)		/* SDA = 1 */
#define IIC_SDA_L_1()  HAL_GPIO_WritePin(SDA_PORT_IIC_1, IIC_SDA_PIN_1, GPIO_PIN_RESET)		/* SDA = 0 */

#define IIC_SDA_READ_1()  HAL_GPIO_ReadPin(SDA_PORT_IIC_1, IIC_SDA_PIN_1)	/* ��SDA����״̬ */

#endif


void IIC_GPIO_Init(void);
   
/*
*********************************************************************************************************
*	�� �� ��: IIC_Delay
*	����˵��: IIC����λ�ӳ٣����400KHz
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void IIC_Delay(void)
{
    uint8_t i;

    /*��
     	�����ʱ����ͨ��������AX-Pro�߼������ǲ��Եõ��ġ�
    	CPU��Ƶ72MHzʱ�����ڲ�Flash����, MDK���̲��Ż�
    	ѭ������Ϊ10ʱ��SCLƵ�� = 205KHz
    	ѭ������Ϊ7ʱ��SCLƵ�� = 347KHz�� SCL�ߵ�ƽʱ��1.5us��SCL�͵�ƽʱ��2.87us
     	ѭ������Ϊ5ʱ��SCLƵ�� = 421KHz�� SCL�ߵ�ƽʱ��1.25us��SCL�͵�ƽʱ��2.375us

    IAR���̱���Ч�ʸߣ���������Ϊ7
    */
    for (i = 0; i < 10; i++);
}

/*
*********************************************************************************************************
*	�� �� ��: IIC_Start
*	����˵��: CPU����IIC���������ź�
*	��    �Σ���
*	�� �� ֵ: ��
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
    /* ��SCL�ߵ�ƽʱ��SDA����һ�������ر�ʾIIC���������ź� */
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
*	�� �� ��: IIC_Stop
*	����˵��: CPU����IIC����ֹͣ�ź�
*	��    �Σ���
*	�� �� ֵ: ��
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
*	�� �� ��: IIC_SendByte
*	����˵��: CPU��IIC�����豸����8bit����
*	��    �Σ�_ucByte �� �ȴ����͵��ֽ�
*	�� �� ֵ: ��
*********************************************************************************************************
*/
#ifdef MUL
void IIC_Send_Byte_1(uint8_t _ucByte)
{
    uint8_t i;
    /* �ȷ����ֽڵĸ�λbit7 */
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
            IIC_SDA_H_1(); // �ͷ�����
        }
        _ucByte <<= 1;	/* ����һ��bit */
        IIC_Delay();
    }
}

void IIC_Send_Byte_2(uint8_t _ucByte)
{
    uint8_t i;
    /* �ȷ����ֽڵĸ�λbit7 */
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
            IIC_SDA_H_2(); // �ͷ�����
        }
        _ucByte <<= 1;	/* ����һ��bit */
        IIC_Delay();
    }
}

void IIC_Send_Byte_3(uint8_t _ucByte)
{
    uint8_t i;
    /* �ȷ����ֽڵĸ�λbit7 */
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
            IIC_SDA_H_3(); // �ͷ�����
        }
        _ucByte <<= 1;	/* ����һ��bit */
        IIC_Delay();
    }
}

void IIC_Send_Byte_4(uint8_t _ucByte)
{
    uint8_t i;
    /* �ȷ����ֽڵĸ�λbit7 */
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
            IIC_SDA_H_4(); // �ͷ�����
        }
        _ucByte <<= 1;	/* ����һ��bit */
        IIC_Delay();
    }
}

//void IIC_Send_Byte_5(uint8_t _ucByte)
//{
//    uint8_t i;
//    /* �ȷ����ֽڵĸ�λbit7 */
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
//            IIC_SDA_H_5(); // �ͷ�����
//        }
//        _ucByte <<= 1;	/* ����һ��bit */
//        IIC_Delay();
//    }
//}


#else

void IIC_Send_Byte_1(uint8_t _ucByte)
{
    uint8_t i;
    /* �ȷ����ֽڵĸ�λbit7 */
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
            IIC_SDA_H_1(); // �ͷ�����
        }
        _ucByte <<= 1;	/* ����һ��bit */
        IIC_Delay();
    }
}


#endif
/*
*********************************************************************************************************
*	�� �� ��: IIC_ReadByte
*	����˵��: CPU��IIC�����豸��ȡ8bit����
*	��    �Σ���
*	�� �� ֵ: ����������
*********************************************************************************************************
*/
#ifdef MUL
uint8_t IIC_Read_Byte_1(void)
{
    uint8_t i;
    uint8_t value;
    /* ������1��bitΪ���ݵ�bit7 */
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
    /* ������1��bitΪ���ݵ�bit7 */
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
    /* ������1��bitΪ���ݵ�bit7 */
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
    /* ������1��bitΪ���ݵ�bit7 */
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
//    /* ������1��bitΪ���ݵ�bit7 */
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
    /* ������1��bitΪ���ݵ�bit7 */
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
*	�� �� ��: IIC_WaitAck
*	����˵��: CPU����һ��ʱ�ӣ�����ȡ������ACKӦ���ź�
*	��    �Σ���
*	�� �� ֵ: ����0��ʾ��ȷӦ��1��ʾ��������Ӧ
*********************************************************************************************************
*/
#ifdef MUL
uint8_t IIC_Wait_Ack_1(void)
{
    uint8_t re;
    IIC_SDA_H_1();	/* CPU�ͷ�SDA���� */
    IIC_Delay();
    IIC_SCL_H_1();	/* CPU����SCL = 1, ��ʱ�����᷵��ACKӦ�� */
    IIC_Delay();
    if (IIC_SDA_READ_1())	/* CPU��ȡSDA����״̬ */
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
    IIC_SDA_H_2();	/* CPU�ͷ�SDA���� */
    IIC_Delay();
    IIC_SCL_H_2();	/* CPU����SCL = 1, ��ʱ�����᷵��ACKӦ�� */
    IIC_Delay();
    if (IIC_SDA_READ_2())	/* CPU��ȡSDA����״̬ */
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
    IIC_SDA_H_3();	/* CPU�ͷ�SDA���� */
    IIC_Delay();
    IIC_SCL_H_3();	/* CPU����SCL = 1, ��ʱ�����᷵��ACKӦ�� */
    IIC_Delay();
    if (IIC_SDA_READ_3())	/* CPU��ȡSDA����״̬ */
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
    IIC_SDA_H_4();	/* CPU�ͷ�SDA���� */
    IIC_Delay();
    IIC_SCL_H_4();	/* CPU����SCL = 1, ��ʱ�����᷵��ACKӦ�� */
    IIC_Delay();
    if (IIC_SDA_READ_4())	/* CPU��ȡSDA����״̬ */
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
//    IIC_SDA_H_5();	/* CPU�ͷ�SDA���� */
//    IIC_Delay();
//    IIC_SCL_H_5();	/* CPU����SCL = 1, ��ʱ�����᷵��ACKӦ�� */
//    IIC_Delay();
//    if (IIC_SDA_READ_5())	/* CPU��ȡSDA����״̬ */
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
    IIC_SDA_H_1();	/* CPU�ͷ�SDA���� */
    IIC_Delay();
    IIC_SCL_H_1();	/* CPU����SCL = 1, ��ʱ�����᷵��ACKӦ�� */
    IIC_Delay();
    if (IIC_SDA_READ_1())	/* CPU��ȡSDA����״̬ */
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
*	�� �� ��: IIC_Ack
*	����˵��: CPU����һ��ACK�ź�
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
#ifdef MUL
void IIC_Ack_1(void)
{
    IIC_SDA_L_1();	/* CPU����SDA = 0 */
    IIC_Delay();
    IIC_SCL_H_1();	/* CPU����1��ʱ�� */
    IIC_Delay();
    IIC_SCL_L_1();
    IIC_Delay();
    IIC_SDA_H_1();	/* CPU�ͷ�SDA���� */
}

void IIC_Ack_2(void)
{
    IIC_SDA_L_2();	/* CPU����SDA = 0 */
    IIC_Delay();
    IIC_SCL_H_2();	/* CPU����1��ʱ�� */
    IIC_Delay();
    IIC_SCL_L_2();
    IIC_Delay();
    IIC_SDA_H_2();	/* CPU�ͷ�SDA���� */
}

void IIC_Ack_3(void)
{
    IIC_SDA_L_3();	/* CPU����SDA = 0 */
    IIC_Delay();
    IIC_SCL_H_3();	/* CPU����1��ʱ�� */
    IIC_Delay();
    IIC_SCL_L_3();
    IIC_Delay();
    IIC_SDA_H_3();	/* CPU�ͷ�SDA���� */
}

void IIC_Ack_4(void)
{
    IIC_SDA_L_4();	/* CPU����SDA = 0 */
    IIC_Delay();
    IIC_SCL_H_4();	/* CPU����1��ʱ�� */
    IIC_Delay();
    IIC_SCL_L_4();
    IIC_Delay();
    IIC_SDA_H_4();	/* CPU�ͷ�SDA���� */
}

//void IIC_Ack_5(void)
//{
//    IIC_SDA_L_5();	/* CPU����SDA = 0 */
//    IIC_Delay();
//    IIC_SCL_H_5();	/* CPU����1��ʱ�� */
//    IIC_Delay();
//    IIC_SCL_L_5();
//    IIC_Delay();
//    IIC_SDA_H_5();	/* CPU�ͷ�SDA���� */
//}



#else
void IIC_Ack_1(void)
{
    IIC_SDA_L_1();	/* CPU����SDA = 0 */
    IIC_Delay();
    IIC_SCL_H_1();	/* CPU����1��ʱ�� */
    IIC_Delay();
    IIC_SCL_L_1();
    IIC_Delay();
    IIC_SDA_H_1();	/* CPU�ͷ�SDA���� */
}

#endif

/*
*********************************************************************************************************
*	�� �� ��: IIC_NAck
*	����˵��: CPU����1��NACK�ź�
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
#ifdef MUL
void IIC_NAck_1(void)
{
    IIC_SDA_H_1();	/* CPU����SDA = 1 */
    IIC_Delay();
    IIC_SCL_H_1();	/* CPU����1��ʱ�� */
    IIC_Delay();
    IIC_SCL_L_1();
    IIC_Delay();
}

void IIC_NAck_2(void)
{
    IIC_SDA_H_2();	/* CPU����SDA = 1 */
    IIC_Delay();
    IIC_SCL_H_2();	/* CPU����1��ʱ�� */
    IIC_Delay();
    IIC_SCL_L_2();
    IIC_Delay();
}


void IIC_NAck_3(void)
{
    IIC_SDA_H_3();	/* CPU����SDA = 1 */
    IIC_Delay();
    IIC_SCL_H_3();	/* CPU����1��ʱ�� */
    IIC_Delay();
    IIC_SCL_L_3();
    IIC_Delay();
}


void IIC_NAck_4(void)
{
    IIC_SDA_H_4();	/* CPU����SDA = 1 */
    IIC_Delay();
    IIC_SCL_H_4();	/* CPU����1��ʱ�� */
    IIC_Delay();
    IIC_SCL_L_4();
    IIC_Delay();
}


//void IIC_NAck_5(void)
//{
//    IIC_SDA_H_5();	/* CPU����SDA = 1 */
//    IIC_Delay();
//    IIC_SCL_H_5();	/* CPU����1��ʱ�� */
//    IIC_Delay();
//    IIC_SCL_L_5();
//    IIC_Delay();
//}


#else
void IIC_NAck_1(void)
{
    IIC_SDA_H_1();	/* CPU����SDA = 1 */
    IIC_Delay();
    IIC_SCL_H_1();	/* CPU����1��ʱ�� */
    IIC_Delay();
    IIC_SCL_L_1();
    IIC_Delay();
}


#endif
/*
*********************************************************************************************************
*	�� �� ��: IIC_GPIO_Config
*	����˵��: ����IIC���ߵ�GPIO������ģ��IO�ķ�ʽʵ��
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
#ifdef MUL
void IIC_GPIO_Init_1(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_IIC_ENABLE_1;	/* ��GPIOʱ�� */
    GPIO_InitStructure.Pin = IIC_SCL_PIN_1;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* ��©��� */
    HAL_GPIO_Init(SCL_PORT_IIC_1, &GPIO_InitStructure);
		GPIO_InitStructure.Pin = IIC_SDA_PIN_1;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* ��©��� */
    HAL_GPIO_Init(SDA_PORT_IIC_1, &GPIO_InitStructure);
    IIC_Stop_1();
}

void IIC_GPIO_Init_2(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_IIC_ENABLE_2;	/* ��GPIOʱ�� */
    GPIO_InitStructure.Pin = IIC_SCL_PIN_2;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* ��©��� */
    HAL_GPIO_Init(SCL_PORT_IIC_2, &GPIO_InitStructure);
		GPIO_InitStructure.Pin = IIC_SDA_PIN_2;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* ��©��� */
    HAL_GPIO_Init(SDA_PORT_IIC_2, &GPIO_InitStructure);
    IIC_Stop_2();
}

void IIC_GPIO_Init_3(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_IIC_ENABLE_3;	/* ��GPIOʱ�� */
    GPIO_InitStructure.Pin = IIC_SCL_PIN_3;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* ��©��� */
    HAL_GPIO_Init(SCL_PORT_IIC_3, &GPIO_InitStructure);
		GPIO_InitStructure.Pin = IIC_SDA_PIN_3;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* ��©��� */
    HAL_GPIO_Init(SDA_PORT_IIC_3, &GPIO_InitStructure);
    IIC_Stop_3();
}

void IIC_GPIO_Init_4(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_IIC_ENABLE_4;	/* ��GPIOʱ�� */
    GPIO_InitStructure.Pin = IIC_SCL_PIN_4;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* ��©��� */
    HAL_GPIO_Init(SCL_PORT_IIC_4, &GPIO_InitStructure);
		GPIO_InitStructure.Pin = IIC_SDA_PIN_4;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* ��©��� */
    HAL_GPIO_Init(SDA_PORT_IIC_4, &GPIO_InitStructure);
    IIC_Stop_4();
}

//void IIC_GPIO_Init_5(void)
//{
//    GPIO_InitTypeDef GPIO_InitStructure;
//    RCC_IIC_ENABLE_5;	/* ��GPIOʱ�� */
//    GPIO_InitStructure.Pin = IIC_SCL_PIN_5;
//    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
//    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* ��©��� */
//    HAL_GPIO_Init(SCL_PORT_IIC_5, &GPIO_InitStructure);
//		GPIO_InitStructure.Pin = IIC_SDA_PIN_5;
//    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
//    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* ��©��� */
//    HAL_GPIO_Init(SDA_PORT_IIC_5, &GPIO_InitStructure);
//    IIC_Stop_5();
//}

#else
void IIC_GPIO_Init_1(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_IIC_ENABLE_1;	/* ��GPIOʱ�� */
    GPIO_InitStructure.Pin = IIC_SCL_PIN_1;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* ��©��� */
    HAL_GPIO_Init(SCL_PORT_IIC_1, &GPIO_InitStructure);
		GPIO_InitStructure.Pin = IIC_SDA_PIN_1;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* ��©��� */
    HAL_GPIO_Init(SDA_PORT_IIC_1, &GPIO_InitStructure);
    IIC_Stop_1();
}

#endif


/*
*********************************************************************************************************
*	�� �� ��: IIC_CheckDevice
*	����˵��: ���IIC�����豸��CPU�����豸��ַ��Ȼ���ȡ�豸Ӧ�����жϸ��豸�Ƿ����
*	��    �Σ�_Address���豸��IIC���ߵ�ַ
*	�� �� ֵ: ����ֵ 0 ��ʾ��ȷ�� ����1��ʾδ̽�⵽
*********************************************************************************************************
*/

#ifdef MUL

uint8_t IIC_CheckDevice_1(uint8_t _Address)
{
    uint8_t ucAck;
    IIC_GPIO_Init_1();		/* ����GPIO */
    IIC_Start_1();		/* ���������ź� */
    /* �����豸��ַ+��д����bit��0 = w�� 1 = r) bit7 �ȴ� */
    IIC_Send_Byte_1(_Address|IIC_WR);
    ucAck = IIC_Wait_Ack_1();	/* ����豸��ACKӦ�� */
    IIC_Stop_1();			/* ����ֹͣ�ź� */
    return ucAck;
}

uint8_t IIC_CheckDevice_2(uint8_t _Address)
{
    uint8_t ucAck;
    IIC_GPIO_Init_2();		/* ����GPIO */
    IIC_Start_2();		/* ���������ź� */
    /* �����豸��ַ+��д����bit��0 = w�� 1 = r) bit7 �ȴ� */
    IIC_Send_Byte_2(_Address|IIC_WR);
    ucAck = IIC_Wait_Ack_2();	/* ����豸��ACKӦ�� */
    IIC_Stop_2();			/* ����ֹͣ�ź� */
    return ucAck;
}

uint8_t IIC_CheckDevice_3(uint8_t _Address)
{
    uint8_t ucAck;
    IIC_GPIO_Init_3();		/* ����GPIO */
    IIC_Start_3();		/* ���������ź� */
    /* �����豸��ַ+��д����bit��0 = w�� 1 = r) bit7 �ȴ� */
    IIC_Send_Byte_3(_Address|IIC_WR);
    ucAck = IIC_Wait_Ack_3();	/* ����豸��ACKӦ�� */
    IIC_Stop_3();			/* ����ֹͣ�ź� */
    return ucAck;
}

uint8_t IIC_CheckDevice_4(uint8_t _Address)
{
    uint8_t ucAck;
    IIC_GPIO_Init_4();		/* ����GPIO */
    IIC_Start_4();		/* ���������ź� */
    /* �����豸��ַ+��д����bit��0 = w�� 1 = r) bit7 �ȴ� */
    IIC_Send_Byte_4(_Address|IIC_WR);
    ucAck = IIC_Wait_Ack_4();	/* ����豸��ACKӦ�� */
    IIC_Stop_4();			/* ����ֹͣ�ź� */
    return ucAck;
}

//uint8_t IIC_CheckDevice_5(uint8_t _Address)
//{
//    uint8_t ucAck;
//    IIC_GPIO_Init_5();		/* ����GPIO */
//    IIC_Start_5();		/* ���������ź� */
//    /* �����豸��ַ+��д����bit��0 = w�� 1 = r) bit7 �ȴ� */
//    IIC_Send_Byte_5(_Address|IIC_WR);
//    ucAck = IIC_Wait_Ack_5();	/* ����豸��ACKӦ�� */
//    IIC_Stop_5();			/* ����ֹͣ�ź� */
//    return ucAck;
//}

#else 
uint8_t IIC_CheckDevice_1(uint8_t _Address)
{
    uint8_t ucAck;
    IIC_GPIO_Init_1();		/* ����GPIO */
    IIC_Start_1();		/* ���������ź� */
    /* �����豸��ַ+��д����bit��0 = w�� 1 = r) bit7 �ȴ� */
    IIC_Send_Byte_1(_Address|IIC_WR);
    ucAck = IIC_Wait_Ack_1();	/* ����豸��ACKӦ�� */
    IIC_Stop_1();			/* ����ֹͣ�ź� */
    return ucAck;
}

#endif



