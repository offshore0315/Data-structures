#include<stdio.h>
#include<math.h>
#include<cstdlib> 
typedef struct student{
	int age;
	struct student *next;
}LinkList;

LinkList* creat(int n){
	LinkList *head,*node,*end;
	head=(LinkList*)malloc(sizeof(LinkList));
	end=head;
	for(int i=0;i<n;i++){
		node=(LinkList*)malloc(sizeof(LinkList));
		scanf("%d",&node->age);
		end->next=node;
		end=node;
	}
	end->next=NULL;
	return head;
}

void Print(LinkList* t,int n){
	int i = 0;
	while(i<n&&t!=NULL){
	 	t=t->next;
	 	i++;
	 	printf("%d ",t->age);
 	}
}
void delet (LinkList *list,int n)
{
	LinkList*t=list,*in;
	int i=0;
	while(i<n&&t!=NULL)
	{
		in=t;
		t=t->next;
		i++;
	}
	if(t!=NULL)
	{
		in->next=t->next;
		free(t);
	}
	else{
		puts("节点不存在");
	}
}
int main(){
	 int n = 10;
	 LinkList* t = creat(n);
	 Print(t,n);
}
