#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	int num;
	char name[20];
	float price;
}STD;
typedef struct{
	STD  *elem;
	int listSize;
	int length; 
}SqList;
int menu();
int init(SqList *H,int max);
int insert(SqList *H,int i,STD x);
STD del(SqList *H,int i);
int show(SqList H);
int find(SqList H,STD x);
int main()
{
	SqList H;
	STD x,y;
	int t = 1,maxsize = 0,n,i = 0,k,choice,select = 0,a = 0,flag = 0;
	while(t){
		n = menu();
		switch(n){
		case 1:printf("输入想要录入图书的总数\n");
				scanf("%d",&maxsize);
				init(&H,maxsize);
				select = 1;
				system("pause");
				break;
		case 2:
				if(select == 0){
					printf("还没有输入图书总数\n\n");
				}else{
					while(1){
						printf("是否继续录入\n\n");
						printf("继续录入输入1，终止输入0\n");
						scanf("%d",&choice);
						if(choice == 1){
						printf("请输入图书的信息(序号、书名、价格) \n\n");
						scanf("%d",&x.num);
						scanf("%s",x.name);
						scanf("%f",&x.price);
						printf("请输入想要插入的位置\n");
						scanf("%d",&i);
						k = insert(&H,i,x);
						while(k == 0){
							scanf("%d",&i);
							k = insert(&H,i,x);
							if(k == 1){
								break;
							}
						}
						}else if(choice == 0){
							break;
						}else{
							printf("输入有误重新输入\n\n");
						}
					}
				}
				system("pause");
				break;
		case 3:
				if(select == 0){
					printf("还没有输入图书总数\n\n");
				}else if(H.length != 0){
					printf("请输入选择想要删除的图书的序号\n");
					scanf("%d",&i);
					for(a = 0;a < H.length;a++){
						if(H.elem[a].num == i){
							flag = 1;
							break;
						}else{
							flag = 0;
						}
					}
					while(!flag){
						printf("删除序号输入有误,请重新输入\n");
						scanf("%d",&i);
						for(a = 0;a < H.length;a++){
						if(H.elem[a].num == i){
							flag = 1;
							break;
						}else{
							flag = 0;
						}
					}
				}
					y = del(&H,i);
					printf("删除的图书信息是\n\n");
					printf("序号:\t图书名称\t\t\t价格\n\n");
					printf("%d\t%s\t\t\t%.2f\n",y.num,y.name,y.price);
				}else{
					printf("还没有录入图书\n");
				}
				system("pause");
				break;
		case 4:
				if(select == 0){
					printf("还没有输入图书总数\n\n");
				}else{
					printf("所有图书信息如下\n\n");
					show(H);
				}
				system("pause");
				break;
		case 5:
				if(select == 0){
					printf("还没有输入图书总数\n\n");
				}else if(H.length != 0){
					printf("请输入想要查找的图书名称\n");
					scanf("%s",x.name);
					if(find(H,x) == 1){
					k = find(H,x);
					printf("该图书的位置是%d\n",k);
					}else{
						printf("没有找到该图书\n");
					}
				}else{
					printf("还没有录入图书\n");
				}
				system("pause");
				break;
		case 6:t = 0;
				break;
		default:printf("输入有误\n");
				system("pause");
				break;

		}

	}
	printf("程序已经退出\n");
	return 0;
};
int menu()
{
	int n;
	printf("\t\t\t\t\tWelcome TO BMS\n");
	printf("\t\t\t\t******************************\n");
	printf("\t\t\t\tPLEASE   SELECT   YOUR   CHOICE\n\n");
	printf("\t\t\t\t1.请输入图书总数	2.录入图书信息\n\n");
	printf("\t\t\t\t3.选择想要删除的图书	4.显示所有的图书\n\n");
	printf("\t\t\t\t5.查找图书	6.结束程序退出\n\n");
	printf("请输入你的选择\n");
	scanf("%d",&n);
	return n;
}
int init(SqList *H,int max)
{
	H -> elem = (STD *)malloc(sizeof(STD) * max);
	if(H -> elem ==NULL){
		printf("申请空间失败\n");
		return 0;
	}
	H -> listSize = max;
	H -> length = 0;
	return 1;
}
int insert(SqList *H,int i,STD x)
{
	int k;
	if((i-1 > H->length) || i < 1 || i > H->listSize){
		printf("插入位置不合理,请重新输入\n");
		return 0;
	}
	for(k = H -> length;k > i - 1;k--){
		H -> elem[k] = H -> elem[k-1];
	}
	H -> elem[i-1] = x;
	H -> length++;
	return 1;
}
STD del(SqList *H,int i)
{
	int k;
	STD Y;
	Y = H -> elem[i-1];
	for(k = i - 1;k < H -> length - 1;k++){
		H -> elem[k] = H -> elem[k+1];
	} 
	H -> length--;
	return Y;
}
int show(SqList H)
{
	int k;
	printf("序号:\t图书名称\t\t价格\n");
	for(k = 0;k < H.length;k++){
		printf("%d\t%s\t\t%.2f\n",H.elem[k].num,H.elem[k].name,H.elem[k].price);
	}
	return 1;
}
int find(SqList H,STD x)
{
	int k,index = 0;
	for(k = 0;k < H.length;k++){
		if(strcmp(x.name,H.elem[k].name) == 0){
			index = 1;
			break;
		}
	}
	if(index == 1){
		return k+1;
	}
	else{
		return 0;
	}
}









