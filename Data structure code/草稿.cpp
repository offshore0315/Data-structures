#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*Linklist;


//�����п� 

bool isempty(Linklist L){
	if(L->next==NULL)return true;
	else return false;
}

//�������� 
int lengthlink(Linklist L){
	int length=0;
	LNode *p=L->next;
	while(p!=NULL){
		length++;
		p=p->next;
	}
	return length;
	
}

//���������м���

//���ؼ��ֲ��Ҽ�ɾ��

//���ؼ��ֲ��ҼӲ���(��������)

//ͷ�巨��ԭ�����ã�


int main(){
	
}
