/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
#include <string.h>
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
IWDG_HandleTypeDef hiwdg;

TIM_HandleTypeDef htim3;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
IWDG_HandleTypeDef hiwdg2;
extern unsigned char uRx_Data[1024];
extern unsigned char uLength;
extern uint8_t rxBuffer[20];
extern unsigned char flag;
extern unsigned char Length;
extern int wrongORright;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_IWDG_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_TIM3_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int initial=0;
volatile int i = 10000;
unsigned char msg[1024];
int f=0;
char string[1024];
int x,seed=520;
volatile int mode=0;  //mode=0
volatile int lim=10;
volatile int updatevalue=0;
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
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  int s=0,j;


  while (1)
   {

	  if (mode==0){
		   seed+=1314;
     // *string="abcd";
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  if (i==lim){
		 if (s==0) sprintf(msg, "You have %d Seconds in total, Let us Start Typing Exercise \r\n [WORD] %s \r\n", i,string);
		 else sprintf(msg, "You have %d Seconds in total, Let us Continue Typing Exercise \r\n [WORD] %s \r\n", i,string);
	  }
   else if (i>=2&&i<=3) sprintf(msg, " [WARNING] %d seconds left! \r\n", i);
     else if (i==1)  sprintf(msg, " [WARNING] %d second left! \r\n", i);
     else if (i==0) {
    	 if (s>=lim) sprintf(msg, "Game over! The Score you get is %d, Excellent!\r\n", s);
    	 else if (s>=lim/2) sprintf(msg, "Game over! The Score you get is %d, Good!\r\n", s);
    	   else if (s>=1) sprintf(msg, "Game over! The Score you get is %d, Practice more!\r\n", s);
    	      else if (s==0)  sprintf(msg, "Game over! The Score you get is %d, Rubbish!\r\n", s);
     }

  if (i==lim||i>=0&&i<=3) HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

   if (i>1||i==0){
	   if (wrongORright==0) HAL_Delay(1000);
   else if (wrongORright==1) {
	   wrongORright=0;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,GPIO_PIN_SET);
		  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
		  HAL_Delay(500);
		  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
		  HAL_Delay(500);


   }
   else if(wrongORright==2){
	   wrongORright=0;
	   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2,GPIO_PIN_SET);
	   HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
	   HAL_Delay(500);
	   HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
	   HAL_Delay(500);

	   s++;
	   srand(seed);
		  for (j=0;j<=(s+9)/3;j++){
			 // srand((unsigned)time(NULL));
			      x=rand()%(25-0+1);
				  string[j]='a'+x;
			  }
			  string[(s+9)/3+1]='\0';
	   HAL_IWDG_Refresh(&hiwdg);
	   i=lim+1;

   }
	   i--;
	    initial=i;
   }
   else if (i==1){
	   HAL_Delay(1000);
	   i--;
	   initial=i;
	   if (wrongORright==1) {
		    wrongORright=0;
	   		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,GPIO_PIN_SET);

	   		  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
	   		  HAL_Delay(500);
	   		  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);


	      }
	      else if(wrongORright==2){
	       wrongORright=0;
	   	   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2,GPIO_PIN_SET);
	   	   HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
	   	   HAL_Delay(500);
	   	   HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);

	   	   s++;
	   	srand(seed);
	 	  for (j=0;j<=(s+9)/3;j++){
	 		// srand((unsigned)time(NULL));
	 		      x=rand()%(25-0+1);
	 			  string[j]='a'+x;
	 		  }
	 		  string[(s+9)/3+1]='\0';
	   	   HAL_IWDG_Refresh(&hiwdg);
	   	   i=lim+1;
	       i--;
	   	   initial=i;
	      }
   }

	  }
	  else{

	  }


 }
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
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
}

/**
  * @brief IWDG Initialization Function
  * @param None
  * @retval None
  */
static void MX_IWDG_Init(void)
{

  /* USER CODE BEGIN IWDG_Init 0 */

  /* USER CODE END IWDG_Init 0 */

  /* USER CODE BEGIN IWDG_Init 1 */

  /* USER CODE END IWDG_Init 1 */
  hiwdg.Instance = IWDG;
  hiwdg.Init.Prescaler = IWDG_PRESCALER_256;
  hiwdg.Init.Reload = 3437;
  if (HAL_IWDG_Init(&hiwdg) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN IWDG_Init 2 */

  /* USER CODE END IWDG_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 719;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 9999;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin : KEY_WK_Pin */
  GPIO_InitStruct.Pin = KEY_WK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(KEY_WK_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : KEY0_Pin */
  GPIO_InitStruct.Pin = KEY0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(KEY0_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LED0_Pin */
  GPIO_InitStruct.Pin = LED0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED0_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : KEY1_Pin */
  GPIO_InitStruct.Pin = KEY1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(KEY1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LED1_Pin */
  GPIO_InitStruct.Pin = LED1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED1_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 2, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 2, 1);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 2);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
switch (GPIO_Pin) {
case KEY0_Pin:
if (HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin) == GPIO_PIN_RESET){
	//HAL_IWDG_Refresh(&hiwdg);
	initial=i;
	  	MX_USART1_UART_Init();
	  	sprintf(msg, "\r\nGame Start! Are you Ready? [Y/N] \r\n(You should give me your choice with 'Y' or 'N' in 10 seconds)\r\n");
	  	HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
	  	HAL_UART_Receive_IT(&huart1,(uint8_t *)rxBuffer,1);
	  	int j=10;
	  	f=0;
	  	while (j!=-1){
	  		 if (j!=0){
	  			 sprintf(msg, "%d--",j);
	  		 }
	  		 else {
	  			sprintf(msg, "%d \r\nTime Over, Quit Game!\r\n",j);
	  		 }
	  		 j--;
	  		 HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
	  		 HAL_Delay(1000);
	  		 if (Length ==1&&uRx_Data[0]=='Y') {
	  			 f=1;
	  			 sprintf(msg, "\r\nReady...Go!\r\n\r\n");
	  			 HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
	  			 break;
	  		 }
	  		 else if (Length ==1&&uRx_Data[0]=='N'){
	  			 sprintf(msg, "\r\nYou can play next time, Quit Game!\r\n");
	  			 HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
	  			 break;
	  		 }

	  	}
	  	if (f==1){
	  		HAL_Delay(1000);
	  		 srand(seed);
	  		for (int j=0;j<=(0+9)/3;j++){
	  		  				  //x=(a*x+c)%m;
	  			  //srand((unsigned)time(NULL));
	  			           x=rand()%(25-0+1);
	  		  				  string[j]='a'+x;
	  		  			  }
	  		  			  string[(0+9)/3+1]='\0';
	  	 //x=rand()%(25-0+1);
	  	 MX_IWDG_Init();
	  	 i=lim+1;
	  	}
	  	else {

	  		while(1){

	  		}
	  	}

}

break;

case KEY_WK_Pin:
	if (HAL_GPIO_ReadPin(KEY_WK_GPIO_Port, KEY_WK_Pin) == GPIO_PIN_SET){
         if (i>=0){
        	 if (mode==0){
			mode=1;
			int ll=0,j;
			char str[]=" [Pause] Please press KEY_WK to continue!\r\n";
			for( j=0;str[j];j++ ){
								ll++;
								uRx_Data[j]=str[j];
							}
							HAL_UART_Transmit(&huart1, uRx_Data, ll, 0xffff);
			HAL_TIM_Base_Start_IT(&htim3);
							HAL_Delay(1000);
		}else{

			mode=0;
			int ll=0,j;
			char str[]=" [continue] Welcome to come back again!\r\n";
			for( j=0;str[j];j++ ){
								ll++;
								uRx_Data[j]=str[j];
							}

							HAL_UART_Transmit(&huart1, uRx_Data, ll, 0xffff);
			HAL_TIM_Base_Stop_IT(&htim3);
							HAL_Delay(1000);
		}
         }

	}
	break;
case KEY1_Pin:
	if (HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == GPIO_PIN_RESET){
		 if (i>=0){
			mode=1;
			int ll=0,j;
			char str[]=" [UPDATE] The current time limit is ";
			int k=lim,len=0;
			char add[]="new";
			char fin[]="friend";
			while(k!=0){
				add[len]=k%10+48;
				len++;
				k=k/10;
				//Time limit changed: ? seconds.\r\n";
			}
			for (j=0;j<len;j++){
				fin[j]=add[len-1-j];
			}
			for( j=0;str[j];j++ ){
								ll++;
								uRx_Data[j]=str[j];
							}
			for (j=0;j<len;j++){

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
							ll=0;
							char str2[]=" [UPDATE] Time limit changed: ? seconds(? can be [1, 20]). Please input ?.\r\n";
							for( j=0;str2[j];j++ ){
												ll++;
												uRx_Data[j]=str2[j];
											}

											HAL_UART_Transmit(&huart1, uRx_Data, ll, 0xffff);
							updatevalue=1;
			HAL_TIM_Base_Start_IT(&htim3);
							HAL_Delay(1000);


		 }
	}
	break;
default:
break;
}
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	HAL_IWDG_Refresh(&hiwdg);

}
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
