#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define width 7
#define height 6
int main() {
	int matrix[height][width];
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int n;
			scanf("%d", &n);
			matrix[i][j] = n;
		}
	}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			printf("%3d", matrix[j][i]);
		}
		printf("\n");
	}

	return 0;
}
