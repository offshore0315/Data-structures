//////////////////////////////////////////////////////////////////////////
//（1）编译预处理命令
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"



//////////////////////////////////////////////////////////////////////////
//（2）自定义数据类型(typedef)
//先定义图书数据的数据类型
typedef struct {
   int no;//number
   char name[32];//name
   float price;//price
}STD;
//再定义顺序表数据类型：
typedef  struct {
STD *data; //dada是一个指向STD类型的指针变量
int  listSize;
int  length;
}SQList;




//////////////////////////////////////////////////////////////////////////
//（3）各个函数的声明
int menu();
int initSqList(SQList *L,int max);
int dispSqList(SQList L);
int insertSqList(SQList *L, int i, STD x);
int deleteSqList(SQList *L, int i, STD *x);
int locateSqList(SQList L, STD x);
int updateSqList(SQList L, int i, STD x);




//////////////////////////////////////////////////////////////////////////
//（4）主函数的定义
int main()
{
	int t=1,n, maxSize;// float fs=.0f;有时候不做这个浮点初始化操作程序会报错
	SQList L;
	STD s;


	while(t){
		n=menu( );//显示主菜单 
		switch(n){
		//初始化图书数据
		case 1:
			printf("请输入需要创建的图书数量：");
			scanf("%d",&maxSize);
			initSqList(&L, maxSize);

			break;

		//插入图书数据
		case 2:
			printf("请输入需要插入图书的编号、书名、价格，用空格隔开：\n");
			scanf("%d%s%f",&s.no,s.name, &s.price);
			int pos;
			printf("请输入插入位置:\n");
			scanf("%d",&pos);
			insertSqList(&L,pos,s);

			break;

		//删除图书数据
		case 3:
			printf("请输入删除图书书名：\n");
			scanf("%s",s.name);
			pos=locateSqList(L,s);
			if(pos==L.length+1) 
				printf("不存在该图书数据\n");
			else
			{
				deleteSqList(&L, pos, &s);
				printf("删除的图书数据为：%d %10s %7.2f\n", s.no,s.name, s.price);
			}

			break;

		//显示图书数据
		case 4:
			dispSqList(L);

			break;

		//更新图书数据
		case 5:
			printf("请输入需要修改的图书编号、名称、价格，用空格隔开：\n");
			scanf("%d%s%f",&s.no,s.name,&s.price);
			n=locateSqList(L,s);
			updateSqList(L,n,s);
		
			break;


		//退出
		case 0:
			t = 0;
			break;

		//错误处理
		default: 
			printf("输入有误！\n");

		}
	}

}




//////////////////////////////////////////////////////////////////////////
//（5）各个函数的定义
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


int initSqList(SQList *L,int max){
	(*L).data=( STD *)malloc(max*sizeof(STD));
	if((*L).data==NULL) return 0;
	(*L).listSize=max;
	(*L).length =0;
	return 1;
}


int dispSqList(SQList L){
	int i;
	if(L.length==0){printf("没有数据！\n");return 0;}
	for(i=0;i<L.length;i++)
		   printf("%d %10s %7.2f\n",L.data[i].no,L.data[i].name, L.data[i].price);
	return 1;
}

int insertSqList(SQList *L, int i, STD x){
	int k;
	if((*L).length>=(*L).listSize){printf("容量不够！\n");return 0;}
	if(i<1 || i> L->length+1) {printf("插入位置非法！\n");return 0;}
	for(k=(*L).length;k>=i;k--)
		(*L).data[k]= (*L).data[k-1];
	(*L).data[i-1]=x;
	(*L).length=(*L).length+1;
	return 1;
}

int deleteSqList(SQList *L, int i, STD *x){
	int k;
	if((*L).length==0){printf("没有数据，不能删除！\n");return 0;}
	*x=(*L).data[i-1];
	for(k=i;k<=(*L).length-1;k++)
		(*L).data[k-1]= (*L).data[k];
	(*L).length=(*L).length-1;
	return 1;
}

int locateSqList(SQList L, STD x){
	int k;
	if(L.length==0){printf("没有数据，无法查找！\n");return 0;}
	for(k=0;k<=L.length-1;k++)
		if( strcmp(L.data[k].name,x.name)==0 )
			break;

	return k+1;
}

int updateSqList(SQList L, int i, STD x){
	if(L.length==0) {printf("没有数据，不能更新\n");return 0;}
	L.data[i-1]=x;
	return 1;

}
