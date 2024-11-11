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
		case 2: printf("请输入图书的信息（序号、书名、价格)\n\n");
		   	    scanf("%d",&x.num);
			    scanf("%s",&x.name);
				scanf("%f",&x.price);
				printf("请输入想要插入的位置\n");
				scanf("%d",&m);
				if(insert(H,m,x)){
					printf("添加数据成功\n");
				}
			    break;
		case 3:	printf("请输入选择想要删除的图书的序号\n");
				scanf("&d",&m);
				if(del(H,m,&x)){
					printf("删除的图书信息是\n\n");
					printf("序号:\t图书名称\t\t\t价格\n\n");
					printf("%d\t\t\t%s\t\t\t%.2f\n",x.num,x.name,x.price);
				}
				break;
		case 4:show(H);break;
		case 5:	printf("请输入想要查找的图书名称\n");
				scanf("%s",x.name);
				if(find(H,m,&x)){
					printf("该图书的位置是%d\n",m);
				}else{
					printf("还没有找到该图书\n");
				}
			    break;
		case 6:t=0;
		       printf("感谢使用");
			   break;
		default:printf("输入有误\n");
			   break;
		}
	}
			printf("程序已经退出\n");
			return 0;
}
int menu()
{
	int n;
	printf("\t\t\t\t\tWelcome To BMS\n");
	printf("\t\t\t\t****************************\n");
	printf("\t\t\t\t1.初始化链表   2.录入图书信息\n\n");
	printf("\t\t\t\t3.选择想要删除的图书    4.显示所有的图书信息\n\n");
	printf("\t\t\t\t5.查找图书   6.结束程序退出\n\n");
	printf("请输入你的选择\n");
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
	if(p==NULL||pos>i-1){printf("插入位置不合理\n");return 0;}
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
	if(p->next==NULL||pos>i-1){printf("链表为空或删除位置不合理\n");return 0;}
	q=p->next;p->next=q->next;*x=q->data;free(q);
	return 1;
}
int show(Linklist H)
{
	Linklist p=H->next;
	if(p==NULL){printf("没有数据!\n");return 0;}
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
	if(p==NULL||n>i){printf("位置不合理，不能获取!\n");return 0;}
	  *x=p->data;
	  return 1;
}



