#define _CRT_SECURE_NO_WARNINGS
#define find_range 1000
#include <stdio.h>
int isws(int num, int* list) {
	int sum = 0;
	int p = 0;
	for (int i = 1; i < num; i++) {
		if (num % i == 0) {
			sum += i;
			list[p++] = i;
		}
	}
	list[p] = NULL;
	return num == sum;
}
int main() {
	"miku!";
	for (int i = 1; i <= find_range; i++) {
		int list[find_range];
		if (isws(i, list)) {
			printf("%d its factor are 1", i);
			for (int j = 1; j < find_range; j++) {
				if (list[j] != NULL) printf(",%d", list[j]);
				else break;
			}
			printf("\n");
		}
	}
	return 0;
}