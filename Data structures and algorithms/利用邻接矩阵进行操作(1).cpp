#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 100
/*
	测试题目:图形结构(结点数据类型为字符串)
	具体内容
	功能:
	1.初始化创建一个图(网)的邻接矩阵(邻接表)
	2.输出邻接矩阵(邻接表)
	3.查找长度最短的一条边
	4.插入一条边到邻接矩阵(邻接表) 
	5.删除一条边到邻接矩阵 (邻接表)
	6.求出每个顶点的度并输出
	7.判断两个顶点之间是否可达 
*/
typedef char data[MAXSIZE];
typedef struct{
	data VexsData[MAXSIZE];
	int Edge[MAXSIZE][MAXSIZE];
	int arcnum,vexnum;
	int weightinfo;
}Graph;
//顶端元素的定位
int FindLocation(Graph ga,char data3[])
{
	for(int i = 0;i < ga.vexnum;i++){
		if(strcmp(ga.VexsData[i],data3) == 0){
			return i;
		}
	}
	return -1;
 } 
//通过邻接矩阵的方式创建图 
void CreateGraph(Graph &ga)
{
	printf("请输入顶点数和边数\n");
	int a,b,weight;
	char data1[MAXSIZE],data2[MAXSIZE];
	scanf("%d%d",&ga.vexnum,&ga.arcnum);
	printf("请输入顶点信息\n");
	for(int i = 0;i < ga.vexnum;i++){
		scanf("%s",ga.VexsData[i]);
	} 
	for(int i = 0;i < ga.vexnum;i++)
		for(int j = 0;j < ga.vexnum;j++){
			if(i == j){
				ga.Edge[i][j] = 0;
			}else{
				ga.Edge[i][j] = 10000;
			}
		}
	printf("请输入边的信息\n");
	for(int i = 0;i < ga.arcnum;i++){
		scanf("%s%s%d",data1,data2,&weight);
		a = FindLocation(ga,data1);
		b = FindLocation(ga,data2);
		if(a != -1 && b != -1){
			ga.Edge[a][b] = weight;
			ga.Edge[b][a] = weight;
		}else{
			printf("输入有误\n");
		}
	}
}
//展示图的邻接矩阵
void ShowGraph(Graph ga)
{
	printf(" ");
	for(int i = 0;i < ga.vexnum;i++){
		printf(" %s",ga.VexsData[i]);
	}
	printf("\n");
	for(int i = 0;i < ga.vexnum;i++){
		printf("%s ",ga.VexsData[i]);
		for(int j = 0;j < ga.vexnum;j++){
			printf("%d ",ga.Edge[i][j]);
		}
		printf("\n");
	}
}
int FindMiniEdge(Graph ga,int &a,int &b)
{
	int minipath = 10000;
	for(int i = 0;i < ga.vexnum;i++)
		for(int j = 0;j < ga.vexnum;j++){
			if(minipath > ga.Edge[i][j] && ga.Edge[i][j] != 0){
				a = i;
				b = j;
				minipath = ga.Edge[i][j];
			}
		}
	return minipath;
}
void InsertEdge(Graph &ga)
{
	int a,b,weight;
	char data1[MAXSIZE],data2[MAXSIZE];
	printf("请输入想要增加的边的信息\n");
	scanf("%s%s%d",data1,data2,&weight);
	getchar();
	a = FindLocation(ga,data1);
	b = FindLocation(ga,data2);
	ga.Edge[a][b] = weight;
	ga.Edge[b][a] = weight;
	printf("插入边成功\n");
}
void DeleteEdge(Graph &ga)
{
	int a,b;
	char data1[MAXSIZE],data2[MAXSIZE];
	printf("请输入想要删除的边的信息\n");
	scanf("%s%s",data1,data2);
	getchar();
	a = FindLocation(ga,data1);
	b = FindLocation(ga,data2);
	ga.Edge[a][b] = 10000;
	ga.Edge[b][a] = 10000;
	printf("删除成功\n");
}
void ComputedDegree(Graph ga,int Degree[])
{
	for(int i = 0;i < ga.vexnum;i++){
		int num = 0;
		for(int j = 0;j < ga.vexnum;j++){
			if(ga.Edge[i][j] != 10000 && ga.Edge[i][j] != 0){
				num++; 
			}
		}
		Degree[i] = num;
	}
}
void DeterminReach(Graph ga,int &reach,int v,int visited[],int v2)
{
	visited[v] = 1;
	for(int j = 0;j < ga.vexnum;j++){
		if(ga.Edge[v][j] != 0 && ga.Edge[v][j] != 10000 && visited[j] == 0){
			if(j == v2){
				reach = 1;
			}
			DeterminReach(ga,reach,j,visited,v2);
		}
	}
}
int menu()
{
	int n;
	printf("1.初始化创建一个图(网)的邻接矩阵  2.输出邻接矩阵\n");
	printf("3.查找长度最短的一条边   4.插入一条边到邻接矩阵\n");
	printf("5.删除一条边到邻接矩阵   6.求出每个顶点的度并输出\n");
	printf("7.判断两个顶点之间是否可达  8.退出\n");
	printf("请输入你的选择\n");
	scanf("%d",&n);
	return n;
}
int main()
{
	int n,t = 1,a,b,minipath,reach = 0;
	int Degree[MAXSIZE],visited[MAXSIZE] = {0};
	char data1[MAXSIZE],data2[MAXSIZE];
	Graph G;
	while(t){
		n = menu();
		switch(n){
			case 1:
				CreateGraph(G);
				break;
			case 2:
				ShowGraph(G);
				break;
			case 3:
				minipath = FindMiniEdge(G,a,b);
				printf("长度最短的一条边%s %s %d\n",G.VexsData[a],G.VexsData[b],minipath);
				break;
			case 4:
				InsertEdge(G);
				break;
			case 5:
				DeleteEdge(G);
				break;
			case 6:
				ComputedDegree(G,Degree);
				printf("每个顶点的度如下\n");
				for(int i = 0;i < G.vexnum;i++){
					printf("%s %d ",G.VexsData[i],Degree[i]);
				}
				printf("\n");
				break;
			case 7:
				printf("请输入需要判断的顶点的信息\n");
				scanf("%s%s",data1,data2);
				a = FindLocation(G,data1);
				b = FindLocation(G,data2);
				DeterminReach(G,reach,a,visited,b);
				if(reach == 1){
					printf("两点可达\n");
				}else{
					printf("两点不可达\n");
				}
				reach = 0;
				break;
			case 8: 
				t = 0;
				printf("已经退出\n");
				break;
			default :printf("输入有误\n");
		}
	}
	return 0;
}

