#define _CRT_SECURE_NO_WARNINGS
#define size 1024
#include <stdio.h>
int main() {
	char str[size];
	int m;
	scanf("%s%d", str, &m);
	m -= 1;
	while (str[m] != '\0')
		putchar(str[m++]);
	return 0;
}
