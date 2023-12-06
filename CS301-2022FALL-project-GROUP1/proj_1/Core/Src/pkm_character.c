#include "pkm_character.h"


#include "main.h"
//#include "usart.h"
//#include "gpio.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
//#include "lcd.h"

extern UART_HandleTypeDef huart1;
static int base_HP = 100;
static int base_ATK = 30;
static int base_DEF = 30;

//此为初始化函数，id=0/1/2，分别对应三种角色,id乱输入则默认选择0号角色

struct character initialize_character(int id){
	char ms[128] = {0};
	sprintf(ms, "initial %d \r\n",id);
	HAL_UART_Transmit(&huart1, (uint8_t*)ms,strlen(ms), HAL_MAX_DELAY);
	if(id == 0){
		// 重攻击类角色, id = 0
		struct character temp = {id,(int)(base_ATK*1.2),(int)(base_DEF/1.5),base_HP,base_HP,1,0,0,0,0,0};
		return temp;
	}else if(id == 1){
		// 重防御类角色, id = 1
		struct character temp = {id,(int)(base_ATK/1.5),(int)(base_DEF*1.8),base_HP,base_HP,1,0,0,0,0,0};
		return temp;
	}else if(id == 2){
		// 重生命类角色, id = 2
		struct character temp = {id,base_ATK,base_DEF,(int)(base_HP*1.6),(int)(base_HP*1.6),1,0,0,0,0,0};
		return temp;
	}else{
		char msg[128] = {0};
		sprintf(msg, "id should be 0,1,2, u enter %d.Therefore we offer the default character(id=0)\r\n",id);
		HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
	}
	struct character temp = {0,(int)(base_ATK*1.5),(int)(base_DEF/2),base_HP,base_HP,1,0,0,0,0,0};
	return temp;
};


// 以下为取属性的函数get，返回此值

int get_id(struct character *p){
	 char msg[64] = {0};
	 sprintf(msg, "id: %d \r\n",p->id);
	 HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
	 return p->id;

};

int get_ATK(struct character *p){
	 char msg[64] = {0};
	 sprintf(msg, "ATK: %d \r\n",p->ATK);
	 HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
	 return p->ATK;
};

int get_DEF(struct character *p){
	 char msg[64] = {0};
	 sprintf(msg, "DEF: %d \r\n",p->DEF);
	 HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
	 return p->DEF;

};

int get_HP(struct character *p){
	 char msg[64] = {0};
	 sprintf(msg, "current HP: %d \r\n",p->HP);
	 HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
	 return p->HP;

};

int get_total_HP(struct character *p){
	 char msg[64] = {0};
	 sprintf(msg, "max HP value: %d \r\n",p->total_HP);
	 HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
	 return p->total_HP;

};

int get_level(struct character *p){
	 char msg[64] = {0};
	 sprintf(msg, "level: %d \r\n",p->level);
	 HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
	 return p->level;
};

int is_active_defending(struct character *p){
	 char msg[64] = {0};
	 if(p->is_active_defend == 1){
		 sprintf(msg, "active defending\r\n");
	 }else{
		 sprintf(msg, "passive defending\r\n");
	 }
	 HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
	 return p->is_active_defend;
};

int is_during_unique_skill_for_id_1(struct character *p){
	 char msg[64] = {0};
	 if(p->special_state == 1){
		 sprintf(msg, "id 1 is under unique skill\r\n");
	 }else{
		 sprintf(msg, "id 1 is not under unique skill\r\n");
	 }
	 HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
	 return p->special_state;
};

int has_weapon(struct character *p){
	char msg[64] = {0};
	if(p->weapon_state == 1){
			 sprintf(msg, "id %d has a weapon now\r\n",p->id);
		 }else{
			 sprintf(msg, "id %d has no weapon\r\n",p->id);
		 }
	HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
	 return p->weapon_state;
};

int has_shield(struct character *p){
	char msg[64] = {0};
	if(p->shield_state == 1){
			 sprintf(msg, "id %d has a shield now\r\n",p->id);
		 }else{
			 sprintf(msg, "id %d has no shield\r\n",p->id);
		 }
	HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
	 return p->shield_state;
};

int has_easter(struct character *p){
	char msg[64] = {0};
	if(p->easter_state == 1){
			 sprintf(msg, "id %d has an easter egg so u can revive after next death\r\n",p->id);
		 }else{
			 sprintf(msg, "id %d has no easter egg\r\n",p->id);
		 }
	HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
	 return p->easter_state;
};

// 由于要返回相应字符串的指针才能确切的返回数组,为了避免过多和指针交互导致不必要的Bug，
// 因此此处选择在外部创建空的char name[64],再传入本函数，执行后外部创建的空name数组会自动塞入名字
void get_name(struct character *p, char name[64]){
	//struct character a = (*p);
	char msg[64] = {0};
	if(p->id == 0){
		sprintf(name, "Pikachu");//皮卡丘，我乱放的，可以根据画出来的图片改
		sprintf(msg, "name: Pikachu \r\n");
	}else if(p->id == 1){
		sprintf(name, "Squirtle");//杰尼龟
		sprintf(msg, "name: Squirtle \r\n");
	}else if(p->id == 2){
		sprintf(name, "Meowth");//火箭队喵喵
		sprintf(msg, "name: Meowth \r\n");
	}
	HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
}

//根据不同角色决定展示不同图像,x与y为图片展示的左上角位置,
//建议图片大小统一为100*100或80*80,不然太大了会影响属性和其他功能显示以及拖慢烧录速度
//bonus：我打算每个角色两张图，1-2级为幼体，3级以上为成年体，共需六个图片
void show_character_image(struct character *p,int x, int y){
	/*// 从demo里扒下来的画图函数，x,y为图左上角点，画图是先画左边的列，再一列一列的往右边推进。由于其中部分函数需要引入LCD相关的lcd.h文件，所以等后期画图方面的文件准备好了再具体改
	uint8_t temp, t, k;
	uint16_t y0 = y;
	int mode = 0;
	int size = 80;

	for (k = 0; k < size; k++) {
		for (t = 0; t < size; t++) {
			temp = warning_img2[k * size + t]; // 此处图片数组将会更换成需要的数组
			if (temp & 0x80)
				LCD_Fast_DrawPoint(x, y, POINT_COLOR);
			else if (mode == 0)
				LCD_Fast_DrawPoint(x, y, BACK_COLOR);
			temp <<= 1;
			y++;
			if (y >= lcddev.height)
				return;		//超区域了
			if ((y - y0) == size) {
				y = y0;
				x++;
				if (x >= lcddev.width)
					return;	//超区域了
				break;
			}
		}
	}*/

	char msg[128] = {0};
	if(p->id == 0){
		if(p->level>=3){
			sprintf(msg, "image waited for id 0, and in the stage 1");
		}else{
			sprintf(msg, "image waited for id 0, and in the stage 2");
		}
	}else if(p->id == 1){
		if(p->level>=3){
			sprintf(msg, "image waited for id 1, and in the stage 1");
		}else{
			sprintf(msg, "image waited for id 1, and in the stage 2");
		}
	}else if(p->id == 2){
		if(p->level>=3){
			sprintf(msg, "image waited for id 2, and in the stage 1");
		}else{
			sprintf(msg, "image waited for id 2, and in the stage 2");
		}
	}
	HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
}

void print_basic_info(struct character *p){
	char begin[32] = {0};
	sprintf(begin,"\r\n character information:\r\n");
	HAL_UART_Transmit(&huart1,(uint8_t*)begin,strlen(begin), HAL_MAX_DELAY);
    char msg[64] = {0};
	is_alive(p);
	get_id(p);
	get_name(p,msg);
	get_ATK(p);
	get_DEF(p);
	get_HP(p);
	get_total_HP(p);
	get_level(p);
	is_active_defending(p);
	if(p->id == 1){
		is_during_unique_skill_for_id_1(p);
	}
	has_weapon(p);
	has_shield(p);
	has_easter(p);
	char over[32] = {0};
	sprintf(over,"--------------\r\n");
	HAL_UART_Transmit(&huart1, (uint8_t*)over,strlen(over), HAL_MAX_DELAY);
}

// 以下为设置属性函数，返回设置后的值。有些属性有特殊的关联导致不能给予设置权限，四个基本属性开放权限，
// 但是由于功能函数本类已实现，一般不需要外部调用set函数

void set_ATK(struct character *p,int atk){
	 p->ATK = atk;
	 char msg[64] = {0};
	 sprintf(msg, "ATK: %d \r\n",p->ATK);
	 HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
	 return;

};

void set_DEF(struct character *p, int def){
	p->DEF = def;
	 char msg[64] = {0};
	 sprintf(msg, "DEF: %d \r\n",p->DEF);
	 HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
	 return;

};

void set_HP(struct character *p, int hp){
	 if(hp > p->total_HP){
		 p->HP = p->total_HP;
	 }else{
		 p->HP = hp;
	 }
	 char msg[64] = {0};
	 sprintf(msg, "HP: %d \r\n",p->HP);
	 HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
	 return;
};

void set_total_HP(struct character *p,int total_hp){
	 p->total_HP = total_hp;
	 char msg[64] = {0};
	 sprintf(msg, "max HP value: %d \r\n",p->total_HP);
	 HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
	 return;

};

// 攻击函数

// 此为普攻函数，直接扔基础值，但是有几率暴击，暴击加成10%，暴击率统一40%；
int normal_attack_skill(struct character *p, struct character *rivel){
	int possibility = rand()%100 + 1;
	int atk_value = p->ATK;
	int judge = 0;
	if(possibility >= 60){
		atk_value  = atk_value + (int)(atk_value*0.1);
		judge = 1;
	}
	if(p->weapon_state == 1){//回应武器特效
		    atk_value += 20;
			p->weapon_state = 0;
	}
	//由于还不确定通信模块如何传输信息，所以此处用串口暂时代替无线通信来报告攻击情况
	char msg[128] = {0};
	if(judge == 0){
		sprintf(msg, "u attack: %d !! \r\n",atk_value);
	}else{
		sprintf(msg, "u attack and cause a critical strike: %d !! \r\n",atk_value);
	}
	HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);

	//对手人偶更新状态：
	defend_clpt_rivel(rivel,atk_value);

	return atk_value;
}

// 计算对手人偶的攻击力，不可外部调用
int normal_attack_skill_rivel(struct character *p){
	int possibility = rand()%100 + 1;
	int atk_value = p->ATK;
	int judge = 0;
	if(possibility >= 60){
		atk_value  = atk_value + (int)(atk_value*0.1);
		judge = 1;
	}
	if(p->weapon_state == 1){//回应武器特效
		    atk_value += 20;
			p->weapon_state = 0;
	}
	//由于还不确定通信模块如何传输信息，所以此处用串口暂时代替无线通信来报告攻击情况
	char msg[128] = {0};
	if(judge == 0){
		sprintf(msg, "u attack: %d !! \r\n",atk_value);
	}else{
		sprintf(msg, "u attack and cause a critical strike: %d !! \r\n",atk_value);
	}
	HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);


	return atk_value;
}

//这个是自身提升技能，此技能在本回合造成普攻一半伤害，
//但是会永久提升4点短板属性，为博弈增添一份不确定性.不返回值
int grow_attack_skill(struct character *p, struct character *rivel){
	int atk_value = (int)(p->ATK / 2);
	if(p->weapon_state == 1){
		atk_value += 20;
		p->weapon_state = 0;
	}

	if(p->id == 0){
			//重视攻击的角色提升防御4点
			p->DEF += 4;

			//由于还不确定通信模块如何传输信息，所以此处用串口暂时代替无线通信来报告攻击情况
			char msg[128] = {0};
			sprintf(msg, "u attack: %d, but ur defend value is: %d now \r\n",atk_value,p->DEF);
			HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);

	}else if(p->id == 1){
			// 重视防御的角色提升攻击4点
			p->ATK += 4;

			//由于还不确定通信模块如何传输信息，所以此处用串口暂时代替无线通信来报告攻击情况
			char msg[128] = {0};
			sprintf(msg, "u attack: %d, but ur attack value is: %d now \r\n",atk_value,p->ATK);
			HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);

	}else if(p->id == 2){
	        // 重视生命的角色的防御和攻击各自提升2点
			p->ATK += 2;
			p->DEF += 2;

			//由于还不确定通信模块如何传输信息，所以此处用串口暂时代替无线通信来报告攻击情况
			char msg[128] = {0};
			sprintf(msg, "u attack: %d, but ur defend and attack value are: %d and %d now \r\n",atk_value,p->DEF,p->ATK);
			HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
	}
	//对手人偶更新状态：
	defend_clpt_rivel(rivel,atk_value);
	return atk_value;
}

// 计算对手人偶攻击力用的，不可外部调用
int grow_attack_skill_rivel(struct character *p){
	int atk_value = (int)(p->ATK / 2);
	if(p->weapon_state == 1){
		atk_value += 20;
		p->weapon_state = 0;
	}

	if(p->id == 0){
			//重视攻击的角色提升防御4点
			p->DEF += 4;

			//由于还不确定通信模块如何传输信息，所以此处用串口暂时代替无线通信来报告攻击情况
			char msg[128] = {0};
			sprintf(msg, "u attack: %d, but ur defend value is: %d now \r\n",atk_value,p->DEF);
			HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);

	}else if(p->id == 1){
			// 重视防御的角色提升攻击4点
			p->ATK += 4;

			//由于还不确定通信模块如何传输信息，所以此处用串口暂时代替无线通信来报告攻击情况
			char msg[128] = {0};
			sprintf(msg, "u attack: %d, but ur attack value is: %d now \r\n",atk_value,p->ATK);
			HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);

	}else if(p->id == 2){
	        // 重视生命的角色的防御和攻击各自提升2点
			p->ATK += 2;
			p->DEF += 2;

			//由于还不确定通信模块如何传输信息，所以此处用串口暂时代替无线通信来报告攻击情况
			char msg[128] = {0};
			sprintf(msg, "u attack: %d, but ur defend and attack value are: %d and %d now \r\n",atk_value,p->DEF,p->ATK);
			HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
	}

	return atk_value;
}

// 此为大招函数,不同角色不同效果
// 大招过后可能导致角色死亡，记得查看角色存货
int unique_skill(struct character *p,struct character *rivel){
	int atk_value = p->ATK;

	if(p->id == 0){
		//重视攻击的角色的大招是绝地反击，根据剩余血量决定本次攻击的提升，血越少本次攻击值越高，最低提升5%攻击力，最高提升50%
		atk_value = p->ATK + (int)(0.05 * (p->ATK) + 0.45*(double)p->ATK * (double)(p->total_HP-p->HP)/((double)p->total_HP));

		if(p->weapon_state == 1){//回应武器特效
			    atk_value += 20;
				p->weapon_state = 0;
		}

		//由于还不确定通信模块如何传输信息，所以此处用串口暂时代替无线通信来报告攻击情况
		char msg[128] = {0};
		sprintf(msg, "counterattack skill: \r\n 1. enhanced attack: %d \r\n",atk_value);
		HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);

	}else if(p->id == 1){
		// 重视防御的角色的大招是献祭，降低相当于最大血量5%的血量，造成自身防御值一半的伤害，并免疫下次对手攻击
		// 如果血不够减，则造成相当于自身防御值的全部伤害，不会扣血但是下一次攻击也不会免疫对手
		atk_value = (int)(p->DEF / 2);

		if(p->HP > (int)((double)p->total_HP*0.05)){
			p->HP = p->HP - (int)((double)p->total_HP*0.05);
			p->special_state = 1;
		}else{
			atk_value = p->DEF;
		}
		if(p->weapon_state == 1){//回应武器特效
			    atk_value += 20;
				p->weapon_state = 0;
		}

		//由于还不确定通信模块如何传输信息，所以此处用串口暂时代替无线通信来报告攻击情况
		char msg[128] = {0};
		if(p->special_state == 1){
			sprintf(msg, "Sacrifice skill: \r\n 1. attack: %d \r\n 2. burn life. So ur HP: %d now \r\n 3. blessing. u won't get hurt the next turn \r\n",atk_value,p->HP);
		}else{
			sprintf(msg, "Sacrifice skill: \r\n 1. attack: %d \r\n u have no enough life to burn, so u have no a blessing the next turn, and ur HP now is %d \r\n",atk_value,p->HP);
		}
		HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);

	}else if(p->id == 2){
        // 重视生命的角色大招是吸血，造成相当于20%自身最大生命的伤害，并给自己恢复相当于5%最大生命的生命值，
		// 但是攻击+吸血值允许被对方的防御值挡下（因为不想访问对方的宝可梦属性来确认是否处于特殊状态）
		atk_value = (int)((double)p->total_HP*0.2);
		p->HP = p->HP + (int)((double)p->total_HP*0.05);
		if(p->HP > p->total_HP){
			p->HP = p->total_HP;
		}
		if(p->weapon_state == 1){//回应武器特效
			    atk_value += 20;
				p->weapon_state = 0;
		}

		//由于还不确定通信模块如何传输信息，所以此处用串口暂时代替无线通信来报告攻击情况
		char msg[128] = {0};
		sprintf(msg, "Vampire Skill: \r\n 1.attack: %d \r\n 2.recover, so ur HP: %d \r\n",atk_value,p->HP);
		HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);

	}
	//对手人偶更新状态：
	defend_clpt_rivel(rivel,atk_value);
	return atk_value;
}

//用于更新对手人偶计算对手人偶攻击值的备份函数，不可被外部调用。
int unique_skill_rivel(struct character *p){
	int atk_value = p->ATK;

	if(p->id == 0){
		//重视攻击的角色的大招是绝地反击，根据剩余血量决定本次攻击的提升，血越少本次攻击值越高，最低提升5%攻击力，最高提升50%
		atk_value = p->ATK + (int)(0.05 * (p->ATK) + 0.45*(double)p->ATK * (double)(p->total_HP-p->HP)/((double)p->total_HP));

		if(p->weapon_state == 1){//回应武器特效
			    atk_value += 20;
				p->weapon_state = 0;
		}

		//由于还不确定通信模块如何传输信息，所以此处用串口暂时代替无线通信来报告攻击情况
		char msg[128] = {0};
		sprintf(msg, "counterattack skill: \r\n 1. enhanced attack: %d \r\n",atk_value);
		HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);

	}else if(p->id == 1){
		// 重视防御的角色的大招是献祭，降低相当于最大血量5%的血量，造成自身防御值一半的伤害，并免疫下次对手攻击
		// 如果血不够减，则造成相当于自身防御值的全部伤害，不会扣血但是下一次攻击也不会免疫对手
		atk_value = (int)(p->DEF / 2);

		if(p->HP > (int)((double)p->total_HP*0.05)){
			p->HP = p->HP - (int)((double)p->total_HP*0.05);
			p->special_state = 1;
		}else{
			atk_value = p->DEF;
		}
		if(p->weapon_state == 1){//回应武器特效
			    atk_value += 20;
				p->weapon_state = 0;
		}

		//由于还不确定通信模块如何传输信息，所以此处用串口暂时代替无线通信来报告攻击情况
		char msg[128] = {0};
		if(p->special_state == 1){
			sprintf(msg, "Sacrifice skill: \r\n 1. attack: %d \r\n 2. burn life. So ur HP: %d now \r\n 3. blessing. u won't get hurt the next turn \r\n",atk_value,p->HP);
		}else{
			sprintf(msg, "Sacrifice skill: \r\n 1. attack: %d \r\n u have no enough life to burn, so u have no a blessing the next turn, and ur HP now is %d \r\n",atk_value,p->HP);
		}
		HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);

	}else if(p->id == 2){
        // 重视生命的角色大招是吸血，造成相当于20%自身最大生命的伤害，并给自己恢复相当于5%最大生命的生命值，
		// 但是攻击+吸血值允许被对方的防御值挡下（因为不想访问对方的宝可梦属性来确认是否处于特殊状态）
		atk_value = (int)((double)p->total_HP*0.2);
		p->HP = p->HP + (int)((double)p->total_HP*0.05);
		if(p->HP > p->total_HP){
			p->HP = p->total_HP;
		}
		if(p->weapon_state == 1){//回应武器特效
			    atk_value += 20;
				p->weapon_state = 0;
		}

		//由于还不确定通信模块如何传输信息，所以此处用串口暂时代替无线通信来报告攻击情况
		char msg[128] = {0};
		sprintf(msg, "Vampire Skill: \r\n 1.attack: %d \r\n 2.recover, so ur HP: %d \r\n",atk_value,p->HP);
		HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);

	}
	return atk_value;
}



//防御函数
//用于让zzb调用的放在显示屏里的按钮函数，为使用防御技能
//使用后，下次对手攻击自己可以全力防御，即发挥全部防御值来抵消对手攻击值，具体看主动防御part
void defend_skill(struct character *p){
	p->is_active_defend = 1;

	char msg[128] = {0};
	sprintf(msg, "u use defend skill, it would make a difference the next turn\r\n");
	HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
}

// 被动防御部分，不是用来给外部调用的，接收攻击(信号传到)时自动调用,只有一半防御力，触发后扣相应血量。
// 接招后可能导致死亡，需要在外部用is_alive查看存活情况
void passive_defend_part(struct character *p, int attack_value){
	int def_value = (int)((double)p->DEF/2);
	//int judge = 0;

	if(p->id == 1 && p->special_state == 1){//此处回应此前的防御角色的大招
		p->special_state = 0;
		attack_value = 0;
		char mss[128] = {0};
		sprintf(mss, "u have sacrificed urself so u would get no hurt this turn \r\n");
		HAL_UART_Transmit(&huart1, (uint8_t*)mss,strlen(mss), HAL_MAX_DELAY);
	};

	if(p->shield_state == 1){//回应盾牌特效
			def_value += 20;
			p->shield_state = 0;
	}

	if(attack_value - def_value > 0){
		int lose = attack_value - def_value;
		if (p->HP-lose>=0){
					p->HP -= lose;
				}
				else p->HP =0;
		char ms[128] = {0};
		sprintf(ms, "u lost HP: -%d and now only %d / %d is left \r\n",lose,p->HP,p->total_HP);
		HAL_UART_Transmit(&huart1, (uint8_t*)ms,strlen(ms), HAL_MAX_DELAY);
	};

	char msg[128] = {0};
	sprintf(msg, "u passively defend: %d !! \r\n",def_value);
	HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);

	return;

}

// 主动防御部分，不是用来给外部调用的，触发全部防御力，
// 接招后可能导致角色死亡，请在外部统一用is_alive查看存活情况
void active_defend_part(struct character *p, int attack_value){
	int def_value = p->DEF;

	if(p->id == 1 && p->special_state == 1){//此处回应此前的防御角色的大招
		p->special_state = 0;
		attack_value = 0;
		char mss[128] = {0};
		sprintf(mss, "u have sacrificed urself the last turn, so u would get no hurt this turn \r\n");
		HAL_UART_Transmit(&huart1, (uint8_t*)mss,strlen(mss), HAL_MAX_DELAY);

	};

	if(p->shield_state == 1){//回应盾牌特效
			def_value += 20;
			p->shield_state = 0;
	}

	if(attack_value - def_value > 0){
		int lose = attack_value - def_value;
		if (p->HP-lose>=0){
			p->HP -= lose;
		}//血量不能为负数
		else p->HP =0;

		char ms[128] = {0};
		sprintf(ms, "ur defend value this turn: %d \r\n u lost HP: -%d and now only %d / %d is left \r\n",p->DEF,lose,p->HP,p->total_HP);
		HAL_UART_Transmit(&huart1, (uint8_t*)ms,strlen(ms), HAL_MAX_DELAY);
	};

	return;
}

//由hrh他们调用，此函数放在无线通信的中断里
//此函数会根据此前是否使用主动防御技能来决定是否要调用主动防御技能还是被动防御技能。
// 接招后角色可能死亡，需要zzb在外部每次刷新屏幕时调用is_alive检查是否存活，
// 或者由hrh在回调函数中调用完此函数后再接着调用is_alive进行存活检查

// 此函数专门用来更新对手人偶的受攻击后的态，不需要外部调用，自己的人偶发起攻击函数时会自动调用
void defend_clpt_rivel(struct character *p,int attack_value){
	if(p->is_active_defend == 1){
				p->is_active_defend = 0;
				active_defend_part(p, attack_value);
			}else{
				passive_defend_part(p, attack_value);
			}
}

//此函数专门用于在对手发起攻击后，接收到信息是调用，自动解码，同时更新自己人偶和对手人偶的状态
void respond_clpt(struct character *p, struct character *rivel, char* codes){
	//此处的p是自己，rivel是对手的人偶，codes是对方做出的操作加密
	//codes格式：前三位密钥：“god”,第四位是操作对应密码，为一位整数，为1-8

//	if(strlen(codes) != 4){
//		return; // 长度不对，退出
//	}

	char s1 = codes[0];
	char s2 = codes[1];
	char s3 = codes[2];
//
//	if(strcmp(s1,"g") != 0 || strcmp(s2,"o") != 0 || strcmp(s3,"d") != 0){
//		return; //密钥不对，退出。
//	}

	char temp = codes[3]; //获取操作密码
	int decode = (int)temp - 48;
	if(decode < 1 || decode > 8){
		return; // 密码超出范围，不对，退出。
	}

	int attack_value = 0;
	if(decode == 1){ // 普攻！
		attack_value = normal_attack_skill_rivel(rivel);
	}else if(decode == 2){ // 辅助攻击！
		attack_value = grow_attack_skill_rivel(rivel);
	}else if(decode == 3){ // 大招！
		attack_value = unique_skill_rivel(rivel);
	}else if(decode == 4){ // 对方在主动防御！
		defend_skill(rivel);
	}else if(decode == 5){ // 对方捡到了武器
		weapon(rivel);
	}else if(decode == 6){// 对方捡到盾牌
		shield(rivel);
	}else if(decode == 7){ // 对方捡到血包
		aid_bag(rivel);
	}else if(decode == 8){ // 对方捡到免死金牌
		easter_egg(rivel);
	}// 以上，对手人偶状态更新完毕。


	if(decode <= 3){ // 只有三个攻击技能会触发防御响应，剩下五个事件不能触发防御响应。
		if(p->is_active_defend == 1){
			p->is_active_defend = 0;
			active_defend_part(p, attack_value);
		}else{
			passive_defend_part(p, attack_value);
		}
	}
}


//状态检查与设置函数
//检查角色血量是否<=0，并处理包括复活在内的特殊死亡情况。
//为了防止复活等特殊状态失效，请不要直接访问get_HP来检查是否存活
//活着返回1，死了返回0
int is_alive(struct character *p){
	char msg[128] = {0};

	if(p->HP <= 0){
		if(p->easter_state == 1){
			p->HP = (int)((p->total_HP) * 0.2);
			p->special_state = 0;
			p->is_active_defend = 0;
			p->weapon_state = 0;
			p->shield_state = 0;
			p->easter_state = 0;

			sprintf(msg, "u revive, so now u have HP: %d / %d \r\n",p->HP,p->total_HP);
			HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);

			return 1;
		}else{
			p->HP = 0;
			p->special_state = 0;
			p->is_active_defend = 0;
			p->weapon_state = 0;
			p->shield_state = 0;
			p->easter_state = 0;

			sprintf(msg, "u die \r\n");
			HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);

			return 0;
		}
	}else{
		sprintf(msg, "u are still alive with HP: %d / %d \r\n",p->HP,p->total_HP);
		HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
		return 1;
	}
}

// 进入下一句游戏前调用此函数来置零角色除了攻击、防御与最大生命以外的状态
// 并回满血
void prepare(struct character *p){
	p->HP = p->total_HP;
	p->special_state = 0;
	p->is_active_defend = 0;
	p->weapon_state = 0;
	p->shield_state = 0;
	p->easter_state = 0;
}

// 刷新角色，各参数全部回到初始状态
void renew(struct character *p){
	p->special_state = 0;
	p->is_active_defend = 0;
	p->weapon_state = 0;
	p->shield_state = 0;
	p->easter_state = 0;
	if(p->id == 0){
		p->ATK = (int)(base_ATK*1.2);
		p->DEF =  (int)(base_DEF/1.5);
		p->HP = base_HP;
		p->total_HP = base_HP;
		}else if(p->id == 1){
			p->ATK = (int)(base_ATK/1.5);
			p->DEF = (int)(base_DEF*1.8);
			p->HP = base_HP;
			p->total_HP = base_HP;
		}else if(p->id == 2){
			// 重生命类角色, id = 2
			p->ATK = base_ATK;
			p->DEF = base_DEF;
			p->HP = (int)(base_HP*1.6);
			p->total_HP = (int)(base_HP*1.6);
		}
}

//bonus项目，升一级角色，此角色的基本参数增加，但是所有特殊状态消失。需要外部用户决定升级触发逻辑
void upgrade(struct character *p){
	p->level++;
	p->ATK += 10;
	p->DEF += 10;
	p->total_HP += 20;
	prepare(p);

	char msg[128] = {0};
	sprintf(msg, "u get promoted and ur level is %d now \r\n", p->level);
	HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);

}

//bonus 项目，特殊道具，特殊道具的出现逻辑请外部用户决定

//武器，下一次攻击触发攻击力额外+20,效果不叠加
void weapon(struct character *p){
	p->weapon_state = 1;
	char msg[128] = {0};
	sprintf(msg, "u get a weapon so u would have 20 more attack the next turn \r\n");
	HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
}

//盾牌，下一次防御触发防御力额外+20
void shield(struct character *p){
	p->shield_state = 1;
	char msg[128] = {0};
	sprintf(msg, "u get a shield so u would have 20 more defend the next turn \r\n");
	HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
}

//急救包，生命力恢复20，但不能超过生命值上限
void aid_bag(struct character *p){
	p->HP += 20;
	if(p->HP > p->total_HP){
		p->HP = p->total_HP;
	}
	char msg[128] = {0};
	sprintf(msg, "u get first aid so u would have 20 more HP, now ur HP: %d / %d \r\n",p->HP,p->total_HP);
	HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
}

//复活节彩蛋，你可以免于一死，但复活效果不能叠加，复活后所有特殊效果丢失，且生命值为总血量20%
void easter_egg(struct character *p){
	p->easter_state = 1;
	char msg[128] = {0};
	sprintf(msg, "u get an easter egg so u would have one chance to revive\r\n");
	HAL_UART_Transmit(&huart1, (uint8_t*)msg,strlen(msg), HAL_MAX_DELAY);
}
