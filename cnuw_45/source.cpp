#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int f(int x) {
	return (x < 1 ? x : ((1 <= x&&x < 10) ? (2 * x - 1) : 3 * x - 11));
}
int main() {
	"miku!";
	int x;
	scanf("%d", &x);
	printf("y=%d", f(x));
	return 0;
}