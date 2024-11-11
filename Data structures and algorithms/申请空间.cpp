#include<stdio.h>
void main()
{
  float a[10];
  int i,j,m;
  float *p=a;
  for(i=0;i<10;i++)
  scanf("%f",&a[i]);
  for(p=a;p<a+10;p++)
  printf("%f ",*p);
  
  float*k= new float[10];
  for(j=0;j<10;j++)
  scanf("%f",&k[j]);
  for(j=0;j<10;j++)
  printf("%f ",k[j]);
  delete[]k;
}
malloc的语法是：
指针名=（数据类型*）malloc（长度），（数据类型*）表示指针。
eg: int*arr=(int*)malloc(sizeof(int)*10)
    float*a=(float*)malloc(sizeof(float)*10)
    for(int i=0;i<size;i++)
	scanf("%d",&a[i]]) 
	free();
	
	
typedef 给类型起别名
typedef 加原数据 加新数据
