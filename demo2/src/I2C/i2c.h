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

// ��ʼ��ʱ���ߺ�������   �㲥Ѱַ��Ҫ����źŵ�gpio�ڳ�ʼ��
void I2C_Init_Out(void);
//����Ӧ���źŵ�ʱ����Ҫ��ʼ��
void I2C_Init_In(void);

// ����iic�����źš�
void I2C_Start(void);
//IIC��ֹͣ�ź�
void IIC_Stop(void);
// �ȴ�Ӧ���źŵĵ���
signed char IIC_Wait_Ack(void);
//����ACKӦ���ź�
void IIC_ACK(void);
//������ACKӦ���ź�
void IIC_NACK(void);
//iic����һ���ֽ�
void IIC_Send_Byte(signed char txd);
//iic��ȡһ���ֽ�
signed char IIC_Read_Byte(signed char ack);

#endif // _I2C_H



