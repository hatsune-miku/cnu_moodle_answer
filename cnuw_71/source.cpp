#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define size 10
int find(int* arr, int l, int r, int x) {
	int mid = (l + r) / 2;
	if (arr[mid] == x)
		return mid;
	if (r - l == 1)
		return -1;
	if (arr[mid] > x)
		return find(arr, 0, mid, x);
	return find(arr, mid, r, x);
}
int main() {
	int arr[size];
	int* p = arr;
	int x;
	for (int i = 0; i < size; i++)
		scanf("%d", p++);
	scanf("%d", &x);
	int index = find(arr, 0, size, x);
	printf("%d", index);
	return 0;
}
