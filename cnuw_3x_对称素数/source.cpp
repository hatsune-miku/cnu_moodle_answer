#define _CRT_SECURE_NO_WARNINGS
#define digit_max 9
#include <stdio.h>
int isPrime(int v) {
	for (int i = 2; i < v; i++) {
		if (i*i > v) break;
		if (v % i == 0) return 0;
	}
	return 1;
}
int isPalindrome(int v) {
	unsigned short split[digit_max + 1] = { 0 };
	int len = 0;
	while (v > 0) {
		split[len++] = v % 10;
		v /= 10;
	}
	for (int i = 0; i < len--; i++) {
		if (split[i] != split[len])
			return 0;
	}
	return 1;
}
int main() {
	int n;
	scanf("%d", &n);
	if (isPrime(n) && isPalindrome(n))
		printf("Yes");
	else
		printf("No");
	return 0;
}
