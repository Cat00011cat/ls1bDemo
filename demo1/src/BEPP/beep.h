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

// ��ʼ����������·
void BEEP_Init(void);

//������ ���𷽷���ʵ��
void BEEP_ON(void);
//������ �رշ�����ʵ��
void BEEP_OFF(void);

#endif // _BEEP_H

