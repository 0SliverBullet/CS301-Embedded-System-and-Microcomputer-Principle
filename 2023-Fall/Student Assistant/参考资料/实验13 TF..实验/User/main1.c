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
 * @brief       ��������
 * @param       color: Ҫ��������ɫ
 * @retval      ��
 */
void lcd_clear1(uint16_t color)
{
    uint32_t index = 0;
    uint32_t totalpoint = lcddev.width;
    totalpoint *= lcddev.height;    /* �õ��ܵ��� */
    lcd_set_cursor(0x00, 0x0000);   /* ���ù��λ�� */
    lcd_write_ram_prepare();        /* ��ʼд��GRAM */

    for (index = 0; index < totalpoint; index++)
    {
        delay_ms(5);  /* ����ͨ��������ʱ�������۲�LCD��ɨ�跽ʽ */
        LCD->LCD_RAM = color;
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

    lcd_scan_dir(L2R_U2D);  /* ɨ�跽���壬Ĭ���Ǵ�����,���ϵ��£�ͨ���βο���ѡ��8��ɨ�跽�� */

    while (1)
    {
        switch (x)
        {
            case 0:
                lcd_clear1(BLUE);
                break;

            case 1:
                lcd_clear1(RED);
                break;

            case 2:
                lcd_clear1(MAGENTA);
                break;

            case 3:
                lcd_clear1(GREEN);
                break;

            case 4:
                lcd_clear1(BRRED);
                break;
        }

        x++;

        if (x == 5)x = 0;

        LED0_TOGGLE();  //�����˸
        delay_ms(100);
    }
}









