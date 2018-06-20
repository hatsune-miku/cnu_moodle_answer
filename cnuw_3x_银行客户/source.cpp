#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	long saving = 0;
	scanf("%ld", &saving);
	if (saving <= 100000)
		printf("*");
	else if (saving <= 500000)
		printf("**");
	else if (saving <= 1000000)
		printf("***");
	else if (saving <= 2000000)
		printf("****");
	else
		printf("*****");
	return 0;
}