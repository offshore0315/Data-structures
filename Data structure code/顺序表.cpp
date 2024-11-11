#include<stdio.h>
#define MaxSize 50
typedef struct SqList{
	int data [MaxSize];
	int length;
}SqList; 

//����
bool ListInsert(SqList &L,int i,int e){
	if(i<1||i>L.length+1)
	return false;
	if(L.length>=MaxSize)
	return false;
	for(int j=L.length;j>=i;j--){//���� 
		L.data[j]=L.data[j-1];
	}
	L.data[i-1]=e;
	L.length++;
	return true;
} 
//ɾ��
bool ListDelete (SqList &L,int i,int &e){
	if(i<1||i>L.length)
	return false;
	e=L.data[i-1];
	for(int j=i;j<L.length;j++){//ǰ�� 
		L.data[j-1]=L.data[j];
	}
	L.length--;
}

//��ѯ ����ֵ��

int Locate(SqList L,int e){
	int i;
	for(i=0;i<L.length;i++){
		if(L.data[i]==e)
		return i+1;
	}
	return 0;
} 

//Ԫ������
 void Reverse(SqList &L){
 	int temp;
 	for(int i=0;i<L.length/2;i++){
 		temp=L.data[i];
 		L.data[i]=L.data[L.length-i-1];
 		L.data[L.length-i-1]=temp;
	 }
 } 

int main(){
	
}
