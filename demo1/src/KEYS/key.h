/*
 * key.h
 *
 * created: 2022/06/16
 *  author: 
 */

#ifndef _KEY_H
#define _KEY_H

// 按键定义
#define KEY1 56 //s1
#define KEY2 57 //d2
#define KEY3 40 //s3
#define KEY4 41 //s4

// 按键默认状态 默认电平： 1 
#define key1Value gpio_read(KEY1)
#define key2Value gpio_read(KEY2)
#define key3Value gpio_read(KEY3)
#define key4Value gpio_read(KEY4)

//驱动按键 初始化端口
void KEY_Init(void);

//获取按键状态
unsigned char KEY_Scan();

#endif // _KEY_H

