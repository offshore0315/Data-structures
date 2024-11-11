#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 100
/*
	������Ŀ:ͼ�νṹ(�����������Ϊ�ַ���)
	��������
	����:
	1.��ʼ������һ��ͼ(��)���ڽӾ���(�ڽӱ�)
	2.����ڽӾ���(�ڽӱ�)
	3.���ҳ�����̵�һ����
	4.����һ���ߵ��ڽӾ���(�ڽӱ�) 
	5.ɾ��һ���ߵ��ڽӾ��� (�ڽӱ�)
	6.���ÿ������ĶȲ����
	7.�ж���������֮���Ƿ�ɴ� 
*/
typedef char data[MAXSIZE];
typedef struct{
	data VexsData[MAXSIZE];
	int Edge[MAXSIZE][MAXSIZE];
	int arcnum,vexnum;
	int weightinfo;
}Graph;
//����Ԫ�صĶ�λ
int FindLocation(Graph ga,char data3[])
{
	for(int i = 0;i < ga.vexnum;i++){
		if(strcmp(ga.VexsData[i],data3) == 0){
			return i;
		}
	}
	return -1;
 } 
//ͨ���ڽӾ���ķ�ʽ����ͼ 
void CreateGraph(Graph &ga)
{
	printf("�����붥�����ͱ���\n");
	int a,b,weight;
	char data1[MAXSIZE],data2[MAXSIZE];
	scanf("%d%d",&ga.vexnum,&ga.arcnum);
	printf("�����붥����Ϣ\n");
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
	printf("������ߵ���Ϣ\n");
	for(int i = 0;i < ga.arcnum;i++){
		scanf("%s%s%d",data1,data2,&weight);
		a = FindLocation(ga,data1);
		b = FindLocation(ga,data2);
		if(a != -1 && b != -1){
			ga.Edge[a][b] = weight;
			ga.Edge[b][a] = weight;
		}else{
			printf("��������\n");
		}
	}
}
//չʾͼ���ڽӾ���
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
	printf("��������Ҫ���ӵıߵ���Ϣ\n");
	scanf("%s%s%d",data1,data2,&weight);
	getchar();
	a = FindLocation(ga,data1);
	b = FindLocation(ga,data2);
	ga.Edge[a][b] = weight;
	ga.Edge[b][a] = weight;
	printf("����߳ɹ�\n");
}
void DeleteEdge(Graph &ga)
{
	int a,b;
	char data1[MAXSIZE],data2[MAXSIZE];
	printf("��������Ҫɾ���ıߵ���Ϣ\n");
	scanf("%s%s",data1,data2);
	getchar();
	a = FindLocation(ga,data1);
	b = FindLocation(ga,data2);
	ga.Edge[a][b] = 10000;
	ga.Edge[b][a] = 10000;
	printf("ɾ���ɹ�\n");
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
	printf("1.��ʼ������һ��ͼ(��)���ڽӾ���  2.����ڽӾ���\n");
	printf("3.���ҳ�����̵�һ����   4.����һ���ߵ��ڽӾ���\n");
	printf("5.ɾ��һ���ߵ��ڽӾ���   6.���ÿ������ĶȲ����\n");
	printf("7.�ж���������֮���Ƿ�ɴ�  8.�˳�\n");
	printf("���������ѡ��\n");
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
				printf("������̵�һ����%s %s %d\n",G.VexsData[a],G.VexsData[b],minipath);
				break;
			case 4:
				InsertEdge(G);
				break;
			case 5:
				DeleteEdge(G);
				break;
			case 6:
				ComputedDegree(G,Degree);
				printf("ÿ������Ķ�����\n");
				for(int i = 0;i < G.vexnum;i++){
					printf("%s %d ",G.VexsData[i],Degree[i]);
				}
				printf("\n");
				break;
			case 7:
				printf("��������Ҫ�жϵĶ������Ϣ\n");
				scanf("%s%s",data1,data2);
				a = FindLocation(G,data1);
				b = FindLocation(G,data2);
				DeterminReach(G,reach,a,visited,b);
				if(reach == 1){
					printf("����ɴ�\n");
				}else{
					printf("���㲻�ɴ�\n");
				}
				reach = 0;
				break;
			case 8: 
				t = 0;
				printf("�Ѿ��˳�\n");
				break;
			default :printf("��������\n");
		}
	}
	return 0;
}

