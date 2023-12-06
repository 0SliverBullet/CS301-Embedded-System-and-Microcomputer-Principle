/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f1xx_it.c
  * @brief   Interrupt Service Routines.
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
#include "stm32f1xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lcd.h"
#include<string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

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
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/

/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M3 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f1xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles EXTI line0 interrupt.
  */
void EXTI0_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI0_IRQn 0 */

  /* USER CODE END EXTI0_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(KEY_WK_Pin);
  /* USER CODE BEGIN EXTI0_IRQn 1 */

  /* USER CODE END EXTI0_IRQn 1 */
}

/**
  * @brief This function handles EXTI line[9:5] interrupts.
  */
void EXTI9_5_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI9_5_IRQn 0 */

  /* USER CODE END EXTI9_5_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(KEY0_Pin);
  /* USER CODE BEGIN EXTI9_5_IRQn 1 */

  /* USER CODE END EXTI9_5_IRQn 1 */
}

/**
  * @brief This function handles EXTI line[15:10] interrupts.
  */
void EXTI15_10_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI15_10_IRQn 0 */

  /* USER CODE END EXTI15_10_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(KEY1_Pin);
  /* USER CODE BEGIN EXTI15_10_IRQn 1 */

  /* USER CODE END EXTI15_10_IRQn 1 */
}

/* USER CODE BEGIN 1 */
void blink_LED0_once(){
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
	  HAL_Delay(500);
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
	  HAL_Delay(500);
}
void blink_LED1_once(){
    HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
    HAL_Delay(500);
    HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
    HAL_Delay(500);

}
void blink_LED0LED1_twice(){
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
	  HAL_Delay(250);
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
	  HAL_Delay(250);
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
	  HAL_Delay(250);
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
	  HAL_Delay(250);
}
static unsigned char uRx_Data[1024] = {0};
static unsigned char uLength = 0;
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,GPIO_PIN_SET);
 	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2,GPIO_PIN_SET);


switch(GPIO_Pin){
case KEY0_Pin:
if(HAL_GPIO_ReadPin(KEY0_GPIO_Port,KEY0_Pin)==GPIO_PIN_RESET){
  blink_LED0_once();
  uRx_Data[uLength]='0';
  uLength++;
  POINT_COLOR = RED;
  LCD_ShowString(10, 50, 200, 16, 16, (uint8_t*) uRx_Data);
	}

break;
case KEY1_Pin:
	if (HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin)==GPIO_PIN_RESET){
		  blink_LED1_once();
          uRx_Data[uLength]='1';
          uLength++;
          POINT_COLOR = RED;
          LCD_ShowString(10, 50, 200, 16, 16, (uint8_t*) uRx_Data);

	}
	break;
case KEY_WK_Pin:
if(HAL_GPIO_ReadPin(KEY_WK_GPIO_Port,KEY_WK_Pin)==GPIO_PIN_SET){
static unsigned char uRx_Data1[1024] = {0};
static unsigned char uRx_Data2[1024] = {0};
static unsigned char uLength1 = 0;
static unsigned char uLength2 = 0;
for (int i=0;i<uLength;i++){
	uRx_Data1[uLength1] = uRx_Data[i];
	uLength1++;
	if (uRx_Data[i]=='0'){
		blink_LED0_once();
	}
	if (uRx_Data[i]=='1'){
		blink_LED1_once();
	}
	if (uRx_Data1[0]=='0'&&uRx_Data1[1]=='0'&&uRx_Data1[2]=='1'&&uRx_Data1[3]=='1'){
		uRx_Data2[uLength2] = 'h';
		uLength2++;
		memset(uRx_Data1, '\0', sizeof(uRx_Data1));
		uLength1 = 0;
		blink_LED0LED1_twice();
	}
	else if (uRx_Data1[0]=='1'&&uRx_Data1[1]=='1'&&uRx_Data1[2]=='0'&&uRx_Data1[3]=='0'){
		uRx_Data2[uLength2] = 'i';
		uLength2++;
		memset(uRx_Data1, '\0', sizeof(uRx_Data1));
		uLength1 = 0;
		blink_LED0LED1_twice();
	}

	}
POINT_COLOR = RED;
LCD_ShowString(10, 198, 200, 16, 16, (uint8_t*) uRx_Data2);
}
break;

}


}
/* USER CODE END 1 */
