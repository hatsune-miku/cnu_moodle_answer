#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	int l = m / 2;
	int** a = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++)
		*(a + i) = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			if (i == l)
				scanf("%d", *(a + i + 1) + j);
			else if (i == l + 1)
				scanf("%d", *(a + i - 1) + j);
			else
				scanf("%d", *(a + i) + j);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%3d", a[j][i]);
		putchar('\n');
	}
	for (int i = 0; i < m; i++)
		free(*(a + i));
	return 0;
}
