#include<string.h>
#include<stdio.h> 
char st[110];//用来记录数字的
char s[100];
int main() {
	
	gets(s);
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			st[i] = 1;
		}
	}
	for (int i = 0; i < len; i++) {
		if (st[i]!=1) {
			printf("%c", s[i]);
		}
	}
	for (int i = 0; i < len; i++) {
		if (st[i] == 1) {
			printf("%c", s[i]);
		}
	}

	return 0;
}
