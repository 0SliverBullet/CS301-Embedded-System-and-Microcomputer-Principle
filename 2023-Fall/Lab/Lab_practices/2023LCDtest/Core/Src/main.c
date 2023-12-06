/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "rtc.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lcd.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_RTC_Init();
  /* USER CODE BEGIN 2 */
  lcd_init();
  /* USER CODE END SysInit */
  // ......

  /* Infinite loop */



  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  uint8_t x = 0;
  while (1) {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  switch (x) {
	  case 0: lcd_clear(WHITE); g_back_color = WHITE; break;
	  case 1: lcd_clear(BLACK); g_back_color = BLACK; break;
	  case 2: lcd_clear(BLUE); g_back_color = BLUE; break;
	  case 3: lcd_clear(RED); g_back_color = RED; break;
	  case 4: lcd_clear(MAGENTA); g_back_color = MAGENTA; break;
	  case 5: lcd_clear(GREEN); g_back_color = GREEN; break;
	  case 6: lcd_clear(CYAN); g_back_color = CYAN; break;
	  case 7: lcd_clear(YELLOW); g_back_color = YELLOW; break;
	  case 8: lcd_clear(BRRED); g_back_color = BRRED; break;
	  case 9: lcd_clear(GRAY); g_back_color = GRAY; break;
	  case 10: lcd_clear(LGRAY); g_back_color = LGRAY; break;
	  case 11: lcd_clear(BROWN); g_back_color = BROWN; break;
	  }//end of switch
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	    RTC_TimeTypeDef sTime;
	    RTC_DateTypeDef sDate;

	    HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);
	    HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
	    char datetime_str[80];
	    sprintf(datetime_str, "%04d/%02d/%02d %02d:%02d:%02d",
	            2000 + sDate.Year, sDate.Month, sDate.Date,
	            sTime.Hours, sTime.Minutes, sTime.Seconds);



	    HAL_Delay(1000); // 延时1�?
      char ch[81];
      //sprintf(ch,"%p",&(GPIOA->CRL));
      sprintf(ch,"%x",lcddev.id);
//      char result[80]="time=";
//      strcat(result, ch);
	  lcd_show_string(30, 40, 200, 24, 24, "Mini STM32 ^_^",RED);
	  lcd_show_string(30, 70, 200, 16, 16, "TFTLCD TEST" ,RED);
	  lcd_show_string(30, 100, 200, 16, 16, ch ,RED);
	  lcd_draw_rectangle(30, 150, 210, 190,BLACK);
	  lcd_fill(31, 151, 209, 189, YELLOW);
	  x++;
	  if (x == 12)
	  x = 0;
	  HAL_Delay(2000);

	  } //end of while(1)
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
