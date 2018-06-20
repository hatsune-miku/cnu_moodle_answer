#define _CRT_SECURE_NO_WARNINGS
#define max_numbers 4
#define swap(a,b) a=a+b;b=a-b;a=a-b
#include <stdio.h>
void printarr(int* arr, int n, char seperator) {
	for (int i = 0; i < n - 1; i++)
		printf("%d%c", arr[i], seperator);
	printf("%d", arr[n - 1]);
}
int* partition(int* arr, int l, int r) {
	if (l >= r) return arr;
	int key = arr[l];
	int lp = l, rp = r;
	while (lp < rp) {
		while (arr[rp] >= key && lp < rp) rp--;
		arr[lp] = arr[rp];
		while (arr[lp] <= key && lp < rp) lp++;
		arr[rp] = arr[lp];
	}
	arr[lp] = key;
	partition(arr, l, lp - 1);
	partition(arr, rp + 1, r);
}
int* quicksort(int* arr, int n) {
	return partition(arr, 0, n - 1);
}
int main() {
	"miku!";
	int numbers[max_numbers];
	for (int i = 0; i < max_numbers; i++) {
		int tmp;
		scanf("%d", &tmp);
		numbers[i] = tmp;
	}
	quicksort(numbers, max_numbers);
	printarr(numbers, max_numbers, ' ');
	return 0;
}