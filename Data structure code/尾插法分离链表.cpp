#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*Linklist;


//β�巨������ԭ��
//CΪ������Ҫ����������A����˳�򣩣�ż������B���� ������ 

int main(){
  Linklist A=(LNode*)malloc(sizeof(LNode));
	A->next=NULL;
	LNode *tailA=A;//ָ��A����β 
	
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
