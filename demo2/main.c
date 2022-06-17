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
// 主程序
//-------------------------------------------------------------------------------------------------

int main(void)
{
    /*实现：按键一次按下灯亮，二次按下灯灭
    定义按键次数的标志位，，，按键取反。。。判断是第一次下还是第二次按下，，
    */
    signed char key1=1,key2=1,key3=1,key4=1;     //按键按下抬起的标志

    printk("\r\nmain() function.\r\n");

    ls1x_drv_init();            		/* Initialize device drivers */

    install_3th_libraries();      		/* Install 3th libraies */

//初始化硬件
    void LED_Init(void);
    void KEY_Init(void);
    void BEEP_Init(void);

    /*
     * 裸机主循环
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
#endif  /*延时亮灯*/

#if 0
//按键初始化为0
        int i=0;
        /*
            标志位flag：1、0不按下。
            按下的时候标志位状态改变。
        */
//接收按键扫描的值

        switch(KEY_Scan())
        {
            case 1:
                gpio_write(GREEN, OFF);
                i++;
                if(i%2==0)  //按键次数 偶数执行
                {
                    gpio_write(GREEN, ON);  // 偶数 灯灭
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
        //按键按下灯亮  实现
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

        //灯电平状态取反
        switch(KEY_Scan())
        {
            case 1:
                if(key1)    //按键按下抬起的标志
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
