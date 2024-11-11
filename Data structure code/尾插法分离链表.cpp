#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*Linklist;


//尾插法（保持原序）
//C为大链表，要求奇数进入A链表（顺序），偶数进入B链表 （逆序） 

int main(){
  Linklist A=(LNode*)malloc(sizeof(LNode));
	A->next=NULL;
	LNode *tailA=A;//指向A的链尾 
	
  Linklist B=(LNode*)malloc(sizeof(LNode));
	B->next=NULL;
	int count=1;
	
  Linklist c=(LNode*)malloc(sizeof(LNode));
	c->next=NULL;
	
	while(c->next!=NULL){
		LNode *p=c->next;
		c->next=c->next->next;
		if(count%2==1){
			tailA->next=p;
			p->next=NULL;
			tailA=p;
		}
		else{
			p->next=B->next;
			B->next=p;
		}
		count++;
	}
} 
