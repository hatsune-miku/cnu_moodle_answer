#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int isws(int num) {
	int sum = 0;
	for (int i = 1; i < num; i++) {
		if (num % i == 0) sum += i;
	}
	return num == sum;
}
int main() {
	"miku!";
	int num;
	scanf("%d", &num);
	printf(isws(num) ? "yes" : "no");
	return 0;
}