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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "sys.h"
#include "delay.h"
//#include "usart.h"
#include "led.h"
#include "key.h"
#include "lcd.h"
//#include "usmart.h"
#include "touch.h"
#include "24cxx.h"
#include "24l01.h" //通信驱动 基于spi进行通信
#include "pkm_character.h"
//#include "remote.h" 红外遥控驱动
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
//#define true 0
//#define false 1
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
u8 DATA_TO_SEND[800];
/* For example
 * character selection:	send a num to the other
 * battle: 	"fth, state"*/
extern UART_HandleTypeDef huart1;
extern uint8_t rxBuffer[64];
extern TIM_HandleTypeDef htim2;
UART_HandleTypeDef huart1;
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
void send(const char* msg){
	NRF24L01_TX_Mode();
	sprintf(DATA_TO_SEND,msg);
	while(1)
	{
		if(NRF24L01_TxPacket(DATA_TO_SEND)==TX_OK)
		{
			break;
		}
		delay_ms(100);
	}
	NRF24L01_RX_Mode();
}

////////////////////////////////////////////////////////////////////////////////
void singleplayer_mode(void)
{

	    u8 key;
		u8 i=0;
		int battle=0;
		int x1=0;
		int y1=0;


		 //进入选角界面
		int finalchoose1=0;
		int finalchoose2=0;
		struct character character1;
		struct character character2;
		u8 dele2choose1[10];


	// take out from this if statement
      if (1){
    	 LCD_Clear(WHITE);
    	 // judge whether it is remote battle, if yes, disable the upper half of the screen
    	 // if(...){
    	 //		continue;
    	 //}

			struct character a1 = initialize_character(0);
			struct character a2 = initialize_character(1);
			struct character a3 = initialize_character(2);
//    	 			struct character b1 = initialize_character(0);
//    	 			struct character b2 = initialize_character(1);
//    	 			struct character b3 = initialize_character(2);

			int a1_HP=get_total_HP(&a1);
			int a1_ATK=get_ATK(&a1);
			int a1_DEF=get_DEF(&a1);

			int a2_HP=get_total_HP(&a2);
			int a2_ATK=get_ATK(&a2);
			int a2_DEF=get_DEF(&a2);

			int a3_HP=get_total_HP(&a3);
			int a3_ATK=get_ATK(&a3);
			int a3_DEF=get_DEF(&a3);

			LCD_ShowNum(0,27+67+1,a1_HP,12,12);
			LCD_ShowNum(80,27+67+1,a2_HP,12,12);
			LCD_ShowNum(160,27+67+1,a3_HP,12,12);
			LCD_ShowNum(0,187+67+1,a1_HP,12,12);
			LCD_ShowNum(80,187+67+1,a2_HP,12,12);
			LCD_ShowNum(160,187+67+1,a3_HP,12,12);
			LCD_ShowString(6,27+67+1,33,12,12, "HP: ");
			LCD_ShowString(86,27+67+1,33,12,12, "HP: ");
			LCD_ShowString(166,27+67+1,33,12,12, "HP: ");
			LCD_ShowString(6,187+67+1,33,12,12, "HP: ");
			LCD_ShowString(86,187+67+1,33,12,12, "HP: ");
			LCD_ShowString(166,187+67+1,33,12,12, "HP: ");

			LCD_ShowNum(0,27+67+1+24,a1_ATK,12,12);
			LCD_ShowNum(80,27+67+1+24,a2_ATK,12,12);
			LCD_ShowNum(160,27+67+1+24,a3_ATK,12,12);
			LCD_ShowNum(0,187+67+1+24,a1_ATK,12,12);
			LCD_ShowNum(80,187+67+1+24,a2_ATK,12,12);
			LCD_ShowNum(160,187+67+1+24,a3_ATK,12,12);
            LCD_ShowString(6,27+67+1+24,33,12,12, "ATK: ");
			LCD_ShowString(86,27+67+1+24,33,12,12, "ATK: ");
			LCD_ShowString(166,27+67+1+24,33,12,12, "ATK: ");
			LCD_ShowString(6,187+67+1+24,33,12,12, "ATK: ");
			LCD_ShowString(86,187+67+1+24,33,12,12, "ATK: ");
			LCD_ShowString(166,187+67+1+24,33,12,12, "ATK: ");

			LCD_ShowNum(0,27+67+1+48,a1_DEF,12,12);
			LCD_ShowNum(80,27+67+1+48,a2_DEF,12,12);
			LCD_ShowNum(160,27+67+1+48,a3_DEF,12,12);
			LCD_ShowNum(0,187+67+1+48,a1_DEF,12,12);
			LCD_ShowNum(80,187+67+1+48,a2_DEF,12,12);
			LCD_ShowNum(160,187+67+1+48,a3_DEF,12,12);
			LCD_ShowString(6,27+67+1+48,33,12,12, "DEF: ");
			LCD_ShowString(86,27+67+1+48,33,12,12, "DEF: ");
			LCD_ShowString(166,27+67+1+48,33,12,12, "DEF: ");
			LCD_ShowString(6,187+67+1+48,33,12,12, "DEF: ");
			LCD_ShowString(86,187+67+1+48,33,12,12, "DEF: ");
			LCD_ShowString(166,187+67+1+48,33,12,12, "DEF: ");


    	 int choose1=0;
    	 int choose2=0;
    	 int choose_to_battle=0;
    	 int checkchoose1=0;
    	 int checkchoose2=0;

    	 choose1=rand()%3+1;

    	 while(1)
    	 		{
    	 		 	key=KEY_Scan(0);
    	 			tp_dev.scan(0);

    	 				LCD_ShowString(0,1,240,12,12, "machine player select your character");
    	 			    LCD_ShowString(0,161,240,12,12, "real player select your character");


    	 			LCD_ShowImage1_1(6,27,1);

    	 			LCD_ShowImage1_2(86,27,1);

    	 			LCD_ShowImage1_3(166,27,1);

    	 			LCD_ShowImage1_1(6,187,1);

    	 			LCD_ShowImage1_2(86,187,1);

    	 			LCD_ShowImage1_3(166,187,1);


    	 			//LCD_ShowNumTest(6+33,27+67+1,a1_HP,12,12);

    	 			 for (x1=0;x1<240;x1++){
    	 				LCD_Fast_DrawPoint(x1, 160, BLUE);
    	 		     	}

    	 			delay_ms(200);
					if (choose1!=1) LCD_ShowImage0(6,27);
					if (choose1!=2) LCD_ShowImage0(86,27);
					if (choose1!=3) LCD_ShowImage0(166,27);
					if (choose2!=1) LCD_ShowImage0(6,187);
					if (choose2!=2) LCD_ShowImage0(86,187);
					if (choose2!=3) LCD_ShowImage0(166,187);
                     delay_ms(50);

                     if (choose1!=0&&choose2!=0){
                    	 if ( choose_to_battle==0){
                    		checkchoose1=choose1;
                    		checkchoose2=choose2;
                    		 choose_to_battle++;
                    	 }
                    	 else{
                    		 if (checkchoose1!=choose1||checkchoose2!=choose2){
                    			 choose_to_battle=0;
                    		 }else{
                    			  choose_to_battle++;
                    		 }

                    	 }

                    	 if (choose_to_battle==6){
                    		 //可以�?终确定玩家�?�择�?么角�?
                    		 finalchoose1=choose1;
                    		 finalchoose2=choose2;
                    		if (finalchoose1==1){
                    			character1=a1;
                    		}else if(finalchoose1==2){
                    			character1=a2;
                    		}else if(finalchoose1==3){
                    			character1=a3;
                    		}

                    		if (finalchoose2==1){
                    			character2=a1;
                    		}else if(finalchoose2==2){
                    			character2=a2;
                    		}else if(finalchoose2==3){
                    			character2=a3;
                    		}
                                    break;
                    	 }
                         	 			}



    	 			if(tp_dev.sta&TP_PRES_DOWN)			//触摸屏被按下
    	 			{

    	 				if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)
    	 				{
    	 					if(tp_dev.x[0]>6&&tp_dev.y[0]>187&&tp_dev.x[0]<6+67&&tp_dev.y[0]<187+67){
    	 						choose2=1;
    	 						//battle=1;
    	 						//break;
    	 					}else if(tp_dev.x[0]>86&&tp_dev.y[0]>187&&tp_dev.x[0]<86+67&&tp_dev.y[0]<187+67){
    	 						choose2=2;
    	 						//battle=1;
    	 						//break;
    	 					}else if(tp_dev.x[0]>166&&tp_dev.y[0]>187&&tp_dev.x[0]<166+67&&tp_dev.y[0]<187+67){
    	 						choose2=3;
    	 						//battle=1;
    	 						//break;
    	 					}


    	 				}
    	 			}else delay_ms(10);	//没有按键按下的时�??
    	 			i++;
    	 			if(i%20==0)LED0=!LED0;

    	 		}
     }
     else if (battle==1){
       //留给单机对战

     }

     //进入战斗界面
     remote_tatakai_PvE(finalchoose1,finalchoose2,&character1,&character2);
     LCD_ShowString(100,160-8,60,16,16, "BACK");
     	while (1) {
     		tp_dev.scan(0);

     		if(tp_dev.sta&TP_PRES_DOWN)			//触摸屏被按下
     		{
     			int x = tp_dev.x[0];
     			int y = tp_dev.y[0];
     			if(x<lcddev.width&&y<lcddev.height)
     			{
     				if (x>100&&x<160&&y>160-8&&y<160+8) {
     					   back_to_Menu();
     				}
     			}
     		}else delay_ms(10);	//没有按键按下的时�??
     	}

     //LCD_Clear(WHITE);

     // tatakai(finalchoose1,finalchoose2,&character1,&character2);

//	//LCD_ShowImage1(6,27);
//	LCD_ShowImage1(86,27);
//	LCD_ShowImage1(166,27);
//	LCD_ShowImage1(6,187);
//	LCD_ShowImage1(86,187);
//	LCD_ShowImage1(166,187);

}

void multi_c_p_mode(void){
	//LCD_ShowImage1(40,80);
	POINT_COLOR=BLUE;//设置字体为蓝�?

	int player_no = choose_player();
	    u8 key;
		u8 i=0;
		int battle=0;
		int x1=0;
		int y1=0;


		 //进入选角界面
		int finalchoose1=0;
		int finalchoose2=0;
		struct character character1;
		struct character character2;
		u8 dele2choose1[10];
		int order1=0;
		int order2=0;
		 int choose1[4];
		  int choose2[4];

	// take out from this if statement
      if (1){
    	 LCD_Clear(WHITE);
    	 // judge whether it is remote battle, if yes, disable the upper half of the screen
    	 // if(...){
    	 //		continue;
    	 //}

			struct character a1 = initialize_character(0);
			struct character a2 = initialize_character(1);
			struct character a3 = initialize_character(2);
//    	 			struct character b1 = initialize_character(0);
//    	 			struct character b2 = initialize_character(1);
//    	 			struct character b3 = initialize_character(2);

			int a1_HP=get_total_HP(&a1);
			int a1_ATK=get_ATK(&a1);
			int a1_DEF=get_DEF(&a1);

			int a2_HP=get_total_HP(&a2);
			int a2_ATK=get_ATK(&a2);
			int a2_DEF=get_DEF(&a2);

			int a3_HP=get_total_HP(&a3);
			int a3_ATK=get_ATK(&a3);
			int a3_DEF=get_DEF(&a3);

			LCD_ShowNum(0,27+67+1,a1_HP,12,12);
			LCD_ShowNum(80,27+67+1,a2_HP,12,12);
			LCD_ShowNum(160,27+67+1,a3_HP,12,12);
			LCD_ShowNum(0,187+67+1,a1_HP,12,12);
			LCD_ShowNum(80,187+67+1,a2_HP,12,12);
			LCD_ShowNum(160,187+67+1,a3_HP,12,12);
			LCD_ShowString(6,27+67+1,33,12,12, "HP: ");
			LCD_ShowString(86,27+67+1,33,12,12, "HP: ");
			LCD_ShowString(166,27+67+1,33,12,12, "HP: ");
			LCD_ShowString(6,187+67+1,33,12,12, "HP: ");
			LCD_ShowString(86,187+67+1,33,12,12, "HP: ");
			LCD_ShowString(166,187+67+1,33,12,12, "HP: ");

			LCD_ShowNum(0,27+67+1+24,a1_ATK,12,12);
			LCD_ShowNum(80,27+67+1+24,a2_ATK,12,12);
			LCD_ShowNum(160,27+67+1+24,a3_ATK,12,12);
			LCD_ShowNum(0,187+67+1+24,a1_ATK,12,12);
			LCD_ShowNum(80,187+67+1+24,a2_ATK,12,12);
			LCD_ShowNum(160,187+67+1+24,a3_ATK,12,12);
            LCD_ShowString(6,27+67+1+24,33,12,12, "ATK: ");
			LCD_ShowString(86,27+67+1+24,33,12,12, "ATK: ");
			LCD_ShowString(166,27+67+1+24,33,12,12, "ATK: ");
			LCD_ShowString(6,187+67+1+24,33,12,12, "ATK: ");
			LCD_ShowString(86,187+67+1+24,33,12,12, "ATK: ");
			LCD_ShowString(166,187+67+1+24,33,12,12, "ATK: ");

			LCD_ShowNum(0,27+67+1+48,a1_DEF,12,12);
			LCD_ShowNum(80,27+67+1+48,a2_DEF,12,12);
			LCD_ShowNum(160,27+67+1+48,a3_DEF,12,12);
			LCD_ShowNum(0,187+67+1+48,a1_DEF,12,12);
			LCD_ShowNum(80,187+67+1+48,a2_DEF,12,12);
			LCD_ShowNum(160,187+67+1+48,a3_DEF,12,12);
			LCD_ShowString(6,27+67+1+48,33,12,12, "DEF: ");
			LCD_ShowString(86,27+67+1+48,33,12,12, "DEF: ");
			LCD_ShowString(166,27+67+1+48,33,12,12, "DEF: ");
			LCD_ShowString(6,187+67+1+48,33,12,12, "DEF: ");
			LCD_ShowString(86,187+67+1+48,33,12,12, "DEF: ");
			LCD_ShowString(166,187+67+1+48,33,12,12, "DEF: ");



    	 int f1[4];
    	 int f2[4];
    	 for (i=1;i<=3;i++){
    		 choose1[i]=0;
    		 choose2[i]=0;
    		 f1[i]=0;
    		 f2[i]=0;
    	 }
    	 int choose_to_battle=0;
    	 int checkchoose1=0;
    	 int checkchoose2=0;


    	 while(1)
    	 		{
    	 		 	key=KEY_Scan(0);
    	 			tp_dev.scan(0);
    	 			if (player_no==1){
    	 				LCD_ShowString(0,1,240,12,12, "player2 reorder your character");
    	 			    LCD_ShowString(0,161,240,12,12, "player1 reorder your character");
    	 			}else{
    	 				LCD_ShowString(0,1,240,12,12, "player1 reorder your character");
    	 			    LCD_ShowString(0,161,240,12,12, "player2 reorder your character");
    	 			}

    	 			LCD_ShowImage1_1(6,27,1);

    	 			LCD_ShowImage1_2(86,27,1);

    	 			LCD_ShowImage1_3(166,27,1);

    	 			LCD_ShowImage1_1(6,187,1);

    	 			LCD_ShowImage1_2(86,187,1);

    	 			LCD_ShowImage1_3(166,187,1);


    	 			//LCD_ShowNumTest(6+33,27+67+1,a1_HP,12,12);

    	 			 for (x1=0;x1<240;x1++){
    	 				LCD_Fast_DrawPoint(x1, 160, BLUE);
    	 		     	}

    	 			delay_ms(200);

					if (f1[1]==0) LCD_ShowImage0(6,27);
					if (f1[2]==0) LCD_ShowImage0(86,27);
					if (f1[3]==0) LCD_ShowImage0(166,27);
					if (f2[1]==0) LCD_ShowImage0(6,187);
					if (f2[2]==0) LCD_ShowImage0(86,187);
					if (f2[3]==0) LCD_ShowImage0(166,187);
                     delay_ms(50);

                     if (f1[1]==1&&f1[2]==1&&f1[3]==1&&f2[1]==1&&f2[2]==1&&f2[3]==1){
                    	 delay_ms(1000);

                    	 if (1){
                    		 //可以�?终确定玩家�?�择�?么角�?
                    		 finalchoose1=choose1[1];
                    		 finalchoose2=choose2[1];
                    		if (finalchoose1==1){
                    			character1=a1;
                    		}else if(finalchoose1==2){
                    			character1=a2;
                    		}else if(finalchoose1==3){
                    			character1=a3;
                    		}

                    		if (finalchoose2==1){
                    			character2=a1;
                    		}else if(finalchoose2==2){
                    			character2=a2;
                    		}else if(finalchoose2==3){
                    			character2=a3;
                    		}
                                    break;
                    	 }
                         	 			}

                    NRF24L01_RX_Mode();
                    if(NRF24L01_RxPacket(dele2choose1)==0)
					{
                    	order1++;
                       if (order1<=3){
                    	choose1[order1] = dele2choose1[0] - '0';
						f1[choose1[order1]]=1;
                       }

					}

    	 			if(tp_dev.sta&TP_PRES_DOWN)			//触摸屏被按下
    	 			{

    	 				if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)
    	 				{
    	 					if(tp_dev.x[0]>6&&tp_dev.y[0]>187&&tp_dev.x[0]<6+67&&tp_dev.y[0]<187+67){
    	 						order2++;
    	 			            if (order2<=3){
    	 			            choose2[order2]=1;
    	 						send("1");
    	 						f2[choose2[order2]]=1;
    	 			            }

    	 						//battle=1;
    	 						//break;
    	 					}else if(tp_dev.x[0]>86&&tp_dev.y[0]>187&&tp_dev.x[0]<86+67&&tp_dev.y[0]<187+67){
    	 						order2++;
    	 						    	 			            if (order2<=3){
    	 						    	 			            choose2[order2]=2;
    	 						    	 						send("2");
    	 						    	 						f2[choose2[order2]]=1;
    	 						    	 			            }
    	 						//battle=1;
    	 						//break;
    	 					}else if(tp_dev.x[0]>166&&tp_dev.y[0]>187&&tp_dev.x[0]<166+67&&tp_dev.y[0]<187+67){
    	 						order2++;
																					   if (order2<=3){
																					choose2[order2]=3;
																						send("3");
																						f2[choose2[order2]]=1;
																						}
    	 						//battle=1;
    	 						//break;
    	 					}


    	 				}
    	 			}else delay_ms(10);	//没有按键按下的时�??
    	 			i++;
    	 			if(i%20==0)LED0=!LED0;

    	 		}
     }
     else if (battle==1){
       //留给单机对战

     }

     //进入战斗界面
     remote_tatakai_MULTI(finalchoose1,finalchoose2,&character1,&character2, player_no,choose1,choose2);
     LCD_ShowString(100,160-8,60,16,16, "BACK");
         	while (1) {
         		tp_dev.scan(0);

         		if(tp_dev.sta&TP_PRES_DOWN)			//触摸屏被按下
         		{
         			int x = tp_dev.x[0];
         			int y = tp_dev.y[0];
         			if(x<lcddev.width&&y<lcddev.height)
         			{
         				if (x>100&&x<160&&y>160-8&&y<160+8) {
         					   back_to_Menu();
         				}
         			}
         		}else delay_ms(10);	//没有按键按下的时�??
         	}
     //LCD_Clear(WHITE);

     // tatakai(finalchoose1,finalchoose2,&character1,&character2);

//	//LCD_ShowImage1(6,27);
//	LCD_ShowImage1(86,27);
//	LCD_ShowImage1(166,27);
//	LCD_ShowImage1(6,187);
//	LCD_ShowImage1(86,187);
//	LCD_ShowImage1(166,187

}
void multiplayer_mode(void)
{
	//LCD_ShowImage1(40,80);
	POINT_COLOR=BLUE;//设置字体为蓝�?

	int player_no = choose_player();



	    u8 key;
		u8 i=0;
		int battle=0;
		int x1=0;
		int y1=0;


		 //进入选角界面
		int finalchoose1=0;
		int finalchoose2=0;
		struct character character1;
		struct character character2;
		u8 dele2choose1[10];


	// take out from this if statement
      if (1){
    	 LCD_Clear(WHITE);
    	 // judge whether it is remote battle, if yes, disable the upper half of the screen
    	 // if(...){
    	 //		continue;
    	 //}

			struct character a1 = initialize_character(0);
			struct character a2 = initialize_character(1);
			struct character a3 = initialize_character(2);
//    	 			struct character b1 = initialize_character(0);
//    	 			struct character b2 = initialize_character(1);
//    	 			struct character b3 = initialize_character(2);

			int a1_HP=get_total_HP(&a1);
			int a1_ATK=get_ATK(&a1);
			int a1_DEF=get_DEF(&a1);

			int a2_HP=get_total_HP(&a2);
			int a2_ATK=get_ATK(&a2);
			int a2_DEF=get_DEF(&a2);

			int a3_HP=get_total_HP(&a3);
			int a3_ATK=get_ATK(&a3);
			int a3_DEF=get_DEF(&a3);

			LCD_ShowNum(0,27+67+1,a1_HP,12,12);
			LCD_ShowNum(80,27+67+1,a2_HP,12,12);
			LCD_ShowNum(160,27+67+1,a3_HP,12,12);
			LCD_ShowNum(0,187+67+1,a1_HP,12,12);
			LCD_ShowNum(80,187+67+1,a2_HP,12,12);
			LCD_ShowNum(160,187+67+1,a3_HP,12,12);
			LCD_ShowString(6,27+67+1,33,12,12, "HP: ");
			LCD_ShowString(86,27+67+1,33,12,12, "HP: ");
			LCD_ShowString(166,27+67+1,33,12,12, "HP: ");
			LCD_ShowString(6,187+67+1,33,12,12, "HP: ");
			LCD_ShowString(86,187+67+1,33,12,12, "HP: ");
			LCD_ShowString(166,187+67+1,33,12,12, "HP: ");

			LCD_ShowNum(0,27+67+1+24,a1_ATK,12,12);
			LCD_ShowNum(80,27+67+1+24,a2_ATK,12,12);
			LCD_ShowNum(160,27+67+1+24,a3_ATK,12,12);
			LCD_ShowNum(0,187+67+1+24,a1_ATK,12,12);
			LCD_ShowNum(80,187+67+1+24,a2_ATK,12,12);
			LCD_ShowNum(160,187+67+1+24,a3_ATK,12,12);
            LCD_ShowString(6,27+67+1+24,33,12,12, "ATK: ");
			LCD_ShowString(86,27+67+1+24,33,12,12, "ATK: ");
			LCD_ShowString(166,27+67+1+24,33,12,12, "ATK: ");
			LCD_ShowString(6,187+67+1+24,33,12,12, "ATK: ");
			LCD_ShowString(86,187+67+1+24,33,12,12, "ATK: ");
			LCD_ShowString(166,187+67+1+24,33,12,12, "ATK: ");

			LCD_ShowNum(0,27+67+1+48,a1_DEF,12,12);
			LCD_ShowNum(80,27+67+1+48,a2_DEF,12,12);
			LCD_ShowNum(160,27+67+1+48,a3_DEF,12,12);
			LCD_ShowNum(0,187+67+1+48,a1_DEF,12,12);
			LCD_ShowNum(80,187+67+1+48,a2_DEF,12,12);
			LCD_ShowNum(160,187+67+1+48,a3_DEF,12,12);
			LCD_ShowString(6,27+67+1+48,33,12,12, "DEF: ");
			LCD_ShowString(86,27+67+1+48,33,12,12, "DEF: ");
			LCD_ShowString(166,27+67+1+48,33,12,12, "DEF: ");
			LCD_ShowString(6,187+67+1+48,33,12,12, "DEF: ");
			LCD_ShowString(86,187+67+1+48,33,12,12, "DEF: ");
			LCD_ShowString(166,187+67+1+48,33,12,12, "DEF: ");


    	 int choose1=0;
    	 int choose2=0;
    	 int choose_to_battle=0;
    	 int checkchoose1=0;
    	 int checkchoose2=0;


    	 while(1)
    	 		{
    	 		 	key=KEY_Scan(0);
    	 			tp_dev.scan(0);
    	 			if (player_no==1){
    	 				LCD_ShowString(0,1,240,12,12, "player2 select your character");
    	 			    LCD_ShowString(0,161,240,12,12, "player1 select your character");
    	 			}else{
    	 				LCD_ShowString(0,1,240,12,12, "player1 select your character");
    	 			    LCD_ShowString(0,161,240,12,12, "player2 select your character");
    	 			}

    	 			LCD_ShowImage1_1(6,27,1);

    	 			LCD_ShowImage1_2(86,27,1);

    	 			LCD_ShowImage1_3(166,27,1);

    	 			LCD_ShowImage1_1(6,187,1);

    	 			LCD_ShowImage1_2(86,187,1);

    	 			LCD_ShowImage1_3(166,187,1);


    	 			//LCD_ShowNumTest(6+33,27+67+1,a1_HP,12,12);

    	 			 for (x1=0;x1<240;x1++){
    	 				LCD_Fast_DrawPoint(x1, 160, BLUE);
    	 		     	}

    	 			delay_ms(200);
					if (choose1!=1) LCD_ShowImage0(6,27);
					if (choose1!=2) LCD_ShowImage0(86,27);
					if (choose1!=3) LCD_ShowImage0(166,27);
					if (choose2!=1) LCD_ShowImage0(6,187);
					if (choose2!=2) LCD_ShowImage0(86,187);
					if (choose2!=3) LCD_ShowImage0(166,187);
                     delay_ms(50);

                     if (choose1!=0&&choose2!=0){
                    	 if ( choose_to_battle==0){
                    		checkchoose1=choose1;
                    		checkchoose2=choose2;
                    		 choose_to_battle++;
                    	 }
                    	 else{
                    		 if (checkchoose1!=choose1||checkchoose2!=choose2){
                    			 choose_to_battle=0;
                    		 }else{
                    			  choose_to_battle++;
                    		 }

                    	 }

                    	 if (choose_to_battle==6){
                    		 //可以�?终确定玩家�?�择�?么角�?
                    		 finalchoose1=choose1;
                    		 finalchoose2=choose2;
                    		if (finalchoose1==1){
                    			character1=a1;
                    		}else if(finalchoose1==2){
                    			character1=a2;
                    		}else if(finalchoose1==3){
                    			character1=a3;
                    		}

                    		if (finalchoose2==1){
                    			character2=a1;
                    		}else if(finalchoose2==2){
                    			character2=a2;
                    		}else if(finalchoose2==3){
                    			character2=a3;
                    		}
                                    break;
                    	 }
                         	 			}

                    NRF24L01_RX_Mode();
                    if(NRF24L01_RxPacket(dele2choose1)==0)
					{
						choose1 = dele2choose1[0] - '0';
					}

    	 			if(tp_dev.sta&TP_PRES_DOWN)			//触摸屏被按下
    	 			{

    	 				if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)
    	 				{
    	 					if(tp_dev.x[0]>6&&tp_dev.y[0]>187&&tp_dev.x[0]<6+67&&tp_dev.y[0]<187+67){
    	 						choose2=1;
    	 						send("1");
    	 						//battle=1;
    	 						//break;
    	 					}else if(tp_dev.x[0]>86&&tp_dev.y[0]>187&&tp_dev.x[0]<86+67&&tp_dev.y[0]<187+67){
    	 						choose2=2;
    	 						send("2");
    	 						//battle=1;
    	 						//break;
    	 					}else if(tp_dev.x[0]>166&&tp_dev.y[0]>187&&tp_dev.x[0]<166+67&&tp_dev.y[0]<187+67){
    	 						choose2=3;
    	 						send("3");
    	 						//battle=1;
    	 						//break;
    	 					}


    	 				}
    	 			}else delay_ms(10);	//没有按键按下的时�??
    	 			i++;
    	 			if(i%20==0)LED0=!LED0;

    	 		}
     }
     else if (battle==1){
       //留给单机对战

     }

     //进入战斗界面
     remote_tatakai(finalchoose1,finalchoose2,&character1,&character2, player_no);
     LCD_ShowString(100,160-8,60,16,16, "BACK");
         	while (1) {
         		tp_dev.scan(0);

         		if(tp_dev.sta&TP_PRES_DOWN)			//触摸屏被按下
         		{
         			int x = tp_dev.x[0];
         			int y = tp_dev.y[0];
         			if(x<lcddev.width&&y<lcddev.height)
         			{
         				if (x>100&&x<160&&y>160-8&&y<160+8) {
         					   back_to_Menu();
         				}
         			}
         		}else delay_ms(10);	//没有按键按下的时�??
         	}
     //LCD_Clear(WHITE);

     // tatakai(finalchoose1,finalchoose2,&character1,&character2);

//	//LCD_ShowImage1(6,27);
//	LCD_ShowImage1(86,27);
//	LCD_ShowImage1(166,27);
//	LCD_ShowImage1(6,187);
//	LCD_ShowImage1(86,187);
//	LCD_ShowImage1(166,187);
}

int choose_player() {
	LCD_Clear(WHITE);
	LCD_ShowString(60,100,140,16,16, "choose player1");

	LCD_ShowString(60,200,140,16,16, "choose player2");

	while (1) {
		tp_dev.scan(0);

		if(tp_dev.sta&TP_PRES_DOWN)			//触摸屏被按下
		{
			int x = tp_dev.x[0];
			int y = tp_dev.y[0];
			if(x<lcddev.width&&y<lcddev.height)
			{
				if (x>60&&x<200&&y>100&&y<124) {
					return 1;
				} else if (x>60&&x<200&&y>200&&y<224) {
					return 2;
				}
			}
		}else delay_ms(10);	//没有按键按下的时�??
	}
}
int S_M(){
	LCD_Clear(WHITE);

	LCD_ShowString(60,100,140,16,16, "Single-Character");

	LCD_ShowString(60,200,140,16,16, "Multi-Character");

	while (1) {
		tp_dev.scan(0);

		if(tp_dev.sta&TP_PRES_DOWN)			//触摸屏被按下
		{
			int x = tp_dev.x[0];
			int y = tp_dev.y[0];
			if(x<lcddev.width&&y<lcddev.height)
			{
				if (x>60&&x<200&&y>100&&y<124) {
					return 1;
				} else if (x>60&&x<200&&y>200&&y<224) {
					return 2;
				}
			}
		}else delay_ms(10);	//没有按键按下的时�??
	}
}
int PvE_PvP() {
	LCD_Clear(WHITE);

	LCD_ShowString(100,100,100,24,24, "PvP");

	LCD_ShowString(100,200,100,24,24, "PvE");

	while (1) {
		tp_dev.scan(0);

		if(tp_dev.sta&TP_PRES_DOWN)			//触摸屏被按下
		{
			int x = tp_dev.x[0];
			int y = tp_dev.y[0];
			if(x<lcddev.width&&y<lcddev.height)
			{
				if (x>60&&x<200&&y>100&&y<124) {
					return 1;
				} else if (x>60&&x<200&&y>200&&y<224) {
					return 2;
				}
			}
		}else delay_ms(10);	//没有按键按下的时�??
	}
}

void screen_print(){
	LCD_Clear(WHITE);//清屏
	POINT_COLOR=BLUE;//设置字体为蓝�????
	// LCD_ShowString(lcddev.width-24,0,200,16,16,"RST");//显示清屏区域
	LCD_ShowString(5,10,200,24,24, "Feed");
	LCD_ShowString(90,10,200,24,24, "Ignored");
	POINT_COLOR=RED;//设置画笔为红�????
	LCD_ShowImage2(40,80);
	printLog();
}


////////////////////////////////////////////////////////////////////////////////
//5个触控点的颜�?????(电容触摸屏用)
const u16 POINT_COLOR_TBL[5]={RED,GREEN,BLUE,BROWN,GRED};

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void remote_tatakai(int finalchoose1, int finalchoose2, struct character *character1, struct character *character2, int player_no){
	int check_takeaction=0;
	 int mode;
	 if (player_no==1){
		 mode=2;
	 }
	 else if (player_no==2){
		 mode=1;
	 }
	 int turn_count=0;
	 int turn_count_check1=0;
	 int turn_count_check2=0;
	 int possibility = 0;
	 LCD_Clear(WHITE);
	 u8 fire[60];
	 memset(fire,0,sizeof(fire));
	 while(1)
		{
			//key=KEY_Scan(0);
			tp_dev.scan(0);

			if (mode==1){
				 delay_ms(200);
				 LCD_ShowImage0(lcddev.width-93,27);
				 delay_ms(50);
			 }
			 else if (mode==2){
				 delay_ms(200);
				 LCD_ShowImage0(27,187);
				 delay_ms(50);
			 }



			LCD_ShowImage3(lcddev.width-93-40,27,3);
			LCD_ShowImage3(lcddev.width-93-80,27,2);
			LCD_ShowImage3(lcddev.width-93-120,27,1);
			LCD_ShowImage3(lcddev.width-93-120,27+30+10,4);
			LCD_ShowImage3(27+67+10,187,1);
			LCD_ShowImage3(27+67+10,187+30+10,4);
			LCD_ShowImage3(27+67+10+40,187,2);
			LCD_ShowImage3(27+67+10+80,187,3);
			if (possibility ==0){
				LCD_ShowImage3(lcddev.width-93-80,27+30+10,0);
				LCD_ShowImage3(27+67+10+40,187+30+10,0);
			}else{
				LCD_ShowImage3(lcddev.width-93-80,27+30+10,possibility+4);
				LCD_ShowImage3(27+67+10+40,187+30+10,possibility+4);
			}


			if (finalchoose1==1){
				LCD_ShowImage1_1(lcddev.width-93,27,get_level(character1));
			}
			else if (finalchoose1==2){
				LCD_ShowImage1_2(lcddev.width-93,27,get_level(character1));

			}else if (finalchoose1==3){
				LCD_ShowImage1_3(lcddev.width-93,27,get_level(character1));
			}

			if (finalchoose2==1){
				LCD_ShowImage1_1(27,187,get_level(character2));
			}else if (finalchoose2==2){
				LCD_ShowImage1_2(27,187,get_level(character2));
			}else if (finalchoose2==3){
				LCD_ShowImage1_3(27,187,get_level(character2));
			}

			char name1[64] = {0};
			get_name(character1,name1);
			char name2[64] = {0};
			get_name(character2,name2);

			LCD_ShowString(lcddev.width-93+36,27+67+1,33,12,12, name1);
			LCD_ShowString(27+36,187+67+1,33,12,12, name2);
			LCD_ShowNum(lcddev.width-93+33,27+67+1+13,get_HP(character1),4,12);
			LCD_ShowNum(27+33,187+67+1+13,get_HP(character2),4,12);
			LCD_ShowNum(lcddev.width-93+33,27+67+1+26,get_ATK(character1),4,12);
			LCD_ShowNum(27+33,187+67+1+26,get_ATK(character2),4,12);
			LCD_ShowNum(lcddev.width-93+33,27+67+1+39,get_DEF(character1),4,12);
			LCD_ShowNum(27+33,187+67+1+39,get_DEF(character2),4,12);

			LCD_ShowString(lcddev.width-93,27+67+1,33,12,12, "NAME: ");
			LCD_ShowString(27,187+67+1,33,12,12, "NAME: ");
			LCD_ShowString(lcddev.width-93,27+67+1+13,33,12,12, "HP: ");
			LCD_ShowString(27,187+67+1+13,33,12,12, "HP: ");
			LCD_ShowString(lcddev.width-93,27+67+1+26,33,12,12, "ATK: ");
			LCD_ShowString(27,187+67+1+26,33,12,12, "ATK: ");
			LCD_ShowString(lcddev.width-93,27+67+1+39,33,12,12, "DEF: ");
			LCD_ShowString(27,187+67+1+39,33,12,12, "DEF: ");

			if (player_no==2){
				LCD_ShowString(lcddev.width-93,13,67,12,12, "player1");
			    LCD_ShowString(27,173,67,12,12, "player2");
			}
			else{
				LCD_ShowString(lcddev.width-93,13,67,12,12, "player2");
	            LCD_ShowString(27,173,67,12,12, "player1");
			}

			 for (int x1=0;x1<240;x1++){
				LCD_Fast_DrawPoint(x1, 160,BLUE);
				}

			 if (check_takeaction!=0){
				   delay_ms(500);
				   if (check_takeaction==1){
					   if (is_alive(character2)==0){
						   LCD_ShowString(lcddev.width-93-80,160-30,60,24,24, "WIN!");
						   LCD_ShowString(27+67+10+40,320-30,60,24,24, "LOSE!");
						   break;
					   }

				   }
				   else if (check_takeaction==2){
					   if (is_alive(character1)==0){
					   LCD_ShowString(lcddev.width-93-80,160-30,60,24,24, "LOSE!");
					   LCD_ShowString(27+67+10+40,320-30,60,24,24, "WIN!");
					   break;
					   }
				   }

				   if (mode==1){
					   mode=2;

				   } else if (mode==2){
					   mode=1;
				   }
				   check_takeaction=0;
				   if (turn_count!=0&&turn_count%4==0&&turn_count_check1!=turn_count){
					   if (get_level(character1)<=4) {
						   upgrade(character1);
					   }
					   if (get_level(character2)<=4) {
						   upgrade(character2);
					   }
					   turn_count_check1=turn_count;
				   }

				   if (turn_count!=0&&turn_count_check2!=turn_count){
					   int coin=0;
					   coin=rand()%100+1;
					   if (coin>60){
						   if (coin>60&&coin<=70){
							   possibility =1;
						   }
						   else if (coin>70&&coin<=80){
							   possibility =2;

						   }else if (coin>80&&coin<=95){
							   possibility =3;

						   }else if (coin>95&&coin<=100){
							   possibility=4;
						   }

					   }
					   else{
					   possibility =0;
				       }
					   turn_count_check2=turn_count;
				   }
			   }
			 //
			 if (mode==1){
				//NRF24L01_RX_Mode();
					 NRF24L01_RX_Mode();
					 if(NRF24L01_RxPacket(fire)==0){
						respond_clpt(character2,character1,fire);
						turn_count++;
						check_takeaction=1;
					 }
					 //else delay_us(100);
//					 mode=2;
//					 upgrade(character2);
//					 upgrade(character1);
//					 delay_us(1000);
//					 break;


#ifdef Obstacle
			 if(tp_dev.sta&TP_PRES_DOWN)			//触摸屏被按下
			{
				if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)
				{

					if(tp_dev.x[0]>lcddev.width-93-120&&tp_dev.y[0]>27&&tp_dev.x[0]<lcddev.width-93-120+30&&tp_dev.y[0]<27+30){
						int is_critical = normal_attack_skill(character1,character2);
						if (is_active_defending(character2)==1){
							active_defend_part(character2, (int)(get_ATK(character1)+is_critical*get_ATK(character1)*0.1));
						}else if (is_active_defending(character2)==0){
							passive_defend_part(character2, (int)(get_ATK(character1)+is_critical*get_ATK(character1)*0.1));
						}
						check_takeaction=1;
						delay_ms(500);
					}
					else if(tp_dev.x[0]>lcddev.width-93-120&&tp_dev.y[0]>27+30+10&&tp_dev.x[0]<lcddev.width-93-120+30&&tp_dev.y[0]<27+30+10+30){
					 grow_attack_skill(character1,character2);
					if (is_active_defending(character2)==1){
						active_defend_part(character2, (int)(get_ATK(character1)*0.5));

					}else if (is_active_defending(character2)==0){
						passive_defend_part(character2, (int)(get_ATK(character1)*0.5));
					}
					check_takeaction=1;
					delay_ms(500);
					}
					else if(tp_dev.x[0]>lcddev.width-93-80&&tp_dev.y[0]>27&&tp_dev.x[0]<lcddev.width-93-80+30&&tp_dev.y[0]<27+30){
						defend_skill(character1);
						check_takeaction=1;
						delay_ms(500);
					}
					else if(tp_dev.x[0]>lcddev.width-93-40&&tp_dev.y[0]>27&&tp_dev.x[0]<lcddev.width-93-40+30&&tp_dev.y[0]<27+30){
						unique_skill(character1,character2);
	//						if (is_active_defending(&character2)==1){
	//							active_defend_part(&character2, (int)(get_ATK(&character1)+is_critical*get_ATK(&character1)*0.1));
	//						}else if (is_active_defending(&character2)==0){
	//							passive_defend_part(&character2, (int)(get_ATK(&character1)+is_critical*get_ATK(&character1)*0.1));
	//						}
						check_takeaction=1;
						delay_ms(500);
					}


				}
			}else delay_ms(10);	//没有按键按下的时�??
			//i++;
			//if(i%20==0)LED0=!LED0;
#endif

			 }
			 else if (mode==2){

				if(tp_dev.sta&TP_PRES_DOWN)			//触摸屏被按下
				{
					if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)
					{

						if(tp_dev.x[0]>27+67+10&&tp_dev.y[0]>187&&tp_dev.x[0]<27+67+10+30&&tp_dev.y[0]<187+30){
							int is_critical = normal_attack_skill(character2,character1);
//							if (is_active_defending(&character1)==1){
//								active_defend_part(&character1, (int)(get_ATK(character2)+is_critical*get_ATK(character2)*0.1));
//							}else if (is_active_defending(&character1)==0){
//								passive_defend_part(&character1, (int)(get_ATK(character2)+is_critical*get_ATK(character2)*0.1));
//							}
							check_takeaction=2;
							turn_count++;
							send("god1");
							delay_ms(500);
						}
						else if(tp_dev.x[0]>27+67+10&&tp_dev.y[0]>187+30+10&&tp_dev.x[0]<27+67+10+30&&tp_dev.y[0]<187+30+10+30){
						 grow_attack_skill(character2,character1);

//						if (is_active_defending(&character1)==1){
//							active_defend_part(&character1, (int)(get_ATK(character2)*0.5));
//
//						}else if (is_active_defending(&character1)==0){
//							passive_defend_part(&character1, (int)(get_ATK(character2)*0.5));
//						}
						check_takeaction=2;
						 turn_count++;
						send("god2");
						delay_ms(500);
						}
						else if(tp_dev.x[0]>27+67+10+40&&tp_dev.y[0]>187&&tp_dev.x[0]<27+67+10+40+30&&tp_dev.y[0]<187+30){
							defend_skill(character2);
							check_takeaction=2;
							 turn_count++;
							send("god4");
							delay_ms(500);
						}
						else if(tp_dev.x[0]>27+67+10+80&&tp_dev.y[0]>187&&tp_dev.x[0]<27+67+10+80+30&&tp_dev.y[0]<187+30){
							unique_skill(character2,character1);
	//							if (is_active_defending(&character2)==1){
	//								active_defend_part(&character2, (int)(get_ATK(&character1)+is_critical*get_ATK(&character1)*0.1));
	//							}else if (is_active_defending(&character2)==0){
	//								passive_defend_part(&character2, (int)(get_ATK(&character1)+is_critical*get_ATK(&character1)*0.1));
	//							}
							check_takeaction=2;
							 turn_count++;
							send("god3");
							delay_ms(500);
						}

						if (possibility!=0){
							if(tp_dev.x[0]>27+67+10+40&&tp_dev.y[0]>187+30+10&&tp_dev.x[0]<27+67+10+40+30&&tp_dev.y[0]<187+30+10+30){
								if (possibility==1){
									weapon(character2);
									check_takeaction=2;
									 turn_count++;
									send("god5");
									delay_ms(500);

								}else if(possibility==2){
									shield(character2);
									check_takeaction=2;
									 turn_count++;
									send("god6");
									delay_ms(500);

								}else if(possibility==3){
									aid_bag(character2);
									check_takeaction=2;
									 turn_count++;
									send("god7");
									delay_ms(500);

								}else if(possibility==4){
									easter_egg(character2);
									check_takeaction=2;
									 turn_count++;
									send("god8");
									delay_ms(500);

								}
							}
						}


					}
				}else delay_ms(10);	//没有按键按下的时�??
				//i++;
				//if(i%20==0)LED0=!LED0;

			 }



		}

}
void remote_tatakai_MULTI(int finalchoose1, int finalchoose2, struct character *character1, struct character *character2, int player_no,int choose1[],int choose2[]){
	int check_takeaction=0;
	 int mode;
	 int order1=1;
	 int order2=1;
		struct character a1 = initialize_character(0);
				struct character a2 = initialize_character(1);
				struct character a3 = initialize_character(2);
	    	 			struct character b1 = initialize_character(0);
	    	 			struct character b2 = initialize_character(1);
	    	 			struct character b3 = initialize_character(2);




	 if (player_no==1){
		 mode=2;
	 }
	 else if (player_no==2){
		 mode=1;
	 }
	 int turn_count=0;
	 int turn_count_check1=0;
	 int turn_count_check2=0;
	 int possibility = 0;
	 LCD_Clear(WHITE);
	 u8 fire[60];
	 memset(fire,0,sizeof(fire));
	 while(1)
		{
			//key=KEY_Scan(0);
			tp_dev.scan(0);

			if (mode==1){
				 delay_ms(200);
				 LCD_ShowImage0(lcddev.width-93,27);
				 delay_ms(50);
			 }
			 else if (mode==2){
				 delay_ms(200);
				 LCD_ShowImage0(27,187);
				 delay_ms(50);
			 }



			LCD_ShowImage3(lcddev.width-93-40,27,3);
			LCD_ShowImage3(lcddev.width-93-80,27,2);
			LCD_ShowImage3(lcddev.width-93-120,27,1);
			LCD_ShowImage3(lcddev.width-93-120,27+30+10,4);
			LCD_ShowImage3(27+67+10,187,1);
			LCD_ShowImage3(27+67+10,187+30+10,4);
			LCD_ShowImage3(27+67+10+40,187,2);
			LCD_ShowImage3(27+67+10+80,187,3);
			if (possibility ==0){
				LCD_ShowImage3(lcddev.width-93-80,27+30+10,0);
				LCD_ShowImage3(27+67+10+40,187+30+10,0);
			}else{
				LCD_ShowImage3(lcddev.width-93-80,27+30+10,possibility+4);
				LCD_ShowImage3(27+67+10+40,187+30+10,possibility+4);
			}


			if (finalchoose1==1){
				LCD_ShowImage1_1(lcddev.width-93,27,get_level(character1));
			}
			else if (finalchoose1==2){
				LCD_ShowImage1_2(lcddev.width-93,27,get_level(character1));

			}else if (finalchoose1==3){
				LCD_ShowImage1_3(lcddev.width-93,27,get_level(character1));
			}

			if (finalchoose2==1){
				LCD_ShowImage1_1(27,187,get_level(character2));
			}else if (finalchoose2==2){
				LCD_ShowImage1_2(27,187,get_level(character2));
			}else if (finalchoose2==3){
				LCD_ShowImage1_3(27,187,get_level(character2));
			}

			char name1[64] = {0};
			get_name(character1,name1);
			char name2[64] = {0};
			get_name(character2,name2);

			LCD_ShowString(lcddev.width-93+36,27+67+1,33,12,12, name1);
			LCD_ShowString(27+36,187+67+1,33,12,12, name2);
			LCD_ShowNum(lcddev.width-93+33,27+67+1+13,get_HP(character1),4,12);
			LCD_ShowNum(27+33,187+67+1+13,get_HP(character2),4,12);
			LCD_ShowNum(lcddev.width-93+33,27+67+1+26,get_ATK(character1),4,12);
			LCD_ShowNum(27+33,187+67+1+26,get_ATK(character2),4,12);
			LCD_ShowNum(lcddev.width-93+33,27+67+1+39,get_DEF(character1),4,12);
			LCD_ShowNum(27+33,187+67+1+39,get_DEF(character2),4,12);

			LCD_ShowString(lcddev.width-93,27+67+1,33,12,12, "NAME: ");
			LCD_ShowString(27,187+67+1,33,12,12, "NAME: ");
			LCD_ShowString(lcddev.width-93,27+67+1+13,33,12,12, "HP: ");
			LCD_ShowString(27,187+67+1+13,33,12,12, "HP: ");
			LCD_ShowString(lcddev.width-93,27+67+1+26,33,12,12, "ATK: ");
			LCD_ShowString(27,187+67+1+26,33,12,12, "ATK: ");
			LCD_ShowString(lcddev.width-93,27+67+1+39,33,12,12, "DEF: ");
			LCD_ShowString(27,187+67+1+39,33,12,12, "DEF: ");

			if (player_no==2){
				LCD_ShowString(lcddev.width-93,13,67,12,12, "player1");
			    LCD_ShowString(27,173,67,12,12, "player2");
			}
			else{
				LCD_ShowString(lcddev.width-93,13,67,12,12, "player2");
	            LCD_ShowString(27,173,67,12,12, "player1");
			}

			 for (int x1=0;x1<240;x1++){
				LCD_Fast_DrawPoint(x1, 160,BLUE);
				}

			 if (check_takeaction!=0){
				   delay_ms(500);
				   if (check_takeaction==1){
					   if (is_alive(character2)==0){
						   if (order2<3){
							   turn_count=0;
							   turn_count_check1=0;
							   turn_count_check1=0;
							   order2++;
							   if (choose2[order2]==1){
								   finalchoose2=1;
	                    			character2=&b1;

	                    		}else if(choose2[order2]==2){
	                    			finalchoose2=2;
	                    			character2=&b2;
	                    		}else if(choose2[order2]==3){
	                    			finalchoose2=3;
	                    			character2=&b3;
	                    		}



						   }
						   else{
							   LCD_ShowString(lcddev.width-93-80,160-30,60,24,24, "WIN!");
						       LCD_ShowString(27+67+10+40,320-30,60,24,24, "LOSE!");
						       break;
						   }

					   }

				   }
				   else if (check_takeaction==2){
					   if (is_alive(character1)==0){
						   if (order1<3){
							   turn_count=0;
							   turn_count_check1=0;
							   turn_count_check1=0;
							   order1++;
							   if (choose1[order1]==1){
								   finalchoose1=1;
	                    			character1=&a1;
	                    		}else if(choose1[order1]==2){
	                    			finalchoose1=2;
	                    			character1=&a2;
	                    		}else if(choose1[order1]==3){
	                    			finalchoose1=3;
	                    			character1=&a3;
	                    		}

						   }
						   else{
							     LCD_ShowString(lcddev.width-93-80,160-30,60,24,24, "LOSE!");
					             LCD_ShowString(27+67+10+40,320-30,60,24,24, "WIN!");
					             break;
						   }

					   }
				   }

				   if (mode==1){
					   mode=2;

				   } else if (mode==2){
					   mode=1;
				   }
				   check_takeaction=0;
				   if (turn_count!=0&&turn_count%4==0&&turn_count_check1!=turn_count){
					   if (get_level(character1)<=4) {
						   upgrade(character1);
					   }
					   if (get_level(character2)<=4) {
						   upgrade(character2);
					   }
					   turn_count_check1=turn_count;
				   }

				   if (turn_count!=0&&turn_count_check2!=turn_count){
					   int coin=0;
					   coin=rand()%100+1;
					   if (coin>60){
						   if (coin>60&&coin<=70){
							   possibility =1;
						   }
						   else if (coin>70&&coin<=80){
							   possibility =2;

						   }else if (coin>80&&coin<=95){
							   possibility =3;

						   }else if (coin>95&&coin<=100){
							   possibility=4;
						   }

					   }
					   else{
					   possibility =0;
				       }
					   turn_count_check2=turn_count;
				   }
			   }
			 //
			 if (mode==1){
				//NRF24L01_RX_Mode();
					 NRF24L01_RX_Mode();
					 if(NRF24L01_RxPacket(fire)==0){
						respond_clpt(character2,character1,fire);
						turn_count++;
						check_takeaction=1;
					 }
					 //else delay_us(100);
//					 mode=2;
//					 upgrade(character2);
//					 upgrade(character1);
//					 delay_us(1000);
//					 break;


#ifdef Obstacle
			 if(tp_dev.sta&TP_PRES_DOWN)			//触摸屏被按下
			{
				if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)
				{

					if(tp_dev.x[0]>lcddev.width-93-120&&tp_dev.y[0]>27&&tp_dev.x[0]<lcddev.width-93-120+30&&tp_dev.y[0]<27+30){
						int is_critical = normal_attack_skill(character1,character2);
						if (is_active_defending(character2)==1){
							active_defend_part(character2, (int)(get_ATK(character1)+is_critical*get_ATK(character1)*0.1));
						}else if (is_active_defending(character2)==0){
							passive_defend_part(character2, (int)(get_ATK(character1)+is_critical*get_ATK(character1)*0.1));
						}
						check_takeaction=1;
						delay_ms(500);
					}
					else if(tp_dev.x[0]>lcddev.width-93-120&&tp_dev.y[0]>27+30+10&&tp_dev.x[0]<lcddev.width-93-120+30&&tp_dev.y[0]<27+30+10+30){
					 grow_attack_skill(character1,character2);
					if (is_active_defending(character2)==1){
						active_defend_part(character2, (int)(get_ATK(character1)*0.5));

					}else if (is_active_defending(character2)==0){
						passive_defend_part(character2, (int)(get_ATK(character1)*0.5));
					}
					check_takeaction=1;
					delay_ms(500);
					}
					else if(tp_dev.x[0]>lcddev.width-93-80&&tp_dev.y[0]>27&&tp_dev.x[0]<lcddev.width-93-80+30&&tp_dev.y[0]<27+30){
						defend_skill(character1);
						check_takeaction=1;
						delay_ms(500);
					}
					else if(tp_dev.x[0]>lcddev.width-93-40&&tp_dev.y[0]>27&&tp_dev.x[0]<lcddev.width-93-40+30&&tp_dev.y[0]<27+30){
						unique_skill(character1,character2);
	//						if (is_active_defending(&character2)==1){
	//							active_defend_part(&character2, (int)(get_ATK(&character1)+is_critical*get_ATK(&character1)*0.1));
	//						}else if (is_active_defending(&character2)==0){
	//							passive_defend_part(&character2, (int)(get_ATK(&character1)+is_critical*get_ATK(&character1)*0.1));
	//						}
						check_takeaction=1;
						delay_ms(500);
					}


				}
			}else delay_ms(10);	//没有按键按下的时�??
			//i++;
			//if(i%20==0)LED0=!LED0;
#endif

			 }
			 else if (mode==2){

				if(tp_dev.sta&TP_PRES_DOWN)			//触摸屏被按下
				{
					if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)
					{

						if(tp_dev.x[0]>27+67+10&&tp_dev.y[0]>187&&tp_dev.x[0]<27+67+10+30&&tp_dev.y[0]<187+30){
							int is_critical = normal_attack_skill(character2,character1);
//							if (is_active_defending(&character1)==1){
//								active_defend_part(&character1, (int)(get_ATK(character2)+is_critical*get_ATK(character2)*0.1));
//							}else if (is_active_defending(&character1)==0){
//								passive_defend_part(&character1, (int)(get_ATK(character2)+is_critical*get_ATK(character2)*0.1));
//							}
							check_takeaction=2;
							turn_count++;
							send("god1");
							delay_ms(500);
						}
						else if(tp_dev.x[0]>27+67+10&&tp_dev.y[0]>187+30+10&&tp_dev.x[0]<27+67+10+30&&tp_dev.y[0]<187+30+10+30){
						 grow_attack_skill(character2,character1);

//						if (is_active_defending(&character1)==1){
//							active_defend_part(&character1, (int)(get_ATK(character2)*0.5));
//
//						}else if (is_active_defending(&character1)==0){
//							passive_defend_part(&character1, (int)(get_ATK(character2)*0.5));
//						}
						check_takeaction=2;
						 turn_count++;
						send("god2");
						delay_ms(500);
						}
						else if(tp_dev.x[0]>27+67+10+40&&tp_dev.y[0]>187&&tp_dev.x[0]<27+67+10+40+30&&tp_dev.y[0]<187+30){
							defend_skill(character2);
							check_takeaction=2;
							 turn_count++;
							send("god4");
							delay_ms(500);
						}
						else if(tp_dev.x[0]>27+67+10+80&&tp_dev.y[0]>187&&tp_dev.x[0]<27+67+10+80+30&&tp_dev.y[0]<187+30){
							unique_skill(character2,character1);
	//							if (is_active_defending(&character2)==1){
	//								active_defend_part(&character2, (int)(get_ATK(&character1)+is_critical*get_ATK(&character1)*0.1));
	//							}else if (is_active_defending(&character2)==0){
	//								passive_defend_part(&character2, (int)(get_ATK(&character1)+is_critical*get_ATK(&character1)*0.1));
	//							}
							check_takeaction=2;
							 turn_count++;
							send("god3");
							delay_ms(500);
						}

						if (possibility!=0){
							if(tp_dev.x[0]>27+67+10+40&&tp_dev.y[0]>187+30+10&&tp_dev.x[0]<27+67+10+40+30&&tp_dev.y[0]<187+30+10+30){
								if (possibility==1){
									weapon(character2);
									check_takeaction=2;
									 turn_count++;
									send("god5");
									delay_ms(500);

								}else if(possibility==2){
									shield(character2);
									check_takeaction=2;
									 turn_count++;
									send("god6");
									delay_ms(500);

								}else if(possibility==3){
									aid_bag(character2);
									check_takeaction=2;
									 turn_count++;
									send("god7");
									delay_ms(500);

								}else if(possibility==4){
									easter_egg(character2);
									check_takeaction=2;
									 turn_count++;
									send("god8");
									delay_ms(500);

								}
							}
						}


					}
				}else delay_ms(10);	//没有按键按下的时�??
				//i++;
				//if(i%20==0)LED0=!LED0;

			 }



		}

}

void remote_tatakai_PvE(int finalchoose1, int finalchoose2, struct character *character1, struct character *character2){
	int check_takeaction=0;
	 int mode;
	 mode=2;
	 int turn_count=0;
	 int turn_count_check1=0;
	 int turn_count_check2=0;
	 int possibility = 0;
	 LCD_Clear(WHITE);
	 u8 fire[60];
	 memset(fire,0,sizeof(fire));
	 while(1)
		{
			//key=KEY_Scan(0);
			tp_dev.scan(0);

			if (mode==1){
				 delay_ms(200);
				 LCD_ShowImage0(lcddev.width-93,27);
				 delay_ms(50);
			 }
			 else if (mode==2){
				 delay_ms(200);
				 LCD_ShowImage0(27,187);
				 delay_ms(50);
			 }



			LCD_ShowImage3(lcddev.width-93-40,27,3);
			LCD_ShowImage3(lcddev.width-93-80,27,2);
			LCD_ShowImage3(lcddev.width-93-120,27,1);
			LCD_ShowImage3(lcddev.width-93-120,27+30+10,4);
			LCD_ShowImage3(27+67+10,187,1);
			LCD_ShowImage3(27+67+10,187+30+10,4);
			LCD_ShowImage3(27+67+10+40,187,2);
			LCD_ShowImage3(27+67+10+80,187,3);
			if (possibility ==0){
				LCD_ShowImage3(lcddev.width-93-80,27+30+10,0);
				LCD_ShowImage3(27+67+10+40,187+30+10,0);
			}else{
				LCD_ShowImage3(lcddev.width-93-80,27+30+10,possibility+4);
				LCD_ShowImage3(27+67+10+40,187+30+10,possibility+4);
			}


			if (finalchoose1==1){
				LCD_ShowImage1_1(lcddev.width-93,27,get_level(character1));
			}
			else if (finalchoose1==2){
				LCD_ShowImage1_2(lcddev.width-93,27,get_level(character1));

			}else if (finalchoose1==3){
				LCD_ShowImage1_3(lcddev.width-93,27,get_level(character1));
			}

			if (finalchoose2==1){
				LCD_ShowImage1_1(27,187,get_level(character2));
			}else if (finalchoose2==2){
				LCD_ShowImage1_2(27,187,get_level(character2));
			}else if (finalchoose2==3){
				LCD_ShowImage1_3(27,187,get_level(character2));
			}

			char name1[64] = {0};
			get_name(character1,name1);
			char name2[64] = {0};
			get_name(character2,name2);

			LCD_ShowString(lcddev.width-93+36,27+67+1,33,12,12, name1);
			LCD_ShowString(27+36,187+67+1,33,12,12, name2);
			LCD_ShowNum(lcddev.width-93+33,27+67+1+13,get_HP(character1),4,12);
			LCD_ShowNum(27+33,187+67+1+13,get_HP(character2),4,12);
			LCD_ShowNum(lcddev.width-93+33,27+67+1+26,get_ATK(character1),4,12);
			LCD_ShowNum(27+33,187+67+1+26,get_ATK(character2),4,12);
			LCD_ShowNum(lcddev.width-93+33,27+67+1+39,get_DEF(character1),4,12);
			LCD_ShowNum(27+33,187+67+1+39,get_DEF(character2),4,12);

			LCD_ShowString(lcddev.width-93,27+67+1,33,12,12, "NAME: ");
			LCD_ShowString(27,187+67+1,33,12,12, "NAME: ");
			LCD_ShowString(lcddev.width-93,27+67+1+13,33,12,12, "HP: ");
			LCD_ShowString(27,187+67+1+13,33,12,12, "HP: ");
			LCD_ShowString(lcddev.width-93,27+67+1+26,33,12,12, "ATK: ");
			LCD_ShowString(27,187+67+1+26,33,12,12, "ATK: ");
			LCD_ShowString(lcddev.width-93,27+67+1+39,33,12,12, "DEF: ");
			LCD_ShowString(27,187+67+1+39,33,12,12, "DEF: ");



				LCD_ShowString(lcddev.width-93,13,90,12,12, "machine player");
	            LCD_ShowString(27,173,67,12,12, "real player");


			 for (int x1=0;x1<240;x1++){
				LCD_Fast_DrawPoint(x1, 160,BLUE);
				}

			 if (check_takeaction!=0){
				   delay_ms(500);
				   if (check_takeaction==1){
					   if (is_alive(character2)==0){
						   LCD_ShowString(lcddev.width-93-80,160-30,60,24,24, "WIN!");
						   LCD_ShowString(27+67+10+40,320-30,60,24,24, "LOSE!");
						   break;
					   }

				   }
				   else if (check_takeaction==2){
					   if (is_alive(character1)==0){
					   LCD_ShowString(lcddev.width-93-80,160-30,60,24,24, "LOSE!");
					   LCD_ShowString(27+67+10+40,320-30,60,24,24, "WIN!");
					   break;
					   }
				   }

				   if (mode==1){
					   mode=2;

				   } else if (mode==2){
					   mode=1;
				   }
				   check_takeaction=0;
				   if (turn_count!=0&&turn_count%4==0&&turn_count_check1!=turn_count){
					   if (get_level(character1)<=4) {
						   upgrade(character1);
					   }
					   if (get_level(character2)<=4) {
						   upgrade(character2);
					   }
					   turn_count_check1=turn_count;
				   }

				   if (turn_count!=0&&turn_count_check2!=turn_count){
					   int coin=0;
					   coin=rand()%100+1;
					   if (coin>60){
						   if (coin>60&&coin<=70){
							   possibility =1;
						   }
						   else if (coin>70&&coin<=80){
							   possibility =2;

						   }else if (coin>80&&coin<=95){
							   possibility =3;

						   }else if (coin>95&&coin<=100){
							   possibility=4;
						   }

					   }
					   else{
					   possibility =0;
				       }
					   turn_count_check2=turn_count;
				   }
			   }
			 //
			 if (mode==1){
				//NRF24L01_RX_Mode();if(tp_dev.sta&TP_PRES_DOWN)			//触摸屏被按下
					int stage=0;
					if (possibility==0) stage=rand()%4+1;
					else stage=rand()%5+1;

							if(stage==1){
								int is_critical = normal_attack_skill(character1,character2);
	//							if (is_active_defending(&character1)==1){
	//								active_defend_part(&character1, (int)(get_ATK(character2)+is_critical*get_ATK(character2)*0.1));
	//							}else if (is_active_defending(&character1)==0){
	//								passive_defend_part(&character1, (int)(get_ATK(character2)+is_critical*get_ATK(character2)*0.1));
	//							}
								check_takeaction=1;
								turn_count++;
								delay_ms(500);
							}
							else if(stage==2){
							 grow_attack_skill(character1,character2);

	//						if (is_active_defending(&character1)==1){
	//							active_defend_part(&character1, (int)(get_ATK(character2)*0.5));
	//
	//						}else if (is_active_defending(&character1)==0){
	//							passive_defend_part(&character1, (int)(get_ATK(character2)*0.5));
	//						}
							check_takeaction=1;
							 turn_count++;
							delay_ms(500);
							}
							else if(stage==3){
								defend_skill(character1);
								check_takeaction=1;
								 turn_count++;
								delay_ms(500);
							}
							else if(stage==4){
								unique_skill(character1,character2);
		//							if (is_active_defending(&character2)==1){
		//								active_defend_part(&character2, (int)(get_ATK(&character1)+is_critical*get_ATK(&character1)*0.1));
		//							}else if (is_active_defending(&character2)==0){
		//								passive_defend_part(&character2, (int)(get_ATK(&character1)+is_critical*get_ATK(&character1)*0.1));
		//							}
								check_takeaction=1;
								 turn_count++;
								delay_ms(500);
							}

							if (possibility!=0){
								if(stage==5){
									if (possibility==1){
										weapon(character1);
										check_takeaction=1;
										 turn_count++;
										delay_ms(500);

									}else if(possibility==2){
										shield(character1);
										check_takeaction=1;
										 turn_count++;
										delay_ms(500);

									}else if(possibility==3){
										aid_bag(character1);
										check_takeaction=1;
										 turn_count++;
										delay_ms(500);

									}else if(possibility==4){
										easter_egg(character1);
										check_takeaction=1;
										 turn_count++;
										delay_ms(500);

									}
								}
							}





					 //else delay_us(100);
//					 mode=2;
//					 upgrade(character2);
//					 upgrade(character1);
//					 delay_us(1000);
//					 break;


#ifdef Obstacle
			 if(tp_dev.sta&TP_PRES_DOWN)			//触摸屏被按下
			{
				if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)
				{

					if(tp_dev.x[0]>lcddev.width-93-120&&tp_dev.y[0]>27&&tp_dev.x[0]<lcddev.width-93-120+30&&tp_dev.y[0]<27+30){
						int is_critical = normal_attack_skill(character1,character2);
						if (is_active_defending(character2)==1){
							active_defend_part(character2, (int)(get_ATK(character1)+is_critical*get_ATK(character1)*0.1));
						}else if (is_active_defending(character2)==0){
							passive_defend_part(character2, (int)(get_ATK(character1)+is_critical*get_ATK(character1)*0.1));
						}
						check_takeaction=1;
						delay_ms(500);
					}
					else if(tp_dev.x[0]>lcddev.width-93-120&&tp_dev.y[0]>27+30+10&&tp_dev.x[0]<lcddev.width-93-120+30&&tp_dev.y[0]<27+30+10+30){
					 grow_attack_skill(character1,character2);
					if (is_active_defending(character2)==1){
						active_defend_part(character2, (int)(get_ATK(character1)*0.5));

					}else if (is_active_defending(character2)==0){
						passive_defend_part(character2, (int)(get_ATK(character1)*0.5));
					}
					check_takeaction=1;
					delay_ms(500);
					}
					else if(tp_dev.x[0]>lcddev.width-93-80&&tp_dev.y[0]>27&&tp_dev.x[0]<lcddev.width-93-80+30&&tp_dev.y[0]<27+30){
						defend_skill(character1);
						check_takeaction=1;
						delay_ms(500);
					}
					else if(tp_dev.x[0]>lcddev.width-93-40&&tp_dev.y[0]>27&&tp_dev.x[0]<lcddev.width-93-40+30&&tp_dev.y[0]<27+30){
						unique_skill(character1,character2);
	//						if (is_active_defending(&character2)==1){
	//							active_defend_part(&character2, (int)(get_ATK(&character1)+is_critical*get_ATK(&character1)*0.1));
	//						}else if (is_active_defending(&character2)==0){
	//							passive_defend_part(&character2, (int)(get_ATK(&character1)+is_critical*get_ATK(&character1)*0.1));
	//						}
						check_takeaction=1;
						delay_ms(500);
					}


				}
			}else delay_ms(10);	//没有按键按下的时�??
			//i++;
			//if(i%20==0)LED0=!LED0;
#endif

			 }
			 else if (mode==2){

				if(tp_dev.sta&TP_PRES_DOWN)			//触摸屏被按下
				{
					if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)
					{

						if(tp_dev.x[0]>27+67+10&&tp_dev.y[0]>187&&tp_dev.x[0]<27+67+10+30&&tp_dev.y[0]<187+30){
							int is_critical = normal_attack_skill(character2,character1);
//							if (is_active_defending(&character1)==1){
//								active_defend_part(&character1, (int)(get_ATK(character2)+is_critical*get_ATK(character2)*0.1));
//							}else if (is_active_defending(&character1)==0){
//								passive_defend_part(&character1, (int)(get_ATK(character2)+is_critical*get_ATK(character2)*0.1));
//							}
							check_takeaction=2;
							turn_count++;
							delay_ms(500);
						}
						else if(tp_dev.x[0]>27+67+10&&tp_dev.y[0]>187+30+10&&tp_dev.x[0]<27+67+10+30&&tp_dev.y[0]<187+30+10+30){
						 grow_attack_skill(character2,character1);

//						if (is_active_defending(&character1)==1){
//							active_defend_part(&character1, (int)(get_ATK(character2)*0.5));
//
//						}else if (is_active_defending(&character1)==0){
//							passive_defend_part(&character1, (int)(get_ATK(character2)*0.5));
//						}
						check_takeaction=2;
						 turn_count++;
						delay_ms(500);
						}
						else if(tp_dev.x[0]>27+67+10+40&&tp_dev.y[0]>187&&tp_dev.x[0]<27+67+10+40+30&&tp_dev.y[0]<187+30){
							defend_skill(character2);
							check_takeaction=2;
							 turn_count++;
							delay_ms(500);
						}
						else if(tp_dev.x[0]>27+67+10+80&&tp_dev.y[0]>187&&tp_dev.x[0]<27+67+10+80+30&&tp_dev.y[0]<187+30){
							unique_skill(character2,character1);
	//							if (is_active_defending(&character2)==1){
	//								active_defend_part(&character2, (int)(get_ATK(&character1)+is_critical*get_ATK(&character1)*0.1));
	//							}else if (is_active_defending(&character2)==0){
	//								passive_defend_part(&character2, (int)(get_ATK(&character1)+is_critical*get_ATK(&character1)*0.1));
	//							}
							check_takeaction=2;
							 turn_count++;
							delay_ms(500);
						}

						if (possibility!=0){
							if(tp_dev.x[0]>27+67+10+40&&tp_dev.y[0]>187+30+10&&tp_dev.x[0]<27+67+10+40+30&&tp_dev.y[0]<187+30+10+30){
								if (possibility==1){
									weapon(character2);
									check_takeaction=2;
									 turn_count++;
									delay_ms(500);

								}else if(possibility==2){
									shield(character2);
									check_takeaction=2;
									 turn_count++;
								delay_ms(500);

								}else if(possibility==3){
									aid_bag(character2);
									check_takeaction=2;
									 turn_count++;
									delay_ms(500);

								}else if(possibility==4){
									easter_egg(character2);
									check_takeaction=2;
									 turn_count++;
									delay_ms(500);

								}
							}
						}


					}
				}else delay_ms(10);	//没有按键按下的时�??
				//i++;
				//if(i%20==0)LED0=!LED0;

			 }



		}

}

#ifdef TATAKAI
void tatakai(int finalchoose1, int finalchoose2, struct character *character1, struct character *character2){
   int check_takeaction=0;
	 int mode=1;
	 LCD_Clear(WHITE);
	 while(1)
		{
			//key=KEY_Scan(0);
			tp_dev.scan(0);

			if (mode==1){
				 delay_ms(200);
				 LCD_ShowImage0(lcddev.width-93,27);
				 delay_ms(50);
			 }
			 else if (mode==2){
				 delay_ms(200);
				 LCD_ShowImage0(27,187);
				 delay_ms(50);
			 }



			LCD_ShowImage3(lcddev.width-93-40,27,3);
			LCD_ShowImage3(lcddev.width-93-80,27,2);
			LCD_ShowImage3(lcddev.width-93-120,27,1);
			LCD_ShowImage3(lcddev.width-93-120,27+30+10,4);
			LCD_ShowImage3(27+67+10,187,1);
			LCD_ShowImage3(27+67+10,187+30+10,4);
			LCD_ShowImage3(27+67+10+40,187,2);
			LCD_ShowImage3(27+67+10+80,187,3);


			if (finalchoose1==1){
				LCD_ShowImage1_1(lcddev.width-93,27,get_level(character1));
			}
			else if (finalchoose1==2){
				LCD_ShowImage1_2(lcddev.width-93,27,get_level(character1));

			}else if (finalchoose1==3){
				LCD_ShowImage1_3(lcddev.width-93,27,get_level(character1));
			}

			if (finalchoose2==1){
				LCD_ShowImage2_1(27,187,get_level(character2));
			}else if (finalchoose2==2){
				LCD_ShowImage2_2(27,187,get_level(character2));
			}else if (finalchoose2==3){
				LCD_ShowImage2_3(27,187,get_level(character2));
			}

			char name1[64] = {0};
			get_name(character1,name1);
			char name2[64] = {0};
			get_name(character2,name2);

			LCD_ShowString(lcddev.width-93+36,27+67+1,33,12,12, name1);
			LCD_ShowString(27+36,187+67+1,33,12,12, name2);
			LCD_ShowNum(lcddev.width-93+33,27+67+1+13,get_HP(character1),4,12);
			LCD_ShowNum(27+33,187+67+1+13,get_HP(character2),4,12);
			LCD_ShowNum(lcddev.width-93+33,27+67+1+26,get_ATK(character1),4,12);
			LCD_ShowNum(27+33,187+67+1+26,get_ATK(character2),4,12);
			LCD_ShowNum(lcddev.width-93+33,27+67+1+39,get_DEF(character1),4,12);
			LCD_ShowNum(27+33,187+67+1+39,get_DEF(character2),4,12);

			LCD_ShowString(lcddev.width-93,27+67+1,33,12,12, "NAME: ");
			LCD_ShowString(27,187+67+1,33,12,12, "NAME: ");
			LCD_ShowString(lcddev.width-93,27+67+1+13,33,12,12, "HP: ");
			LCD_ShowString(27,187+67+1+13,33,12,12, "HP: ");
			LCD_ShowString(lcddev.width-93,27+67+1+26,33,12,12, "ATK: ");
			LCD_ShowString(27,187+67+1+26,33,12,12, "ATK: ");
			LCD_ShowString(lcddev.width-93,27+67+1+39,33,12,12, "DEF: ");
			LCD_ShowString(27,187+67+1+39,33,12,12, "DEF: ");

			LCD_ShowString(lcddev.width-93,13,67,12,12, "player1");
			LCD_ShowString(27,173,67,12,12, "player2");
			 for (int x1=0;x1<240;x1++){
				LCD_Fast_DrawPoint(x1, 160,BLUE);
				}

			 if (check_takeaction!=0){
					   delay_ms(500);
					   if (check_takeaction==1){
						   if (is_alive(character2)==0){
							   LCD_ShowString(lcddev.width-93-80,160-30,60,24,24, "WIN!");
							   LCD_ShowString(27+67+10+40,320-30,60,24,24, "LOSE!");
							   break;
						   }

					   }
					   else if (check_takeaction==2){
						   if (is_alive(character1)==0){
						   LCD_ShowString(lcddev.width-93-80,160-30,60,24,24, "LOSE!");
						   LCD_ShowString(27+67+10+40,320-30,60,24,24, "WIN!");
						   break;
					   }

					   }


					   if (mode==1){
						   mode=2;
					   }else if (mode==2){
						   mode=1;
					   }
					   check_takeaction=0;


				   }




			 if (mode==1){

			 if(tp_dev.sta&TP_PRES_DOWN)			//触摸屏被按下
			{
				if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)
				{

					if(tp_dev.x[0]>lcddev.width-93-120&&tp_dev.y[0]>27&&tp_dev.x[0]<lcddev.width-93-120+30&&tp_dev.y[0]<27+30){
						int is_critical = normal_attack_skill(character1);
						if (is_active_defending(character2)==1){
							active_defend_part(character2, (int)(get_ATK(character1)+is_critical*get_ATK(character1)*0.1));
						}else if (is_active_defending(character2)==0){
							passive_defend_part(character2, (int)(get_ATK(character1)+is_critical*get_ATK(character1)*0.1));
						}
						check_takeaction=1;
						delay_ms(500);
					}
					else if(tp_dev.x[0]>lcddev.width-93-120&&tp_dev.y[0]>27+30+10&&tp_dev.x[0]<lcddev.width-93-120+30&&tp_dev.y[0]<27+30+10+30){
					 grow_attack_skill(character1);
					if (is_active_defending(character2)==1){
						active_defend_part(character2, (int)(get_ATK(character1)*0.5));

					}else if (is_active_defending(character2)==0){
						passive_defend_part(character2, (int)(get_ATK(character1)*0.5));
					}
					check_takeaction=1;
					delay_ms(500);
					}
					else if(tp_dev.x[0]>lcddev.width-93-80&&tp_dev.y[0]>27&&tp_dev.x[0]<lcddev.width-93-80+30&&tp_dev.y[0]<27+30){
						defend_skill(character1);
						check_takeaction=1;
						delay_ms(500);
					}
					else if(tp_dev.x[0]>lcddev.width-93-40&&tp_dev.y[0]>27&&tp_dev.x[0]<lcddev.width-93-40+30&&tp_dev.y[0]<27+30){
						unique_skill(character1);
//						if (is_active_defending(&character2)==1){
//							active_defend_part(&character2, (int)(get_ATK(&character1)+is_critical*get_ATK(&character1)*0.1));
//						}else if (is_active_defending(&character2)==0){
//							passive_defend_part(&character2, (int)(get_ATK(&character1)+is_critical*get_ATK(&character1)*0.1));
//						}
						check_takeaction=1;
						delay_ms(500);
					}


				}
			}else delay_ms(10);	//没有按键按下的时�??
			//i++;
			//if(i%20==0)LED0=!LED0;


			 }
			 else if (mode==2){

				if(tp_dev.sta&TP_PRES_DOWN)			//触摸屏被按下
				{
					if(tp_dev.x[0]<lcddev.width&&tp_dev.y[0]<lcddev.height)
					{

						if(tp_dev.x[0]>27+67+10&&tp_dev.y[0]>187&&tp_dev.x[0]<27+67+10+30&&tp_dev.y[0]<187+30){
							int is_critical = normal_attack_skill(character2);
							if (is_active_defending(&character1)==1){
								active_defend_part(&character1, (int)(get_ATK(character2)+is_critical*get_ATK(character2)*0.1));
							}else if (is_active_defending(&character1)==0){
								passive_defend_part(&character1, (int)(get_ATK(character2)+is_critical*get_ATK(character2)*0.1));
							}
							check_takeaction=2;
							delay_ms(500);
						}
						else if(tp_dev.x[0]>27+67+10&&tp_dev.y[0]>187+30+10&&tp_dev.x[0]<27+67+10+30&&tp_dev.y[0]<187+30+10+30){
						 grow_attack_skill(character2);
						if (is_active_defending(&character1)==1){
							active_defend_part(&character1, (int)(get_ATK(character2)*0.5));

						}else if (is_active_defending(&character1)==0){
							passive_defend_part(&character1, (int)(get_ATK(character2)*0.5));
						}
						check_takeaction=2;
						delay_ms(500);
						}
						else if(tp_dev.x[0]>27+67+10+40&&tp_dev.y[0]>187&&tp_dev.x[0]<27+67+10+40+30&&tp_dev.y[0]<187+30){
							defend_skill(character2);
							check_takeaction=2;
							delay_ms(500);
						}
						else if(tp_dev.x[0]>27+67+10+80&&tp_dev.y[0]>187&&tp_dev.x[0]<27+67+10+80+30&&tp_dev.y[0]<187+30){
							unique_skill(character2);
//							if (is_active_defending(&character2)==1){
//								active_defend_part(&character2, (int)(get_ATK(&character1)+is_critical*get_ATK(&character1)*0.1));
//							}else if (is_active_defending(&character2)==0){
//								passive_defend_part(&character2, (int)(get_ATK(&character1)+is_critical*get_ATK(&character1)*0.1));
//							}
							check_takeaction=2;
							delay_ms(500);
						}


					}
				}else delay_ms(10);	//没有按键按下的时�??
				//i++;
				//if(i%20==0)LED0=!LED0;

			 }



		}
}
#endif
void back_to_Menu(void){
	 LCD_Clear(WHITE);
	 POINT_COLOR=BLUE;
	   int PvEorPvP=PvE_PvP();
	   if (PvEorPvP==1){
	 	  LCD_Clear(WHITE);
	 	  POINT_COLOR=BLUE;
	 	   int SorM=S_M();
	 	   if (SorM==1){
	 		   LCD_Clear(WHITE);
	 		   multiplayer_mode();
	 	   }else{
	 		   multi_c_p_mode();
	 	   }

	   }
	   else{
	 	  LCD_Clear(WHITE);
	 	  singleplayer_mode();
	   }
}
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
  Stm32_Clock_Init(RCC_PLL_MUL9);   	//设置时钟,72M
	delay_init(72);               		//初始化延时函�?????
//	uart_init(115200);					//初始化串�?????
//	usmart_dev.init(84); 		  	  	//初始化USMART
	LED_Init();							//初始化LED
	KEY_Init();							//初始化按�?????
	LCD_Init();							//初始化LCD
	tp_dev.init();				   		//触摸屏初始化
	NRF24L01_Init();
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  MX_USART1_UART_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_UART_Receive_IT(&huart1, (uint8_t *)rxBuffer, 1);
  HAL_TIM_Base_Start_IT(&htim2);
  POINT_COLOR=RED;
  while(NRF24L01_Check())
  	{
		LCD_ShowString(30,130,200,16,16,"NRF24L01 Error");
		delay_ms(200);
		LCD_Fill(30,130,239,130+16,WHITE);
		delay_ms(200);
  	}
  POINT_COLOR=BLUE;
  int PvEorPvP=PvE_PvP();
  if (PvEorPvP==1){
	  LCD_Clear(WHITE);
	  POINT_COLOR=BLUE;
	   int SorM=S_M();
	   if (SorM==1){
		   LCD_Clear(WHITE);
		   multiplayer_mode();
	   }else{
		   multi_c_p_mode();
	   }

  }
  else{
	  LCD_Clear(WHITE);
	  singleplayer_mode();
  }
  					//电阻�????
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
//#define OLD
#ifdef OLD
  	u8 key,mode;
  	u16 t=0;
  	//////把你要发送的字符串sprintf进来///////////
  	u8 tmp_buf[33];
  	////////////////////////////////////////
  	LCD_ShowString(30,130,200,16,16,"NRF24L01 OK");
  	 	while(1)
  		{
  			key=KEY_Scan(0);
  			if(key==KEY0_PRES)
  			{
  				mode=0;
  				break;
  			}else if(key==KEY1_PRES)
  			{
  				mode=1;
  				break;
  			}
  			t++;
  			if(t==100)LCD_ShowString(10,150,230,16,16,"KEY0:RX_Mode  KEY1:TX_Mode"); //��˸��ʾ��ʾ��Ϣ
  	 		if(t==200)
  			{
  				LCD_Fill(10,150,230,150+16,WHITE);
  				t=0;
  			}
  			delay_ms(5);
  		}
  	 	LCD_Fill(10,150,240,166,WHITE);//����������ʾ
  	 	POINT_COLOR=BLUE;//��������Ϊ��ɫ
  		if(mode==0)//RXģʽ
  		{
  			LCD_ShowString(30,150,200,16,16,"NRF24L01 RX_Mode");
  			LCD_ShowString(30,170,200,16,16,"Received DATA:");
  			/////////从这里开始是接收数据//////////////////////////
  			NRF24L01_RX_Mode();
  			/////////////////////////////////////////////////////
  			while(1)
  			{
  				////////////////0 return means successfully received//////////////////
  				if(NRF24L01_RxPacket(tmp_buf)==0)//һ�����յ���Ϣ,����ʾ����.
  				/////////////////////////////////////////////////////
  				{
  					tmp_buf[32]=0;//�����ַ���������
  					LCD_ShowString(0,190,lcddev.width-1,32,16,tmp_buf);
  				}else delay_us(100);
  				t++;
  				if(t==10000)//��Լ1s�Ӹı�һ��״̬
  				{
  					t=0;
  					LED0=!LED0;
  				}
  			};
  		}else//TXģʽ
  		{
  			LCD_ShowString(30,150,200,16,16,"NRF24L01 TX_Mode");
  			////////////////////////传输数据模式///////////////////////
  			NRF24L01_TX_Mode();
  			////////////////////////////////////////////////////////
  			mode=' ';//�ӿո�����?
  			while(1)
  			{
  				//////////这里传输数据，返回�?�为TX_OK代表成功////////////
  				if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
  				/////////////////////////////////////////////////
  				{
  					LCD_ShowString(30,170,239,32,16,"Sended DATA:");
  					LCD_ShowString(0,190,lcddev.width-1,32,16,tmp_buf);
  					key=mode;
  					for(t=0;t<32;t++)
  					{
  						key++;
  						if(key>('~'))key=' ';
  						tmp_buf[t]=key;
  					}
  					mode++;
  					if(mode>'~')mode=' ';
  					tmp_buf[32]=0;//���������?
  				}else
  				{
  	 				LCD_Fill(0,170,lcddev.width,170+16*3,WHITE);//������?
  					LCD_ShowString(30,170,lcddev.width-1,32,16,"Send Failed ");
  				};
  				LED0=!LED0;
  				delay_ms(1500);
  			};
  		}
#endif
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_8;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7199;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9999;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

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
