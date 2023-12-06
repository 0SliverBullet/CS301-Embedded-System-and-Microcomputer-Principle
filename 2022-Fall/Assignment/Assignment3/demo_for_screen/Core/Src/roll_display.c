
#include "roll_display.h"
#include <string.h>
#include <stdlib.h>

Linkedlist *creatList(int size)       //创建一个普通的链表
{
	int i;
	Linkedlist *head = (Linkedlist*)malloc(sizeof(Linkedlist));
	Linkedlist *temp = head;
	for (i=0;i<size;i++)
	{
		Linkedlist *tail = (Linkedlist*)malloc(sizeof(Linkedlist));  //节点
		tail->next = NULL;    //确保下一次迭代时为空
		temp->next = tail;    //指向下一个节点
		temp = tail;          //迭代
	}
	return head;
}

Linkedlist *closeList(Linkedlist *list)				//闭合一个链表,返回末尾指针
{
	Linkedlist *temp = list;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = list;
	return temp;
}


