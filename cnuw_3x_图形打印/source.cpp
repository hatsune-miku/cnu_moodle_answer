#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void makespace(int amount) {
	while (amount--) putchar(' ');
}
int main() {
	int n, i = 0, ns;
	char c;
	scanf("%d%c", &n, &c);
	ns = (n - 1) * 2 + 2;
	while (i++,n--) {
		makespace(ns -= 2);
		for (int j = 0; j < i; j++)
			putchar(c);
		putchar('\n');
	}
	return 0;
}