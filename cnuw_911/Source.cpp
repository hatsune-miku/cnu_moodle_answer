#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void intsort(int* integer, int n) {
	for (int i = 0; i < n - 1; i++) {
		int k = i;
		for (int j = i + 1; j < n; j++)
			if (integer[k] > integer[j])
				k = j;
		int tmp = integer[i];
		integer[i] = integer[k];
		integer[k] = tmp;
	}
}

int main() {
	int size = 0;
	scanf("%d", &size);
	int* integer = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) 
		scanf("%d", &integer[i]);
	intsort(integer, size);
	for (int i = 0; i < size; i++)
		printf("%d ", integer[i]);
	free(integer);
	return 0;
}
