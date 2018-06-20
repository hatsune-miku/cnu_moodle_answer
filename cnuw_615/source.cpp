#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int len = 0;
	char c;
	while ((c = getchar()) != '\n')
		len++;
	printf("%d", len);
	return 0;
}
