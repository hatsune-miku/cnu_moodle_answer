#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
bool isPrime(int x) {
	for (int i = 2; i < x; i++)
		if (x % i == 0) return false;
	return true;
}
int main() {
	int x;
	scanf("%d", &x);
	if (x < 6 || (x / 2 * 2 != x)) {
		printf("Error!");
		return 0;
	}
	for (int i = 2; i < x / 2; i++) {
		if (!isPrime(i))
			continue;
		int y = x - i;
		if (!isPrime(y))
			continue;
		printf("%d=%d+%d\n", x, i, y);
	}
	return 0;
}
