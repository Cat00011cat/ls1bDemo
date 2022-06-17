/*
 * beep.c
 *
 * created: 2022/06/16
 *  author:
 */

#include "ls1b_gpio.h"
#include "beep.h"

void BEEP_Init(void)
{
    gpio_enable(BEEP, DIR_IN);    // Pin: UART0_DCD
    gpio_write(BEEP,OFF);   // 场效应管 增强型 n沟 箭头向内 低电平不响
}

//蜂鸣器 响起方法的实现
void BEEP_ON(void)
{
    gpio_write(BEEP,ON);
}

void BEEP_OFF(void)
{
    gpio_write(BEEP,OFF);
}
