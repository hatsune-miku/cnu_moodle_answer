#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define size 10
void swap(int* a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void bubblesort(int* arr, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}
int main() {
	int arr[size];
	int* p = arr;
	for (int i = 0; i < size; i++)
		scanf("%d", p++);
	bubblesort(arr, size);
	for (int i = 0; i < size; i++)
		printf("%3d", arr[i]);
	return 0;
}
