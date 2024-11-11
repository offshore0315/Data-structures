#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//////////////////////////////////////////////////////////////////////////
//（2）自定义数据类型(typedef)
//先定义图书数据的数据类型
typedef struct {
	int no;//number
	char name[32];//name
	float price;//price
}STD;
//再定义链表数据类型：
typedef  struct Node{
	STD data; //dada是一个指向STD类型的指针变量
	struct Node *next;
}LNode,*LinkList;



int menu();
int initLinkList(LinkList &L);
int insertLinkList(LinkList L, int i, STD x);
int deleteLinkList(LinkList L, int i,STD &x);
int disLinkList(LinkList L);
int locateLinkList(LinkList L, STD x);
int updateLinkList(LinkList L,int i,STD x);



void main()
{
	int t=1,n;
	float fs=.0f;//有时候不做这个浮点初始化操作程序会报错
	LinkList head;
	int pos;
	STD e;

	while(t){
		n=menu( );//显示主菜单 
		switch(n){
			
		case 1:
			initLinkList(head);
			break;

		case 2:
			printf("请输入插入的位置：");
			scanf("%d",&pos);
			printf("请输入图书的（编号 书名 价格）\n");
			scanf("%d%s%f",&e.no,e.name,&e.price);
			insertLinkList(head, pos, e);
			break;

		case 3:
			printf("请输入删除图书书名：\n");
			scanf("%s",e.name);
			pos=locateLinkList(head,e);
			if(pos==0) 
				printf("不存在该图书数据\n");
			else
			{
				deleteLinkList(head, pos, e);
				printf("删除的图书数据为：%d %10s %7.2f\n",e.no,e.name, e.price);
			}
			break;

		case 4:
			disLinkList(head);
			break;

		case 5:
			printf("请输入需要修改的图书编号、名称、价格，用空格隔开：\n");
			scanf("%d%s%f",&e.no,e.name,&e.price);
			pos=locateLinkList(head,e);
			if(pos==0)
				printf("不存在给定名字的图书\n");
			else
				updateLinkList(head,pos,e);
			break;

		case 0:
			t = 0;
			break;

		default: 
			printf("输入有误！\n");
		
		}
	}
	return 0;
}


int menu(){
	int n;
	//system("cls");//清屏
	printf("****welcome to book management system****\n");
	printf("   1、initialize    2、insert\n");
	printf("   3、delete        4、display\n");
	printf("   5、update        0、exit\n");
	printf("*****************************************\n");
	printf("choose function(0-5)：");
	scanf("%d",&n);
	return n;
}

int initLinkList(LinkList &L)//initLinkList(head);调用时候的写法
//int initLinkList(LinkList *L)//initLinkList(&head);调用时候的写法
{
	L = new LNode;
	L->next = NULL;
	return 1;
}

int insertLinkList(LinkList L, int i, STD x)
{
	LinkList p;
	int j=0;
	p = L;
	while(p && j<i-1){
		p = p->next;
		j++;
	}
	if(!p || j>i-1){
		printf("插入位置不合法\n");
		return 0;
	}
	LinkList q = new LNode;
	q->data = x;
	q->next = p->next;
	p->next = q;
	return 1; 
}

int disLinkList(LinkList L)
{
	L = L->next;
	while(L){
		printf("%d %10s %7.2f\n",L->data.no,L->data.name,L->data.price);
		L = L->next;
	}
	return 1;
}

int locateLinkList(LinkList L, STD x)
{
	int i=1;
	L = L->next;
	while(L!=NULL)
	{
		if(strcmp(L->data.name, x.name)==0)
			return i;
		L=L->next;
		i++;
	}
	return 0;
}

int deleteLinkList(LinkList L, int i, STD &x)
{
	LinkList p,q;
	int j=0;
	p = L;
	while(p && j<i-1){
		p = p->next;
		j++;
	}
	if(p==NULL || p->next==NULL || j>i-1){
		printf("删除位置不合法\n");
		return 0;
	}
	x = p->next->data;
	q = p->next;
	p->next = q->next;
	delete q;
	return 1;
}

int updateLinkList(LinkList L,int i,STD x)
{

	int j = 1;
	LinkList p=L->next;	
	while(p && j<i){
		j++;
		p=p->next;
	}

	p->data = x;

	return 1;
}
