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
		case 1:printf("������Ҫ¼��ͼ�������\n");
				scanf("%d",&maxsize);
				init(&H,maxsize);
				select = 1;
				system("pause");
				break;
		case 2:
				if(select == 0){
					printf("��û������ͼ������\n\n");
				}else{
					while(1){
						printf("�Ƿ����¼��\n\n");
						printf("����¼������1����ֹ����0\n");
						scanf("%d",&choice);
						if(choice == 1){
						printf("������ͼ�����Ϣ(��š��������۸�) \n\n");
						scanf("%d",&x.num);
						scanf("%s",x.name);
						scanf("%f",&x.price);
						printf("��������Ҫ�����λ��\n");
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
							printf("����������������\n\n");
						}
					}
				}
				system("pause");
				break;
		case 3:
				if(select == 0){
					printf("��û������ͼ������\n\n");
				}else if(H.length != 0){
					printf("������ѡ����Ҫɾ����ͼ������\n");
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
						printf("ɾ�������������,����������\n");
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
					printf("ɾ����ͼ����Ϣ��\n\n");
					printf("���:\tͼ������\t\t\t�۸�\n\n");
					printf("%d\t%s\t\t\t%.2f\n",y.num,y.name,y.price);
				}else{
					printf("��û��¼��ͼ��\n");
				}
				system("pause");
				break;
		case 4:
				if(select == 0){
					printf("��û������ͼ������\n\n");
				}else{
					printf("����ͼ����Ϣ����\n\n");
					show(H);
				}
				system("pause");
				break;
		case 5:
				if(select == 0){
					printf("��û������ͼ������\n\n");
				}else if(H.length != 0){
					printf("��������Ҫ���ҵ�ͼ������\n");
					scanf("%s",x.name);
					if(find(H,x) == 1){
					k = find(H,x);
					printf("��ͼ���λ����%d\n",k);
					}else{
						printf("û���ҵ���ͼ��\n");
					}
				}else{
					printf("��û��¼��ͼ��\n");
				}
				system("pause");
				break;
		case 6:t = 0;
				break;
		default:printf("��������\n");
				system("pause");
				break;

		}

	}
	printf("�����Ѿ��˳�\n");
	return 0;
};
int menu()
{
	int n;
	printf("\t\t\t\t\tWelcome TO BMS\n");
	printf("\t\t\t\t******************************\n");
	printf("\t\t\t\tPLEASE   SELECT   YOUR   CHOICE\n\n");
	printf("\t\t\t\t1.������ͼ������	2.¼��ͼ����Ϣ\n\n");
	printf("\t\t\t\t3.ѡ����Ҫɾ����ͼ��	4.��ʾ���е�ͼ��\n\n");
	printf("\t\t\t\t5.����ͼ��	6.���������˳�\n\n");
	printf("���������ѡ��\n");
	scanf("%d",&n);
	return n;
}
int init(SqList *H,int max)
{
	H -> elem = (STD *)malloc(sizeof(STD) * max);
	if(H -> elem ==NULL){
		printf("����ռ�ʧ��\n");
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
		printf("����λ�ò�����,����������\n");
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
	printf("���:\tͼ������\t\t�۸�\n");
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









