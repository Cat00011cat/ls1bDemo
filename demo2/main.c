/*
 * Copyright (C) 2020-2021 Suzhou Tiancheng Software Ltd.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*
 * Loongson 1B Bare Program, Sample main file
 */

#include <stdio.h>

#include "ls1b.h"
#include "mips.h"

//-------------------------------------------------------------------------------------------------
// BSP
//-------------------------------------------------------------------------------------------------
#include "bsp.h"

#include "led.h"
#include "key.h"
#include "beep.h"
#include "i2c.h"

//-------------------------------------------------------------------------------------------------
// ������
//-------------------------------------------------------------------------------------------------

int main(void)
{
    /*ʵ�֣�����һ�ΰ��µ��������ΰ��µ���
    ���尴�������ı�־λ����������ȡ���������ж��ǵ�һ���»��ǵڶ��ΰ��£���
    */
    signed char key1=1,key2=1,key3=1,key4=1;     //��������̧��ı�־

    printk("\r\nmain() function.\r\n");

    ls1x_drv_init();            		/* Initialize device drivers */

    install_3th_libraries();      		/* Install 3th libraies */

//��ʼ��Ӳ��
    void LED_Init(void);
    void KEY_Init(void);
    void BEEP_Init(void);

    /*
     * �����ѭ��
     */
    for (;;)
    {
        unsigned int tickcount = get_clock_ticks();
        printk("tick count = %i\r\n", tickcount);
#if 0
        gpio_write(red, OFF);
        delay_ms(500);
        gpio_write(green, OFF);
        delay_ms(500);
        gpio_write(blue, OFF);
        delay_ms(500);
#endif  /*��ʱ����*/

#if 0
//������ʼ��Ϊ0
        int i=0;
        /*
            ��־λflag��1��0�����¡�
            ���µ�ʱ���־λ״̬�ı䡣
        */
//���հ���ɨ���ֵ

        switch(KEY_Scan())
        {
            case 1:
                gpio_write(GREEN, OFF);
                i++;
                if(i%2==0)  //�������� ż��ִ��
                {
                    gpio_write(GREEN, ON);  // ż�� ����
                }
                break;
            case 2:
                gpio_write(GREEN, OFF);
                i++;
                if(i%2==0)
                {
                    gpio_write(GREEN, ON);
                }
                break;
            case 3:
                gpio_write(BLUE, OFF);
                i++;
                if(i%2==0)
                {
                    gpio_write(GREEN, ON);
                }
            case 4:
                gpio_write(BEEP, OFF);
                i++;
                if(i%2==0)
                {
                    gpio_write(GREEN, ON);
                }
                break;
        }
#endif

#if 0
        //�������µ���  ʵ��
        switch(KEY_Scan())
        {
            case 1:
                ledRed_ON();
                break;
            case 2:
                ledGreen_ON();
                break;
            case 3:
                ledBlue_ON();
                break;
            case 4:
                BEEP_ON();
                break;
        }

#endif

        //�Ƶ�ƽ״̬ȡ��
        switch(KEY_Scan())
        {
            case 1:
                if(key1)    //��������̧��ı�־
                {
                    ledRed_ON();
                    key1 = 0;
                }
                else
                {
                    ledRed_OFF();
                    key1 = 1;
                }
                break;
            case 2:
                if(key2)
                {
                    ledGreen_ON();
                    key2 = 0;
                }
                else
                {
                    ledGreen_OFF();
                    key2 = 1;
                }
                break;
            case 3:
                if(key3)
                {
                    ledBlue_ON();
                    key3 = 0;
                }
                else
                {
                    ledBlue_OFF();
                    key3 = 1;
                }
                break;
            case 4:
                if(key4)
                {
                    BEEP_ON();
                    key4 = 0;
                }
                else
                {
                    BEEP_OFF();
                    key4 = 1;
                }
                break;
        }

    }

    /*
     * Never goto here!
     */
    return 0;
}

/*
 * @@ End
 */
