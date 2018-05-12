#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
bool isPrime(int x) {
	for (int i = 2; i < x; i++)
		if (x % i == 0)
			return false;
	return true;
}
int main() {
	int n;
	scanf("%d", &n);
	printf(isPrime(n) ? "YES" : "NO");
	return 0;
}
