#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*Linklist;


//链表判空 

bool isempty(Linklist L){
	if(L->next==NULL)return true;
	else return false;
}

//求链表长度 
int lengthlink(Linklist L){
	int length=0;
	LNode *p=L->next;
	while(p!=NULL){
		length++;
		p=p->next;
	}
	return length;
	
}

//返回链表中间结点

//按关键字查找加删除

//按关键字查找加插入(有序链表)

//头插法（原地逆置）


int main(){
	
}
