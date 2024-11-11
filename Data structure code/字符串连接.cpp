#include<stdio.h>
int main(){
	char a[10],b[10];
	gets(a);
	gets(b);
	int i,j,k;
	for(i=0;a[i]!='\0';i++)
	k++;
	for(i=k,j=0;b[j]!='\0';i++,j++)
	{
		a[i]=b[j];
	}
	puts(a);
}
