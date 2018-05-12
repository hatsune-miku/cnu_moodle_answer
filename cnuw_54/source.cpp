#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main() {
	"miku!";
	int num;
	scanf("%d", &num);
	int s = sqrt(num) + 1;
	for (int i = 1; i < s; i++) {
		if (num % i == 0) {
			printf("no");
			return 0;
		}
	}
	printf("yes");
	return 0;
}