#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int notRelative(int num, int n) {
	if (num % n == 0)
		return 0;
	do {
		if (num % 10 == n)
			return 0;
	} while ((num /= 10) > 0);
	return 1;
}
int main() {
	"miku!";
	int m, n = 7, sum = 0;
	scanf("%d", &m);
	for (int i = 0; i <= m; i++) {
		if (notRelative(i, n)) {
			sum += i*i;
		}
	}
	printf("%d", sum);
	return 0;
}