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
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
UART_HandleTypeDef huart1;

osThreadId MsgProducerHandle;
osThreadId MsgConsumerHandle;
osMessageQId myQueue01Handle;
osSemaphoreId bSemEmptyHandle;
osSemaphoreId bSemFilledHandle;
/* USER CODE BEGIN PV */
typedef struct
{
uint16_t var;
} mailStruct;
osMailQId mail01Handle;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
void MsgProducerTask(void const * argument);
void MsgConsumerTask(void const * argument);

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
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* definition and creation of bSemEmpty */
  osSemaphoreDef(bSemEmpty);
  bSemEmptyHandle = osSemaphoreCreate(osSemaphore(bSemEmpty), 4);

  /* definition and creation of bSemFilled */
  osSemaphoreDef(bSemFilled);
  bSemFilledHandle = osSemaphoreCreate(osSemaphore(bSemFilled), 4);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* definition and creation of myQueue01 */
  osMessageQDef(myQueue01, 16, uint16_t);
  myQueue01Handle = osMessageCreate(osMessageQ(myQueue01), NULL);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* add queues, ... */
  osMailQDef(mail01, 4, mailStruct);
  mail01Handle = osMailCreate(osMailQ(mail01),
  NULL);
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of MsgProducer */
  osThreadDef(MsgProducer, MsgProducerTask, osPriorityNormal, 0, 128);
  MsgProducerHandle = osThreadCreate(osThread(MsgProducer), NULL);

  /* definition and creation of MsgConsumer */
  osThreadDef(MsgConsumer, MsgConsumerTask, osPriorityNormal, 0, 128);
  MsgConsumerHandle = osThreadCreate(osThread(MsgConsumer), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
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

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* USER CODE BEGIN Header_MsgProducerTask */
/**
  * @brief  Function implementing the MsgProducer thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_MsgProducerTask */
void MsgProducerTask(void const * argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
	mailStruct * mail;
	char msg[20];
	/* Infinite loop */
	for(;;)
	{
	//osSemaphoreWait(bSemEmptyHandle, osWaitForever);
//	osDelay(1000);
//	mail = (mailStruct *)osMailAlloc(mail01Handle,
//	osWaitForever);
//	mail->var = 1;
//	sprintf(msg, "produce: %d\r\n", mail->var);
//	HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg),HAL_MAX_DELAY);
//	osDelay(1000);
//	osMailPut(mail01Handle, mail);
//	osDelay(2000);
	mail = (mailStruct *)osMailAlloc(mail01Handle,
	osWaitForever);
	mail->var = 2;
	sprintf(msg, "produce: %d\r\n", mail->var);
	HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg),HAL_MAX_DELAY);
	//osDelay(1000);
	HAL_Delay(1000);
	osMailPut(mail01Handle, mail);
	//osSemaphoreRelease(bSemFilledHandle);
	}
  /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_MsgConsumerTask */
/**
* @brief Function implementing the MsgConsumer thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_MsgConsumerTask */
void MsgConsumerTask(void const * argument)
{
  /* USER CODE BEGIN MsgConsumerTask */
  /* Infinite loop */
	osEvent event;
	mailStruct * pMail;
	char msg[20];
	/* Infinite loop */
	for(;;)
	{
	//osSemaphoreWait(bSemFilledHandle, osWaitForever);
	event = osMailGet(mail01Handle, osWaitForever);
	if (event.status == osEventMail)
	{
	pMail = event.value.p;
	sprintf(msg, "consume: %d\r\n", pMail->var);
	HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg),HAL_MAX_DELAY);
	HAL_Delay(6000);
	osMailFree(mail01Handle, pMail);
	//osSemaphoreRelease(bSemEmptyHandle);
	}
	}
  /* USER CODE END MsgConsumerTask */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM3 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM3) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

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
