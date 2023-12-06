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
uint8_t rxBuffer[1024];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern UART_HandleTypeDef huart1;
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
  * @brief This function handles USART1 global interrupt.
  */
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */

  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */
  HAL_UART_Receive_IT(&huart1, (uint8_t *) rxBuffer, 1);
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
static unsigned char uRx_Data0[1] = {0};
static unsigned char uRx_Data[1024] = {0};
static unsigned char uRx_Data1[1024] = {0};
static unsigned char uRx_Data2[1024] = {0};
static unsigned char uRx_Data3[1024] = {0};
static unsigned char uLength = 0;
static unsigned char uLength1 = 0;
static unsigned char uLength2 = 0;
static unsigned char uLength3 = 0;
int mode=0;
int k=0;
int h=0;
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,GPIO_PIN_SET);
 	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2,GPIO_PIN_SET);


switch(GPIO_Pin){
case KEY0_Pin:
if(HAL_GPIO_ReadPin(KEY0_GPIO_Port,KEY0_Pin)==GPIO_PIN_RESET){
  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
  HAL_Delay(500);
  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
  HAL_Delay(500);
  uRx_Data[uLength]='.';
  uLength++;

	}


break;
case KEY1_Pin:
	if (HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin)==GPIO_PIN_RESET){
          HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
          HAL_Delay(500);
          HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
          HAL_Delay(500);
          uRx_Data[uLength]='-';
          uLength++;

	}
	break;
case KEY_WK_Pin:
if(HAL_GPIO_ReadPin(KEY_WK_GPIO_Port,KEY_WK_Pin)==GPIO_PIN_SET){
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
  uRx_Data[uLength]='/';
  uLength++;
  mode=1;
  for (int i=0;i<uLength;i++){
      if (uRx_Data[i]=='.'){
          }
         else  if (uRx_Data[i]=='-'){

       }
         else if (uRx_Data[i]=='/'){
        	   int f=0;
        	   for (int j=k;j<=i-1;j++){
        		   if (uRx_Data[j]!='.'&&uRx_Data[j]!='-'){
        			   f=1;
        			   break;
        		   }
        	   }
        	   if (f==1||i-k>4||(i-k==4&&((uRx_Data[k]=='.'&&uRx_Data[k+1]=='.'&&uRx_Data[k+2]=='-'&&uRx_Data[k+3]=='-')
        			   ||(uRx_Data[k]=='.'&&uRx_Data[k+1]=='-'&&uRx_Data[k+2]=='.'&&uRx_Data[k+3]=='-')
					   ||(uRx_Data[k]=='-'&&uRx_Data[k+1]=='-'&&uRx_Data[k+2]=='-'&&uRx_Data[k+3]=='.')
					   ||(uRx_Data[k]=='-'&&uRx_Data[k+1]=='-'&&uRx_Data[k+2]=='-'&&uRx_Data[k+3]=='-')))){
        		    uRx_Data1[uLength1]='d';
	        	    	uRx_Data1[uLength1+1]='e';
	        	    	uRx_Data1[uLength1+2]='c';
	        	    	uRx_Data1[uLength1+3]='o';
	        	    	uRx_Data1[uLength1+4]='d';
	        	    	uRx_Data1[uLength1+5]='e';
	        	    	uRx_Data1[uLength1+6]=' ';
	        	    	uRx_Data1[uLength1+7]='E';
	        	    	uRx_Data1[uLength1+8]='r';
	        	    	uRx_Data1[uLength1+9]='r';
	        	    	uRx_Data1[uLength1+10]='o';
	        	    	uRx_Data1[uLength1+11]='r';
	        	    	uRx_Data1[uLength1+12]=':';
	        	    	uRx_Data1[uLength1+13]=' ';
	        	    	for (int j=k;j<=i-1;j++){
 	        		  	uRx_Data1[uLength1+13+j-k+1]=uRx_Data[j];
 	        	   }
	        	    	uLength1+=13+i-k+1;
	        	    	//k=i+1;
	        	    uRx_Data2[h]='d';
	        	    uLength2+=1;
        	   }
        	   else {
        		   if (i-k==1){
        			  if (uRx_Data[k]=='.') {
        				  uRx_Data1[uLength1]='E';
        				  uLength1++; uRx_Data2[h]='.';
	 	        	    	uRx_Data2[h+1]='/';
  	 	        	    	//k=k+2;
  	 	        	        uLength2+=2;

        			  }
        			  else if (uRx_Data[k]=='-') {
        				  uRx_Data1[uLength1]='T';
        				  uLength1++;uRx_Data2[h]='-';
	 	        	    	uRx_Data2[h+1]='/';
  	 	        	    	//k=k+2;
  	 	        	        uLength2+=2;
        			  }
        		  }else if(i-k==2) {
        			 if (uRx_Data[k]=='.') {
        				  if (uRx_Data[k+1]=='.') {
        				       uRx_Data1[uLength1]='I';
        				       uLength1++;uRx_Data2[h]='.';
    	 	        	    	uRx_Data2[h+1]='.';
    	 	        	    	uRx_Data2[h+2]='/';
       	 	        	    	//k=k+3;
       	 	        	        uLength2+=3;
        				   }
        				 else if (uRx_Data[k+1]=='-') {
        				       uRx_Data1[uLength1]='A';
        				       uLength1++;
        				       uRx_Data2[h]='.';
  	 	        	    	  uRx_Data2[h+1]='-';
  	 	        	    	  uRx_Data2[h+2]='/';
  	 	        	    	//k=k+3;
  	 	        	        uLength2+=3;

        				   }

        			  }
        			 else if (uRx_Data[k]=='-') {
        				  if (uRx_Data[k+1]=='.') {
        				        uRx_Data1[uLength1]='N';
        				        uLength1++;uRx_Data2[h]='-';
     	 	        	    	uRx_Data2[h+1]='.';
     	 	        	    	uRx_Data2[h+2]='/';
        	 	        	    	//k=k+3;
        	 	        	        uLength2+=3;
        				  }
        				  else if (uRx_Data[k+1]=='-') {
        				        uRx_Data1[uLength1]='M';
        				        uLength1++;uRx_Data2[h]='-';
     	 	        	    	uRx_Data2[h+1]='-';
     	 	        	    	uRx_Data2[h+2]='/';
        	 	        	    	//k=k+3;
        	 	        	        uLength2+=3;
        				  }

        			}

        		  }else if (i-k==3){
        	     if (uRx_Data[k]=='.') {
    				  if (uRx_Data[k+1]=='.') {
    					  if (uRx_Data[k+2]=='.') {
   				       uRx_Data1[uLength1]='S';
   				       uLength1++; uRx_Data2[h]='.';
	 	        	    	uRx_Data2[h+1]='.';
	 	        	    	uRx_Data2[h+2]='.';
	 	        	    	uRx_Data2[h+3]='/';
	 	        	    	//k=k+4;
	 	        	        uLength2+=4;
   				   }
   				 else if (uRx_Data[k+2]=='-') {
   				       uRx_Data1[uLength1]='U';
   				       uLength1++;uRx_Data2[h]='.';
	 	        	    	uRx_Data2[h+1]='.';
	 	        	    	uRx_Data2[h+2]='-';
	 	        	    	uRx_Data2[h+3]='/';
	 	        	    	//k=k+4;
	 	        	        uLength2+=4;
   				   }

    				   }
    				 else if (uRx_Data[k+1]=='-') {
    					 if (uRx_Data[k+2]=='.') {
  				       uRx_Data1[uLength1]='R';
  				       uLength1++;uRx_Data2[h]='.';
	 	        	    	uRx_Data2[h+1]='-';
	 	        	    	uRx_Data2[h+2]='.';
	 	        	    	uRx_Data2[h+3]='/';
	 	        	    	//k=k+4;
	 	        	        uLength2+=4;
  				   }
  				 else if (uRx_Data[k+2]=='-') {
  				       uRx_Data1[uLength1]='W';
  				       uLength1++;uRx_Data2[h]='.';
	 	        	    	uRx_Data2[h+1]='-';
	 	        	    	uRx_Data2[h+2]='-';
	 	        	    	uRx_Data2[h+3]='/';
	 	        	    	//k=k+4;
	 	        	        uLength2+=4;
  				   }

    				   }

    			  }
    			 else if (uRx_Data[k]=='-') {
    				  if (uRx_Data[k+1]=='.') {
    					  if (uRx_Data[k+2]=='.') {
      				       uRx_Data1[uLength1]='D';
      				       uLength1++;uRx_Data2[h]='-';
	 	        	    	uRx_Data2[h+1]='.';
	 	        	    	uRx_Data2[h+2]='.';
	 	        	    	uRx_Data2[h+3]='/';
   	 	        	    	//k=k+4;
   	 	        	        uLength2+=4;
      				   }
      				 else if (uRx_Data[k+2]=='-') {
      				       uRx_Data1[uLength1]='K';
      				       uLength1++;uRx_Data2[h]='-';
	 	        	    	uRx_Data2[h+1]='.';
	 	        	    	uRx_Data2[h+2]='-';
	 	        	    	uRx_Data2[h+3]='/';
   	 	        	    	//k=k+4;
   	 	        	        uLength2+=4;
      				   }

    				  }
    				  else if (uRx_Data[k+1]=='-') {
    					  if (uRx_Data[k+2]=='.') {
      				       uRx_Data1[uLength1]='G';
      				       uLength1++;uRx_Data2[h]='-';
	 	        	    	uRx_Data2[h+1]='-';
	 	        	    	uRx_Data2[h+2]='.';
	 	        	    	uRx_Data2[h+3]='/';
   	 	        	    	//k=k+4;
   	 	        	        uLength2+=4;
      				   }
      				 else if (uRx_Data[k+2]=='-') {
      				       uRx_Data1[uLength1]='O';
      				       uLength1++; uRx_Data2[h]='-';
 	 	        	    	uRx_Data2[h+1]='-';
 	 	        	    	uRx_Data2[h+2]='-';
 	 	        	    	uRx_Data2[h+3]='/';
   	 	        	    	//k=k+4;
   	 	        	        uLength2+=4;
      				   }

    				  }

    			}


        		  }else if (i-k==4){

        		if (uRx_Data[k]=='.') {
    				  if (uRx_Data[k+1]=='.') {
    					  if (uRx_Data[k+2]=='.') {
    						  if (uRx_Data[k+3]=='.') {
	        				       uRx_Data1[uLength1]='H';
	        				       uLength1++;uRx_Data2[h]='.';
    	 	        	    	uRx_Data2[h+1]='.';
    	 	        	    	uRx_Data2[h+2]='.';
    	 	        	    	uRx_Data2[h+3]='.';
    	 	        	    	uRx_Data2[h+4]='/';
       	 	        	    	//k=k+5;
       	 	        	        uLength2+=5;
	        				   }
	        				 else if (uRx_Data[k+3]=='-') {
	        				       uRx_Data1[uLength1]='V';
	        				       uLength1++;uRx_Data2[h]='.';
     	 	        	    	uRx_Data2[h+1]='.';
     	 	        	    	uRx_Data2[h+2]='.';
     	 	        	    	uRx_Data2[h+3]='-';
     	 	        	    	uRx_Data2[h+4]='/';
       	 	        	    	//k=k+5;
       	 	        	        uLength2+=5;
	        				   }

   				   }
   				 else if (uRx_Data[k+2]=='-') {
   					 if (uRx_Data[k+3]=='.') {
				       uRx_Data1[uLength1]='F';
				       uLength1++;uRx_Data2[h]='.';
 	        	    	uRx_Data2[h+1]='.';
 	        	    	uRx_Data2[h+2]='-';
 	        	    	uRx_Data2[h+3]='.';
 	        	    	uRx_Data2[h+4]='/';
	 	        	    	//k=k+5;
	 	        	        uLength2+=5;
				   }
				 else if (uRx_Data[k+3]=='-') {

				   }
   				   }

    				   }
    				 else if (uRx_Data[k+1]=='-') {
    					 if (uRx_Data[k+2]=='.') {
    						 if (uRx_Data[k+3]=='.') {
        				       uRx_Data1[uLength1]='L';
        				       uLength1++;uRx_Data2[h]='.';
    	 	        	    	uRx_Data2[h+1]='-';
    	 	        	    	uRx_Data2[h+2]='.';
    	 	        	    	uRx_Data2[h+3]='.';
    	 	        	    	uRx_Data2[h+4]='/';
       	 	        	    	//k=k+5;
       	 	        	        uLength2+=5;
        				   }
        				 else if (uRx_Data[k+3]=='-') {

        				   }

  				   }
  				 else if (uRx_Data[k+2]=='-') {
  					 if (uRx_Data[k+3]=='.') {
				       uRx_Data1[uLength1]='P';
				       uLength1++;uRx_Data2[h]='.';
	 	        	    	uRx_Data2[h+1]='-';
	 	        	    	uRx_Data2[h+2]='-';
	 	        	    	uRx_Data2[h+3]='.';
	 	        	    	uRx_Data2[h+4]='/';
	 	        	    	//k=k+5;
	 	        	        uLength2+=5;
				   }
				 else if (uRx_Data[k+3]=='-') {
				       uRx_Data1[uLength1]='J';
				       uLength1++;uRx_Data2[h]='.';
 	        	    	uRx_Data2[h+1]='-';
 	        	    	uRx_Data2[h+2]='-';
 	        	    	uRx_Data2[h+3]='-';
 	        	    	uRx_Data2[h+4]='/';
	 	        	    	//k=k+5;
	 	        	        uLength2+=5;
				   }

  				   }

    				   }

    			  }
    			 else if (uRx_Data[k]=='-') {
    				  if (uRx_Data[k+1]=='.') {
    					  if (uRx_Data[k+2]=='.') {
    						  if (uRx_Data[k+3]=='.') {
	        				       uRx_Data1[uLength1]='B';
	        				       uLength1++;uRx_Data2[h]='-';
   	 	        	    	uRx_Data2[h+1]='.';
   	 	        	    	uRx_Data2[h+2]='.';
   	 	        	    	uRx_Data2[h+3]='.';
   	 	        	    	uRx_Data2[h+4]='/';
   	 	        	    	//k=k+5;
   	 	        	        uLength2+=5;
	        				   }
	        				 else if (uRx_Data[k+3]=='-') {
	        				       uRx_Data1[uLength1]='X';
	        				       uLength1++;uRx_Data2[h]='-';
     	 	        	    	uRx_Data2[h+1]='.';
     	 	        	    	uRx_Data2[h+2]='.';
     	 	        	    	uRx_Data2[h+3]='-';
     	 	        	    	uRx_Data2[h+4]='/';
       	 	        	    	//k=k+5;
       	 	        	        uLength2+=5;
	        				   }

      				   }
      				 else if (uRx_Data[k+2]=='-') {
      					 if (uRx_Data[k+3]=='.') {
    				       uRx_Data1[uLength1]='C';
    				       uLength1++; uRx_Data2[h]='-';
	        	    	     uRx_Data2[h+1]='.';
	        	    	     uRx_Data2[h+2]='-';
	        	    	     uRx_Data2[h+3]='.';
	        	    	     uRx_Data2[h+4]='/';
	 	        	    	//k=k+5;
	 	        	        uLength2+=5;
    				   }
    				 else if (uRx_Data[k+3]=='-') {
    				       uRx_Data1[uLength1]='Y';
    				       uLength1++; uRx_Data2[h]='-';
 	 	        	    	uRx_Data2[h+1]='.';
 	 	        	    	uRx_Data2[h+2]='-';
 	 	        	    	uRx_Data2[h+3]='-';
 	 	        	    	uRx_Data2[h+4]='/';
   	 	        	    	//k=k+5;
   	 	        	        uLength2+=5;
    				   }

      				   }

    				  }
    				  else if (uRx_Data[k+1]=='-') {
    					  if (uRx_Data[k+2]=='.') {
    						  if (uRx_Data[k+3]=='.') {
	        				       uRx_Data1[uLength1]='Z';
	        				       uLength1++; uRx_Data2[h]='-';
     	 	        	    	uRx_Data2[h+1]='-';
     	 	        	    	uRx_Data2[h+2]='.';
     	 	        	    	uRx_Data2[h+3]='.';
     	 	        	    	uRx_Data2[h+4]='/';
       	 	        	    	//k=k+5;
       	 	        	        uLength2+=5;
	        				   }
	        				 else if (uRx_Data[k+3]=='-') {
	        				       uRx_Data1[uLength1]='Q';
	        				       uLength1++; uRx_Data2[h]='-';
     	 	        	    	uRx_Data2[h+1]='-';
     	 	        	    	uRx_Data2[h+2]='.';
     	 	        	    	uRx_Data2[h+3]='-';
     	 	        	    	uRx_Data2[h+4]='/';
       	 	        	    	//k=k+5;
       	 	        	        uLength2+=5;
	        				   }

      				   }
      				 else if (uRx_Data[k+2]=='-') {
      					 if (uRx_Data[k+3]=='.') {

    				   }
    				 else if (uRx_Data[k+3]=='-') {

    				   }

      				   }

    				  }

    			}



        		  }

                 // k=i+1;
        	   }

         }
      //HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,GPIO_PIN_SET);
                              	 	        	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2,GPIO_PIN_SET);

                              	 	        	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,GPIO_PIN_SET);
                              	 	        	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2,GPIO_PIN_SET);
                              	 	        	 //h=uLength2;
      }

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,GPIO_PIN_SET);
   	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2,GPIO_PIN_SET);

     HAL_UART_RxCpltCallback(&huart1);
	 //HAL_UART_Transmit(&huart1, uRx_Data1, uLength1, 0xffff);
	 uLength = 0;
	 uLength1 = 0;
	 uLength2 = 0;
	 mode=0;

}
break;
default:
break;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2,GPIO_PIN_SET);


}

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
            if(huart->Instance==USART1){
                       k=0;
                       h=0;

                       if(rxBuffer[0] == '\n'){
                    	   if (mode==0){
                    	   if (uLength==2){
                    		   if(uRx_Data[0]=='1'){
                    			   uRx_Data0[0]=1;
                    			   uRx_Data1[0]='E';
                    			   uRx_Data1[1]='n';
                    			   uRx_Data1[2]='c';
                    			   uRx_Data1[3]='o';
                    			   uRx_Data1[4]='d';
                    			   uRx_Data1[5]='e';
                    			   uRx_Data1[6]=' ';
                    			   uRx_Data1[7]='S';
                    			   uRx_Data1[8]='t';
                    			   uRx_Data1[9]='a';
                    			   uRx_Data1[10]='t';
                    			   uRx_Data1[11]='e';
                    			   uRx_Data1[12]=':';
                    			   uLength1=13;


                    		   }
                    		   else if(uRx_Data[0]=='0'){
                    			   uRx_Data0[0]=0;
                    			   uRx_Data1[0]='D';
                    			   uRx_Data1[1]='e';
                    			   uRx_Data1[2]='c';
                    			   uRx_Data1[3]='o';
                    			   uRx_Data1[4]='d';
                    			   uRx_Data1[5]='e';
                    			   uRx_Data1[6]=' ';
                    			   uRx_Data1[7]='S';
                    			   uRx_Data1[8]='t';
                    			   uRx_Data1[9]='a';
                    			   uRx_Data1[10]='t';
                    			   uRx_Data1[11]='e';
                    			   uRx_Data1[12]=':';
                    			   uLength1=13;

                    		   }
                    		   else{
                    			   if (uRx_Data0[0]==1){
                    				   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,GPIO_PIN_SET);
                    				   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2,GPIO_PIN_SET);
                    				   for (int i=0;i<uLength-1;i++){
                                           {
                            	 	        	 switch (uRx_Data[i]){
                            	 	        	     case 'A':
                            	 	        	    	uRx_Data1[k]='.';
                            	 	        	    	uRx_Data1[k+1]='-';
                            	 	        	    	uRx_Data1[k+2]='/';
                            	 	        	    	//k=k+3;
                            	 	        	        uLength1+=3;
                            	 	        		 break;
                            	 	        		 case 'B':
                             	 	        	    	uRx_Data1[k]='-';
                             	 	        	    	uRx_Data1[k+1]='.';
                             	 	        	    	uRx_Data1[k+2]='.';
                             	 	        	    	uRx_Data1[k+3]='.';
                             	 	        	    	uRx_Data1[k+4]='/';
                             	 	        	    	//k=k+5;
                             	 	        	        uLength1+=5;
                             	 	        		 break;
                             	 	        		 case 'C':
                             	 	        			 uRx_Data1[k]='-';
                          	 	        	    	     uRx_Data1[k+1]='.';
                          	 	        	    	     uRx_Data1[k+2]='-';
                          	 	        	    	     uRx_Data1[k+3]='.';
                          	 	        	    	     uRx_Data1[k+4]='/';
                             	 	        	    	//k=k+5;
                             	 	        	        uLength1+=5;
                             	 	        		 break;
                             	 	        		 case 'D':
                             	 	        	    uRx_Data1[k]='-';
                          	 	        	    	uRx_Data1[k+1]='.';
                          	 	        	    	uRx_Data1[k+2]='.';
                          	 	        	    	uRx_Data1[k+3]='/';
                             	 	        	    	//k=k+4;
                             	 	        	        uLength1+=4;
                             	 	        		 break;
                             	 	        		 case 'E':
                             	 	        			 uRx_Data1[k]='.';
                          	 	        	    	uRx_Data1[k+1]='/';
                             	 	        	    	//k=k+2;
                             	 	        	        uLength1+=2;
                             	 	        		 break;
                             	 	        		 case 'F':
                             	 	        			 uRx_Data1[k]='.';
                          	 	        	    	uRx_Data1[k+1]='.';
                          	 	        	    	uRx_Data1[k+2]='-';
                          	 	        	    	uRx_Data1[k+3]='.';
                          	 	        	    	uRx_Data1[k+4]='/';
                             	 	        	    	//k=k+5;
                             	 	        	        uLength1+=5;
                             	 	        		 break;
                             	 	        		 case 'G':
                             	 	        			 uRx_Data1[k]='-';
                          	 	        	    	uRx_Data1[k+1]='-';
                          	 	        	    	uRx_Data1[k+2]='.';
                          	 	        	    	uRx_Data1[k+3]='/';
                             	 	        	    	//k=k+4;
                             	 	        	        uLength1+=4;
                             	 	        		 break;
                             	 	        		 case 'H':
                             	 	        			 uRx_Data1[k]='.';
                          	 	        	    	uRx_Data1[k+1]='.';
                          	 	        	    	uRx_Data1[k+2]='.';
                          	 	        	    	uRx_Data1[k+3]='.';
                          	 	        	    	uRx_Data1[k+4]='/';
                             	 	        	    	//k=k+5;
                             	 	        	        uLength1+=5;
                             	 	        		 break;
                             	 	        		 case 'I':
                             	 	        			 uRx_Data1[k]='.';
                          	 	        	    	uRx_Data1[k+1]='.';
                          	 	        	    	uRx_Data1[k+2]='/';
                             	 	        	    	//k=k+3;
                             	 	        	        uLength1+=3;
                             	 	        		 break;
                             	 	        		 case 'J':uRx_Data1[k]='.';
                          	 	        	    	uRx_Data1[k+1]='-';
                          	 	        	    	uRx_Data1[k+2]='-';
                          	 	        	    	uRx_Data1[k+3]='-';
                          	 	        	    	uRx_Data1[k+4]='/';
                             	 	        	    	//k=k+5;
                             	 	        	        uLength1+=5;
                             	 	        		 break;
                             	 	        		 case 'K':
                             	 	        			 uRx_Data1[k]='-';
                          	 	        	    	uRx_Data1[k+1]='.';
                          	 	        	    	uRx_Data1[k+2]='-';
                          	 	        	    	uRx_Data1[k+3]='/';
                             	 	        	    	//k=k+4;
                             	 	        	        uLength1+=4;
                             	 	        		 break;
                             	 	        		 case 'L':
                             	 	        			 uRx_Data1[k]='.';
                          	 	        	    	uRx_Data1[k+1]='-';
                          	 	        	    	uRx_Data1[k+2]='.';
                          	 	        	    	uRx_Data1[k+3]='.';
                          	 	        	    	uRx_Data1[k+4]='/';
                             	 	        	    	//k=k+5;
                             	 	        	        uLength1+=5;
                             	 	        		 break;
                             	 	        		 case 'M':
                             	 	        			 uRx_Data1[k]='-';
                          	 	        	    	uRx_Data1[k+1]='-';
                          	 	        	    	uRx_Data1[k+2]='/';
                             	 	        	    	//k=k+3;
                             	 	        	        uLength1+=3;
                             	 	        		 break;
                             	 	        		 case 'N':
                             	 	        			 uRx_Data1[k]='-';
                          	 	        	    	uRx_Data1[k+1]='.';
                          	 	        	    	uRx_Data1[k+2]='/';
                             	 	        	    	//k=k+3;
                             	 	        	        uLength1+=3;
                             	 	        		 break;
                             	 	        		 case 'O':
                             	 	        			 uRx_Data1[k]='-';
                           	 	        	    	uRx_Data1[k+1]='-';
                           	 	        	    	uRx_Data1[k+2]='-';
                           	 	        	    	uRx_Data1[k+3]='/';
                             	 	        	    	//k=k+4;
                             	 	        	        uLength1+=4;
                             	 	        		 break;
                             	 	        		 case 'P':
                             	 	        			 uRx_Data1[k]='.';
                           	 	        	    	uRx_Data1[k+1]='-';
                           	 	        	    	uRx_Data1[k+2]='-';
                           	 	        	    	uRx_Data1[k+3]='.';
                           	 	        	    	uRx_Data1[k+4]='/';
                             	 	        	    	//k=k+5;
                             	 	        	        uLength1+=5;
                             	 	        		 break;
                             	 	        		 case 'Q':
                             	 	        			 uRx_Data1[k]='-';
                           	 	        	    	uRx_Data1[k+1]='-';
                           	 	        	    	uRx_Data1[k+2]='.';
                           	 	        	    	uRx_Data1[k+3]='-';
                           	 	        	    	uRx_Data1[k+4]='/';
                             	 	        	    	//k=k+5;
                             	 	        	        uLength1+=5;
                             	 	        		 break;
                             	 	        		 case 'R':
                             	 	        			 uRx_Data1[k]='.';
                           	 	        	    	uRx_Data1[k+1]='-';
                           	 	        	    	uRx_Data1[k+2]='.';
                           	 	        	    	uRx_Data1[k+3]='/';
                             	 	        	    	//k=k+4;
                             	 	        	        uLength1+=4;
                             	 	        		 break;
                             	 	        		 case 'S':
                             	 	        			 uRx_Data1[k]='.';
                           	 	        	    	uRx_Data1[k+1]='.';
                           	 	        	    	uRx_Data1[k+2]='.';
                           	 	        	    	uRx_Data1[k+3]='/';
                             	 	        	    	//k=k+4;
                             	 	        	        uLength1+=4;
                             	 	        		 break;
                             	 	        		 case 'T':
                             	 	        			 uRx_Data1[k]='-';
                           	 	        	    	uRx_Data1[k+1]='/';
                             	 	        	    	//k=k+2;
                             	 	        	        uLength1+=2;
                             	 	        		 break;
                             	 	        		 case 'U':
                             	 	        			 uRx_Data1[k]='.';
                           	 	        	    	uRx_Data1[k+1]='.';
                           	 	        	    	uRx_Data1[k+2]='-';
                           	 	        	    	uRx_Data1[k+3]='/';
                             	 	        	    	//k=k+4;
                             	 	        	        uLength1+=4;
                             	 	        		 break;
                             	 	        		 case 'V':
                             	 	        			 uRx_Data1[k]='.';
                           	 	        	    	uRx_Data1[k+1]='.';
                           	 	        	    	uRx_Data1[k+2]='.';
                           	 	        	    	uRx_Data1[k+3]='-';
                           	 	        	    	uRx_Data1[k+4]='/';
                             	 	        	    	//k=k+5;
                             	 	        	        uLength1+=5;
                             	 	        		 break;
                             	 	        		 case 'W':
                             	 	        			 uRx_Data1[k]='.';
                           	 	        	    	uRx_Data1[k+1]='-';
                           	 	        	    	uRx_Data1[k+2]='-';
                           	 	        	    	uRx_Data1[k+3]='/';
                             	 	        	    	//k=k+4;
                             	 	        	        uLength1+=4;
                             	 	        		 break;
                             	 	        		 case 'X':
                             	 	        			 uRx_Data1[k]='-';
                           	 	        	    	uRx_Data1[k+1]='.';
                           	 	        	    	uRx_Data1[k+2]='.';
                           	 	        	    	uRx_Data1[k+3]='-';
                           	 	        	    	uRx_Data1[k+4]='/';
                             	 	        	    	//k=k+5;
                             	 	        	        uLength1+=5;
                             	 	        		 break;
                             	 	        		 case 'Y':
                             	 	        			 uRx_Data1[k]='-';
                           	 	        	    	uRx_Data1[k+1]='.';
                           	 	        	    	uRx_Data1[k+2]='-';
                           	 	        	    	uRx_Data1[k+3]='-';
                           	 	        	    	uRx_Data1[k+4]='/';
                             	 	        	    	//k=k+5;
                             	 	        	        uLength1+=5;
                             	 	        		 break;
                             	 	        		 case 'Z':
                             	 	        			 uRx_Data1[k]='-';
                           	 	        	    	uRx_Data1[k+1]='-';
                           	 	        	    	uRx_Data1[k+2]='.';
                           	 	        	    	uRx_Data1[k+3]='.';
                           	 	        	    	uRx_Data1[k+4]='/';
                             	 	        	    	//k=k+5;
                             	 	        	        uLength1+=5;
                             	 	        		 break;

                             	 	        		 default:
                             	 	        			uRx_Data1[k]='E';
                            	 	        	    	uRx_Data1[k+1]='n';
                            	 	        	    	uRx_Data1[k+2]='c';
                            	 	        	    	uRx_Data1[k+3]='o';
                            	 	        	    	uRx_Data1[k+4]='d';
                            	 	        	    	uRx_Data1[k+5]='e';
                            	 	        	    	uRx_Data1[k+6]=' ';
                            	 	        	    	uRx_Data1[k+7]='E';
                            	 	        	    	uRx_Data1[k+8]='r';
                            	 	        	    	uRx_Data1[k+9]='r';
                            	 	        	    	uRx_Data1[k+10]='o';
                            	 	        	    	uRx_Data1[k+11]='r';
                            	 	        	    	uRx_Data1[k+12]=':';
                            	 	        	    	uRx_Data1[k+13]=' ';
                            	 	        	    	uRx_Data1[k+14]=uRx_Data[i];
                            	 	        	    	uLength1+=15;

                            	 	        	 }
                            	 	        	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,GPIO_PIN_SET);
                            	 	        	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2,GPIO_PIN_SET);
                            	 	        	 for (int j=k;j<=uLength1-1;j++){
                            	 	        		 if (uRx_Data1[j]=='.'){
                                 	 	            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
                                 	 	            HAL_Delay(500);
                                 	 	            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
                                 	 	            HAL_Delay(500);
                                 	 	          }
                                 	 	         else  if (uRx_Data1[j]=='-'){
                                 	 	            HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
                                 	 	            HAL_Delay(500);
                                 	 	            HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
                                 	 	            HAL_Delay(500);

                                 	 	       }
                                 	 	         else if (uRx_Data1[j]=='/'){
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
                                 	 	         else if (uRx_Data1[j]=='E'){
                                 	 	        	 j=uLength1;
                                 	 	        	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
                                	 	        	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
                                	 	        	  HAL_Delay(166);
                                	 	        	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
                                	 	        	  HAL_Delay(167);
                                	 	        	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
                                	 	        	  HAL_Delay(166);
                                	 	        	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
                                	 	        	  HAL_Delay(167);
                                	 	        	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
                                	 	        	  HAL_Delay(166);
                                	 	        	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
                                	 	        	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
                                	 	        	  HAL_Delay(168);
                                 	 	         }
                            	 	        	 }
                            	 	        	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,GPIO_PIN_SET);
                            	 	        	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2,GPIO_PIN_SET);
                            	 	        	 k=uLength1;

                            	 	         }
                                           }
                    			   }
                    			   else if (uRx_Data0[0]==0){
                            		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,GPIO_PIN_SET);
                                       HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2,GPIO_PIN_SET);
                                       for (int i=0;i<uLength-1;i++){
                                       if (uRx_Data[i]=='.'){
                        	 	          }
                        	 	         else  if (uRx_Data[i]=='-'){

                        	 	       }
                        	 	         else if (uRx_Data[i]=='/'){
                        	 	        	   int f=0;
                        	 	        	   for (int j=k;j<=i-1;j++){
                        	 	        		   if (uRx_Data[j]!='.'&&uRx_Data[j]!='-'){
                        	 	        			   f=1;
                        	 	        			   break;
                        	 	        		   }
                        	 	        	   }
                        	 	        	   if (f==1||i-k>4||(i-k==4&&((uRx_Data[k]=='.'&&uRx_Data[k+1]=='.'&&uRx_Data[k+2]=='-'&&uRx_Data[k+3]=='-')
                        	 	        			   ||(uRx_Data[k]=='.'&&uRx_Data[k+1]=='-'&&uRx_Data[k+2]=='.'&&uRx_Data[k+3]=='-')
        											   ||(uRx_Data[k]=='-'&&uRx_Data[k+1]=='-'&&uRx_Data[k+2]=='-'&&uRx_Data[k+3]=='.')
        											   ||(uRx_Data[k]=='-'&&uRx_Data[k+1]=='-'&&uRx_Data[k+2]=='-'&&uRx_Data[k+3]=='-')))){
                        	 	        		    uRx_Data1[uLength1]='d';
                           	 	        	    	uRx_Data1[uLength1+1]='e';
                           	 	        	    	uRx_Data1[uLength1+2]='c';
                           	 	        	    	uRx_Data1[uLength1+3]='o';
                           	 	        	    	uRx_Data1[uLength1+4]='d';
                           	 	        	    	uRx_Data1[uLength1+5]='e';
                           	 	        	    	uRx_Data1[uLength1+6]=' ';
                           	 	        	    	uRx_Data1[uLength1+7]='E';
                           	 	        	    	uRx_Data1[uLength1+8]='r';
                           	 	        	    	uRx_Data1[uLength1+9]='r';
                           	 	        	    	uRx_Data1[uLength1+10]='o';
                           	 	        	    	uRx_Data1[uLength1+11]='r';
                           	 	        	    	uRx_Data1[uLength1+12]=':';
                           	 	        	    	uRx_Data1[uLength1+13]=' ';
                           	 	        	    	for (int j=k;j<=i-1;j++){
                             	 	        		  	uRx_Data1[uLength1+13+j-k+1]=uRx_Data[j];
                             	 	        	   }
                           	 	        	    	uLength1+=13+i-k+1;
                           	 	        	    	k=i+1;
                           	 	        	    uRx_Data2[h]='d';
                           	 	        	    uLength2+=1;
                        	 	        	   }
                        	 	        	   else {
                        	 	        		   if (i-k==1){
                        	 	        			  if (uRx_Data[k]=='.') {
                        	 	        				  uRx_Data1[uLength1]='E';
                        	 	        				  uLength1++; uRx_Data2[h]='.';
                                	 	        	    	uRx_Data2[h+1]='/';
                                   	 	        	    	//k=k+2;
                                   	 	        	        uLength2+=2;

                        	 	        			  }
                        	 	        			  else if (uRx_Data[k]=='-') {
                        	 	        				  uRx_Data1[uLength1]='T';
                        	 	        				  uLength1++;uRx_Data2[h]='-';
                                 	 	        	    	uRx_Data2[h+1]='/';
                                   	 	        	    	//k=k+2;
                                   	 	        	        uLength2+=2;
                        	 	        			  }
                        	 	        		  }else if(i-k==2) {
                        	 	        			 if (uRx_Data[k]=='.') {
                        	 	        				  if (uRx_Data[k+1]=='.') {
                        	 	        				       uRx_Data1[uLength1]='I';
                        	 	        				       uLength1++;uRx_Data2[h]='.';
                                     	 	        	    	uRx_Data2[h+1]='.';
                                     	 	        	    	uRx_Data2[h+2]='/';
                                        	 	        	    	//k=k+3;
                                        	 	        	        uLength2+=3;
                        	 	        				   }
                        	 	        				 else if (uRx_Data[k+1]=='-') {
                        	 	        				       uRx_Data1[uLength1]='A';
                        	 	        				       uLength1++;
                        	 	        				       uRx_Data2[h]='.';
                                   	 	        	    	  uRx_Data2[h+1]='-';
                                   	 	        	    	  uRx_Data2[h+2]='/';
                                   	 	        	    	//k=k+3;
                                   	 	        	        uLength2+=3;

                        	 	        				   }

                        	 	        			  }
                        	 	        			 else if (uRx_Data[k]=='-') {
                        	 	        				  if (uRx_Data[k+1]=='.') {
                        	 	        				        uRx_Data1[uLength1]='N';
                        	 	        				        uLength1++;uRx_Data2[h]='-';
                                      	 	        	    	uRx_Data2[h+1]='.';
                                      	 	        	    	uRx_Data2[h+2]='/';
                                         	 	        	    	//k=k+3;
                                         	 	        	        uLength2+=3;
                        	 	        				  }
                        	 	        				  else if (uRx_Data[k+1]=='-') {
                        	 	        				        uRx_Data1[uLength1]='M';
                        	 	        				        uLength1++;uRx_Data2[h]='-';
                                      	 	        	    	uRx_Data2[h+1]='-';
                                      	 	        	    	uRx_Data2[h+2]='/';
                                         	 	        	    	//k=k+3;
                                         	 	        	        uLength2+=3;
                        	 	        				  }

                        	 	        			}

                        	 	        		  }else if (i-k==3){
                        	 	        	     if (uRx_Data[k]=='.') {
                    	 	        				  if (uRx_Data[k+1]=='.') {
                    	 	        					  if (uRx_Data[k+2]=='.') {
                   	 	        				       uRx_Data1[uLength1]='S';
                   	 	        				       uLength1++; uRx_Data2[h]='.';
                              	 	        	    	uRx_Data2[h+1]='.';
                              	 	        	    	uRx_Data2[h+2]='.';
                              	 	        	    	uRx_Data2[h+3]='/';
                                	 	        	    	//k=k+4;
                                	 	        	        uLength2+=4;
                   	 	        				   }
                   	 	        				 else if (uRx_Data[k+2]=='-') {
                   	 	        				       uRx_Data1[uLength1]='U';
                   	 	        				       uLength1++;uRx_Data2[h]='.';
                              	 	        	    	uRx_Data2[h+1]='.';
                              	 	        	    	uRx_Data2[h+2]='-';
                              	 	        	    	uRx_Data2[h+3]='/';
                                	 	        	    	//k=k+4;
                                	 	        	        uLength2+=4;
                   	 	        				   }

                    	 	        				   }
                    	 	        				 else if (uRx_Data[k+1]=='-') {
                    	 	        					 if (uRx_Data[k+2]=='.') {
                  	 	        				       uRx_Data1[uLength1]='R';
                  	 	        				       uLength1++;uRx_Data2[h]='.';
                              	 	        	    	uRx_Data2[h+1]='-';
                              	 	        	    	uRx_Data2[h+2]='.';
                              	 	        	    	uRx_Data2[h+3]='/';
                                	 	        	    	//k=k+4;
                                	 	        	        uLength2+=4;
                  	 	        				   }
                  	 	        				 else if (uRx_Data[k+2]=='-') {
                  	 	        				       uRx_Data1[uLength1]='W';
                  	 	        				       uLength1++;uRx_Data2[h]='.';
                              	 	        	    	uRx_Data2[h+1]='-';
                              	 	        	    	uRx_Data2[h+2]='-';
                              	 	        	    	uRx_Data2[h+3]='/';
                                	 	        	    	//k=k+4;
                                	 	        	        uLength2+=4;
                  	 	        				   }

                    	 	        				   }

                    	 	        			  }
                    	 	        			 else if (uRx_Data[k]=='-') {
                    	 	        				  if (uRx_Data[k+1]=='.') {
                    	 	        					  if (uRx_Data[k+2]=='.') {
                      	 	        				       uRx_Data1[uLength1]='D';
                      	 	        				       uLength1++;uRx_Data2[h]='-';
                                 	 	        	    	uRx_Data2[h+1]='.';
                                 	 	        	    	uRx_Data2[h+2]='.';
                                 	 	        	    	uRx_Data2[h+3]='/';
                                    	 	        	    	//k=k+4;
                                    	 	        	        uLength2+=4;
                      	 	        				   }
                      	 	        				 else if (uRx_Data[k+2]=='-') {
                      	 	        				       uRx_Data1[uLength1]='K';
                      	 	        				       uLength1++;uRx_Data2[h]='-';
                                 	 	        	    	uRx_Data2[h+1]='.';
                                 	 	        	    	uRx_Data2[h+2]='-';
                                 	 	        	    	uRx_Data2[h+3]='/';
                                    	 	        	    	//k=k+4;
                                    	 	        	        uLength2+=4;
                      	 	        				   }

                    	 	        				  }
                    	 	        				  else if (uRx_Data[k+1]=='-') {
                    	 	        					  if (uRx_Data[k+2]=='.') {
                      	 	        				       uRx_Data1[uLength1]='G';
                      	 	        				       uLength1++;uRx_Data2[h]='-';
                                 	 	        	    	uRx_Data2[h+1]='-';
                                 	 	        	    	uRx_Data2[h+2]='.';
                                 	 	        	    	uRx_Data2[h+3]='/';
                                    	 	        	    	//k=k+4;
                                    	 	        	        uLength2+=4;
                      	 	        				   }
                      	 	        				 else if (uRx_Data[k+2]=='-') {
                      	 	        				       uRx_Data1[uLength1]='O';
                      	 	        				       uLength1++; uRx_Data2[h]='-';
                                  	 	        	    	uRx_Data2[h+1]='-';
                                  	 	        	    	uRx_Data2[h+2]='-';
                                  	 	        	    	uRx_Data2[h+3]='/';
                                    	 	        	    	//k=k+4;
                                    	 	        	        uLength2+=4;
                      	 	        				   }

                    	 	        				  }

                    	 	        			}


                        	 	        		  }else if (i-k==4){

                        	 	        		if (uRx_Data[k]=='.') {
                    	 	        				  if (uRx_Data[k+1]=='.') {
                    	 	        					  if (uRx_Data[k+2]=='.') {
                    	 	        						  if (uRx_Data[k+3]=='.') {
                          	 	        				       uRx_Data1[uLength1]='H';
                          	 	        				       uLength1++;uRx_Data2[h]='.';
                                     	 	        	    	uRx_Data2[h+1]='.';
                                     	 	        	    	uRx_Data2[h+2]='.';
                                     	 	        	    	uRx_Data2[h+3]='.';
                                     	 	        	    	uRx_Data2[h+4]='/';
                                        	 	        	    	//k=k+5;
                                        	 	        	        uLength2+=5;
                          	 	        				   }
                          	 	        				 else if (uRx_Data[k+3]=='-') {
                          	 	        				       uRx_Data1[uLength1]='V';
                          	 	        				       uLength1++;uRx_Data2[h]='.';
                                      	 	        	    	uRx_Data2[h+1]='.';
                                      	 	        	    	uRx_Data2[h+2]='.';
                                      	 	        	    	uRx_Data2[h+3]='-';
                                      	 	        	    	uRx_Data2[h+4]='/';
                                        	 	        	    	//k=k+5;
                                        	 	        	        uLength2+=5;
                          	 	        				   }

                   	 	        				   }
                   	 	        				 else if (uRx_Data[k+2]=='-') {
                   	 	        					 if (uRx_Data[k+3]=='.') {
                	 	        				       uRx_Data1[uLength1]='F';
                	 	        				       uLength1++;uRx_Data2[h]='.';
                             	 	        	    	uRx_Data2[h+1]='.';
                             	 	        	    	uRx_Data2[h+2]='-';
                             	 	        	    	uRx_Data2[h+3]='.';
                             	 	        	    	uRx_Data2[h+4]='/';
                                	 	        	    	//k=k+5;
                                	 	        	        uLength2+=5;
                	 	        				   }
                	 	        				 else if (uRx_Data[k+3]=='-') {

                	 	        				   }
                   	 	        				   }

                    	 	        				   }
                    	 	        				 else if (uRx_Data[k+1]=='-') {
                    	 	        					 if (uRx_Data[k+2]=='.') {
                    	 	        						 if (uRx_Data[k+3]=='.') {
                        	 	        				       uRx_Data1[uLength1]='L';
                        	 	        				       uLength1++;uRx_Data2[h]='.';
                                     	 	        	    	uRx_Data2[h+1]='-';
                                     	 	        	    	uRx_Data2[h+2]='.';
                                     	 	        	    	uRx_Data2[h+3]='.';
                                     	 	        	    	uRx_Data2[h+4]='/';
                                        	 	        	    	//k=k+5;
                                        	 	        	        uLength2+=5;
                        	 	        				   }
                        	 	        				 else if (uRx_Data[k+3]=='-') {

                        	 	        				   }

                  	 	        				   }
                  	 	        				 else if (uRx_Data[k+2]=='-') {
                  	 	        					 if (uRx_Data[k+3]=='.') {
                	 	        				       uRx_Data1[uLength1]='P';
                	 	        				       uLength1++;uRx_Data2[h]='.';
                              	 	        	    	uRx_Data2[h+1]='-';
                              	 	        	    	uRx_Data2[h+2]='-';
                              	 	        	    	uRx_Data2[h+3]='.';
                              	 	        	    	uRx_Data2[h+4]='/';
                                	 	        	    	//k=k+5;
                                	 	        	        uLength2+=5;
                	 	        				   }
                	 	        				 else if (uRx_Data[k+3]=='-') {
                	 	        				       uRx_Data1[uLength1]='J';
                	 	        				       uLength1++;uRx_Data2[h]='.';
                             	 	        	    	uRx_Data2[h+1]='-';
                             	 	        	    	uRx_Data2[h+2]='-';
                             	 	        	    	uRx_Data2[h+3]='-';
                             	 	        	    	uRx_Data2[h+4]='/';
                                	 	        	    	//k=k+5;
                                	 	        	        uLength2+=5;
                	 	        				   }

                  	 	        				   }

                    	 	        				   }

                    	 	        			  }
                    	 	        			 else if (uRx_Data[k]=='-') {
                    	 	        				  if (uRx_Data[k+1]=='.') {
                    	 	        					  if (uRx_Data[k+2]=='.') {
                    	 	        						  if (uRx_Data[k+3]=='.') {
                         	 	        				       uRx_Data1[uLength1]='B';
                         	 	        				       uLength1++;uRx_Data2[h]='-';
                                    	 	        	    	uRx_Data2[h+1]='.';
                                    	 	        	    	uRx_Data2[h+2]='.';
                                    	 	        	    	uRx_Data2[h+3]='.';
                                    	 	        	    	uRx_Data2[h+4]='/';
                                    	 	        	    	//k=k+5;
                                    	 	        	        uLength2+=5;
                         	 	        				   }
                         	 	        				 else if (uRx_Data[k+3]=='-') {
                         	 	        				       uRx_Data1[uLength1]='X';
                         	 	        				       uLength1++;uRx_Data2[h]='-';
                                      	 	        	    	uRx_Data2[h+1]='.';
                                      	 	        	    	uRx_Data2[h+2]='.';
                                      	 	        	    	uRx_Data2[h+3]='-';
                                      	 	        	    	uRx_Data2[h+4]='/';
                                        	 	        	    	//k=k+5;
                                        	 	        	        uLength2+=5;
                         	 	        				   }

                      	 	        				   }
                      	 	        				 else if (uRx_Data[k+2]=='-') {
                      	 	        					 if (uRx_Data[k+3]=='.') {
                    	 	        				       uRx_Data1[uLength1]='C';
                    	 	        				       uLength1++; uRx_Data2[h]='-';
                            	 	        	    	     uRx_Data2[h+1]='.';
                            	 	        	    	     uRx_Data2[h+2]='-';
                            	 	        	    	     uRx_Data2[h+3]='.';
                            	 	        	    	     uRx_Data2[h+4]='/';
                               	 	        	    	//k=k+5;
                               	 	        	        uLength2+=5;
                    	 	        				   }
                    	 	        				 else if (uRx_Data[k+3]=='-') {
                    	 	        				       uRx_Data1[uLength1]='Y';
                    	 	        				       uLength1++; uRx_Data2[h]='-';
                                  	 	        	    	uRx_Data2[h+1]='.';
                                  	 	        	    	uRx_Data2[h+2]='-';
                                  	 	        	    	uRx_Data2[h+3]='-';
                                  	 	        	    	uRx_Data2[h+4]='/';
                                    	 	        	    	//k=k+5;
                                    	 	        	        uLength2+=5;
                    	 	        				   }

                      	 	        				   }

                    	 	        				  }
                    	 	        				  else if (uRx_Data[k+1]=='-') {
                    	 	        					  if (uRx_Data[k+2]=='.') {
                    	 	        						  if (uRx_Data[k+3]=='.') {
                         	 	        				       uRx_Data1[uLength1]='Z';
                         	 	        				       uLength1++; uRx_Data2[h]='-';
                                      	 	        	    	uRx_Data2[h+1]='-';
                                      	 	        	    	uRx_Data2[h+2]='.';
                                      	 	        	    	uRx_Data2[h+3]='.';
                                      	 	        	    	uRx_Data2[h+4]='/';
                                        	 	        	    	//k=k+5;
                                        	 	        	        uLength2+=5;
                         	 	        				   }
                         	 	        				 else if (uRx_Data[k+3]=='-') {
                         	 	        				       uRx_Data1[uLength1]='Q';
                         	 	        				       uLength1++; uRx_Data2[h]='-';
                                      	 	        	    	uRx_Data2[h+1]='-';
                                      	 	        	    	uRx_Data2[h+2]='.';
                                      	 	        	    	uRx_Data2[h+3]='-';
                                      	 	        	    	uRx_Data2[h+4]='/';
                                        	 	        	    	//k=k+5;
                                        	 	        	        uLength2+=5;
                         	 	        				   }

                      	 	        				   }
                      	 	        				 else if (uRx_Data[k+2]=='-') {
                      	 	        					 if (uRx_Data[k+3]=='.') {

                    	 	        				   }
                    	 	        				 else if (uRx_Data[k+3]=='-') {

                    	 	        				   }

                      	 	        				   }

                    	 	        				  }

                    	 	        			}



                        	 	        		  }

                                                   k=i+1;
                        	 	        	   }

                        	 	         }
                                       //HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,GPIO_PIN_SET);
                                                               	 	        	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2,GPIO_PIN_SET);
                                                               	 	        	 for (int j=h;j<=uLength2-1;j++){
                                                               	 	        		 if (uRx_Data2[j]=='.'){
                                                                    	 	            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
                                                                    	 	            HAL_Delay(500);
                                                                    	 	            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
                                                                    	 	            HAL_Delay(500);
                                                                    	 	          }
                                                                    	 	         else  if (uRx_Data2[j]=='-'){
                                                                    	 	            HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
                                                                    	 	            HAL_Delay(500);
                                                                    	 	            HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
                                                                    	 	            HAL_Delay(500);

                                                                    	 	       }
                                                                    	 	         else if (uRx_Data2[j]=='/'){
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
                                                                    	 	         else if (uRx_Data2[j]=='d'){
                                                                    	 	        	 //j=uLength2;
                                                                    	 	        	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
                                                                    	 	        	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
                                                                   	 	        	  HAL_Delay(166);
                                                                   	 	        	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
                                                                   	 	        	  HAL_Delay(167);
                                                                   	 	        	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
                                                                   	 	        	  HAL_Delay(166);
                                                                   	 	        	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
                                                                   	 	        	  HAL_Delay(167);
                                                                   	 	        	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
                                                                   	 	        	  HAL_Delay(166);
                                                                   	 	        	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
                                                                   	 	        	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
                                                                   	 	        	  HAL_Delay(168);
                                                                    	 	         }
                                                               	 	        	 }
                                                               	 	        	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,GPIO_PIN_SET);
                                                               	 	        	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2,GPIO_PIN_SET);
                                                               	 	        	 h=uLength2;
                                       }

                                       //



                            	   }
                    		   }

                    	   }
                    	   else {
                    		   if (uRx_Data0[0]==1){
            				   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,GPIO_PIN_SET);
            				   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2,GPIO_PIN_SET);
            				   for (int i=0;i<uLength-1;i++){
                                   {
                    	 	        	 switch (uRx_Data[i]){
                    	 	        	     case 'A':
                    	 	        	    	uRx_Data1[k]='.';
                    	 	        	    	uRx_Data1[k+1]='-';
                    	 	        	    	uRx_Data1[k+2]='/';
                    	 	        	    	//k=k+3;
                    	 	        	        uLength1+=3;
                    	 	        		 break;
                    	 	        		 case 'B':
                     	 	        	    	uRx_Data1[k]='-';
                     	 	        	    	uRx_Data1[k+1]='.';
                     	 	        	    	uRx_Data1[k+2]='.';
                     	 	        	    	uRx_Data1[k+3]='.';
                     	 	        	    	uRx_Data1[k+4]='/';
                     	 	        	    	//k=k+5;
                     	 	        	        uLength1+=5;
                     	 	        		 break;
                     	 	        		 case 'C':
                     	 	        			 uRx_Data1[k]='-';
                  	 	        	    	     uRx_Data1[k+1]='.';
                  	 	        	    	     uRx_Data1[k+2]='-';
                  	 	        	    	     uRx_Data1[k+3]='.';
                  	 	        	    	     uRx_Data1[k+4]='/';
                     	 	        	    	//k=k+5;
                     	 	        	        uLength1+=5;
                     	 	        		 break;
                     	 	        		 case 'D':
                     	 	        	    uRx_Data1[k]='-';
                  	 	        	    	uRx_Data1[k+1]='.';
                  	 	        	    	uRx_Data1[k+2]='.';
                  	 	        	    	uRx_Data1[k+3]='/';
                     	 	        	    	//k=k+4;
                     	 	        	        uLength1+=4;
                     	 	        		 break;
                     	 	        		 case 'E':
                     	 	        			 uRx_Data1[k]='.';
                  	 	        	    	uRx_Data1[k+1]='/';
                     	 	        	    	//k=k+2;
                     	 	        	        uLength1+=2;
                     	 	        		 break;
                     	 	        		 case 'F':
                     	 	        			 uRx_Data1[k]='.';
                  	 	        	    	uRx_Data1[k+1]='.';
                  	 	        	    	uRx_Data1[k+2]='-';
                  	 	        	    	uRx_Data1[k+3]='.';
                  	 	        	    	uRx_Data1[k+4]='/';
                     	 	        	    	//k=k+5;
                     	 	        	        uLength1+=5;
                     	 	        		 break;
                     	 	        		 case 'G':
                     	 	        			 uRx_Data1[k]='-';
                  	 	        	    	uRx_Data1[k+1]='-';
                  	 	        	    	uRx_Data1[k+2]='.';
                  	 	        	    	uRx_Data1[k+3]='/';
                     	 	        	    	//k=k+4;
                     	 	        	        uLength1+=4;
                     	 	        		 break;
                     	 	        		 case 'H':
                     	 	        			 uRx_Data1[k]='.';
                  	 	        	    	uRx_Data1[k+1]='.';
                  	 	        	    	uRx_Data1[k+2]='.';
                  	 	        	    	uRx_Data1[k+3]='.';
                  	 	        	    	uRx_Data1[k+4]='/';
                     	 	        	    	//k=k+5;
                     	 	        	        uLength1+=5;
                     	 	        		 break;
                     	 	        		 case 'I':
                     	 	        			 uRx_Data1[k]='.';
                  	 	        	    	uRx_Data1[k+1]='.';
                  	 	        	    	uRx_Data1[k+2]='/';
                     	 	        	    	//k=k+3;
                     	 	        	        uLength1+=3;
                     	 	        		 break;
                     	 	        		 case 'J':uRx_Data1[k]='.';
                  	 	        	    	uRx_Data1[k+1]='-';
                  	 	        	    	uRx_Data1[k+2]='-';
                  	 	        	    	uRx_Data1[k+3]='-';
                  	 	        	    	uRx_Data1[k+4]='/';
                     	 	        	    	//k=k+5;
                     	 	        	        uLength1+=5;
                     	 	        		 break;
                     	 	        		 case 'K':
                     	 	        			 uRx_Data1[k]='-';
                  	 	        	    	uRx_Data1[k+1]='.';
                  	 	        	    	uRx_Data1[k+2]='-';
                  	 	        	    	uRx_Data1[k+3]='/';
                     	 	        	    	//k=k+4;
                     	 	        	        uLength1+=4;
                     	 	        		 break;
                     	 	        		 case 'L':
                     	 	        			 uRx_Data1[k]='.';
                  	 	        	    	uRx_Data1[k+1]='-';
                  	 	        	    	uRx_Data1[k+2]='.';
                  	 	        	    	uRx_Data1[k+3]='.';
                  	 	        	    	uRx_Data1[k+4]='/';
                     	 	        	    	//k=k+5;
                     	 	        	        uLength1+=5;
                     	 	        		 break;
                     	 	        		 case 'M':
                     	 	        			 uRx_Data1[k]='-';
                  	 	        	    	uRx_Data1[k+1]='-';
                  	 	        	    	uRx_Data1[k+2]='/';
                     	 	        	    	//k=k+3;
                     	 	        	        uLength1+=3;
                     	 	        		 break;
                     	 	        		 case 'N':
                     	 	        			 uRx_Data1[k]='-';
                  	 	        	    	uRx_Data1[k+1]='.';
                  	 	        	    	uRx_Data1[k+2]='/';
                     	 	        	    	//k=k+3;
                     	 	        	        uLength1+=3;
                     	 	        		 break;
                     	 	        		 case 'O':
                     	 	        			 uRx_Data1[k]='-';
                   	 	        	    	uRx_Data1[k+1]='-';
                   	 	        	    	uRx_Data1[k+2]='-';
                   	 	        	    	uRx_Data1[k+3]='/';
                     	 	        	    	//k=k+4;
                     	 	        	        uLength1+=4;
                     	 	        		 break;
                     	 	        		 case 'P':
                     	 	        			 uRx_Data1[k]='.';
                   	 	        	    	uRx_Data1[k+1]='-';
                   	 	        	    	uRx_Data1[k+2]='-';
                   	 	        	    	uRx_Data1[k+3]='.';
                   	 	        	    	uRx_Data1[k+4]='/';
                     	 	        	    	//k=k+5;
                     	 	        	        uLength1+=5;
                     	 	        		 break;
                     	 	        		 case 'Q':
                     	 	        			 uRx_Data1[k]='-';
                   	 	        	    	uRx_Data1[k+1]='-';
                   	 	        	    	uRx_Data1[k+2]='.';
                   	 	        	    	uRx_Data1[k+3]='-';
                   	 	        	    	uRx_Data1[k+4]='/';
                     	 	        	    	//k=k+5;
                     	 	        	        uLength1+=5;
                     	 	        		 break;
                     	 	        		 case 'R':
                     	 	        			 uRx_Data1[k]='.';
                   	 	        	    	uRx_Data1[k+1]='-';
                   	 	        	    	uRx_Data1[k+2]='.';
                   	 	        	    	uRx_Data1[k+3]='/';
                     	 	        	    	//k=k+4;
                     	 	        	        uLength1+=4;
                     	 	        		 break;
                     	 	        		 case 'S':
                     	 	        			 uRx_Data1[k]='.';
                   	 	        	    	uRx_Data1[k+1]='.';
                   	 	        	    	uRx_Data1[k+2]='.';
                   	 	        	    	uRx_Data1[k+3]='/';
                     	 	        	    	//k=k+4;
                     	 	        	        uLength1+=4;
                     	 	        		 break;
                     	 	        		 case 'T':
                     	 	        			 uRx_Data1[k]='-';
                   	 	        	    	uRx_Data1[k+1]='/';
                     	 	        	    	//k=k+2;
                     	 	        	        uLength1+=2;
                     	 	        		 break;
                     	 	        		 case 'U':
                     	 	        			 uRx_Data1[k]='.';
                   	 	        	    	uRx_Data1[k+1]='.';
                   	 	        	    	uRx_Data1[k+2]='-';
                   	 	        	    	uRx_Data1[k+3]='/';
                     	 	        	    	//k=k+4;
                     	 	        	        uLength1+=4;
                     	 	        		 break;
                     	 	        		 case 'V':
                     	 	        			 uRx_Data1[k]='.';
                   	 	        	    	uRx_Data1[k+1]='.';
                   	 	        	    	uRx_Data1[k+2]='.';
                   	 	        	    	uRx_Data1[k+3]='-';
                   	 	        	    	uRx_Data1[k+4]='/';
                     	 	        	    	//k=k+5;
                     	 	        	        uLength1+=5;
                     	 	        		 break;
                     	 	        		 case 'W':
                     	 	        			 uRx_Data1[k]='.';
                   	 	        	    	uRx_Data1[k+1]='-';
                   	 	        	    	uRx_Data1[k+2]='-';
                   	 	        	    	uRx_Data1[k+3]='/';
                     	 	        	    	//k=k+4;
                     	 	        	        uLength1+=4;
                     	 	        		 break;
                     	 	        		 case 'X':
                     	 	        			 uRx_Data1[k]='-';
                   	 	        	    	uRx_Data1[k+1]='.';
                   	 	        	    	uRx_Data1[k+2]='.';
                   	 	        	    	uRx_Data1[k+3]='-';
                   	 	        	    	uRx_Data1[k+4]='/';
                     	 	        	    	//k=k+5;
                     	 	        	        uLength1+=5;
                     	 	        		 break;
                     	 	        		 case 'Y':
                     	 	        			 uRx_Data1[k]='-';
                   	 	        	    	uRx_Data1[k+1]='.';
                   	 	        	    	uRx_Data1[k+2]='-';
                   	 	        	    	uRx_Data1[k+3]='-';
                   	 	        	    	uRx_Data1[k+4]='/';
                     	 	        	    	//k=k+5;
                     	 	        	        uLength1+=5;
                     	 	        		 break;
                     	 	        		 case 'Z':
                     	 	        			 uRx_Data1[k]='-';
                   	 	        	    	uRx_Data1[k+1]='-';
                   	 	        	    	uRx_Data1[k+2]='.';
                   	 	        	    	uRx_Data1[k+3]='.';
                   	 	        	    	uRx_Data1[k+4]='/';
                     	 	        	    	//k=k+5;
                     	 	        	        uLength1+=5;
                     	 	        		 break;

                     	 	        		 default:
                     	 	        			uRx_Data1[k]='E';
                    	 	        	    	uRx_Data1[k+1]='n';
                    	 	        	    	uRx_Data1[k+2]='c';
                    	 	        	    	uRx_Data1[k+3]='o';
                    	 	        	    	uRx_Data1[k+4]='d';
                    	 	        	    	uRx_Data1[k+5]='e';
                    	 	        	    	uRx_Data1[k+6]=' ';
                    	 	        	    	uRx_Data1[k+7]='E';
                    	 	        	    	uRx_Data1[k+8]='r';
                    	 	        	    	uRx_Data1[k+9]='r';
                    	 	        	    	uRx_Data1[k+10]='o';
                    	 	        	    	uRx_Data1[k+11]='r';
                    	 	        	    	uRx_Data1[k+12]=':';
                    	 	        	    	uRx_Data1[k+13]=' ';
                    	 	        	    	uRx_Data1[k+14]=uRx_Data[i];
                    	 	        	    	uLength1+=15;

                    	 	        	 }
                    	 	        	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,GPIO_PIN_SET);
                    	 	        	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2,GPIO_PIN_SET);
                    	 	        	 for (int j=k;j<=uLength1-1;j++){
                    	 	        		 if (uRx_Data1[j]=='.'){
                         	 	            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
                         	 	            HAL_Delay(500);
                         	 	            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
                         	 	            HAL_Delay(500);
                         	 	          }
                         	 	         else  if (uRx_Data1[j]=='-'){
                         	 	            HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
                         	 	            HAL_Delay(500);
                         	 	            HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
                         	 	            HAL_Delay(500);

                         	 	       }
                         	 	         else if (uRx_Data1[j]=='/'){
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
                         	 	         else if (uRx_Data1[j]=='E'){
                         	 	        	 j=uLength1;
                         	 	        	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
                        	 	        	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
                        	 	        	  HAL_Delay(166);
                        	 	        	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
                        	 	        	  HAL_Delay(167);
                        	 	        	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
                        	 	        	  HAL_Delay(166);
                        	 	        	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
                        	 	        	  HAL_Delay(167);
                        	 	        	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
                        	 	        	  HAL_Delay(166);
                        	 	        	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
                        	 	        	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
                        	 	        	  HAL_Delay(168);
                         	 	         }
                    	 	        	 }
                    	 	        	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,GPIO_PIN_SET);
                    	 	        	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2,GPIO_PIN_SET);
                    	 	        	 k=uLength1;

                    	 	         }
                                   }
            			   }
                    		   else if (uRx_Data0[0]==0){
                        		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,GPIO_PIN_SET);
                                   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2,GPIO_PIN_SET);
                                   for (int i=0;i<uLength-1;i++){
                                   if (uRx_Data[i]=='.'){
                    	 	          }
                    	 	         else  if (uRx_Data[i]=='-'){

                    	 	       }
                    	 	         else if (uRx_Data[i]=='/'){
                    	 	        	   int f=0;
                    	 	        	   for (int j=k;j<=i-1;j++){
                    	 	        		   if (uRx_Data[j]!='.'&&uRx_Data[j]!='-'){
                    	 	        			   f=1;
                    	 	        			   break;
                    	 	        		   }
                    	 	        	   }
                    	 	        	   if (f==1||i-k>4||(i-k==4&&((uRx_Data[k]=='.'&&uRx_Data[k+1]=='.'&&uRx_Data[k+2]=='-'&&uRx_Data[k+3]=='-')
                    	 	        			   ||(uRx_Data[k]=='.'&&uRx_Data[k+1]=='-'&&uRx_Data[k+2]=='.'&&uRx_Data[k+3]=='-')
    											   ||(uRx_Data[k]=='-'&&uRx_Data[k+1]=='-'&&uRx_Data[k+2]=='-'&&uRx_Data[k+3]=='.')
    											   ||(uRx_Data[k]=='-'&&uRx_Data[k+1]=='-'&&uRx_Data[k+2]=='-'&&uRx_Data[k+3]=='-')))){
                    	 	        		    uRx_Data1[uLength1]='d';
                       	 	        	    	uRx_Data1[uLength1+1]='e';
                       	 	        	    	uRx_Data1[uLength1+2]='c';
                       	 	        	    	uRx_Data1[uLength1+3]='o';
                       	 	        	    	uRx_Data1[uLength1+4]='d';
                       	 	        	    	uRx_Data1[uLength1+5]='e';
                       	 	        	    	uRx_Data1[uLength1+6]=' ';
                       	 	        	    	uRx_Data1[uLength1+7]='E';
                       	 	        	    	uRx_Data1[uLength1+8]='r';
                       	 	        	    	uRx_Data1[uLength1+9]='r';
                       	 	        	    	uRx_Data1[uLength1+10]='o';
                       	 	        	    	uRx_Data1[uLength1+11]='r';
                       	 	        	    	uRx_Data1[uLength1+12]=':';
                       	 	        	    	uRx_Data1[uLength1+13]=' ';
                       	 	        	    	for (int j=k;j<=i-1;j++){
                         	 	        		  	uRx_Data1[uLength1+13+j-k+1]=uRx_Data[j];
                         	 	        	   }
                       	 	        	    	uLength1+=13+i-k+1;
                       	 	        	    	k=i+1;
                       	 	        	    uRx_Data2[h]='d';
                       	 	        	    uLength2+=1;
                    	 	        	   }
                    	 	        	   else {
                    	 	        		   if (i-k==1){
                    	 	        			  if (uRx_Data[k]=='.') {
                    	 	        				  uRx_Data1[uLength1]='E';
                    	 	        				  uLength1++; uRx_Data2[h]='.';
                            	 	        	    	uRx_Data2[h+1]='/';
                               	 	        	    	//k=k+2;
                               	 	        	        uLength2+=2;

                    	 	        			  }
                    	 	        			  else if (uRx_Data[k]=='-') {
                    	 	        				  uRx_Data1[uLength1]='T';
                    	 	        				  uLength1++;uRx_Data2[h]='-';
                             	 	        	    	uRx_Data2[h+1]='/';
                               	 	        	    	//k=k+2;
                               	 	        	        uLength2+=2;
                    	 	        			  }
                    	 	        		  }else if(i-k==2) {
                    	 	        			 if (uRx_Data[k]=='.') {
                    	 	        				  if (uRx_Data[k+1]=='.') {
                    	 	        				       uRx_Data1[uLength1]='I';
                    	 	        				       uLength1++;uRx_Data2[h]='.';
                                 	 	        	    	uRx_Data2[h+1]='.';
                                 	 	        	    	uRx_Data2[h+2]='/';
                                    	 	        	    	//k=k+3;
                                    	 	        	        uLength2+=3;
                    	 	        				   }
                    	 	        				 else if (uRx_Data[k+1]=='-') {
                    	 	        				       uRx_Data1[uLength1]='A';
                    	 	        				       uLength1++;
                    	 	        				       uRx_Data2[h]='.';
                               	 	        	    	  uRx_Data2[h+1]='-';
                               	 	        	    	  uRx_Data2[h+2]='/';
                               	 	        	    	//k=k+3;
                               	 	        	        uLength2+=3;

                    	 	        				   }

                    	 	        			  }
                    	 	        			 else if (uRx_Data[k]=='-') {
                    	 	        				  if (uRx_Data[k+1]=='.') {
                    	 	        				        uRx_Data1[uLength1]='N';
                    	 	        				        uLength1++;uRx_Data2[h]='-';
                                  	 	        	    	uRx_Data2[h+1]='.';
                                  	 	        	    	uRx_Data2[h+2]='/';
                                     	 	        	    	//k=k+3;
                                     	 	        	        uLength2+=3;
                    	 	        				  }
                    	 	        				  else if (uRx_Data[k+1]=='-') {
                    	 	        				        uRx_Data1[uLength1]='M';
                    	 	        				        uLength1++;uRx_Data2[h]='-';
                                  	 	        	    	uRx_Data2[h+1]='-';
                                  	 	        	    	uRx_Data2[h+2]='/';
                                     	 	        	    	//k=k+3;
                                     	 	        	        uLength2+=3;
                    	 	        				  }

                    	 	        			}

                    	 	        		  }else if (i-k==3){
                    	 	        	     if (uRx_Data[k]=='.') {
                	 	        				  if (uRx_Data[k+1]=='.') {
                	 	        					  if (uRx_Data[k+2]=='.') {
               	 	        				       uRx_Data1[uLength1]='S';
               	 	        				       uLength1++; uRx_Data2[h]='.';
                          	 	        	    	uRx_Data2[h+1]='.';
                          	 	        	    	uRx_Data2[h+2]='.';
                          	 	        	    	uRx_Data2[h+3]='/';
                            	 	        	    	//k=k+4;
                            	 	        	        uLength2+=4;
               	 	        				   }
               	 	        				 else if (uRx_Data[k+2]=='-') {
               	 	        				       uRx_Data1[uLength1]='U';
               	 	        				       uLength1++;uRx_Data2[h]='.';
                          	 	        	    	uRx_Data2[h+1]='.';
                          	 	        	    	uRx_Data2[h+2]='-';
                          	 	        	    	uRx_Data2[h+3]='/';
                            	 	        	    	//k=k+4;
                            	 	        	        uLength2+=4;
               	 	        				   }

                	 	        				   }
                	 	        				 else if (uRx_Data[k+1]=='-') {
                	 	        					 if (uRx_Data[k+2]=='.') {
              	 	        				       uRx_Data1[uLength1]='R';
              	 	        				       uLength1++;uRx_Data2[h]='.';
                          	 	        	    	uRx_Data2[h+1]='-';
                          	 	        	    	uRx_Data2[h+2]='.';
                          	 	        	    	uRx_Data2[h+3]='/';
                            	 	        	    	//k=k+4;
                            	 	        	        uLength2+=4;
              	 	        				   }
              	 	        				 else if (uRx_Data[k+2]=='-') {
              	 	        				       uRx_Data1[uLength1]='W';
              	 	        				       uLength1++;uRx_Data2[h]='.';
                          	 	        	    	uRx_Data2[h+1]='-';
                          	 	        	    	uRx_Data2[h+2]='-';
                          	 	        	    	uRx_Data2[h+3]='/';
                            	 	        	    	//k=k+4;
                            	 	        	        uLength2+=4;
              	 	        				   }

                	 	        				   }

                	 	        			  }
                	 	        			 else if (uRx_Data[k]=='-') {
                	 	        				  if (uRx_Data[k+1]=='.') {
                	 	        					  if (uRx_Data[k+2]=='.') {
                  	 	        				       uRx_Data1[uLength1]='D';
                  	 	        				       uLength1++;uRx_Data2[h]='-';
                             	 	        	    	uRx_Data2[h+1]='.';
                             	 	        	    	uRx_Data2[h+2]='.';
                             	 	        	    	uRx_Data2[h+3]='/';
                                	 	        	    	//k=k+4;
                                	 	        	        uLength2+=4;
                  	 	        				   }
                  	 	        				 else if (uRx_Data[k+2]=='-') {
                  	 	        				       uRx_Data1[uLength1]='K';
                  	 	        				       uLength1++;uRx_Data2[h]='-';
                             	 	        	    	uRx_Data2[h+1]='.';
                             	 	        	    	uRx_Data2[h+2]='-';
                             	 	        	    	uRx_Data2[h+3]='/';
                                	 	        	    	//k=k+4;
                                	 	        	        uLength2+=4;
                  	 	        				   }

                	 	        				  }
                	 	        				  else if (uRx_Data[k+1]=='-') {
                	 	        					  if (uRx_Data[k+2]=='.') {
                  	 	        				       uRx_Data1[uLength1]='G';
                  	 	        				       uLength1++;uRx_Data2[h]='-';
                             	 	        	    	uRx_Data2[h+1]='-';
                             	 	        	    	uRx_Data2[h+2]='.';
                             	 	        	    	uRx_Data2[h+3]='/';
                                	 	        	    	//k=k+4;
                                	 	        	        uLength2+=4;
                  	 	        				   }
                  	 	        				 else if (uRx_Data[k+2]=='-') {
                  	 	        				       uRx_Data1[uLength1]='O';
                  	 	        				       uLength1++; uRx_Data2[h]='-';
                              	 	        	    	uRx_Data2[h+1]='-';
                              	 	        	    	uRx_Data2[h+2]='-';
                              	 	        	    	uRx_Data2[h+3]='/';
                                	 	        	    	//k=k+4;
                                	 	        	        uLength2+=4;
                  	 	        				   }

                	 	        				  }

                	 	        			}


                    	 	        		  }else if (i-k==4){

                    	 	        		if (uRx_Data[k]=='.') {
                	 	        				  if (uRx_Data[k+1]=='.') {
                	 	        					  if (uRx_Data[k+2]=='.') {
                	 	        						  if (uRx_Data[k+3]=='.') {
                      	 	        				       uRx_Data1[uLength1]='H';
                      	 	        				       uLength1++;uRx_Data2[h]='.';
                                 	 	        	    	uRx_Data2[h+1]='.';
                                 	 	        	    	uRx_Data2[h+2]='.';
                                 	 	        	    	uRx_Data2[h+3]='.';
                                 	 	        	    	uRx_Data2[h+4]='/';
                                    	 	        	    	//k=k+5;
                                    	 	        	        uLength2+=5;
                      	 	        				   }
                      	 	        				 else if (uRx_Data[k+3]=='-') {
                      	 	        				       uRx_Data1[uLength1]='V';
                      	 	        				       uLength1++;uRx_Data2[h]='.';
                                  	 	        	    	uRx_Data2[h+1]='.';
                                  	 	        	    	uRx_Data2[h+2]='.';
                                  	 	        	    	uRx_Data2[h+3]='-';
                                  	 	        	    	uRx_Data2[h+4]='/';
                                    	 	        	    	//k=k+5;
                                    	 	        	        uLength2+=5;
                      	 	        				   }

               	 	        				   }
               	 	        				 else if (uRx_Data[k+2]=='-') {
               	 	        					 if (uRx_Data[k+3]=='.') {
            	 	        				       uRx_Data1[uLength1]='F';
            	 	        				       uLength1++;uRx_Data2[h]='.';
                         	 	        	    	uRx_Data2[h+1]='.';
                         	 	        	    	uRx_Data2[h+2]='-';
                         	 	        	    	uRx_Data2[h+3]='.';
                         	 	        	    	uRx_Data2[h+4]='/';
                            	 	        	    	//k=k+5;
                            	 	        	        uLength2+=5;
            	 	        				   }
            	 	        				 else if (uRx_Data[k+3]=='-') {

            	 	        				   }
               	 	        				   }

                	 	        				   }
                	 	        				 else if (uRx_Data[k+1]=='-') {
                	 	        					 if (uRx_Data[k+2]=='.') {
                	 	        						 if (uRx_Data[k+3]=='.') {
                    	 	        				       uRx_Data1[uLength1]='L';
                    	 	        				       uLength1++;uRx_Data2[h]='.';
                                 	 	        	    	uRx_Data2[h+1]='-';
                                 	 	        	    	uRx_Data2[h+2]='.';
                                 	 	        	    	uRx_Data2[h+3]='.';
                                 	 	        	    	uRx_Data2[h+4]='/';
                                    	 	        	    	//k=k+5;
                                    	 	        	        uLength2+=5;
                    	 	        				   }
                    	 	        				 else if (uRx_Data[k+3]=='-') {

                    	 	        				   }

              	 	        				   }
              	 	        				 else if (uRx_Data[k+2]=='-') {
              	 	        					 if (uRx_Data[k+3]=='.') {
            	 	        				       uRx_Data1[uLength1]='P';
            	 	        				       uLength1++;uRx_Data2[h]='.';
                          	 	        	    	uRx_Data2[h+1]='-';
                          	 	        	    	uRx_Data2[h+2]='-';
                          	 	        	    	uRx_Data2[h+3]='.';
                          	 	        	    	uRx_Data2[h+4]='/';
                            	 	        	    	//k=k+5;
                            	 	        	        uLength2+=5;
            	 	        				   }
            	 	        				 else if (uRx_Data[k+3]=='-') {
            	 	        				       uRx_Data1[uLength1]='J';
            	 	        				       uLength1++;uRx_Data2[h]='.';
                         	 	        	    	uRx_Data2[h+1]='-';
                         	 	        	    	uRx_Data2[h+2]='-';
                         	 	        	    	uRx_Data2[h+3]='-';
                         	 	        	    	uRx_Data2[h+4]='/';
                            	 	        	    	//k=k+5;
                            	 	        	        uLength2+=5;
            	 	        				   }

              	 	        				   }

                	 	        				   }

                	 	        			  }
                	 	        			 else if (uRx_Data[k]=='-') {
                	 	        				  if (uRx_Data[k+1]=='.') {
                	 	        					  if (uRx_Data[k+2]=='.') {
                	 	        						  if (uRx_Data[k+3]=='.') {
                     	 	        				       uRx_Data1[uLength1]='B';
                     	 	        				       uLength1++;uRx_Data2[h]='-';
                                	 	        	    	uRx_Data2[h+1]='.';
                                	 	        	    	uRx_Data2[h+2]='.';
                                	 	        	    	uRx_Data2[h+3]='.';
                                	 	        	    	uRx_Data2[h+4]='/';
                                	 	        	    	//k=k+5;
                                	 	        	        uLength2+=5;
                     	 	        				   }
                     	 	        				 else if (uRx_Data[k+3]=='-') {
                     	 	        				       uRx_Data1[uLength1]='X';
                     	 	        				       uLength1++;uRx_Data2[h]='-';
                                  	 	        	    	uRx_Data2[h+1]='.';
                                  	 	        	    	uRx_Data2[h+2]='.';
                                  	 	        	    	uRx_Data2[h+3]='-';
                                  	 	        	    	uRx_Data2[h+4]='/';
                                    	 	        	    	//k=k+5;
                                    	 	        	        uLength2+=5;
                     	 	        				   }

                  	 	        				   }
                  	 	        				 else if (uRx_Data[k+2]=='-') {
                  	 	        					 if (uRx_Data[k+3]=='.') {
                	 	        				       uRx_Data1[uLength1]='C';
                	 	        				       uLength1++; uRx_Data2[h]='-';
                        	 	        	    	     uRx_Data2[h+1]='.';
                        	 	        	    	     uRx_Data2[h+2]='-';
                        	 	        	    	     uRx_Data2[h+3]='.';
                        	 	        	    	     uRx_Data2[h+4]='/';
                           	 	        	    	//k=k+5;
                           	 	        	        uLength2+=5;
                	 	        				   }
                	 	        				 else if (uRx_Data[k+3]=='-') {
                	 	        				       uRx_Data1[uLength1]='Y';
                	 	        				       uLength1++; uRx_Data2[h]='-';
                              	 	        	    	uRx_Data2[h+1]='.';
                              	 	        	    	uRx_Data2[h+2]='-';
                              	 	        	    	uRx_Data2[h+3]='-';
                              	 	        	    	uRx_Data2[h+4]='/';
                                	 	        	    	//k=k+5;
                                	 	        	        uLength2+=5;
                	 	        				   }

                  	 	        				   }

                	 	        				  }
                	 	        				  else if (uRx_Data[k+1]=='-') {
                	 	        					  if (uRx_Data[k+2]=='.') {
                	 	        						  if (uRx_Data[k+3]=='.') {
                     	 	        				       uRx_Data1[uLength1]='Z';
                     	 	        				       uLength1++; uRx_Data2[h]='-';
                                  	 	        	    	uRx_Data2[h+1]='-';
                                  	 	        	    	uRx_Data2[h+2]='.';
                                  	 	        	    	uRx_Data2[h+3]='.';
                                  	 	        	    	uRx_Data2[h+4]='/';
                                    	 	        	    	//k=k+5;
                                    	 	        	        uLength2+=5;
                     	 	        				   }
                     	 	        				 else if (uRx_Data[k+3]=='-') {
                     	 	        				       uRx_Data1[uLength1]='Q';
                     	 	        				       uLength1++; uRx_Data2[h]='-';
                                  	 	        	    	uRx_Data2[h+1]='-';
                                  	 	        	    	uRx_Data2[h+2]='.';
                                  	 	        	    	uRx_Data2[h+3]='-';
                                  	 	        	    	uRx_Data2[h+4]='/';
                                    	 	        	    	//k=k+5;
                                    	 	        	        uLength2+=5;
                     	 	        				   }

                  	 	        				   }
                  	 	        				 else if (uRx_Data[k+2]=='-') {
                  	 	        					 if (uRx_Data[k+3]=='.') {

                	 	        				   }
                	 	        				 else if (uRx_Data[k+3]=='-') {

                	 	        				   }

                  	 	        				   }

                	 	        				  }

                	 	        			}



                    	 	        		  }

                                               k=i+1;
                    	 	        	   }

                    	 	         }
                                   //HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,GPIO_PIN_SET);
                                                           	 	        	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2,GPIO_PIN_SET);
                                                           	 	        	 for (int j=h;j<=uLength2-1;j++){
                                                           	 	        		 if (uRx_Data2[j]=='.'){
                                                                	 	            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
                                                                	 	            HAL_Delay(500);
                                                                	 	            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
                                                                	 	            HAL_Delay(500);
                                                                	 	          }
                                                                	 	         else  if (uRx_Data2[j]=='-'){
                                                                	 	            HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
                                                                	 	            HAL_Delay(500);
                                                                	 	            HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
                                                                	 	            HAL_Delay(500);

                                                                	 	       }
                                                                	 	         else if (uRx_Data2[j]=='/'){
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
                                                                	 	         else if (uRx_Data2[j]=='d'){
                                                                	 	        	 //j=uLength2;
                                                                	 	        	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
                                                                	 	        	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
                                                               	 	        	  HAL_Delay(166);
                                                               	 	        	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
                                                               	 	        	  HAL_Delay(167);
                                                               	 	        	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
                                                               	 	        	  HAL_Delay(166);
                                                               	 	        	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
                                                               	 	        	  HAL_Delay(167);
                                                               	 	        	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
                                                               	 	        	  HAL_Delay(166);
                                                               	 	        	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
                                                               	 	        	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
                                                               	 	        	  HAL_Delay(168);
                                                                	 	         }
                                                           	 	        	 }
                                                           	 	        	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,GPIO_PIN_SET);
                                                           	 	        	//HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2,GPIO_PIN_SET);
                                                           	 	        	 h=uLength2;
                                   }



                        	   }


                                   }
                                   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,GPIO_PIN_SET);
                                   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2,GPIO_PIN_SET);
                                   HAL_UART_Transmit(&huart1, uRx_Data1, uLength1, 0xffff);
                                   uLength = 0;
                                   uLength1 = 0;
                                   uLength2 = 0;

                       }else {
                    	   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,GPIO_PIN_SET);
                    	   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2,GPIO_PIN_SET);
                    	   if (uRx_Data0[0]==1){
                    		uLength3=0;
                    	    uRx_Data3[uLength3]='E';
  	 	        	    	uRx_Data3[uLength3+1]='n';
  	 	        	    	uRx_Data3[uLength3+2]='c';
  	 	        	    	uRx_Data3[uLength3+3]='o';
  	 	        	    	uRx_Data3[uLength3+4]='d';
  	 	        	    	uRx_Data3[uLength3+5]='e';
  	 	        	    	uRx_Data3[uLength3+6]=' ';
  	 	        	    	uRx_Data3[uLength3+7]='E';
  	 	        	    	uRx_Data3[uLength3+8]='r';
  	 	        	    	uRx_Data3[uLength3+9]='r';
  	 	        	    	uRx_Data3[uLength3+10]='o';
  	 	        	    	uRx_Data3[uLength3+11]='r';
  	 	        	    	uRx_Data3[uLength3+12]=':';
  	 	        	    	uRx_Data3[uLength3+13]=' ';
  	 	        	    	for (int i=0;i<=uLength-1;i++){
  	 	        	    		uRx_Data3[uLength3+i+14]=uRx_Data[i];
  	 	        	    	}
  	 	        	    	uLength1=uLength-1+uLength3+14+1;
  	 	        	    	for (int i=0;i<=uLength1-1;i++){
  	 	        	    		uRx_Data1[i]=uRx_Data3[i];
  	 	        	    	}
  	 	        	      HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
      	 	        	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
      	 	        	  HAL_Delay(166);
      	 	        	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
      	 	        	  HAL_Delay(167);
      	 	        	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
      	 	        	  HAL_Delay(166);
      	 	        	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
      	 	        	  HAL_Delay(167);
      	 	        	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
      	 	        	  HAL_Delay(166);
      	 	        	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
      	 	        	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
      	 	        	  HAL_Delay(168);
      	 	        	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,GPIO_PIN_SET);
                          HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2,GPIO_PIN_SET);
                          HAL_UART_Transmit(&huart1, uRx_Data1, uLength1, 0xffff);
                          uLength = 0;
                          uLength1 = 0;
                          uLength2 = 0;

                    	   }

                    	   else{

                    	   h=0;
                    	   for (int j=h;j<=uLength2-1;j++){
     	 	        		 if (uRx_Data2[j]=='.'){
          	 	            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
          	 	            HAL_Delay(500);
          	 	            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
          	 	            HAL_Delay(500);
          	 	          }
          	 	         else  if (uRx_Data2[j]=='-'){
          	 	            HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
          	 	            HAL_Delay(500);
          	 	            HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
          	 	            HAL_Delay(500);

          	 	       }
          	 	         else if (uRx_Data2[j]=='/'){
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
          	 	         else if (uRx_Data2[j]=='d'){
          	 	        	 //j=uLength2;
          	 	        	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
          	 	        	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
         	 	        	  HAL_Delay(166);
         	 	        	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
         	 	        	  HAL_Delay(167);
         	 	        	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
         	 	        	  HAL_Delay(166);
         	 	        	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
         	 	        	  HAL_Delay(167);
         	 	        	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
         	 	        	  HAL_Delay(166);
         	 	        	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_2);
         	 	        	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
         	 	        	  HAL_Delay(168);
          	 	         }
     	 	        	 }

                       HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,GPIO_PIN_SET);
                       HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2,GPIO_PIN_SET);
                       HAL_UART_Transmit(&huart1, uRx_Data1, uLength1, 0xffff);
                       uLength = 0;
                       uLength1 = 0;
                       uLength2 = 0;
                       }
                       }



            }else{
                                   uRx_Data[uLength] = rxBuffer[0];
                                   uLength++;

                       }
            }
}
/* USER CODE END 1 */
