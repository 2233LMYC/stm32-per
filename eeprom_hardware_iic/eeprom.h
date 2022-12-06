
 
#ifndef __AT24C02_H
#define __AT24C02_H
 
#include <stdint.h>
 
#define AT24CXX_Write_ADDR 0xA0
#define AT24CXX_Read_ADDR  0xA1
#define AT24CXX_MAX_SIZE   256
#define AT24CXX_PAGE_SIZE  8
#define AT24CXX_PAGE_TOTAL (AT24CXX_MAX_SIZE/AT24CXX_PAGE_SIZE) 

#define IIC_PORT_eeprom hi2c2

 

int AT24C02_write(uint8_t addr, uint8_t* dataPtr, uint16_t dataSize);
int AT24C02_read (uint8_t addr, uint8_t* dataPtr, uint16_t dataSize);
 

 
#endif
