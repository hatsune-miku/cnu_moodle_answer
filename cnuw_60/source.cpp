#define _CRT_SECURE_NO_WARNINGS
#define size 8
#include <stdio.h>
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
int main() {
	int arr[size];
	int* p = arr;
	for (int i = 0; i < size; i++)
		scanf("%d", p++);
	for (int i = 0; i < size - 1; i++) {
		if (arr[i] > arr[i + 1])
			swap(&arr[i], &arr[i + 1]);
	}
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	return 0;
}