/*
	ԭ�����λѡ�������ұ�֤ÿһλ���ظ�
	ʱ�临�Ӷ� O(n!) 
*/ 
#include <stdio.h>
#define MAX 10
int arr[MAX] = { 0 }, visit[MAX] = { 0 };   // arr�����ŵ��ǵ�ǰ�����У�visit�����ŵ�������1~n�ĸ����Ѿ���ѡ���� 
int N;
void arrange(int count){ 					// count����ǰ�Ѿ�ѡ�˼����� 
	if (count == N){						// �ݹ�������� 
		for (int i = 0; i < N; i++){
			printf("%d", arr[i]);
		}
		putchar('\n');
		return;
	}
	for (int i = 1; i <= N; i++){
		if (!visit[i]){
			arr[count] = i;					// ���µ����������� 
			visit[i] = 1;					// ���������Ѿ��ù� 
			arrange(count+1);				// ѡ����һ���� 
			arr[count] = 0; 				// ��֮ǰ�ӵ���ȥ�� 
			visit[i] = 0;					// ѡ��ǰ��������Ѿ����꣬ȥ����� 
		}
	}
	return;
}
int main(void){
	printf("����N��N<10����");
	scanf("%d", &N);
	printf("ȫ���У�\n");
	arrange(0);
	return 0;
} 
