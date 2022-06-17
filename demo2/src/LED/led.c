/*
 * led.c
 *
 * created: 2022/06/15
 *  author:
 */
#include "ls1b_gpio.h"
#include "led.h"

//初始化led的GPIO端口
void LED_Init(void)
{
    gpio_enable(RED, DIR_OUT);   // Pin: UART0_RTS
    gpio_enable(GREEN, DIR_OUT);   // Pin: UART0_CTS
    gpio_enable(BLUE, DIR_OUT);   // Pin: UART0_DSR
    //三色灯默认状态    场效验管，，，增强型  n沟 1
    gpio_write(RED, OFF);
    gpio_write(GREEN, OFF);
    gpio_write(BLUE, OFF);
}


//封装三个方法 来控制灯的灭。在需要用的地方直接调用就能实现点灯的操作。
/*
ON开状态
OFF关闭状态
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

//封装三个方法 来控制灯的灭。在需要用的地方直接调用就能实现点灯的操作。
/*
ON开状态
OFF关闭状态
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
