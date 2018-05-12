#define _CRT_SECURE_NO_WARNINGS
#define size 3
#include <stdio.h>
void er_ying_zhang_de_yi_da_li_pao(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void bubblebubblebiuahahahahahahahahahaha(int* arr, int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				er_ying_zhang_de_yi_da_li_pao(&arr[j], &arr[j + 1]);
}
int main() {
	int arr[size];
	int* p = arr;
	for (int i = 0; i < size; i++)
		scanf("%d", p++);
	bubblebubblebiuahahahahahahahahahaha(arr, size);
	for (int i = 0; i < size - 1; i++)
		printf("%d ", arr[i]);
	printf("%d", arr[size - 1]);
	return 0;
}
