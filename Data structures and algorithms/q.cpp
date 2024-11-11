#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef char data[MAXSIZE];
typedef struct{
	data VexsData[MAXSIZE;
	int arcnum,vexnum;
	int weightinfo;
	int Edge[MAXSIZE][MAXSIZE];
}Graph;

int FindLocation(Graph ga,data3[])
{
	for(i=0;i<ga.vexnum;i++)
	{
	   if(strcmp(ga.VexsData[i],data3)==0)
		   return i;
	   }
	return -1;
}

void CreateGraph(Graph &ga)
{
	int a,b,weight;
	char data1[MAXSIZE],data2[MAXSIZE];
	printf("");
	scanf("%d%d",ga.vexnum,ga.arcnum);
	printf("");
	for(int i=0;i<ga.vexnum;i++)
	{
		scanf("%s",ga.VexsData[i]);
	}
	for(int i=0;i<ga.vexnum;i++)
	{
		for(int j=0;j<ga.vexnum;j++)
		{
			if(i==j)
				ga.Edge[i][j]=0;
			else
				ga.Edge[i][j]=10000;
		}
	}
	printf("");
	for(int j=0;j<ga.arcnum;j++)
	{
		scanf("%d%d%s",data1,data2,&weight);
		a=FindLocation(ga,data1);
		b=FindLocation(ga,data2);
		ga.Edge[a][b]=weight;
	}
}


void ShowGraph(Graph ga)
{
	for(int i=0;i<ga.vexnum;i++)
	{
		prirntf(" %s",ga.VexsData[i]);
	}
	for(int i=0;i<ga.vexnum;i++)
	{
		printf("%s ",ga.VexsData[i]);
	   for(int j=0;j<ga.vexnum;j++)
	   {
		   printf("%d",ga.VexsData[i]);
	   }
	}
}
int FindMinpath(Graph ga,int &a,int &b)
{
	int minipath=10000;
	for(int i=0;i<ga.vexnum[i];i++)
	{
	    for(int j=0;j<ga.vexnum;j++)
		{
			if(minipath>ga.Edge[i][j]&&ga.Edge[i][j]!=0)
			{
				a=i;
				b=j;
				minipath=ga.Edge[i][j];
			}
		}
	}
	return minipath;
}

void InsertEdge(Graph &ga)
{
	int a,b,weight;
	char data1[MAXSIZE],data2[MAXSIZE];
	printf("");
	scanf("%s%s%d",data1,data2,weight);
	a=FindLocation(ga,data1);
	b=FindLocation(ga,data2);
	ga.Edge[a][b]=weight;
	ga.Edge[b][a]=weight;
}

void DeleteEdge(Graph &ga)
{
	int a,b;
	char data1[MAXSIZE],data2[MAXSIZE];
	printf("");
	scanf("%s%s",data1,data2);
	a=FindLocation(ga,data1);
	b=FindLocation(ga,daat2);
	ga.Edge[a][b]=10000;
	ga.Edge[b][a]=10000;
}

void ComputedDegree(Graph ga,Degree[])
{
	for(int i=0;i<ga.vexnum;i++)
	{
		int num=0;
		for(int j=0;j<ga.vexnum;j++)
		{
			if(ga.Edge[i][j]!=10000&&ga.Edge[i][j]!=0)
			{
				num++;
			}
		}
		Degree[i]=num;
	}
}

void DeterminReach(Graph ga,int &reach,int v,int visited[],int v2)
{
	visited[v]=1;
	for(int j=0;j<ga.vexnum;j++)
	{
      if(ga.Edge[v][j]!=0&&ga.Edge[v][j]!=10000&&visitded[j]==0)
	  {
		  if(j==v2)
		   reach=1;
		  DeterminReach(ga,reach,j,visited,v2);
	  }
	}
}

int menu()
{
	int n;
	printf("");
	printf("");
	printf("");
	printf("");
	printf("");
	scanf("");
	return n;
}

int main()
{
	int n,t=1,a,b,weight,reach,minipath;
    int Degree[MAXSIZE],visited[MAXSIZE];
	char data1[MAXSIZE],data2[MAXSIZE];
	Graph G;
    while(t=1)
	{
		n=menu();
		switch(n)
		{
		case 1:
			CreateGraph(G);
			break;
		case 2:
			ShowGraph(G);
			break;
		case 3:
			minipath=FindMinipath(G,a,b);
			printf("");
			break;
		case 4:
			InsdertEdge(G);
			break;
		case 5:
			DeleteEdge(G);
			break;
		case 6:
			printf("");
			for(int i=0;i<G.vexnum;i++)
			{
				printf"%s %d",G.VexsData[i],Degree[i]);
			}
			break;
		case 7:
			printf("");
			scanf("%s%s",data1,data2)
			a=FindLocation(G,data1);
			b=FindLocation(G,data2);
			DeterminReach(G,reach,a,visitded,b);
			if(reach==1)
				printf("");
			else
				printf("");
		}
	}
	return -1;
}



