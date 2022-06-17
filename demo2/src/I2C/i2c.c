/*
 * I2C.c
 *
 * created: 2022/06/16
 *  author:
 */
#include "i2c.h"

#define SDA 30   //������
#define SCL 29    //ʱ����

#define OFF     1   //��
#define ON      0   //��
#define READ_SDA   1    //������SDA IN��״̬

#define BYTE

//����ģ�������ߺ�ʱ����  ���
void I2C_Init_Out(void)
{
    gpio_enable(30, DIR_OUT);    // Pin: SPI0_CS3      SDA    ������
    gpio_enable(29, DIR_OUT);    // Pin: SPI0_CS2      SCL    ʱ����

    //�ȴ�״̬ ��������
    gpio_write(SDA, OFF);    // gpio_write(int ioNum, bool val) ��ʾ����GPIO�����ƽ
    gpio_write(SCL, OFF);

}

//����ģ�������ߺ�ʱ����  ����
void I2C_Init_In(void)
{
    gpio_enable(30, DIR_IN);    // Pin: SPI0_CS3      SDA    ������
    gpio_enable(29, DIR_IN);    // Pin: SPI0_CS2      SCL    ʱ����

    //�ȴ�״̬ ��������
    gpio_write(SDA, OFF);    // gpio_write(int ioNum, bool val) ��ʾ����GPIO�����ƽ
    gpio_write(SCL, OFF);

}

//IIC�������ź�
void I2C_Start(void)
{
    I2C_Init_Out();                 //��ʼ���˿�out�����ƽ
    gpio_write(SDA, OFF);    // 1
    gpio_write(SCL, OFF);   //   1
    delay_us(5);
    gpio_write(SDA, ON);    // 0   �����ߴӸߵ��͵�����
    delay_ms(5);  // ��֤������Ч��
    gpio_write(SCL, OFF);   // 0 ǯסiiC���ߣ�����׼�����ͻ�������ݡ�
}

//IIC��ֹͣ�ź�
void IIC_Stop(void)
{
    I2C_Init_Out();                 //��ʼ���˿�out�����ƽ
    gpio_write(SDA, ON);    // 0
    gpio_write(SCL, ON);   //   0
    delay_ms(5);    // ��֤������Ч��
    gpio_write(SDA, OFF);      //1
    gpio_write(SCL, OFF);   //1    �ָ�iic����Ϊ �ȴ�״̬
    delay_ms(5);    // ��֤������Ч�� ������ƽë��
}

/* ˭���͵����� ˭��Ҫ����Ӧ���źš�
    �ȴ�Ӧ���źŵ�������������ʱ�����ж�Ϊ��ʱ��
    ����ֵ��0�ɹ���1ʧ��
*/
signed char IIC_Wait_Ack(void)
{
    signed char timeOut=0;      //��ʱ����Ӧ��
    I2C_Init_In();  //ֱ�ӵ�������ʼ������ΪIN��
    gpio_write(SDA, OFF);      //1
    delay_ms(5);                        //��֤������Ч��
    gpio_write(SCL, OFF);   //1    �ָ�iic����Ϊ �ȴ�״̬
    delay_ms(5);    //��֤������Ч��
    while(READ_SDA)
    {
        timeOut++;
        //��ʱ��δ��Ӧ��ôֱ�ӳ�ʱ����
        if(timeOut>250)
        {
            //����ֹͣ����
            IIC_Stop();
            return 1;    //����1  ��ʾ��Ӧʧ�ܡ�
        }
    }
    gpio_write(SCL, OFF);   // ʱ�ӵ�ƽ��-��0���䡣���ݴ���
    return 0;   //�ɹ���־��
}

//����ackӦ���ź�
void IIC_ACK(void)
{
    gpio_write(SCL, OFF);   //ʱ����0
    I2C_Init_Out(); //��ʼ��iicΪ�����
    gpio_write(SDA, OFF);   //������0
    delay_ms(5);    //��ʱ��֤������Ч��
    gpio_write(SCL, ON);   //1 ʱ���ߴӸߵ��͵����� ���ݷ���
    delay_ms(5);    //��ʱ��֤������Ч��
    gpio_write(SCL, ON);   //0
}

//������ackӦ���ź�
void IIC_NACK(void)
{
    gpio_write(SCL, OFF);   //ʱ����0
    I2C_Init_Out(); //��ʼ��iicΪ�����
    gpio_write(SDA, ON);   //������1
    delay_ms(5);
    gpio_write(SCL, ON);   //ʱ����1
    delay_ms(5);
    gpio_write(SCL, OFF);   //ʱ����0
}

//iic����һ���ֽ�8λ��
/*
�ӻ�����1Ӧ��0��Ӧ��
*/
void IIC_Send_Byte(signed char txd)
{
    signed char t;
    I2C_Init_Out(); //����gpio iic�˿ڷ���Ϊ���롣
    gpio_write(SCL, ON);   //0 ����ʱ�� ��ʼ���ݴ��䡣����
    for(t=0; t<8; t++)          //ѭ����Ŀ���ǽ��ֽ�һλһλ�Ĵ����ȥ    hex80->bin1000 0000
    {
        // ����ʵ�ֵĵ��� ͨ��λ���� ʹ���ݱ�Ϊ�����Ƶ�01�������Ӷ��ı������ߵ�ƽ״̬ �����ݷ���������
        gpio_write(SDA, (txd&0x80)>>7);
        txd<<=1;    //
        delay_ms(5);    //��֤������Ч�ԡ�
        gpio_write(SCL, ON);   //ʱ����1
        delay_ms(5);
        gpio_write(SCL, OFF);   //ʱ����0
        delay_ms(5);
    }
}

//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK
signed char IIC_Read_Byte(signed char ack)
{
    signed char i,receive=0;
    I2C_Init_In();          //��ʼ�������߷������롣
    for(i=0; i<8; i++)
    {
        gpio_write(SCL, OFF);   //0
        delay_ms(5);
        gpio_write(SCL, ON);    //�ڳ�����
        receive<<=1;    //
        if(READ_SDA)
        {
            receive++;
        }
        delay_ms(5);    //
    }
    if(!ack)
    {
        IIC_NACK();    //���ú������ط�Ӧ���ź�
    }
    if(ack)
    {
        IIC_ACK();
    }
    return receive;
}
