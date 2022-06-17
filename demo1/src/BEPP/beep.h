/*
 * beep.h
 *
 * created: 2022/06/16
 *  author:
 */

#ifndef _BEEP_H
#define _BEEP_H

#define BEEP 48

#define ON  0
#define OFF 1

// 初始化蜂鸣器电路
void BEEP_Init(void);

//蜂鸣器 响起方法的实现
void BEEP_ON(void);
//蜂鸣器 关闭方法的实现
void BEEP_OFF(void);

#endif // _BEEP_H

