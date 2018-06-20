#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void put(int i) {
	if (i == 0) printf("%4c", ' ');
	else printf("%4d", i);
}
int main() {
	"miku!";
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			put(i<=j?(i*j):0);
		}
		printf("\n");
	}
	return 0;
}