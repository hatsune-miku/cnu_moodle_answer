#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void partition(int* arr, int l, int r) {
	if (l > r) return;
	int key = arr[l];
	int lp = l, rp = r;
	while (lp < rp) {
		while (lp < rp && arr[rp] >= key) rp--;
		arr[lp] = arr[rp];
		while (lp < rp && arr[lp] <= key) lp++;
		arr[rp] = arr[lp];
	}
	arr[lp] = key;
	partition(arr, l, lp - 1);
	partition(arr, lp + 1, r);
}
void quicksort_unsafe(int* arr, int n) {
	partition(arr, 0, n);
}
int main() {
	while (1) {
		int arr[20] = { -3939 };
		int* parr = arr;
		int n, cnt = 0;
		double sum = 0;
		scanf("%d", &n);
		if (n == 0) return 0;
		for (int i = 0; i < n; i++)
			scanf("%d", parr++);
		parr -= n + 1;
		quicksort_unsafe(parr, n);
		for (int i = 1; i < n; i += 2) {
			if (i >= n) break;
			sum += arr[i];
			cnt++;
		}
		printf("%.1lf\n", sum / cnt);
	}
	return 0;
}
