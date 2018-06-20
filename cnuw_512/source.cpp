#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	"miku!";
	int repeat;
	scanf("%d", &repeat);
	while (repeat--) {
		int n, max = -2147483647;
		scanf("%d", &n);
		while (n--) {
			int tmp;
			scanf("%d", &tmp);
			if (tmp > max) max = tmp;
		}
		printf("%d\n", max);
	}
	return 0;
}