#define _CRT_SECURE_NO_WARNINGS
#define size 1024
#include <stdio.h>
int main() {
	int n, m;
	int num[size];
	int* p = num;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", p++);
	for (int i = n - m; i < n; i++)
		printf("%3d", num[i]);
	for (int i = 0; i < n - m; i++)
		printf("%3d", num[i]);
	return 0;
}
