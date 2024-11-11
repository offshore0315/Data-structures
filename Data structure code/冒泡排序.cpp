#include<stdio.h> 
int main(){
	int a[10]={12,20,3,5,6,7,8,1,9,0};
	int i,j,temp=0;
	for(i=0;i<10-1;i++)
	{
		for(j=0;j<10-i-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(i=0;i<10;i++)
	printf("%d ",a[i]);
}

//for(i=0;i<n-1;i++)
//  for(j=0;j<n-i-1;j++)
