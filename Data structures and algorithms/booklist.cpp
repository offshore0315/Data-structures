//////////////////////////////////////////////////////////////////////////
//��1������Ԥ��������
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"



//////////////////////////////////////////////////////////////////////////
//��2���Զ�����������(typedef)
//�ȶ���ͼ�����ݵ���������
typedef struct {
   int no;//number
   char name[32];//name
   float price;//price
}STD;
//�ٶ���˳����������ͣ�
typedef  struct {
STD *data; //dada��һ��ָ��STD���͵�ָ�����
int  listSize;
int  length;
}SQList;




//////////////////////////////////////////////////////////////////////////
//��3����������������
int menu();
int initSqList(SQList *L,int max);
int dispSqList(SQList L);
int insertSqList(SQList *L, int i, STD x);
int deleteSqList(SQList *L, int i, STD *x);
int locateSqList(SQList L, STD x);
int updateSqList(SQList L, int i, STD x);




//////////////////////////////////////////////////////////////////////////
//��4���������Ķ���
int main()
{
	int t=1,n, maxSize;// float fs=.0f;��ʱ������������ʼ����������ᱨ��
	SQList L;
	STD s;


	while(t){
		n=menu( );//��ʾ���˵� 
		switch(n){
		//��ʼ��ͼ������
		case 1:
			printf("��������Ҫ������ͼ��������");
			scanf("%d",&maxSize);
			initSqList(&L, maxSize);

			break;

		//����ͼ������
		case 2:
			printf("��������Ҫ����ͼ��ı�š��������۸��ÿո������\n");
			scanf("%d%s%f",&s.no,s.name, &s.price);
			int pos;
			printf("���������λ��:\n");
			scanf("%d",&pos);
			insertSqList(&L,pos,s);

			break;

		//ɾ��ͼ������
		case 3:
			printf("������ɾ��ͼ��������\n");
			scanf("%s",s.name);
			pos=locateSqList(L,s);
			if(pos==L.length+1) 
				printf("�����ڸ�ͼ������\n");
			else
			{
				deleteSqList(&L, pos, &s);
				printf("ɾ����ͼ������Ϊ��%d %10s %7.2f\n", s.no,s.name, s.price);
			}

			break;

		//��ʾͼ������
		case 4:
			dispSqList(L);

			break;

		//����ͼ������
		case 5:
			printf("��������Ҫ�޸ĵ�ͼ���š����ơ��۸��ÿո������\n");
			scanf("%d%s%f",&s.no,s.name,&s.price);
			n=locateSqList(L,s);
			updateSqList(L,n,s);
		
			break;


		//�˳�
		case 0:
			t = 0;
			break;

		//������
		default: 
			printf("��������\n");

		}
	}

}




//////////////////////////////////////////////////////////////////////////
//��5�����������Ķ���
int menu(){
	int n;
	//system("cls");//����
	printf("****welcome to book management system****\n");
	printf("   1��initialize    2��insert\n");
	printf("   3��delete        4��display\n");
	printf("   5��update        0��exit\n");
	printf("*****************************************\n");
	printf("choose function(0-5)��");
	scanf("%d",&n);
	return n;
}


int initSqList(SQList *L,int max){
	(*L).data=( STD *)malloc(max*sizeof(STD));
	if((*L).data==NULL) return 0;
	(*L).listSize=max;
	(*L).length =0;
	return 1;
}


int dispSqList(SQList L){
	int i;
	if(L.length==0){printf("û�����ݣ�\n");return 0;}
	for(i=0;i<L.length;i++)
		   printf("%d %10s %7.2f\n",L.data[i].no,L.data[i].name, L.data[i].price);
	return 1;
}

int insertSqList(SQList *L, int i, STD x){
	int k;
	if((*L).length>=(*L).listSize){printf("����������\n");return 0;}
	if(i<1 || i> L->length+1) {printf("����λ�÷Ƿ���\n");return 0;}
	for(k=(*L).length;k>=i;k--)
		(*L).data[k]= (*L).data[k-1];
	(*L).data[i-1]=x;
	(*L).length=(*L).length+1;
	return 1;
}

int deleteSqList(SQList *L, int i, STD *x){
	int k;
	if((*L).length==0){printf("û�����ݣ�����ɾ����\n");return 0;}
	*x=(*L).data[i-1];
	for(k=i;k<=(*L).length-1;k++)
		(*L).data[k-1]= (*L).data[k];
	(*L).length=(*L).length-1;
	return 1;
}

int locateSqList(SQList L, STD x){
	int k;
	if(L.length==0){printf("û�����ݣ��޷����ң�\n");return 0;}
	for(k=0;k<=L.length-1;k++)
		if( strcmp(L.data[k].name,x.name)==0 )
			break;

	return k+1;
}

int updateSqList(SQList L, int i, STD x){
	if(L.length==0) {printf("û�����ݣ����ܸ���\n");return 0;}
	L.data[i-1]=x;
	return 1;

}
