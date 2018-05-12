#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define width 6
#define height 5
#define INT_MIN -2147483647-1
int main() {
	int arr[height][width];
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) {
			int tmp;
			scanf("%d", &tmp);
			arr[i][j] = tmp;
		}
	for (int i = 0; i < height; i++) {
		int max = INT_MIN;
		int row, col;
		for (int j = 0; j < width; j++) {
			if (arr[i][j] > max) {
				max = arr[i][j];
				col = j;
				row = i;
			}
		}
		for (int j = 0; j < height; j++) {
			if (arr[j][col] < max) {
				row = -1;
				break;
			}
		}
		if (row != -1) {
			printf("%d %d", row+1, col+1);
			return 0;
		}
	}
	printf("none");
	return 0;
}