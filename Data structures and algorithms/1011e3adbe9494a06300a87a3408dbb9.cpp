/*
	原理：逐个位选数，并且保证每一位不重复
	时间复杂度 O(n!) 
*/ 
#include <stdio.h>
#define MAX 10
int arr[MAX] = { 0 }, visit[MAX] = { 0 };   // arr数组存放的是当前的排列，visit数组存放的是数字1~n哪个数已经被选过了 
int N;
void arrange(int count){ 					// count代表当前已经选了几个数 
	if (count == N){						// 递归结束条件 
		for (int i = 0; i < N; i++){
			printf("%d", arr[i]);
		}
		putchar('\n');
		return;
	}
	for (int i = 1; i <= N; i++){
		if (!visit[i]){
			arr[count] = i;					// 将新的数加入排列 
			visit[i] = 1;					// 标记这个数已经用过 
			arrange(count+1);				// 选择下一个数 
			arr[count] = 0; 				// 把之前加的数去掉 
			visit[i] = 0;					// 选择当前数的情况已经找完，去掉标记 
		}
	}
	return;
}
int main(void){
	printf("输入N（N<10）：");
	scanf("%d", &N);
	printf("全排列：\n");
	arrange(0);
	return 0;
} 
