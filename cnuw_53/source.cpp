#include <stdio.h>
int main() {
	int a, n;
	scanf("%d%d", &a, &n);
	long long base = a, sum = base;
	while (--n) {
		base = base * 10 + a;
		sum += base;
	}
	printf("%llu", sum);
	return 0;
}
