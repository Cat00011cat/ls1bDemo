/*
 * key.c
 *
 * created: 2022/06/16
 *  author:
 */
#include "ls1b_gpio.h"
#include "key.h"
#include "tick.h"

void KEY_Init(void)
{
    gpio_enable(KEY1, DIR_IN);    // Pin: CAN1_RX
    gpio_enable(KEY2, DIR_IN);    // Pin: CAN1_TX
    gpio_enable(KEY3, DIR_IN);    // Pin: UART3_RX
    gpio_enable(KEY4, DIR_IN);    // Pin: UART3_TX
}

//��ȡ����״̬
unsigned char KEY_Scan()
{
    if ( gpio_read(KEY1) == 0 )
    {
        delay_ms( 5);                 /* �������� */
        if ( gpio_read( KEY1 ) == 0 )  /* ��ʾ��ȷ�������� */
        {
            while ( gpio_read( KEY1 ) == 0 );  /* �ȴ�������� */
            return 1;   //���ذ�����־
        }
    }
    else if ( gpio_read( KEY2 ) == 0 )
    {
        delay_ms( 5 );                 /* �������� */
        if ( gpio_read( KEY2 ) == 0 )  /* ��ʾ��ȷ�������� */
        {
            while ( gpio_read( KEY2 ) == 0 );  /* �ȴ�������� */
            return 2;
        }
    }
    else if ( gpio_read( KEY3 ) == 0 )
    {
        delay_ms( 5 );                 /* �������� */
        if ( gpio_read( KEY3 ) == 0 )  /* ��ʾ��ȷ�������� */
        {
            while ( gpio_read( KEY3 ) == 0 );  /* �ȴ�������� */
            return 3;
        }
    }
    else if ( gpio_read( KEY4 ) == 0 )
    {
        delay_ms( 5 );                 /* �������� */
        if ( gpio_read( KEY4 ) == 0 )  /* ��ʾ��ȷ�������� */
        {
            while ( gpio_read( KEY4 ) == 0 );  /* �ȴ�������� */
            return 4;
        }
    }
    return 0;
}


