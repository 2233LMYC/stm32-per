#include "USB_Mouse.h"
#include "usb_device.h"
#include "usbd_core.h"
#include "usbd_desc.h"
#include "usbd_hid.h"
#include "usbd_def.h"


extern USBD_HandleTypeDef hUsbDeviceFS;

void Click_L()
{
	uint8_t buf0[4] = {1,0,0,0};
	uint8_t buf1[4] = {0,0,0,0};
	USBD_HID_SendReport(&hUsbDeviceFS,buf0,4);//����������
	HAL_Delay(10);
	USBD_HID_SendReport(&hUsbDeviceFS,buf1,4);//�ɿ���갴��
	HAL_Delay(10);
}
void Click_R()
{
	uint8_t buf0[4] = {2,0,0,0};
	uint8_t buf1[4] = {0,0,0,0};
	USBD_HID_SendReport(&hUsbDeviceFS,buf0,4);//��������Ҽ�
	HAL_Delay(10);
	USBD_HID_SendReport(&hUsbDeviceFS,buf1,4);//�ɿ���갴��
	HAL_Delay(10);
}
void Click_M()
{
	uint8_t buf0[4] = {4,0,0,0};
	uint8_t buf1[4] = {0,0,0,0};
	USBD_HID_SendReport(&hUsbDeviceFS,buf0,4);//��������м�
	HAL_Delay(10);
	USBD_HID_SendReport(&hUsbDeviceFS,buf1,4);//�ɿ�����м�
	HAL_Delay(10);
}
void Scroll(int8_t x)
{
	uint8_t buf[4] = {0,0,0,0};
	buf[3]=x;
	USBD_HID_SendReport(&hUsbDeviceFS,buf,4);//������
	HAL_Delay(10);
}
void Move(int8_t x,int8_t y)
{
	uint8_t buf[4] = {0,0,0,0};
	buf[1]=x;
	buf[2]=y;
	USBD_HID_SendReport(&hUsbDeviceFS,buf,4);//����ƶ�
	HAL_Delay(10);
}


