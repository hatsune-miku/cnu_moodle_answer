#define _CRT_SECURE_NO_WARNINGS
#define size 512
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	while (n > 0) {
		printf("%d", n % 10);
		n /= 10;
	}
	return 0;
}


/*
void mikumikubiu(int* arr, int n) {
	if (n == -1) return;
	putchar(arr[n] + '0');
	mikumikubiu(arr, n - 1);
}
int main() {
	// 用递归会运行时错误
	int arr[size];
	int n = 0;
	char c;
	while ((c = getchar()) != '\n')
		arr[n++] = (int)(c - '0');
	for (int i = n - 1; i >= 0; i--) {
		printf("%d", arr[i]);
	}
	//mikumikubiu(arr, n-1);
	return 0;
}
*/
