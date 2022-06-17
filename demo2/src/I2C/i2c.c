/*
 * I2C.c
 *
 * created: 2022/06/16
 *  author:
 */
#include "i2c.h"

void I2C_Init(void)
{
    gpio_enable(29, DIR_OUT);    // Pin: SPI0_CS2      SCL    时钟线
    gpio_enable(30, DIR_OUT);    // Pin: SPI0_CS3      SDA    数据线
    
}

//IIC的起始信号
void I2C_Start(void){

}

