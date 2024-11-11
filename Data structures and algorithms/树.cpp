#include<stdio.h>
#include<stdlib.h>
# define MAXLEN 100
typedef struct BiTNode{
	char data_1;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode,*BiTree;
typedef struct {
	int front;
	int rear;
	int queueSize;
	BiTree data[MAXLEN];
}SqQueue;
typedef struct stack{
	BiTree data_2[MAXLEN];
	int top;
	int stackSize;
}SqStack;
//初始化栈
int initSqStack(SqStack *LS)
{
	LS -> top = -1;
	LS -> stackSize = MAXLEN;
	return 1;	
}
//判断栈空
int SqStackEmpty(SqStack LS)
{
	if(LS.top == -1){
		return 1;
	}
	return 0;
}
//取栈顶元素
int SqStackGetTop(SqStack S,BiTree *x)
{
	if(SqStackEmpty(S) == 1)
	{
		return 0;
	}
	*x = S.data_2[S.top];
	return 1;
}
//进栈
int SqStackPush(SqStack *LS,BiTree x)
{
	if(LS -> stackSize == LS -> top+1) return 0;
	LS -> top++;
	LS -> data_2[LS->top] = x;
	return 1;
}
//出栈
int SqStackPop(SqStack *LS,BiTree *x)
{
	if(LS -> top == -1){
		return 0;
	}
	*x = LS -> data_2[LS->top];
	LS -> top--;
	return 1;
}
//遍历栈
int SqStackTravers(SqStack S)
{
	int k;
	if(SqStackEmpty(S) == 1){
		return 0;
	}
	for(k=S.top;k>=0;k--){
		printf("%c",S.data_2[k] -> data_1);
	}	
	printf("\n");
	return 1;
} 
//初始化队列 
int initSqQueue(SqQueue * LQ)
{
	LQ -> front = LQ -> rear = 0;
	LQ -> queueSize = MAXLEN;
	return 1;
}
//判断队列是否为空 
int SqQueueEmpty(SqQueue *LQ)
{
	if(LQ -> front == LQ -> rear) return 1;
	return 0;
}
//求队列的长度 
int SqQueueLength(SqQueue LQ)
{
	int length;
	length = (LQ.rear - LQ.front + LQ.queueSize) % LQ.queueSize;
	return length;
}
//取队首元素 
int SqGetHead(SqQueue *LQ,BiTree *x)
{
	if(LQ -> front == LQ -> rear) return 0;
	*x = LQ -> data[LQ -> front];
	return 1;
}
//入队列 
int SqEnQueue(SqQueue *LQ,BiTree x)
{
	if((LQ -> rear + 1) % LQ -> queueSize == LQ -> front) return 0;
	LQ -> data[LQ -> rear] = x;
	LQ -> rear = (LQ -> rear + 1) % LQ -> queueSize;
	return 1;
}
//出队列 
int SqDeQueue(SqQueue *LQ,BiTree *x)
{
	if(LQ -> rear == LQ -> front) return 0;
	*x = LQ -> data[LQ -> front];
	LQ -> front = (LQ -> front + 1) % LQ -> queueSize;
	return 1;
}
//遍历队列
void SqQueueTravers(SqQueue LQ)
{
	int p = LQ.front;
	while(p != (LQ.rear + 1) % LQ.queueSize){
		printf("%c ",LQ.data[p]);
		p = (p+1) % LQ.queueSize;
	}
	printf("\n");
}
//以字符串根左子树右子树的形式创建二叉链表
void create_tree(BiTree *T)
{
	char ch;
	scanf("%c",&ch);
	if(ch == '#') *T = NULL;
	else{
		*T = (BiTree) malloc(sizeof(BiTNode));
		(*T) -> data_1 = ch;
		create_tree(&(*T) -> lchild);
		create_tree(&(*T) -> rchild);
	}
}
//读入边创建二叉链表的非递归算法
void Creat_BiTree(BiTree *T,SqQueue *Q)
{
	BiTree s,m;
	*T = NULL;
	char fa,ch;
	int lrflag;
	scanf("%c%c%d",&fa,&ch,&lrflag);
	while(ch!='#'){
		BiTree p;
		p = (BiTree) malloc (sizeof(BiTNode));
		p -> data_1 = ch;
		p -> lchild = p -> rchild = NULL;
		SqEnQueue(Q,p);
		if(fa == '#') *T = p;
		else{
			SqGetHead(Q,&s);
			while(s -> data_1 != fa){
				SqDeQueue(Q,&m);
				SqGetHead(Q,&s);
			}
			if(lrflag == 0)
			s -> lchild = p;
			else s -> rchild = p;
		}
		getchar();
		scanf("%c%c%d",&fa,&ch,&lrflag);
	}
}
//层次遍历算法
void layer(BiTree T,SqQueue *Q)
{
	initSqQueue(Q);
	BiTree m;
	if(T){
		SqEnQueue(Q,T);
	}
	while(!SqQueueEmpty(Q)){
		SqDeQueue(Q,&m);
		printf("%c",m -> data_1);
		if(m->lchild) SqEnQueue(Q,m->lchild);
		if(m->rchild) SqEnQueue(Q,m->rchild);
	}
} 
//先序输出 
void preorder(BiTree T)
{
	if(T){
		printf("%c",T -> data_1);
		preorder(T->lchild);
		preorder(T->rchild);
	}
}
//实现二叉树的凹入输出
void dispBitree(BiTree T,int level,char c)
{
	int i,k;
	if(T){
		for(i = 1;i < level;i++)putchar(' ');
		printf("%c(%c)+",T->data_1,c);
		for(k=i+4;k<20;k++)putchar('-');
		printf("\n");
		dispBitree(T->lchild,level+2,'L');
		dispBitree(T->rchild,level+2,'R');
	}
 }
//实现查找指定名称的结点并返回指针
BiTree layer_findName(BiTree T,SqQueue *Q)
{
	initSqQueue(Q);
	BiTree m;
	char c;
	printf("请输入数据\n");
	scanf("%c",&c);
	if(T){
		SqEnQueue(Q,T);
	}
	while(!SqQueueEmpty(Q)){
		SqDeQueue(Q,&m);
		//printf("%c",m -> data_1);
		if(m -> data_1 == c){
			return m;
		}
		if(m->lchild) SqEnQueue(Q,m->lchild);
		if(m->rchild) SqEnQueue(Q,m->rchild);
	}		
}
//插入指定名称的节点
int	insertBiTNode(BiTree T,SqQueue *Q)
{
	printf("请分别输入父节点和子节点以及是L还是R\n");
	char fa,ch;
	int lrflag;
	scanf("%c%c%d",&fa,&ch,&lrflag);
	initSqQueue(Q);
	BiTree m,n;
	n = (BiTree) malloc (sizeof(BiTNode));
	n -> data_1 = ch;
	n -> lchild = NULL;
	n -> rchild = NULL;
	if(T){
		SqEnQueue(Q,T);
	}
	while(!SqQueueEmpty(Q)){
		SqDeQueue(Q,&m);
		if(m -> data_1 == fa){
			if(lrflag == 0 && m -> lchild == NULL){
				m -> lchild = n;
			}
			if(lrflag == 1 && m -> rchild == NULL){
				m -> rchild = n;
			}
		}
		if(m->lchild) SqEnQueue(Q,m->lchild);
		if(m->rchild) SqEnQueue(Q,m->rchild);
	}
	return 1;
}
//生成一个二叉树的节点
BiTree GetTreeNode(char c,BiTree lptr,BiTree rptr)
{
	BiTree T;
	T = (BiTree) malloc (sizeof(BiTNode));
	if(T == NULL){
		printf("申请空间失败\n");
		return NULL;
	}
	T -> data_1 = c;
	T -> lchild = lptr;
	T -> rchild = rptr;
	return T;
} 
//复制二叉树,返回一个根节点 
BiTree CopyTree(BiTree T)
{
	if(!T) return NULL;
	BiTree newlptr,newrptr,newT;
	if(T->lchild){
		newlptr = CopyTree(T->lchild);
	}
	else{
		newlptr = NULL;
	}
	if(T->rchild){
		newrptr = CopyTree(T->rchild);
	}
	else{
		newrptr = NULL;
	}
	newT = GetTreeNode(T->data_1,newlptr,newrptr);
	return newT;
}
//利用回溯算法，输出叶子节点的路径
void OutPutBiTNode(BiTree T,SqQueue Q)
{
	if(T != NULL){
		SqEnQueue(&Q,T);
	}
	if(T->lchild != NULL){
		OutPutBiTNode(T->lchild,Q);
	}
	if(T->rchild != NULL){
		OutPutBiTNode(T->rchild,Q);
	}
	if(T->lchild == NULL && T->rchild == NULL){
		BiTree F;
		while(Q.front != (Q.rear) % Q.queueSize){
			SqGetHead(&Q,&F);
			printf("%c",F->data_1);
			Q.front++;
		}
		printf("\n");
		return;
	}
}
//非递归实现中序输出
int inorder(BiTree T,BiTree *N,char num)
{
	BiTree x;
	int flag = 0;
	x = T;
	SqStack S;
	initSqStack(&S);
	while(x || S.top != -1){
		if(x){
			SqStackPush(&S,x);
			x = x -> lchild;	
		}
		else{
			SqStackPop(&S,&x);
			if(flag == 1){
				*N = x;
				break;
			}
			//printf("%c",x->data_1);
			if(x->data_1 == num){
				flag = 1;
			}
			x = x -> rchild;
		}
	}
	return 1;
}
//寻找删除节点的父节点 
int findDeBiTree(BiTree T,BiTree *N,char num)
{
	SqQueue Q;
	initSqQueue(&Q);
	BiTree m;
	if(T){
		SqEnQueue(&Q,T);
	}
	while(!SqQueueEmpty(&Q)){
		SqDeQueue(&Q,&m);
		if(m->lchild != NULL && m->rchild == NULL){
			if(m->lchild->data_1 == num){
				*N = m;
				break;
			}
		}
		if(m->lchild == NULL && m->rchild != NULL){
			if(m->rchild->data_1 == num){
				*N = m;
				break;
			}
		}
		if(m->lchild != NULL && m->rchild != NULL){
			if(m->lchild->data_1 == num){
				*N = m;
				break;
			}
			if(m->rchild->data_1 == num){
				*N = m;
				break;
			}
		}
		
		if(m->lchild) SqEnQueue(&Q,m->lchild);
		if(m->rchild) SqEnQueue(&Q,m->rchild);
	}	
} 
//递归实现中序递归输出
int inorder_1(BiTree T)
{
	if(T){
		inorder_1(T->lchild);
		printf("%c",T->data_1);
		inorder_1(T->rchild);
	}
	return 1;
 } 
int main()
{
	//以字符串根左子树右子树的形式创建二叉链表
	//create_tree(&T);
	SqQueue Q;
	BiTree T,L,N,M,E,P,S;
	char num;
	
	//初始化队列 
	initSqQueue(&Q);
	
	//读入边创建二叉链表的非递归算法 
	Creat_BiTree(&T,&Q);
	
	//先序输出 
	preorder(T);
	printf("\n");
	
	//删除节点 
	getchar();
	printf("请输出想要删除的节点\n");
	scanf("%c",&num);
	findDeBiTree(T,&E,num);
	if(E -> lchild != NULL && E->lchild->data_1 == num){
		P = E -> lchild;
	}
	else if(E -> rchild != NULL && E->rchild->data_1 == num){
		P = E -> rchild;
	}
	if(P -> lchild == NULL && P -> rchild == NULL){
		if(E->lchild->data_1 == num){
			P = E -> lchild;
			E -> lchild = NULL;
			free(P);
		}
		else if(E->rchild->data_1 == num){
			P = E -> rchild;
			E -> rchild = NULL;
			free(P);
		}
	}
	else if((P -> lchild != NULL && P -> rchild == NULL) || (P -> lchild == NULL && P -> rchild != NULL)){
		if(P -> lchild != NULL && P -> rchild == NULL){
			P = P -> lchild;
		}
		else if(P -> lchild == NULL && P -> rchild != NULL){
			P = P -> rchild;
		}
	}
	else if(P -> lchild != NULL && P -> rchild != NULL ){
		inorder(T,&M,num);
		if(E -> lchild != NULL && E->lchild->data_1 == num){
			P = E -> lchild;
			E -> rchild = M;
			M -> lchild = P -> lchild;
			if(M -> lchild == M){
				M -> lchild = NULL;
			}
			M -> rchild = P -> rchild;
			if(M -> rchild == M){
				M -> rchild = NULL;
			}
			free(P);
		}
		else if(E -> rchild != NULL && E->rchild->data_1 == num){
			P = E -> rchild;
			E -> rchild = M;
			M -> lchild = P -> lchild;
			if(M -> lchild == M){
				M -> lchild = NULL;
			}
			M -> rchild = P -> rchild;
			if(M -> rchild == M){
				M -> rchild = NULL;
			}
			free(P);
		}
	}
	
	//inorder_1(T);
	
	//层次遍历 
	layer(T,&Q);
	printf("\n");
	
	//实现二叉树的凹入输出
	/*dispBitree(T,0,'D');
	printf("\n");*/
	
	//利用层次遍历进行节点查找
	/*getchar();
	L = layer_findName(T,&Q);
	printf("该元素是\n");
	printf("%c\n",L->data_1);*/
	
	//插入新的节点
	//getchar();
	//insertBiTNode(T,&Q);
	//printf("\n");
	//进行输出检查 
	//layer(T,&Q);
	
	//进行二叉树的复制 
	//N = CopyTree(T);
	//输出检查 
	//preorder(N);
	//printf("\n");
	
	//利用回溯算法,输出叶子节点的路径
	 //initSqQueue(&Q);
	 //OutPutBiTNode(T,Q);
	return 0;
}
