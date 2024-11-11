#include<stdio.h>
typedef struct TNode{
	int data;
	struct TNode *lchild,*rchild;
}TNode,*Tree;

void PreOrder(Tree root){
	if(root==NULL) return;
	//visit(root);
	PreOrder(root->lchild);
	PreOrder(root->rchild);
	}
	
void InOrder(Tree root){
	if(root==NULL) return;
	InOrder(root->lchild);
//	visit(root);
	InOrder(root->rchild);
}	

void PostOrder(Tree root){
	if(root==NULL)return;
	PostOrder(root->lchild);
	PostOrder(root->rchild);
//	visit(root);
}


int main(){
	
}
