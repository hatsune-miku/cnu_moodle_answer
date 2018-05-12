#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	"miku!";
	int n, num[65535],i,max=-2147483647;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		num[i] = tmp;
	}
	for (int j = 0; j < i; j++) {
		if (num[j] > max)
			max = num[j];
	}
	printf("%d", max);
	return 0;
}