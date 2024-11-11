#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 #define MAX 150
 typedef struct{
 	int *data;
 	int length;
 	int top;
 }SqStack;
 typedef struct {
 	char *a;
 	int length;
 	int top;
 }LinkStack;
 int main()
 {
 	int initSqStack(SqStack *LS);
 	int initLinkStack(LinkStack *LS);
 	int SqStackEmpty(SqStack s);
 	int LinkStackEmpty(LinkStack s);
 	int SqStackFull(SqStack s);
 	int LinkStackFull(LinkStack s);
 	int GetTop(SqStack s,int *e);
 	int LinkStackGetTop(LinkStack s,char *e);
 	int SqStackPush(SqStack *s,int n);
 	int LinkStackPush(LinkStack *s,char n);
 	int SqStackPop(SqStack *s,int *n);
 	int LinkStackPop(LinkStack *s,char *n);
 	int transform(LinkStack p,char num[],char num01[]);
 	int prior(char a);
	int n,i = 0,a,b;
	char num[50];
	char num01[150];
 	SqStack s;
 	LinkStack p;
	initLinkStack(&p);
 	initSqStack(&s);
 	printf("请输入需要计算的公式\n");
 	scanf("%s",num);
 	transform(p,num,num01);
/*	printf("%s\n",num01);*/
	while(num01[i]!='\0'){
		if(num01[i] >= '0' && num01[i] <= '9'){
			a = num01[i] - '0';
			SqStackPush(&s,a);
		}
		else{
			switch(num01[i]){
				case '+':SqStackPop(&s,&a);
						SqStackPop(&s,&b);
						a = a + b;
						SqStackPush(&s,a);
						break;
				case '-':
						SqStackPop(&s,&a);
						SqStackPop(&s,&b);
						a = b - a;
						SqStackPush(&s,a);
						break;
				case '*':
						SqStackPop(&s,&a);
						SqStackPop(&s,&b);
						a = a * b;
						SqStackPush(&s,a);
						break;
				case '/':
						SqStackPop(&s,&a);
						SqStackPop(&s,&b);
						a = b / a;
						SqStackPush(&s,a);
						break;
			}
		}
		i++;
	}
	SqStackPop(&s,&a);
	printf("结果是%d\n",a);
	return 0;
 }
 //初始化计算栈 
 int initSqStack(SqStack *LS)
 {
 	LS -> data = (int *)malloc(MAX * sizeof(int));
	if(LS -> data == NULL){
		printf("申请空间失败\n");
		return 0;
	}
	LS -> length = MAX;
	LS -> top = -1;
	return 1;
 }
 //初始化后缀表达式栈
 int initLinkStack(LinkStack *LS)
{
	LS -> a = (char *)malloc(MAX * sizeof(char));
	if(LS -> a == NULL){
		printf("申请空间失败\n");
		return 0;
	}
	LS -> length = MAX;
	LS -> top = -1;
	return 1;
} 
 //判断栈空
 int SqStackEmpty(SqStack s)
{
	if(s.top == -1){
		return 1;
	}
	return 0;
}
 int LinkStackEmpty(LinkStack s)
{
	if(s.top == -1){
		return 1;
	}
	return 0;
}
//判断栈满
int SqStackFull(SqStack s)
{
	if(s.top == s.length -1){
		return 1;
	}
	return 0;
}
int LinkStackFull(LinkStack s)
{
	if(s.top == s.length -1){
		return 1;
	}
	return 0;
}
//取栈顶元素
int GetTop(SqStack s,int *e)
{
	if(SqStackEmpty(s)){
		return 0;
	}else{
		*e = s.data[s.top];
	}
	return 1;
}
int LinkStackGetTop(LinkStack s,char *e)
{
	if(LinkStackEmpty(s)){
		return 0;
	}else{
		*e = s.a[s.top];
	}
	return 1;
}
//入栈
int  SqStackPush(SqStack *s,int n)
{
	s->top++;
	s->data[s->top] = n;
	return 1;
}
int  LinkStackPush(LinkStack *s,char n)
{
	 s->top++;
	s->a[s->top] = n;
	return 1;
}
//出栈
int SqStackPop(SqStack *s,int *n)
{
	*n = s->data[s->top];
	s->top--;
	return 1;
}
int LinkStackPop(LinkStack *s,char *n)
{
	*n = s->a[s->top];
	s->top--;
	return 1;
}
int prior(char a){
	if(a=='*'||a=='/'){
		return 4;
	}
	else if(a == '+' || a == '-'){
		return 3;
	}
	else if(a == '('){
		return 2;
	}
	else if(a == '#'){
		return 1;
	}
	else{
		return 0;
	}
}
int transform(LinkStack p,char num[],char num01[])
{
	int i = 0,n,k = 0;
	char ch;
	LinkStackPush(&p,'#');
	n = strlen(num);
	num[n] = '#';
	num[n+1] = '\0';
	while(num[i]!='\0'){
		if(num[i] >= '0' && num[i] <= '9'){
			num01[k++] = num[i];
		}else{
			switch(num[i]){
				case '(':LinkStackPush(&p,num[i]);
							break;
				case ')':LinkStackGetTop(p,&ch);
						while(ch!='('){
							num01[k++] = ch;
							LinkStackPop(&p,&ch);
							LinkStackGetTop(p,&ch);
						}
						LinkStackPop(&p,&ch);
						break;
				default:
						if(num[i]!='#'){
							LinkStackGetTop(p,&ch);
							while(prior(ch) >= prior(num[i])){
							num01[k++] = ch;
							LinkStackPop(&p,&ch);
							LinkStackGetTop(p,&ch);
						}
							LinkStackPush(&p,num[i]);
						}else if(num[i] == '#'){
							LinkStackPop(&p,&ch);
							while(ch!='#'){
								num01[k++] = ch;
								LinkStackPop(&p,&ch);
							}
						}
			}
		}
		i++;
	}
	num01[k++] = '\0';
	return 1;
	
}
