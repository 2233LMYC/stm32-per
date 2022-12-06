
#include "eeprom.h"
#include "main.h"
#include "i2c.h"

 
int AT24C02_write(uint8_t addr, uint8_t* dataPtr, uint16_t dataSize)
{
    if (0 == dataSize) { return -1; }
    
    int res = HAL_OK;
    
    int selectPage_idx  = addr % AT24CXX_PAGE_SIZE;
    int selectPage_rest = AT24CXX_PAGE_SIZE - selectPage_idx;
    
    if (dataSize <= selectPage_rest) {
        res = HAL_I2C_Mem_Write(&IIC_PORT_eeprom, 
                                 AT24CXX_Write_ADDR, 
                                 addr,
                                 I2C_MEMADD_SIZE_8BIT, 
                                 dataPtr,
                                 dataSize,
                                 0xFF);
        
        if (HAL_OK != res) { return -1; }
        
        HAL_Delay(10);
        
    } else {
    
        res = HAL_I2C_Mem_Write(&IIC_PORT_eeprom, 
                                 AT24CXX_Write_ADDR, 
                                 addr,
                                 I2C_MEMADD_SIZE_8BIT, 
                                 dataPtr,
                                 selectPage_rest,
                                 0xFF);
        
        if (HAL_OK != res) { return -1; }
        
        addr     += selectPage_rest;
        dataSize -= selectPage_rest;
        dataPtr  += selectPage_rest;
        
        HAL_Delay(5);
        
        /*! 2 write nextPage full */
        int fullPage = dataSize/AT24CXX_PAGE_SIZE;
        for (int iPage = 0; iPage < fullPage; ++iPage) {
            res = HAL_I2C_Mem_Write(&IIC_PORT_eeprom, 
                                     AT24CXX_Write_ADDR, 
                                     addr,
                                     I2C_MEMADD_SIZE_8BIT, 
                                     dataPtr,
                                     AT24CXX_PAGE_SIZE,
                                     0xFF);
            
            if (HAL_OK != res) { return -1; }
            
            HAL_Delay(5);
            
            addr     += AT24CXX_PAGE_SIZE;
            dataSize -= AT24CXX_PAGE_SIZE;
            dataPtr  += AT24CXX_PAGE_SIZE;
        }
        
        if (0 != dataSize) {
            res = HAL_I2C_Mem_Write(&IIC_PORT_eeprom, 
                                     AT24CXX_Write_ADDR, 
                                     addr,
                                     I2C_MEMADD_SIZE_8BIT, 
                                     dataPtr,
                                     dataSize,
                                     0xFF);
        
            if (HAL_OK != res) { return -1; }
            
            HAL_Delay(5);
        }
    }
    
    return 0;
}

int AT24C02_read(uint8_t addr, uint8_t* dataPtr, uint16_t dataSize)
{
    int res = HAL_I2C_Mem_Read(&IIC_PORT_eeprom,
                                AT24CXX_Read_ADDR,
                                addr,
                                I2C_MEMADD_SIZE_8BIT,
                                dataPtr,
                                dataSize,
                                0xFF);
    
    if (HAL_OK != res) { return -1; }
    
    return 0;
}

