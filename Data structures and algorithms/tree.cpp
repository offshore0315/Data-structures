
/////////////////////////////////////////////////
//Desc��  ģ����Դ������,���ú��ӡ��ֵ�����
//        �ṹʵ�֡�
//Author��JRH
//Date:    5/11/2020
//
//#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "locale.h"
#include "stdlib.h"

/******************************************
�������ݽṹ
*******************************************/
//��������
typedef struct _Node{
	char  szName[64];
	struct _Node *pChild, *pSibling;
}NODE, *NODE_PTR;

//ѭ�����е���������
typedef struct {
	NODE_PTR *elem;
	int front,rear;
	int queuesize;
}XhQueue;



//�й�ѭ�����е�һ�����
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
		printf("\nջΪ��!\n");
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
		printf("\nջ��!������ջ!\n");
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
		printf("\nջ��!\n");
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
��ʽ��void Create(NODE_PTR &pTree) 
���ܣ���������
���룺��ָ�����ñ�����
������ޡ�
��ע���������ĺ���-�ֵ�����ʽ��������������룬���Ϊ��������^�����磺
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

*********************************************///���������ַ��������ķ�ʽ
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
/*********************************************///����ߴ����ķ�ʽ
void CreateTree( NODE_PTR &T ) {
	char fa[30],ch[30];
	NODE_PTR p,s,r;
    XhQueue Q;
	InitQueue(Q,50);
	T = NULL;
	printf("�����븸�����ӽ�㣨�ÿո������������˫��Ϊ#��\n");
    scanf("%s%s",fa, ch);
    for( ; strcmp(ch,"end"); ) {
		p =new  NODE;    // �������
		strcpy(p->szName,ch);
		p->pChild=p->pSibling=NULL;
		
		EnQueue(Q, p);// ָ�������
		if (strcmp(fa,"#")==0)  T = p;  // ����Ϊ�����
		else {// �Ǹ��������
			GetHead(Q,s);  // ȡ����ͷԪ��(ָ��ֵ)
			
			while (strcmp(s->szName,fa)) { // ��ѯ˫�׽��
				DeQueue(Q,s);  GetHead(Q,s); 
			}//while   
			
			if (!(s->pChild)){ 
				s->pChild = p; 
				r = p; 
			}// ���ӵ�һ�����ӽ��
			else { 
				r->pSibling = p;  r = p; 
			}// �����������ӽ�� 
		}// �Ǹ��������
		printf("�����븸�����ӽ�㣨�ÿո����������ʱ����end end��\n");
		scanf("%s%s",fa,ch);
	} // for
}


/********************************************
��ʽ��void Destroy(NODE_PTR pTree)
���ܣ���������
���룺���ڵ�ָ�����á�
������ޡ�
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
��ʽ��void Print(NODE_PTR pTree, int indent)
���ܣ��԰�������ʽ�����ʾ��
���룺
	pTree�� ���ڵ�ָ�롣
	indent�������μ�����
������ޡ�
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
��ʽ��void Find(NODE_PTR pTree, char  *szName, NODE_PTR &p)
���ܣ�����ָ�����ƽڵ㡣
���룺
	pTree�� ���ڵ�ָ�롣
	szName�������ڵ�����
	p��		���ҵ�������Ϊ�ڵ�ָ�롣
������ޡ�
��ע���ڵ��ú���ʱ��p��ʵ�α���ֵ����ΪNULL��
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
//��pTree���Һ��ӽڵ�
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
��ʽ��void Find(NODE_PTR pTree, char  *szName, NODE_PTR &pLast, NODE_PTR &p1, NODE_PTR &p2)
���ܣ�����ָ�����ƽڵ㼰����������µĸ��ڵ�(��Ӧ���У�Ӧ�Ǹ��ڵ�����ֵܽڵ�)��
���룺
	pTree�� ��ǰ�ڵ��ָ�롣
	szName�����ҵĽڵ����ơ�
	pLast�� ��ǰ�ڵ�ĸ��ڵ㡣
	p1��	�ҵ����ĸ��ڵ�ָ�롣
	p2:     �ҵ��ڵ��ָ�롣
������ޡ�
��ע���ڵ��ú���ʱ��pLast,p1��p2��ʵ�α���ֵ����ΪNULL��
*********************************************/
void Find(NODE_PTR pTree, char  *szName, NODE_PTR &pLast, NODE_PTR &p1, NODE_PTR &p2)
{
	if(pTree == NULL) return;
	if(strcmp(pTree->szName, szName) == 0){//�ҵ��򷵻ظ��ڵ�ָ��͵�ǰ�ڵ�ָ��
		p2 = pTree;//��ǰ�ڵ�
		p1 = pLast;//���ڵ�
	}
	else{
		pLast = pTree;//�ݴ���һ���ڵ�ָ��
		Find(pTree->pChild, szName, pLast, p1, p2);
		pLast = pTree;
		Find(pTree->pSibling, szName, pLast, p1, p2);
	}
}

/********************************************
void Insert(NODE_PTR pTree, char  *szParent, char  *szNew)
���ܣ������½ڵ㡣
���룺
	pTree�� ���ڵ�ָ�롣
		szParent�����ڵ�����
	szNew��   �½ڵ�����
������ޡ�
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
				printf("�ӽڵ��Ѵ��ڣ�\n");
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
		printf("���ڵ㲻����!\n");

}
/********************************************
void Delete(NODE_PTR &pTree, char  *szName){
���ܣ�ɾ��ָ���ڵ㡣
���룺
	pTree�� ���ڵ�ָ�롣
	szName����ɾ���ڵ�����
������ޡ�
*********************************************/
void Delete(NODE_PTR &pTree, char  *szName){
	NODE_PTR pFind = NULL, pParent = NULL, p = NULL;

	Find(pTree, szName, p, pParent, pFind);
	
	if(pFind){
		if(pParent == NULL){//ɾ�����ڵ�
			Destroy(pTree);
			pTree = NULL;
		}else{
			if(pParent->pChild == pFind)//ɾ�����ӽڵ�
				pParent->pChild = pFind->pSibling;
			else//ɾ���ֵܽڵ�
				pParent->pSibling = pFind->pSibling;
			
			pFind->pSibling = NULL;//ժ����ǰ�ڵ�			
			Destroy(pFind);//ɾ����ǰ�ڵ�
		}
	}else
		printf("ָ��ɾ���ڵ㲻����!\n");
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

	
	//_wsetlocale(LC_CTYPE,L"chs");//�����ַ���ʾΪ���ķ�ʽ

	for(; ;){
		printf("/******************************************");
		printf("\n*          ���ƣ�������Դ������           *");
		printf("\n*          ���ߣ�JRH,2020            *");
		printf("\n******************************************/\n");
		printf("1----�����ַ�������\n");
		printf("2----����ߴ���\n");
		printf("3----������ʾ\n");
		printf("4----����\n");
		printf("5----ɾ��\n");
		printf("6----����\n");
		printf("7----·��\n");
		printf("8----����\n");
		printf("0----�˳�\n");
		

		printf("��ѡ����: ");
		scanf("%d", &nChoice);
		printf("\n");
		switch(nChoice){
		case 1:
			printf("�����봴����Ϣ:\n");
			gets(szEat);//ȥ����Ч�ַ�
			Create(Tree);
			break;
		case 2:
			printf("�����봴����Ϣ:\n");
			gets(szEat);//ȥ����Ч�ַ�
			CreateTree(Tree);
			break;
		case 3:
			Print(Tree, 0);
			break;
		case 4:
			printf("�����븸�ڵ���: ");gets(szEat);gets(szP);
			printf("�������½ڵ���: ");gets(szN);
			Insert(Tree, szP, szN);
			break;
		case 5:
			printf("�������ɾ�ڵ���: ");gets(szEat);gets(szDel);
			//Delete(Tree, szDel);
			Delete2(Tree, szDel);
			break;
		case 6:
			Destroy(Tree);
			break;
		case 7:
			printf("������ڵ���: ");gets(szEat);gets(sz);
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
