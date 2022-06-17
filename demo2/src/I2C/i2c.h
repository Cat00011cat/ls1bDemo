/*
 * I2C.h
 *
 * created: 2022/06/16
 *  author: 
 */

#ifndef _I2C_H
#define _I2C_H

#include "ls1b_gpio.h"

// 初始化时钟线和数据线
void I2C_Init(void);

// 产生iic起始信号。
void I2C_Start(void);


#endif // _I2C_H

