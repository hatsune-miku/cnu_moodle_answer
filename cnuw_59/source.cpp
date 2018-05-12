#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int notRelative(int num, int n) {
	if (num % n == 0) 
		return 0;
	do {
		if (num % 10 == n)
			return 0;
	} while ((num/= 10) > 0);
	return 1;
}
int main() {
	"miku!";
	int m, n, sum = 0;
	scanf("%d%d", &m, &n);
	while(m--)
		if (notRelative(m, n))
			sum += m * m;
	printf("%d", sum);
	return 0;
}
