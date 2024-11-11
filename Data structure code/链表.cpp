#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*Linklist;

//�����п� 
bool isLinklistEmpty(Linklist head){
	if(head->next==NULL)
	return true;
	else return false;
}

//�������� 
int listlen(Linklist L){
	int length=0;
	LNode *p=L->next;
	while(p!=NULL){
		length++;
		p=p->next;
	}
	printf("������ = %d\n",length);
	return length;
}

//���������м���
LNode *findMidNode(Linklist L){
	int length=0;
	LNode *p=L->next;
	while(p!=NULL){
		length++;
		p=p->next;
	}
	int count=0;
	p=L->next;
	while(p!=NULL){
		count++;
		if(count==length/2)
		break;
		p=p->next;
	}
	return p;
} 

//���ؼ��ֲ��Ҽ�ɾ��
void deleteX(Linklist L,int x){
	LNode *pre=L;
	LNode *p=pre->next;
	while(p!=NULL){
	if(p->data==x)
	{
		LNode *q=p;
		p=p->next;
		pre->next=p;
		free(q);
	}
	else{
		pre=p;
		p-p->next;
	}
	}
} 


//���ؼ��ֲ��ҼӲ���(��������)
void InsertX(Linklist L,int x){
	LNode *pre=L;
	LNode *p=pre->next;
	while(p!=NULL){
		if(p->data>x)
		{
			break;
		}
		else{
			pre=p;
			p=p->next;
		}
	}
		LNode *q=(LNode*)malloc(sizeof(LNode));
		q->data=x;
		q->next=p;
		pre->next=q;
}


//ͷ�巨��ԭ�����ã�
void ListReserve(Linklist L){
	//����ͷ��� 
  Linklist head=(LNode*)malloc(sizeof(LNode));
  head->next=NULL;
 
	while(L->next!=NULL){
		LNode *p=L->next;
		L->next=L->next->next;
		p->next=head->next;
		head->next=p;
	}
	L->next=head->next;
	free(head);
} 


int main(){
	 // ��ʼ������ͷ�ڵ�
    Linklist L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;

	bool isEmpty = isLinklistEmpty(L);
    if (isEmpty) {
        printf("The linked list is empty.\n");
    } else {
        printf("The linked list is not empty.\n");
    }
    
}

