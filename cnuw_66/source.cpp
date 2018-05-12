#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void arrcpy(int* dst, int* src, int len) {
	while (len--)
		*dst++ = *src++;
}
int main() {
	int n;
	scanf("%d", &n);
	int last_serial[32768] = { 0 };
	for (int i = 1; i <= n; i++) {
		int pending_last_serial[32768] = {0};
		for (int j = 1; j <= i; j++) {
			int l = last_serial[j - 1];
			int r = last_serial[j];
			int sum;
			if (l == 0 || r == 0)
				sum = 1;
			else
				sum = l + r;
			pending_last_serial[j] = sum;
			printf("%4d", sum);
		}
		arrcpy(last_serial, pending_last_serial,i+1);
		putchar('\n');
	}
	return 0;
}