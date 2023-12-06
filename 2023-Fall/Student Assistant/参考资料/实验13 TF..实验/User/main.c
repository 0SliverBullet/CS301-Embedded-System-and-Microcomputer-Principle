/**
 ****************************************************************************************************
 * @file        main.c
 * @author      ����ԭ���Ŷ�(ALIENTEK)
 * @version     V1.0
 * @date        2020-04-21
 * @brief       TFTLCD(MCU��) ʵ��
 * @license     Copyright (c) 2020-2032, ������������ӿƼ����޹�˾
 ****************************************************************************************************
 * @attention
 *
 * ʵ��ƽ̨:����ԭ�� STM32F103������
 * ������Ƶ:www.yuanzige.com
 * ������̳:www.openedv.com
 * ��˾��ַ:www.alientek.com
 * �����ַ:openedv.taobao.com
 *
 ****************************************************************************************************
 */

#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "./BSP/LCD/lcd.h"


int main(void)
{
    uint8_t x = 0;
    uint8_t lcd_id[12];

    HAL_Init();                                         /* ��ʼ��HAL�� */
    sys_stm32_clock_init(RCC_PLL_MUL9);                 /* ����ʱ��, 72Mhz */
    delay_init(72);                                     /* ��ʱ��ʼ�� */
    usart_init(115200);                                 /* ���ڳ�ʼ��Ϊ115200 */
    led_init();                                         /* ��ʼ��LED */
    lcd_init();                                         /* ��ʼ��LCD */
    g_point_color = RED;
    sprintf((char *)lcd_id, "LCD ID:%04X", lcddev.id);  /* ��LCD ID��ӡ��lcd_id���� */

    while (1)
    {
        switch (x)
        {
        case 0:
            lcd_clear(WHITE);
            break;

        case 1:
            lcd_clear(BLACK);
            break;

        case 2:
            lcd_clear(BLUE);
            break;

        case 3:
            lcd_clear(RED);
            break;

        case 4:
            lcd_clear(MAGENTA);
            break;

        case 5:
            lcd_clear(GREEN);
            break;

        case 6:
            lcd_clear(CYAN);
            break;

        case 7:
            lcd_clear(YELLOW);
            break;

        case 8:
            lcd_clear(BRRED);
            break;

        case 9:
            lcd_clear(GRAY);
            break;

        case 10:
            lcd_clear(LGRAY);
            break;

        case 11:
            lcd_clear(BROWN);
            break;
        }

        lcd_show_string(10, 40, 240, 32, 32, "STM32", RED);
        lcd_show_string(10, 80, 240, 24, 24, "TFTLCD TEST", RED);
        lcd_show_string(10, 110, 240, 16, 16, "ATOM@ALIENTEK", RED);
        lcd_show_string(10, 130, 240, 16, 16, (char *)lcd_id, RED); /* ��ʾLCD ID */
        x++;

        if (x == 12)
            x = 0;

        LED0_TOGGLE(); /*�����˸*/
        delay_ms(1000);
    }
}
