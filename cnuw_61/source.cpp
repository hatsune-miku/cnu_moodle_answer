#define _CRT_SECURE_NO_WARNINGS
#define size 10
#define INT_MAX 2147483647
#include <stdio.h>
int main() {
	int arr[size];
	int* p = arr;
	int n;
	for (int i = 0; i < size; i++)
		scanf("%d", p++);
	scanf("%d", &n);
	int min = INT_MAX, position = -1;
	for (int i = n; i < size; i++) {
		if (arr[i] < min) 
			min = arr[position=i];
	}
	printf("%d", position);
	return 0;
}