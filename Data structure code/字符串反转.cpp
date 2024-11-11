#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[105] = {0};
    gets(s);
    int len = strlen(s);
    for(int i = len-1;i>=0;i--){
        printf("%c",s[i]);
    }
    return 0;
}


