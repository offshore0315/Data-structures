#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
  int num;
  char name[20];
  float price;
}STD;
typedef struct LNode
{
	STD data;
	struct LNode *next;
}LNode,*Linklist;
int init(Linklist *H);
int insert(Linklist H,int i,STD x);
int del(Linklist H,int i,STD *x);
int show(Linklist H);
int find(Linklist H,int &i,STD *x);
int menu();
int main()
{
	Linklist H;
	STD x;
	int t=1,n,m;
	while(t){
		n=menu();
		switch(n){
		case 1:init(&H);
		       break;
		case 2: printf("������ͼ�����Ϣ����š��������۸�)\n\n");
		   	    scanf("%d",&x.num);
			    scanf("%s",&x.name);
				scanf("%f",&x.price);
				printf("��������Ҫ�����λ��\n");
				scanf("%d",&m);
				if(insert(H,m,x)){
					printf("������ݳɹ�\n");
				}
			    break;
		case 3:	printf("������ѡ����Ҫɾ����ͼ������\n");
				scanf("&d",&m);
				if(del(H,m,&x)){
					printf("ɾ����ͼ����Ϣ��\n\n");
					printf("���:\tͼ������\t\t\t�۸�\n\n");
					printf("%d\t\t\t%s\t\t\t%.2f\n",x.num,x.name,x.price);
				}
				break;
		case 4:show(H);break;
		case 5:	printf("��������Ҫ���ҵ�ͼ������\n");
				scanf("%s",x.name);
				if(find(H,m,&x)){
					printf("��ͼ���λ����%d\n",m);
				}else{
					printf("��û���ҵ���ͼ��\n");
				}
			    break;
		case 6:t=0;
		       printf("��лʹ��");
			   break;
		default:printf("��������\n");
			   break;
		}
	}
			printf("�����Ѿ��˳�\n");
			return 0;
}
int menu()
{
	int n;
	printf("\t\t\t\t\tWelcome To BMS\n");
	printf("\t\t\t\t****************************\n");
	printf("\t\t\t\t1.��ʼ������   2.¼��ͼ����Ϣ\n\n");
	printf("\t\t\t\t3.ѡ����Ҫɾ����ͼ��    4.��ʾ���е�ͼ����Ϣ\n\n");
	printf("\t\t\t\t5.����ͼ��   6.���������˳�\n\n");
	printf("���������ѡ��\n");
	scanf("%d",&n);
	return n;
}
int init(Linklist *H)
{
	*H=(Linklist)malloc(sizeof(LNode));
	if(*H==NULL)return 0;
	(*H)->next=NULL;
	return 1;
}
int insert(Linklist H,int i,STD x)
{
	Linklist p=H,s;
	int pos=0;
	while(p!=NULL&&pos<i-1){p=p->next;pos=pos+1;}
	if(p==NULL||pos>i-1){printf("����λ�ò�����\n");return 0;}
	s=(Linklist)malloc(sizeof(LNode));
	s->data=x;
	s->next=p->next;p->next=s;
	return 1;
}
int del(Linklist H,int i,STD *x)
{
	Linklist q,p=H;
	int pos=0;
	while(p->next!=NULL&&pos<i-1){p=p->next;pos=pos+1;}
	if(p->next==NULL||pos>i-1){printf("����Ϊ�ջ�ɾ��λ�ò�����\n");return 0;}
	q=p->next;p->next=q->next;*x=q->data;free(q);
	return 1;
}
int show(Linklist H)
{
	Linklist p=H->next;
	if(p==NULL){printf("û������!\n");return 0;}
	while(p)
	{
		printf("%d%s%f\n",p->data.num,p->data.name,p->data.price);
		p=p->next;
	}
	return 1;
}
int find(Linklist H,int &i,STD *x)
{
	Linklist p=H->next;
	int n=1;
	while(p&&n<i){p=p->next;n++;}
	if(p==NULL||n>i){printf("λ�ò��������ܻ�ȡ!\n");return 0;}
	  *x=p->data;
	  return 1;
}



