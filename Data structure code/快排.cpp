#include<stdio.h>
int huafen(int a[],int L,int R){
	int mid=a[L];
	while(L<R){
		while(a[R]>=mid&&L<R) R--;
		a[L]=a[R];
		while(a[L]<=mid&&L<R) L++;
		a[R]=a[L];
	}
	a[L]=mid;
	return L;
}
void Qsort(int a[],int L,int R){
	if(L>=R) return;
	int M=huafen(a,L,R);
	Qsort(a,L,M-1);
	Qsort(a,M+1,R);
}

int main(){
	int a[10]={3,4,2,5,6,7,8,1,9,0};
	int i;
	Qsort(a,0,9);
	for(i=0;i<10;i++)
	printf("%d ",a[i]);
}
