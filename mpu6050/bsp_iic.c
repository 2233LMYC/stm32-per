/*
  ******************************************************************************
  * File Name          : bsp_iic.c
  * Description        : this code is used for at24c02 application
  * Author             : 
  * Date               : 
  ******************************************************************************
*/
 
/*! -------------------------------------------------------------------------- */
/*! Include headers */
#include "bsp_iic.h"
 
/*
	Ӧ��˵����
	�ڷ���IIC�豸ǰ�����ȵ��� IIC_CheckDevice() ���IIC�豸�Ƿ��������ú���������GPIO
*/


/*****************************************************************************************/
/* ����IIC�������ӵ�GPIO�˿�, �û�ֻ��Ҫ�޸�����4�д��뼴������ı�SCL��SDA������ */
#define SDA_PORT_IIC     GPIOB                       /* GPIO�˿� */
#define SCL_PORT_IIC     GPIOB                       /* GPIO�˿� */
#define RCC_IIC_ENABLE    __HAL_RCC_GPIOB_CLK_ENABLE()       /* GPIO�˿�ʱ�� */
#define IIC_SCL_PIN       GPIO_PIN_10                 /* ���ӵ�SCLʱ���ߵ�GPIO */
#define IIC_SDA_PIN       GPIO_PIN_11                  /* ���ӵ�SDA�����ߵ�GPIO */
/********************************************************************************************/

/* �����дSCL��SDA�ĺ꣬�����Ӵ���Ŀ���ֲ�ԺͿ��Ķ��� */
#define IIC_SCL_1()  HAL_GPIO_WritePin(SCL_PORT_IIC, IIC_SCL_PIN, GPIO_PIN_SET)		/* SCL = 1 */
#define IIC_SCL_0()  HAL_GPIO_WritePin(SCL_PORT_IIC, IIC_SCL_PIN, GPIO_PIN_RESET)		/* SCL = 0 */

#define IIC_SDA_1()  HAL_GPIO_WritePin(SDA_PORT_IIC, IIC_SDA_PIN, GPIO_PIN_SET)		/* SDA = 1 */
#define IIC_SDA_0()  HAL_GPIO_WritePin(SDA_PORT_IIC, IIC_SDA_PIN, GPIO_PIN_RESET)		/* SDA = 0 */

#define IIC_SDA_READ()  HAL_GPIO_ReadPin(SDA_PORT_IIC, IIC_SDA_PIN)	/* ��SDA����״̬ */

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
void IIC_Start(void)
{
    /* ��SCL�ߵ�ƽʱ��SDA����һ�������ر�ʾIIC���������ź� */
    IIC_SDA_1();
    IIC_SCL_1();
    IIC_Delay();
    IIC_SDA_0();
    IIC_Delay();
    IIC_SCL_0();
    IIC_Delay();
}

/*
*********************************************************************************************************
*	�� �� ��: IIC_Start
*	����˵��: CPU����IIC����ֹͣ�ź�
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void IIC_Stop(void)
{
    /* ��SCL�ߵ�ƽʱ��SDA����һ�������ر�ʾIIC����ֹͣ�ź� */
    IIC_SDA_0();
    IIC_SCL_1();
    IIC_Delay();
    IIC_SDA_1();
}

/*
*********************************************************************************************************
*	�� �� ��: IIC_SendByte
*	����˵��: CPU��IIC�����豸����8bit����
*	��    �Σ�_ucByte �� �ȴ����͵��ֽ�
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void IIC_Send_Byte(uint8_t _ucByte)
{
    uint8_t i;

    /* �ȷ����ֽڵĸ�λbit7 */
    for (i = 0; i < 8; i++)
    {
        if (_ucByte & 0x80)
        {
            IIC_SDA_1();
        }
        else
        {
            IIC_SDA_0();
        }
        IIC_Delay();
        IIC_SCL_1();
        IIC_Delay();
        IIC_SCL_0();
        if (i == 7)
        {
            IIC_SDA_1(); // �ͷ�����
        }
        _ucByte <<= 1;	/* ����һ��bit */
        IIC_Delay();
    }
}

/*
*********************************************************************************************************
*	�� �� ��: IIC_ReadByte
*	����˵��: CPU��IIC�����豸��ȡ8bit����
*	��    �Σ���
*	�� �� ֵ: ����������
*********************************************************************************************************
*/
uint8_t IIC_Read_Byte(uint8_t ack)
{
    uint8_t i;
    uint8_t value;

    /* ������1��bitΪ���ݵ�bit7 */
    value = 0;
    for (i = 0; i < 8; i++)
    {
        value <<= 1;
        IIC_SCL_1();
        IIC_Delay();
        if (IIC_SDA_READ())
        {
            value++;
        }
        IIC_SCL_0();
        IIC_Delay();
    }
    if(ack==0)
        IIC_NAck();
    else
        IIC_Ack();
    return value;
}

/*
*********************************************************************************************************
*	�� �� ��: IIC_WaitAck
*	����˵��: CPU����һ��ʱ�ӣ�����ȡ������ACKӦ���ź�
*	��    �Σ���
*	�� �� ֵ: ����0��ʾ��ȷӦ��1��ʾ��������Ӧ
*********************************************************************************************************
*/
uint8_t IIC_Wait_Ack(void)
{
    uint8_t re;

    IIC_SDA_1();	/* CPU�ͷ�SDA���� */
    IIC_Delay();
    IIC_SCL_1();	/* CPU����SCL = 1, ��ʱ�����᷵��ACKӦ�� */
    IIC_Delay();
    if (IIC_SDA_READ())	/* CPU��ȡSDA����״̬ */
    {
        re = 1;
    }
    else
    {
        re = 0;
    }
    IIC_SCL_0();
    IIC_Delay();
    return re;
}

/*
*********************************************************************************************************
*	�� �� ��: IIC_Ack
*	����˵��: CPU����һ��ACK�ź�
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void IIC_Ack(void)
{
    IIC_SDA_0();	/* CPU����SDA = 0 */
    IIC_Delay();
    IIC_SCL_1();	/* CPU����1��ʱ�� */
    IIC_Delay();
    IIC_SCL_0();
    IIC_Delay();
    IIC_SDA_1();	/* CPU�ͷ�SDA���� */
}

/*
*********************************************************************************************************
*	�� �� ��: IIC_NAck
*	����˵��: CPU����1��NACK�ź�
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void IIC_NAck(void)
{
    IIC_SDA_1();	/* CPU����SDA = 1 */
    IIC_Delay();
    IIC_SCL_1();	/* CPU����1��ʱ�� */
    IIC_Delay();
    IIC_SCL_0();
    IIC_Delay();
}

/*
*********************************************************************************************************
*	�� �� ��: IIC_GPIO_Config
*	����˵��: ����IIC���ߵ�GPIO������ģ��IO�ķ�ʽʵ��
*	��    �Σ���
*	�� �� ֵ: ��
*********************************************************************************************************
*/
void IIC_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_IIC_ENABLE;	/* ��GPIOʱ�� */

    GPIO_InitStructure.Pin = IIC_SCL_PIN;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* ��©��� */
    HAL_GPIO_Init(SCL_PORT_IIC, &GPIO_InitStructure);
		GPIO_InitStructure.Pin = IIC_SDA_PIN;
    GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;  	/* ��©��� */
    HAL_GPIO_Init(SDA_PORT_IIC, &GPIO_InitStructure);

    /* ��һ��ֹͣ�ź�, ��λIIC�����ϵ������豸������ģʽ */
    IIC_Stop();
}

/*
*********************************************************************************************************
*	�� �� ��: IIC_CheckDevice
*	����˵��: ���IIC�����豸��CPU�����豸��ַ��Ȼ���ȡ�豸Ӧ�����жϸ��豸�Ƿ����
*	��    �Σ�_Address���豸��IIC���ߵ�ַ
*	�� �� ֵ: ����ֵ 0 ��ʾ��ȷ�� ����1��ʾδ̽�⵽
*********************************************************************************************************
*/
uint8_t IIC_CheckDevice(uint8_t _Address)
{
    uint8_t ucAck;

    IIC_GPIO_Init();		/* ����GPIO */

    IIC_Start();		/* ���������ź� */

    /* �����豸��ַ+��д����bit��0 = w�� 1 = r) bit7 �ȴ� */
    IIC_Send_Byte(_Address|IIC_WR);
    ucAck = IIC_Wait_Ack();	/* ����豸��ACKӦ�� */

    IIC_Stop();			/* ����ֹͣ�ź� */

    return ucAck;
}



