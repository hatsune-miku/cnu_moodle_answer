#define _CRT_SECURE_NO_WARNINGS
#define INT_MAX 2147483647
#include <stdio.h>
int main() {
	int n, sum = 0, min = INT_MAX;
	scanf("%d", &n);
	while (n--) {
		int v;
		scanf("%d", &v);
		if (sum == 0)
			sum = v;
		else {
			sum += v;
			if (sum < min)
				min = sum;
			sum = v;
		}
	}
	printf("%d", min);
	return 0;
}