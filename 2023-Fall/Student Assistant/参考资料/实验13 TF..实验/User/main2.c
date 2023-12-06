/**
 ****************************************************************************************************
 * @file        main.c
 * @author      ����ԭ���Ŷ�(ALIENTEK)
 * @version     V1.0
 * @date        2020-03-23
 * @brief       TFTLCD(MCU��) ʵ��
 * @license     Copyright (c) 2020-2032, ������������ӿƼ����޹�˾
 ****************************************************************************************************
 * @attention
 *
 * ����ԭ�� STM32F103������
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
#include "./BSP/KEY/key.h"
#include "./BSP/LCD/lcd.h"


/**
 * @brief       ����LCDɨ�跽��
 * @param       x:0~7����ʾL2R_U2D��D2U_R2L�����ַ���
 * @retval      ��
 */
void lcd_direction(uint8_t x)
{
    switch (x)
    {
        case 0:
            lcd_scan_dir(L2R_U2D);  /* ������,���ϵ��� */
            break;

        case 1:
            lcd_scan_dir(L2R_D2U);  /* ������,���µ��� */
            break;

        case 2:
            lcd_scan_dir(R2L_U2D);  /* ���ҵ���,���ϵ��� */
            break;

        case 3:
            lcd_scan_dir(R2L_D2U);  /* ���ҵ���,���µ��� */
            break;

        case 4:
            lcd_scan_dir(U2D_L2R);  /* ���ϵ���,������ */
            break;

        case 5:
            lcd_scan_dir(U2D_R2L);  /* ���ϵ���,���ҵ��� */
            break;

        case 6:
            lcd_scan_dir(D2U_L2R);  /* ���µ���,������ */
            break;

        case 7:
            lcd_scan_dir(D2U_R2L);  /* ���µ���,���ҵ��� */ 
            break;
    }
}

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
        lcd_direction(x);  /* ����LCDɨ�跽�� */

        switch (x)
        {
            case 0:
                lcd_clear(BROWN);
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
        }

        lcd_show_string(64, 10, 96, 32, 32, "X--->", RED);
        lcd_show_string(10, 64, 32, 32, 32, "Y", RED);
        lcd_show_string(10, 96, 32, 32, 32, "|", RED);
        lcd_show_string(10, 112, 32, 32, 32, "|", RED);
        lcd_show_string(10, 144, 32, 32, 32, "|", RED);
        lcd_show_string(10, 176, 32, 32, 32, "V", RED);
        delay_ms(3000);

        lcd_show_string(64, 64, 240, 32, 32,  "STM32", RED);
        lcd_show_string(64, 104, 240, 24, 24, "TFTLCD TEST", RED);
        lcd_show_string(64, 134, 240, 16, 16, "ATOM@ALIENTEK", RED);
        lcd_show_string(64, 154, 240, 16, 16, (char*)lcd_id, RED);  /* ��ʾLCD ID */

        x++;
        if (x == 8)x = 0;

        LED0_TOGGLE();  //�����˸
        delay_ms(1000);
    }
}









