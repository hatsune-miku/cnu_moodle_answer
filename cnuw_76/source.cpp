#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int rabbits = 1;
void mikumikubiu(int month, int n) {
	int submonth = month;
	while (submonth <= n) {
		if ((submonth - month) >= 2) {
			rabbits++;
			mikumikubiu(submonth, n);
		}
		submonth++;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	mikumikubiu(1, n);
	printf("%d", rabbits);
	return 0;
}
