#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define size 9
#define INT_MIN -2147483647-1
int max(int* arr, int n) {
	int _max = INT_MIN;
	for (int i = 0; i < n; i++)
		if (arr[i] > _max)
			_max = arr[i];
	return _max;
}
int main() {
	int arr[size];
	int* p = arr;
	for (int i = 0; i < size; i++)
		scanf("%d", p++);
	int _max = max(arr, size);
	printf("%d", _max);
	return 0;
}
