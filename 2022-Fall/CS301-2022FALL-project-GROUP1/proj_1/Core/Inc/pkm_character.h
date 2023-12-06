/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.h
  * @brief   This file contains all the function prototypes for
  *          the gpio.c file
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PKM_CHARACTER_H__
#define __PKM_CHARACTER_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
typedef struct character{
	int id; //识别宝可梦身份，共三种，id为0-2；id对应名字string+形象图片数组array+特殊技能等，因此此struct得以避免存任何数组
	int ATK; // 基础攻击值
	int DEF; // 基础防御值
	int HP; // 血量
	int total_HP; // 本角色总血量
	int level; //bonus 级别，打赢一次升一级，各属性+，可考虑图片变动

	//以下变量是为了方便管理特殊状态设置的，不建议使用，除非显示的图片也想跟着特殊状态一起变
	//特殊状态，为二值属性。不同角色特殊状态下有不同效果，适配需要跨回合发挥作用的技能。
	int is_active_defend; //确认角色有没有正在处于主动防御期间
	int special_state; //防御类角色是否正处于大招期间
	int weapon_state; //是否正在持有武器
	int shield_state; //是否正在持有盾牌
	int easter_state; //是否正在持有免死金牌
}cha;


/* USER CODE END Private defines */
struct character initialize_character(int id); // 初始化角色，返回的是struct对象
//注意！为了规避自动拷贝，以下所有函数都是传入指针而非struct本身，即如果角色变量名为“a”，则以下函数都传入“&a”，而非“a”

int get_id(struct character *p);
int get_ATK(struct character *p);
int get_DEF(struct character *p);
int get_HP(struct character *p);
int get_total_HP(struct character *p);
int get_level(struct character *p);
int is_active_defending(struct character *p);
int is_during_unique_skill_for_id_1(struct character *p);//此参数只对防御类角色有意义
int has_weapon(struct character *p);
int has_shield(struct character *p);
int has_easter(struct character *p);
void get_name(struct character *p,char name[64]);//得到角色名字，需要外部创建一个空的char数组传入本函数，稍后该数组会自动载有名字
void show_character_image(struct character *p,int x, int y);//显示角色形象，目前图片数组等待烧录
void print_basic_info(struct character *p);//在串口上打印以上角色属性与状态信息，包括存活与否

void set_ATK(struct character *p,int atk);//不建议直接修改参数，可能导致逻辑失控
void set_DEF(struct character *p,int def);//不建议直接修改参数
void set_HP(struct character *p,int hp);//不建议直接修改参数
void set_total_HP(struct character *p,int thp);//不建议直接修改参数


// 返回此次发出的攻击值，请在外部手动传输返回的攻击值
int normal_attack_skill(struct character *p, struct character *rivel);//普攻，立刻生效。由zzb调用
int grow_attack_skill(struct character *p, struct character *rivel);//辅助攻击技能，立刻生效。由zzb调用
int unique_skill(struct character *p, struct character *rivel);//大招，立刻生效。由zzb调用


void defend_skill(struct character *p);//由zzb调用，主动使用防御技能，使用后下次攻击触发主动防御效果，否则触发被动防御效果


void respond_clpt(struct character *p, struct character *rivel, char* codes);// 正式游戏时接收对方的信息，自动解码，自动更新对手人偶和自己人偶的状态。


int is_alive(struct character *p);//由zzb调用。检查是否活着，并处理有免死金牌等特殊情况，因此请务必通过此函数检查存活而不要直接访问结构体
void prepare(struct character *p);//活着进入下一局战斗前调用，用于置零各种特效状态以及把血回满。似乎不需要这个功能但是先写了再说
void renew(struct character *p);//刷新角色，各参数全部回到初始状态。不清楚什么情况会需要这个功能，但是先写了再说


void upgrade(struct character *p);//升一级，同时置零所有特殊状态，需要zzb决定升级逻辑，由zzb调用


void weapon(struct character *p);// 捡到武器，由zzb调用
void shield(struct character *p);// 捡到盾牌，由zzb调用
void aid_bag(struct character *p);// 捡到急救包，由zzb调用
void easter_egg(struct character *p);// 捡到免死金牌，由zzb调用

void passive_defend_part(struct character *p, int attack_value);
void active_defend_part(struct character *p, int attack_value);


/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

