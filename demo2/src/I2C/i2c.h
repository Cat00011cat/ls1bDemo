/*
 * I2C.h
 *
 * created: 2022/06/16
 *  author: 
 */

#ifndef _I2C_H
#define _I2C_H

#include "ls1b_gpio.h"
#include "tick.h"

// 初始化时钟线和数据线   广播寻址需要输出信号的gpio口初始化
void I2C_Init_Out(void);
//输入应答信号的时候需要初始化
void I2C_Init_In(void);

// 产生iic启动信号。
void I2C_Start(void);
//IIC的停止信号
void IIC_Stop(void);
// 等待应答信号的到来
signed char IIC_Wait_Ack(void);
//产生ACK应答信号
void IIC_ACK(void);
//产生非ACK应答信号
void IIC_NACK(void);
//iic发送一个字节
void IIC_Send_Byte(signed char txd);
//iic读取一个字节
signed char IIC_Read_Byte(signed char ack);

#endif // _I2C_H



