#define _CRT_SECURE_NO_WARNINGS
#define n 10
#define size 1024
#define INT_MIN -2147483647-1
#include <stdio.h>
int main() {
	char str[n][size];
	int max = INT_MIN, index = 0;
	for (int i = 0; i < n; i++) {
		char c;
		int len = 0;
		while ((c = getchar()) != '\n')
			str[i][len++] = c;
		str[i][len] = '\0';
		if (len > max) {
			max = len;
			index = i;
		}
	}
	printf("%s", str[index]);
	return 0;
}
