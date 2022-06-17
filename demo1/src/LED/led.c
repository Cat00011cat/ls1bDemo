/*
 * led.c
 *
 * created: 2022/06/15
 *  author:
 */
#include "ls1b_gpio.h"
#include "led.h"

//��ʼ��led��GPIO�˿�
void LED_Init(void)
{
    gpio_enable(RED, DIR_OUT);   // Pin: UART0_RTS
    gpio_enable(GREEN, DIR_OUT);   // Pin: UART0_CTS
    gpio_enable(BLUE, DIR_OUT);   // Pin: UART0_DSR
    //��ɫ��Ĭ��״̬    ��Ч��ܣ�������ǿ��  n�� 1
    gpio_write(RED, OFF);
    gpio_write(GREEN, OFF);
    gpio_write(BLUE, OFF);
}


//��װ�������� �����ƵƵ�������Ҫ�õĵط�ֱ�ӵ��þ���ʵ�ֵ�ƵĲ�����
/*
ON��״̬
OFF�ر�״̬
*/
void ledRed_ON(void){
    gpio_write(RED, ON);
}

void ledGreen_ON(void){
    gpio_write(GREEN, ON);
}

void ledBlue_ON(void){
    gpio_write(BLUE, ON);
}

//��װ�������� �����ƵƵ�������Ҫ�õĵط�ֱ�ӵ��þ���ʵ�ֵ�ƵĲ�����
/*
ON��״̬
OFF�ر�״̬
*/
void ledRed_OFF(void){
    gpio_write(RED, OFF);
}

void ledGreen_OFF(void){
    gpio_write(GREEN, OFF);
}

void ledBlue_OFF(void){
    gpio_write(BLUE, OFF);
}
