/*实现一个二叉树管理功能，结点存储字符串：
9.输出所有叶子结点的路径。*/

#include <cstdio>
#include <queue>
#include <iostream>
#include <string.h>

using namespace std;

struct Tree{
	char data;
	Tree* left;
	Tree* right;
	Tree(char d,Tree* l,Tree* r){
		data = d;
		left = l;
		right = r;
	}
};
int pos,len;

void build(Tree** t,char *str){//建树 
	pos++;
	char ch = str[pos];
	if (pos>strlen(str))	return;
	if (ch=='#')	*t = NULL;
	else{
		*t = new Tree(ch,NULL,NULL);
		build(&(*t)->left,str);
		build(&(*t)->right,str);
	}
}

void preorder(Tree* t){//先序遍历 
	if(t==NULL)	return;
	printf("%c ",t->data);
	preorder(t->left);
	preorder(t->right);
}

void displayTree(Tree* t,int level,char belong){//凹入输出 
	int i;
	if (t==NULL)	return;
	for (i = 1; i<level; i++)	printf(" ");
	printf("%c(%c)",t->data,belong);
	for (int j = i+4; j<20; j++)	printf("-");printf("\n");
	displayTree(t->left,level+1,'L');
	displayTree(t->right,level+1,'R');
}

void printTree(Tree* t){//按层次遍历输出 
	queue<Tree*> Q;
	Q.push(t);
	while (!Q.empty()){
		Tree* p = Q.front();Q.pop();
		printf("%c ",p->data);
		if (p->left!=NULL) Q.push(p->left);
		if (p->right!=NULL) Q.push(p->right);
	} 
	printf("\n");
}

void find(Tree* t,char ch,Tree** p,bool* q){
	if (t->data==ch){
		*p = t;
		*q = true;
		return;
	}
	if (*q)	return;
	if (t->left!=NULL) find(t->left,ch,p,q);
	if (t->right!=NULL)	find(t->right,ch,p,q);
}

void insert(Tree* t,char fa,char node){
	Tree* p = NULL;
	bool q = false;
	find(t,fa,&p,&q);
	if (q==false){
		printf("the node don't exist\n");
		return; 
	}
	Tree* son = new Tree(node,NULL,NULL);
	if (p->left==NULL)	p->left = son;
	else p->right = son;
	return;
} 

void Delete(Tree* t,char node){
	if (t==NULL)	return;
	if (t->left!=NULL && t->left->data==node)	t->left = NULL;
	if (t->right!=NULL && t->right->data==node)	t->right = NULL;
	Delete(t->left,node);
	Delete(t->right,node);
}

void copy(Tree** nt,Tree* t){
	if (t==NULL)	return;
	(*nt) = new Tree(t->data,NULL,NULL);
	copy(&(*nt)->left,t->left);
	copy(&(*nt)->right,t->right);
}

void road(Tree* t,char *s){
	if (t->left==NULL && t->right==NULL){
		for (int i = 0; i<len; i++)
			printf("%c->",s[i]);
		printf("%c\n",t->data);
		return; 
	}
	s[len] = t->data;
	len++;
	if (t->left!=NULL)	road(t->left,s);
	if (t->right!=NULL) road(t->right,s);
	len--;
}

int main(){
	char ch,ch1;
	char str[80];
	scanf("%s",str);
	scanf("%c",&ch);
	pos = -1;
	Tree* t = new Tree('0',NULL,NULL);
	t = NULL;
	build(&t,str);
	
	preorder(t);printf("\n");
	
	displayTree(t,1,'D');
	
	printTree(t);
	
	printf("please input the value of the node you want:");
	scanf("%c",&ch);scanf("%c",&ch1);
	Tree* where = NULL;
	bool Find = false;
	find(t,ch,&where,&Find);
	if (Find)	cout<<where<<endl;
	else printf("no such node\n");
	
	printf("please input fa point and the point you want to insert:");
	scanf("%c %c",&ch,&ch1);
	insert(t,ch,ch1);
	preorder(t);printf("\n");
	scanf("%c",&ch);
	
	printf("please input the point you want to delete:");
	scanf("%c%c",&ch,&ch1);
	Delete(t,ch);
	preorder(t);printf("\n");
	
	Tree* ntree = NULL;
	copy(&ntree,t);
	preorder(ntree);printf("\n");

	char rec[80];
	rec[0] = '\0';
	road(t,rec);
} 
