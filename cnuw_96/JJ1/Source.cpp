#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int m;
	float real_min = 2147483647;
	scanf("%d", &m);
	while (m--) {
		int n;
		float min = 2147483647;
		scanf("%d", &n);
		while (n--) {
			float sal;
			scanf("%f", &sal);
			if (sal < min)
				min = sal;
		}
		printf("%.2f\n", min);
		if (min < real_min)
			real_min = min;
	}
	printf("%.2f", real_min);
	return 0;
}
