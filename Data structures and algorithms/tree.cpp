
/////////////////////////////////////////////////
//Desc：  模拟资源管理器,采用孩子—兄弟链表
//        结构实现。
//Author：JRH
//Date:    5/11/2020
//
//#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "locale.h"
#include "stdlib.h"

/******************************************
定义数据结构
*******************************************/
//二叉链表
typedef struct _Node{
	char  szName[64];
	struct _Node *pChild, *pSibling;
}NODE, *NODE_PTR;

//循环队列的数据类型
typedef struct {
	NODE_PTR *elem;
	int front,rear;
	int queuesize;
}XhQueue;



//有关循环队列的一组操作
void InitQueue(XhQueue &Q,int maxsize){
	Q.elem=new NODE_PTR[maxsize];
	if(Q.elem!=NULL){
		Q.front=Q.rear=0;
		Q.queuesize=maxsize;
	}
}


void EnQueue(XhQueue &Q,NODE_PTR p){
	if((Q.rear+1)%Q.queuesize!=Q.front){
		Q.elem[Q.rear]=p;
        Q.rear=(Q.rear+1)%Q.queuesize;
	}
}

void DeQueue(XhQueue &Q,NODE_PTR &p){
	if(Q.front!=Q.rear){
		p=Q.elem[Q.front];
        Q.front=(Q.front+1)%Q.queuesize;
	}
}


void GetHead(XhQueue &Q,NODE_PTR &p){
	if(Q.front!=Q.rear){
		p=Q.elem[Q.front];
	}
}

int EmQueue(XhQueue Q){
	if(Q.front!=Q.rear)return 0;
	else return 1;
}


#define Stack_Size  32
#define String_Len  32
typedef struct SqStack
{
	char ** elem;
	char **top;
}SqStack;


int InitStack(SqStack& sq)
{
	sq.elem = new char*[Stack_Size];
	sq.top = sq.elem-1;

	if(sq.elem) return 1;
	else return 0;
}

void Destroy(SqStack& sq)
{
	delete []sq.elem;
	sq.elem = NULL;
}

int Pop(SqStack& sq,char *elem)
{
	if(sq.elem-1 == sq.top)
	{
		printf("\n栈为空!\n");
		return 0;
	}
	strcpy(elem,*sq.top);
	--sq.top;
	return 1;
}

int Push(SqStack& sq,char *elem)
{
	if(sq.top-sq.elem == Stack_Size-1)
	{
		printf("\n栈满!不能入栈!\n");
		return 0;
	}
	sq.top++;
	*sq.top = new char[String_Len];
	strcpy(*sq.top,elem);
	
	return 1;
}

char* Top(SqStack& sq)
{
	if(sq.elem-1 == sq.top)
	{
		printf("\n栈空!\n");
	}
	return *sq.top;
}


void PrintStack(SqStack sq)
{
	char **p;
	p = sq.elem;
	while(p<=sq.top){
		printf("/%s",*p);
		p++;
	}
}
/********************************************
形式：void Create(NODE_PTR &pTree) 
功能：创建树。
输入：树指针引用变量。
输出：无。
附注：按照树的孩子-兄弟链表方式先序遍历后结果输入，如果为空则输入^，例如：
dir1
file1
^
file2
^
dir2
file3
^
^
dir4
^
^
^

*********************************************///输入先序字符串创建的方式
void Create(NODE_PTR &pTree)
{
	char  szInput[64];
	gets(szInput);
	if(szInput[0] == '^')
		pTree = NULL;
	else{
		pTree = new NODE;
		strcpy(pTree->szName, szInput);
		Create(pTree->pChild);
		Create(pTree->pSibling);
	}
}
/*********************************************///输入边创建的方式
void CreateTree( NODE_PTR &T ) {
	char fa[30],ch[30];
	NODE_PTR p,s,r;
    XhQueue Q;
	InitQueue(Q,50);
	T = NULL;
	printf("请输入父结点和子结点（用空格隔开，根结点的双亲为#）\n");
    scanf("%s%s",fa, ch);
    for( ; strcmp(ch,"end"); ) {
		p =new  NODE;    // 创建结点
		strcpy(p->szName,ch);
		p->pChild=p->pSibling=NULL;
		
		EnQueue(Q, p);// 指针入队列
		if (strcmp(fa,"#")==0)  T = p;  // 所建为根结点
		else {// 非根结点的情况
			GetHead(Q,s);  // 取队列头元素(指针值)
			
			while (strcmp(s->szName,fa)) { // 查询双亲结点
				DeQueue(Q,s);  GetHead(Q,s); 
			}//while   
			
			if (!(s->pChild)){ 
				s->pChild = p; 
				r = p; 
			}// 链接第一个孩子结点
			else { 
				r->pSibling = p;  r = p; 
			}// 链接其它孩子结点 
		}// 非根结点的情况
		printf("请输入父结点和子结点（用空格隔开，结束时输入end end）\n");
		scanf("%s%s",fa,ch);
	} // for
}


/********************************************
形式：void Destroy(NODE_PTR pTree)
功能：销毁树。
输入：根节点指针引用。
输出：无。
*********************************************/
void Destroy(NODE_PTR &pTree)
{
	if(pTree == NULL) return;
	if(pTree->pChild)
		Destroy(pTree->pChild);
	if(pTree->pSibling)
		Destroy(pTree->pSibling);
	
	delete pTree;
	pTree = NULL;
}

/********************************************
形式：void Print(NODE_PTR pTree, int indent)
功能：以凹入表的形式输出显示。
输入：
	pTree： 根节点指针。
	indent：凹入层次计数。
输出：无。
*********************************************/
void Print(NODE_PTR pTree, int indent)
{
    if (pTree == NULL)
        return;
	
	for(int i = 0; i < indent; i++)
		printf("  ");

	printf("%s\n", pTree->szName);
	Print(pTree->pChild, indent + 1);
	Print(pTree->pSibling, indent);
}

/********************************************
形式：void Find(NODE_PTR pTree, char  *szName, NODE_PTR &p)
功能：查找指定名称节点。
输入：
	pTree： 根节点指针。
	szName：给定节点名。
	p：		如找到则设置为节点指针。
输出：无。
附注：在调用函数时，p的实参变量值设置为NULL。
*********************************************/
void Find(NODE_PTR pTree, char  *szName, NODE_PTR &p)
{
	if(pTree == NULL) return;
	
	if(strcmp(pTree->szName, szName) == 0)
		p = pTree;
	else{
		Find(pTree->pChild, szName, p);
		Find(pTree->pSibling, szName, p);
	}
}

/*
//在pTree里找孩子节点
void FindChild(NODE_PTR pTree, char  *szName, NODE_PTR &p)
{
	if(pTree == NULL){
		p=NULL;
		return;
	}
	
	if(strcmp(pTree->szName, szName) == 0)
		p = pTree;
	else{
		FindChild(pTree->pChild, szName, p);
	}
}
*/

/********************************************
形式：void Find(NODE_PTR pTree, char  *szName, NODE_PTR &pLast, NODE_PTR &p1, NODE_PTR &p2)
功能：查找指定名称节点及其二叉链表下的父节点(对应树中，应是父节点或者兄弟节点)。
输入：
	pTree： 当前节点的指针。
	szName：查找的节点名称。
	pLast： 当前节点的父节点。
	p1：	找到结点的父节点指针。
	p2:     找到节点的指针。
输出：无。
附注：在调用函数时，pLast,p1和p2的实参变量值设置为NULL。
*********************************************/
void Find(NODE_PTR pTree, char  *szName, NODE_PTR &pLast, NODE_PTR &p1, NODE_PTR &p2)
{
	if(pTree == NULL) return;
	if(strcmp(pTree->szName, szName) == 0){//找到则返回父节点指针和当前节点指针
		p2 = pTree;//当前节点
		p1 = pLast;//父节点
	}
	else{
		pLast = pTree;//暂存上一级节点指针
		Find(pTree->pChild, szName, pLast, p1, p2);
		pLast = pTree;
		Find(pTree->pSibling, szName, pLast, p1, p2);
	}
}

/********************************************
void Insert(NODE_PTR pTree, char  *szParent, char  *szNew)
功能：插入新节点。
输入：
	pTree： 根节点指针。
		szParent：父节点名。
	szNew：   新节点名。
输出：无。
*********************************************/
void Insert(NODE_PTR pTree, char  *szParent, char  *szNew)
{
	NODE_PTR pFind = NULL;
	NODE_PTR pChild = NULL;
	Find(pTree, szParent, pFind);

	if(pFind){
		pChild = pFind->pChild;
		while(pChild!=NULL){
			if(strcmp(pChild->szName,szNew)==0){
				printf("子节点已存在！\n");
				return;
			}else
				pChild=pChild->pSibling;
		}

		NODE_PTR pNew = new NODE;
		strcpy(pNew->szName, szNew);
		if(pFind->pChild){
			pNew->pSibling = pFind->pChild;
			pNew->pChild = NULL;
		}else{
			pNew->pChild = NULL;
			pNew->pSibling = NULL;
		}
		pFind->pChild = pNew;
	}else
		printf("父节点不存在!\n");

}
/********************************************
void Delete(NODE_PTR &pTree, char  *szName){
功能：删除指定节点。
输入：
	pTree： 根节点指针。
	szName：待删除节点名。
输出：无。
*********************************************/
void Delete(NODE_PTR &pTree, char  *szName){
	NODE_PTR pFind = NULL, pParent = NULL, p = NULL;

	Find(pTree, szName, p, pParent, pFind);
	
	if(pFind){
		if(pParent == NULL){//删除根节点
			Destroy(pTree);
			pTree = NULL;
		}else{
			if(pParent->pChild == pFind)//删除孩子节点
				pParent->pChild = pFind->pSibling;
			else//删除兄弟节点
				pParent->pSibling = pFind->pSibling;
			
			pFind->pSibling = NULL;//摘除当前节点			
			Destroy(pFind);//删除当前节点
		}
	}else
		printf("指定删除节点不存在!\n");
}


void Delete2(NODE_PTR &pTree, char  *szName){
	if(pTree){
		if(strcmp(pTree->szName,szName)==0){
			NODE_PTR p;
			p = pTree;
			pTree=pTree->pSibling;
			p->pSibling = NULL;
			Destroy(p);
		}else{
			Delete2(pTree->pChild,szName);
			Delete2(pTree->pSibling,szName);
		}
	}
}

void Path(NODE_PTR pTree, SqStack &sq, char  *szName)
{
	char sz[32];
	if(pTree){
		Push(sq,pTree->szName);
		if(strcmp(pTree->szName,szName)==0)
			PrintStack(sq);
		Path(pTree->pChild,sq,szName);
		Pop(sq,sz);
		Path(pTree->pSibling,sq,szName);
	}

}


void PreVisit(NODE_PTR pTree)
{
	while(pTree)
	{
		printf("%s ",pTree->szName);
		PreVisit(pTree->pChild);
		pTree=pTree->pSibling;
	}
}

/*
void pre1(NODE_PTR pTree)
{
	if(pTree)
	{
		printf("%s ",pTree->szName);
		pre1(pTree->pChild);
		pre1(pTree->pSibling);
	}
}
*/


int main(int argc, char* argv[])
{
	int nChoice;
	NODE_PTR Tree = NULL;
	char  szP[64],szN[64],szEat[64],szDel[64],sz[64];
	char pszPath[128];
	pszPath[0]='\0';

	
	//_wsetlocale(LC_CTYPE,L"chs");//设置字符显示为中文方式

	for(; ;){
		printf("/******************************************");
		printf("\n*          名称：虚拟资源管理器           *");
		printf("\n*          作者：JRH,2020            *");
		printf("\n******************************************/\n");
		printf("1----先序字符串创建\n");
		printf("2----输入边创建\n");
		printf("3----凹入显示\n");
		printf("4----插入\n");
		printf("5----删除\n");
		printf("6----销毁\n");
		printf("7----路径\n");
		printf("8----先序\n");
		printf("0----退出\n");
		

		printf("请选择功能: ");
		scanf("%d", &nChoice);
		printf("\n");
		switch(nChoice){
		case 1:
			printf("请输入创建信息:\n");
			gets(szEat);//去除无效字符
			Create(Tree);
			break;
		case 2:
			printf("请输入创建信息:\n");
			gets(szEat);//去除无效字符
			CreateTree(Tree);
			break;
		case 3:
			Print(Tree, 0);
			break;
		case 4:
			printf("请输入父节点名: ");gets(szEat);gets(szP);
			printf("请输入新节点名: ");gets(szN);
			Insert(Tree, szP, szN);
			break;
		case 5:
			printf("请输入待删节点名: ");gets(szEat);gets(szDel);
			//Delete(Tree, szDel);
			Delete2(Tree, szDel);
			break;
		case 6:
			Destroy(Tree);
			break;
		case 7:
			printf("请输入节点名: ");gets(szEat);gets(sz);
			SqStack sq;
			InitStack(sq);
			Path(Tree,sq, sz);
			Destroy(sq);
			printf("\n");
			break;
		case 8:
			PreVisit(Tree);
			printf("\n");
			break;

		case 0:
			Destroy(Tree);
			return 0;
		}
	}
	
}
/*
root1
file1
file3
^
^
file2
^
^
root2
file4
^
file5
^
^
^


  */
