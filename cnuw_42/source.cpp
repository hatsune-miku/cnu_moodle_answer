#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	"miku!";
	char c;
	scanf("%c", &c);
	if ('A' <= c && c <= 'Z') 
		printf("%c", c + 32);
	else if ('a' <= c && c <= 'z')
		printf("%c", c - 32);
	else 
		printf("input error");
	return 0;
}