/*
 * led.h
 *
 * created: 2022/06/15
 *  author: 
 */

#ifndef _LED_H
#define _LED_H

#define RED     44
#define GREEN   45
#define BLUE    46

#define ON  0   //开状态
#define OFF 1   //关状态

void LED_Init(void);

//实现灯亮的方法
void ledRed_ON(void);
void ledGreen_ON(void);
void ledBlue_ON(void);

//实现灯灭的方法
void ledRed_OFF(void);
void ledGreen_OFF(void);
void ledBlue_OFF(void);

#endif // _LED_H

