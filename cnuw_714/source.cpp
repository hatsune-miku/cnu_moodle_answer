#define _CRT_SECURE_NO_WARNINGS
#define size 12
#include <stdio.h>
char str[size];
int n = 0;
int sum = 0;
int nya(char c) {
	if (c >= 'a')
		return (int)(c - 'a') + 10;
	else if (c >= 'A')
		return (int)(c - 'A') + 10;
	else
		return (int)(c - '0');
}
int pow(int x, int y) {
	int ret = 1;
	while (y--) ret *= x;
	return ret;
}
void mikumikubiu(int d, int i) {
	if (d == -1) return;
	sum += nya(str[d])*pow(16, i);
	mikumikubiu(d - 1, i + 1);
}
int main() {
	char c;
	while ((c = getchar()) != '\n')
		str[n++] = c;
	mikumikubiu(n-1, 0);
	printf("%d", sum);
	return 0;
}
