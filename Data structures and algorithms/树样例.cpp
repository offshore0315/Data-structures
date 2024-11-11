#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX_NAME_LEN  32

typedef struct tagNode{
	char szName[MAX_NAME_LEN];
	struct tagNode *pL,*pR;
}TNode, *PNode;
//ѭ�����е���������
typedef struct {
	PNode *elem;
	int front,rear;
	int queuesize;
}XhQueue;

//�й�ѭ�����е�һ�����
void InitQueue(XhQueue &Q,int maxsize){
	Q.elem=new PNode[maxsize];
	if(Q.elem!=NULL){
		Q.front=Q.rear=0;
		Q.queuesize=maxsize;
	}
}


void EnQueue(XhQueue &Q,PNode p){
	if((Q.rear+1)%Q.queuesize!=Q.front){
		Q.elem[Q.rear]=p;
        Q.rear=(Q.rear+1)%Q.queuesize;
	}
}

void DeQueue(XhQueue &Q,PNode &p){
	if(Q.front!=Q.rear){
		p=Q.elem[Q.front];
        Q.front=(Q.front+1)%Q.queuesize;
	}
}


void GetHead(XhQueue &Q,PNode &p){
	if(Q.front!=Q.rear){
		p=Q.elem[Q.front];
	}
}

int EmQueue(XhQueue Q){
	if(Q.front!=Q.rear)return 0;
	else return 1;
}
//�����ַ�������
void create(PNode &Root)
{
	char sz[MAX_NAME_LEN];
	scanf("%s",sz);
	if(strcmp(sz,"#")==0)
		Root = NULL;
	else{
		Root = new TNode;
		strcpy(Root->szName,sz);
		create(Root->pL);
		create(Root->pR);
	}
}
//����ߴ���
void CreateTree( PNode &T ) {
	char fa[30],ch[30];
	PNode p,s;
	int flag;
    XhQueue Q;
	InitQueue(Q,50);
	T = NULL;
	printf("�����븸��㡢�ӽ�㡢���ұ�־���ÿո������������˫��Ϊ#��\n");
    scanf("%s%s%d",fa, ch,&flag);
    for( ; strcmp(ch,"end"); ) {
		p =new TNode;    // �������
		strcpy(p->szName,ch);
		p->pL=p->pR=NULL;
		
		EnQueue(Q, p);// ָ�������
		if (strcmp(fa,"#")==0)  T = p;  // ����Ϊ�����
		else {// �Ǹ��������
			GetHead(Q,s);  // ȡ����ͷԪ��(ָ��ֵ)
			while (strcmp(s->szName,fa)) { // ��ѯ˫�׽��
				DeQueue(Q,s);  GetHead(Q,s); 
			}//while   
			
			if (flag==0){ 
				s->pL = p; 
			}// ��������
			else { 
				s->pR = p;
			}// �����Һ��� 
		}// �Ǹ��������
		printf("�����븸��㡢�ӽ�㡢���ұ�־���ÿո����������ʱ����end end 0\n");
		scanf("%s%s%d",fa,ch,&flag);
	} // for
}

void PreOrder(PNode Root)
{
	if(Root != NULL)
	{
		printf("%s ",Root->szName);
		PreOrder(Root->pL);
		PreOrder(Root->pR);
	}
}

void Aoru(PNode Root,int indent)
{
	if(Root != NULL){
		for(int i=0;i<indent;i++)
			printf("\t");
		printf("%s\n",Root->szName);

		Aoru(Root->pL,indent+1);
		Aoru(Root->pR,indent+1);

	}
}

void Layer(PNode Root)
{
	XhQueue q;
	PNode p;
	InitQueue(q,100);
	if(Root!=NULL)
		EnQueue(q,Root);

	while(EmQueue(q)==0){
		DeQueue(q,p);
		printf("%s ",p->szName);
		if(p->pL!=NULL)
			EnQueue(q,p->pL);
		
		if(p->pR!=NULL)
			EnQueue(q,p->pR);		
	}
	printf("\n");

}

////////////////////////////////////
//���Ҹ�������name�Ľ�㣬�����ؽ��ָ��f��ȫ�������꣬�ҵ���Ҳ��������
void Find(PNode Root, char *name, PNode &f)
{
	if(Root){
		if(strcmp(Root->szName,name)==0){
			f = Root;
		}
		else{
			Find(Root->pL, name, f);
			Find(Root->pR, name, f);
		}
	}
}

/////////////////////////////////////////
//���Ҹ�������name�Ľ�㣬�ҵ���ͷ���
PNode FindFast(PNode Root, char *name)
{
	
	PNode p;
	if(!Root) 
		return NULL;
	else{
		if(strcmp(Root->szName,name)==0)
			return Root;
		else if(p=FindFast(Root->pL, name))
			return p;
		else
			return FindFast(Root->pR, name);
		
	}
}


////////////////////////////////////
//���Ҹ�������name�Ľ�㣬�����ؽ��ĸ����ָ��p
void FindParent(PNode Root, char *name, PNode pL, PNode &p, PNode &f)
{
	if(Root == NULL)
		return;
	else if(strcmp(Root->szName, name) == 0){
		f = Root;
		p = pL;
		return;
	}else{
		FindParent(Root->pL, name, Root, p, f);
		FindParent(Root->pR, name, Root, p, f);
	}
}
//���ٶ�����
void Destroy(PNode p)
{
	if(p)
	{
		Destroy(p->pL);
		Destroy(p->pR);
		delete p;
	}
}



//ɾ���������ֵĽ��
void Delete(PNode& Root, char *name){

	if(Root){
		if(strcmp(Root->szName,name)==0){
			Destroy(Root);
			Root = NULL;
		}
		else{
			Delete(Root->pL, name);
			Delete(Root->pR, name);
		}
	}

}

//����cname��㣬��ָ������������pname
void Insert(PNode Root, char *pname, char *cname)
{
	PNode parent,pnew;
	Find(Root,pname, parent);
	if(parent==NULL){
		printf("����㲻����\n");
		return;
	}else{
		if(parent->pL&&parent->pR){
			printf("�ӽ������\n");
			return;
		}
		if(parent->pL){
			if(strcmp(parent->pL->szName,cname)==0){
				printf("ͬ���ӽ���Ѵ���\n");
				return;
			}
		}
		if(parent->pR){
			if(strcmp(parent->pR->szName, cname)==0){
				printf("ͬ���ӽ���Ѵ���\n");
				return;
			}
		}	
		
		pnew = new TNode;pnew->pL=pnew->pR=NULL;
		strcpy(pnew->szName, cname);		
		if(parent->pL==NULL)
			parent->pL = pnew;
		else
			parent->pR=pnew;


	}
}
//δ��ɣ�������
void Trans2Seq(PNode Root)
{
	char arr[100];
	XhQueue q;
	PNode p;


	int k=0;

	InitQueue(q,100);
	if(Root!=NULL){
		EnQueue(q,Root);
	}

	while(EmQueue(q)==0){
		DeQueue(q,p);

		if(p->pL!=NULL){
			EnQueue(q,p->pL);
			arr[k++]=p->pL->szName[0];
		}else
			arr[k++]='#';
		
		if(p->pR!=NULL){
			EnQueue(q,p->pR);	
			arr[k++]=p->pR->szName[0];
		}else
			arr[k++]='#';
	}

}

void main()
{
	PNode T,p;
	char choice;
	char sz1[32],sz2[32];

	for(;;){
	    printf("===========menu============\n");
		printf("1---create by preorder\n");
		printf("2---create by edge\n");
		printf("3---preorder display\n");
		printf("4---Aoru display\n");
		printf("5---Layer display\n");	
		printf("6---Find by name\n");	
		printf("7---insert node\n");
		printf("8---delete node\n");
		printf("9---transfer to seqence storage\n");
		printf("0---quit\n");

	printf("please choose��");
		scanf("%c",&choice);
		switch(choice){
		case '1':
			printf("�������ַ���[ncepu ee # # cs # #]:\n");
			create(T);
			break;
		case '2':
			printf("������ߴ���\n");
			CreateTree(T);
			break;
		case '3':
			PreOrder(T);
			printf("\n");
			break;
		case '4':
			Aoru(T,0);
			break;
		case '5':
			Layer(T);
			break;
		case '6':
			printf("��������ҽ������");
			scanf("%s", sz1);
			p = FindFast(T,sz1);
			if(p)
				printf("%x %s\n",p,p->szName);
			else
				printf("û�ҵ����\n");
			break;
		case '7':
			printf("�����븸��������½������(�м��ÿո����)��");
			scanf("%s %s", sz1,sz2);
			Insert(T, sz1, sz2);
			break;
		case '8':
			printf("������������");
			scanf("%s", sz1);
			Delete(T, sz1);
			break;
		case '9':
			Trans2Seq(T);
			break;
		case '0':
			printf("---bye-bye---\n");
			exit(0);
			break;
		default:
			printf("����ѡ�����\n");
			break;
		}
		getchar();
		
	}

}
/*

a b # c # # d e # # #

 */ 
 
 /*
       a
 b          d
     c   e




*/