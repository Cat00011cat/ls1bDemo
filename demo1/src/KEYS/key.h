/*
 * key.h
 *
 * created: 2022/06/16
 *  author: 
 */

#ifndef _KEY_H
#define _KEY_H

// ��������
#define KEY1 56 //s1
#define KEY2 57 //d2
#define KEY3 40 //s3
#define KEY4 41 //s4

// ����Ĭ��״̬ Ĭ�ϵ�ƽ�� 1 
#define key1Value gpio_read(KEY1)
#define key2Value gpio_read(KEY2)
#define key3Value gpio_read(KEY3)
#define key4Value gpio_read(KEY4)

//�������� ��ʼ���˿�
void KEY_Init(void);

//��ȡ����״̬
unsigned char KEY_Scan();

#endif // _KEY_H

