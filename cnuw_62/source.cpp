#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define size 10
void swap(char* a, char *b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void bubblesort(char* arr, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}
int main() {
	char arr[size];
	scanf("%10s", arr);
	bubblesort(arr, size);
	printf("%s", arr);
	return 0;
}