#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	scanf("%d", &n);
	int l = n / 2;
	int** m = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		*(m + i) = (int*)malloc(n * sizeof(int));
		for(int j = 0; j < n; j++)
			if(j == l)
				scanf("%d", *(m + i) + j + 1);
			else if(j == l + 1)
				scanf("%d", *(m + i) + j - 1);
			else
				scanf("%d", *(m + i) + j);
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (j >= i)
				sum += m[i][j];
		free(m[i]);
		m[i] = NULL;
	}
	printf("%d", sum);
	return 0;
}
