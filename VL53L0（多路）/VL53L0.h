#ifndef _VL53L0_H
#define _VL53L0_H

#define VL53L0X_REG_IDENTIFICATION_MODEL_ID         0xc0
#define VL53L0X_REG_IDENTIFICATION_REVISION_ID      0xc2
#define VL53L0X_REG_PRE_RANGE_CONFIG_VCSEL_PERIOD   0x50
#define VL53L0X_REG_FINAL_RANGE_CONFIG_VCSEL_PERIOD 0x70
#define VL53L0X_REG_SYSRANGE_START                  0x00
#define VL53L0X_REG_RESULT_INTERRUPT_STATUS         0x13
#define VL53L0X_REG_RESULT_RANGE_STATUS             0x14
#define VL53L0X_Add 0x29

#include "stm32f1xx_hal.h"
#include "IIC.h"

#define MUL  1

uint16_t bswap(uint8_t b[]); 				 
uint16_t VL53L0X_decode_vcsel_period(short vcsel_period_reg);	
uint16_t makeuint16(int lsb, int msb);


#ifdef MUL
uint8_t VL53L0X_Write_Len_1(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf);//连续写
uint8_t VL53L0X_Read_Len_1(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf);//连续读
uint8_t VL53L0X_Write_Byte_1(uint8_t reg,uint8_t data);//写一个字节
uint8_t VL53L0X_Read_Byte_1(uint8_t reg);//读一个字节
int GET_VL53L0_1(uint8_t addr);
int VL53L0_Init_1(uint8_t addr);

uint8_t VL53L0X_Write_Len_2(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf);//连续写
uint8_t VL53L0X_Read_Len_2(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf);//连续读
uint8_t VL53L0X_Write_Byte_2(uint8_t reg,uint8_t data);//写一个字节
uint8_t VL53L0X_Read_Byte_2(uint8_t reg);//读一个字节
int GET_VL53L0_2(uint8_t addr);
int VL53L0_Init_2(uint8_t addr);

uint8_t VL53L0X_Write_Len_3(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf);//连续写
uint8_t VL53L0X_Read_Len_3(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf);//连续读
uint8_t VL53L0X_Write_Byte_3(uint8_t reg,uint8_t data);//写一个字节
uint8_t VL53L0X_Read_Byte_3(uint8_t reg);//读一个字节
int GET_VL53L0_3(uint8_t addr);
int VL53L0_Init_3(uint8_t addr);

uint8_t VL53L0X_Write_Len_4(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf);//连续写
uint8_t VL53L0X_Read_Len_4(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf);//连续读
uint8_t VL53L0X_Write_Byte_4(uint8_t reg,uint8_t data);//写一个字节
uint8_t VL53L0X_Read_Byte_4(uint8_t reg);//读一个字节
int GET_VL53L0_4(uint8_t addr);
int VL53L0_Init_4(uint8_t addr);

//uint8_t VL53L0X_Write_Len_5(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf);//连续写
//uint8_t VL53L0X_Read_Len_5(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf);//连续读
//uint8_t VL53L0X_Write_Byte_5(uint8_t reg,uint8_t data);//写一个字节
//uint8_t VL53L0X_Read_Byte_5(uint8_t reg);//读一个字节
//int GET_VL53L0_5(uint8_t addr);
//int VL53L0_Init_5(uint8_t addr);

#else
uint8_t VL53L0X_Write_Len_1(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf);//连续写
uint8_t VL53L0X_Read_Len_1(uint8_t addr,uint8_t reg,uint8_t len,uint8_t *buf);//连续读
uint8_t VL53L0X_Write_Byte_1(uint8_t reg,uint8_t data);//写一个字节
uint8_t VL53L0X_Read_Byte_1(uint8_t reg);//读一个字节
int GET_VL53L0_1(uint8_t addr);
int VL53L0_Init_1(uint8_t addr);


#endif



#endif
