/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f1xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
uint8_t rxBuffer[20];
unsigned char uRx_Data[1024] = {0};
unsigned char uLength = 0;
unsigned char flag='Y';
unsigned char Length = 0;
int wrongORright=0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim3;
extern UART_HandleTypeDef huart1;
/* USER CODE BEGIN EV */
extern int f;
extern char string[];
extern int initial;
extern volatile int lim;
extern volatile int updatevalue;
extern volatile int mode;
extern volatile int i;
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
  * @brief This function handles TIM3 global interrupt.
  */
void TIM3_IRQHandler(void)
{
  /* USER CODE BEGIN TIM3_IRQn 0 */

  /* USER CODE END TIM3_IRQn 0 */
  HAL_TIM_IRQHandler(&htim3);
  /* USER CODE BEGIN TIM3_IRQn 1 */

  /* USER CODE END TIM3_IRQn 1 */
}

/**
  * @brief This function handles USART1 global interrupt.
  */
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */

  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */
  HAL_UART_Receive_IT(&huart1,(uint8_t *)rxBuffer,1);
  /* USER CODE END USART1_IRQn 1 */
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
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (initial>=1)
if(huart->Instance==USART1){
if(rxBuffer[0] == '\n'){
	flag=uRx_Data[0];
	Length=uLength-1;
	HAL_UART_Transmit(&huart1, uRx_Data, uLength, 0xffff);
	int j;
	if (f==1){
		if (updatevalue==1){
			updatevalue=0;
			lim=0;
			for (j=0;j<Length;j++){
						lim=lim*10+uRx_Data[j]-48;
				}
			int ll=0;
			char str3[]=" [UPDATE] Time limit changed: ";
			char fin[]="friend";
			for (j=0;j<Length;j++){
									fin[j]=uRx_Data[j];
							}
			for( j=0;str3[j];j++ ){
											ll++;
											uRx_Data[j]=str3[j];
										}
			for (j=0;j<Length;j++){

						uRx_Data[ll]=fin[j];
						ll++;
						}
			if (lim>1){
								char str1[]=" seconds.\r\n";
							for( j=0;str1[j];j++ ){

															uRx_Data[ll]=str1[j];
															ll++;
														}
							}
							else {
								char str1[]=" second.\r\n";
										for( j=0;str1[j];j++ ){

																		uRx_Data[ll]=str1[j];
																		ll++;
																	}
							}
			HAL_UART_Transmit(&huart1, uRx_Data, ll, 0xffff);
			i=lim+1;
			HAL_TIM_Base_Stop_IT(&htim3);
						mode=0;

		}else{
			unsigned char uRx_Data1[1024] = {0};
					int l=0,ll=0,check=0,j;
					for (j=0;j<Length;j++){
						if (uRx_Data[j]!=' '){
							uRx_Data1[l]=uRx_Data[j];
							l++;
						}
					}
					Length=l;
					for (j=0;j<l;j++){
						uRx_Data[j]=uRx_Data1[j];
						}
					l=0;
					for( j=0;string[j];j++ )
					    l++;
					if (Length!=l){
						ll=0;
							char str[]=" [INFO] Wrong input! Please try again!\r\n";
							for( j=0;str[j];j++ ){
								ll++;
								uRx_Data[j]=str[j];
							}

							HAL_UART_Transmit(&huart1, uRx_Data, ll, 0xffff);
							wrongORright=1;

					}
					else {
						for (int j=0;j<Length;j++){
							if (uRx_Data[j]>='a'&&uRx_Data[j]<='z'){
								uRx_Data[j]-=32;
							}
							if (string[j]>='a'&&string[j]<='z'){
								string[j]-=32;
							}
						}

						for (int j=0;j<Length;j++){
						   if (uRx_Data[j]!=string[j]){
							   ll=0;
							   				char str[]=" [INFO] Wrong input! Please try again!\r\n";
							   				for( j=0;str[j];j++ ){
							   					ll++;
							   					uRx_Data[j]=str[j];
							   				}

							   				HAL_UART_Transmit(&huart1, uRx_Data, ll, 0xffff);
							   				wrongORright=1;
							   		        check=1;
							   				break;
						   }
					   }
						if (check==0){
							ll=0;
							char str[]=" [INFO] Good job!\r\n";
							for( j=0;str[j];j++ ){
								ll++;
								uRx_Data[j]=str[j];
							}

							HAL_UART_Transmit(&huart1, uRx_Data, ll, 0xffff);
							wrongORright=2;

						}
					}
		}


	}

uLength = 0;
}else{
uRx_Data[uLength] = rxBuffer[0];
uLength++;
}
}
}
/* USER CODE END 1 */
