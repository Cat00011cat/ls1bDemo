/*
 * I2C.c
 *
 * created: 2022/06/16
 *  author:
 */
#include "i2c.h"

#define SDA 30   //数据线
#define SCL 29    //时钟线

#define OFF     1   //关
#define ON      0   //开
#define READ_SDA   1    //数据线SDA IN的状态

#define BYTE

//用于模拟数据线和时钟线  输出
void I2C_Init_Out(void)
{
    gpio_enable(30, DIR_OUT);    // Pin: SPI0_CS3      SDA    数据线
    gpio_enable(29, DIR_OUT);    // Pin: SPI0_CS2      SCL    时钟线

    //等待状态 上拉电阻
    gpio_write(SDA, OFF);    // gpio_write(int ioNum, bool val) 表示控制GPIO输出电平
    gpio_write(SCL, OFF);

}

//用于模拟数据线和时钟线  输入
void I2C_Init_In(void)
{
    gpio_enable(30, DIR_IN);    // Pin: SPI0_CS3      SDA    数据线
    gpio_enable(29, DIR_IN);    // Pin: SPI0_CS2      SCL    时钟线

    //等待状态 上拉电阻
    gpio_write(SDA, OFF);    // gpio_write(int ioNum, bool val) 表示控制GPIO输出电平
    gpio_write(SCL, OFF);

}

//IIC的启动信号
void I2C_Start(void)
{
    I2C_Init_Out();                 //初始化端口out输出电平
    gpio_write(SDA, OFF);    // 1
    gpio_write(SCL, OFF);   //   1
    delay_us(5);
    gpio_write(SDA, ON);    // 0   数据线从高到低的跳变
    delay_ms(5);  // 保证数据有效性
    gpio_write(SCL, OFF);   // 0 钳住iiC总线，，，准备发送或接收数据。
}

//IIC的停止信号
void IIC_Stop(void)
{
    I2C_Init_Out();                 //初始化端口out输出电平
    gpio_write(SDA, ON);    // 0
    gpio_write(SCL, ON);   //   0
    delay_ms(5);    // 保证数据有效性
    gpio_write(SDA, OFF);      //1
    gpio_write(SCL, OFF);   //1    恢复iic总线为 等待状态
    delay_ms(5);    // 保证数据有效性 消除电平毛刺
}

/* 谁发送的数据 谁就要接收应答信号。
    等待应答信号到来，，，超出时间则判断为超时。
    返回值：0成功，1失败
*/
signed char IIC_Wait_Ack(void)
{
    signed char timeOut=0;      //超时不响应。
    I2C_Init_In();  //直接掉函数初始化方向为IN。
    gpio_write(SDA, OFF);      //1
    delay_ms(5);                        //保证数据有效性
    gpio_write(SCL, OFF);   //1    恢复iic总线为 等待状态
    delay_ms(5);    //保证数据有效性
    while(READ_SDA)
    {
        timeOut++;
        //长时间未响应那么直接超时处理。
        if(timeOut>250)
        {
            //调用停止方法
            IIC_Stop();
            return 1;    //返回1  表示响应失败。
        }
    }
    gpio_write(SCL, OFF);   // 时钟电平高-低0跳变。数据传输
    return 0;   //成功标志。
}

//产生ack应答信号
void IIC_ACK(void)
{
    gpio_write(SCL, OFF);   //时钟线0
    I2C_Init_Out(); //初始化iic为输出。
    gpio_write(SDA, OFF);   //数据线0
    delay_ms(5);    //延时保证数据有效性
    gpio_write(SCL, ON);   //1 时钟线从高到低的跳变 数据发送
    delay_ms(5);    //延时保证数据有效性
    gpio_write(SCL, ON);   //0
}

//产生非ack应答信号
void IIC_NACK(void)
{
    gpio_write(SCL, OFF);   //时钟线0
    I2C_Init_Out(); //初始化iic为输出。
    gpio_write(SDA, ON);   //数据线1
    delay_ms(5);
    gpio_write(SCL, ON);   //时钟线1
    delay_ms(5);
    gpio_write(SCL, OFF);   //时钟线0
}

//iic发送一个字节8位。
/*
从机返回1应答，0无应答。
*/
void IIC_Send_Byte(signed char txd)
{
    signed char t;
    I2C_Init_Out(); //配置gpio iic端口方向为输入。
    gpio_write(SCL, ON);   //0 拉低时钟 开始数据传输。。。
    for(t=0; t<8; t++)          //循环的目的是将字节一位一位的传输出去    hex80->bin1000 0000
    {
        // 这里实现的的是 通过位运算 使数据变为二进制的01，，，从而改变数据线电平状态 让数据发出。。。
        gpio_write(SDA, (txd&0x80)>>7);
        txd<<=1;    //
        delay_ms(5);    //保证数据有效性。
        gpio_write(SCL, ON);   //时钟线1
        delay_ms(5);
        gpio_write(SCL, OFF);   //时钟线0
        delay_ms(5);
    }
}

//读1个字节，ack=1时，发送ACK，ack=0，发送nACK
signed char IIC_Read_Byte(signed char ack)
{
    signed char i,receive=0;
    I2C_Init_In();          //初始化数据线方向输入。
    for(i=0; i<8; i++)
    {
        gpio_write(SCL, OFF);   //0
        delay_ms(5);
        gpio_write(SCL, ON);    //挖成跳变
        receive<<=1;    //
        if(READ_SDA)
        {
            receive++;
        }
        delay_ms(5);    //
    }
    if(!ack)
    {
        IIC_NACK();    //调用函数返回非应答信号
    }
    if(ack)
    {
        IIC_ACK();
    }
    return receive;
}
