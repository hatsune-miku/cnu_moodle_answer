#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int m;
	float real_max = -1;
	scanf("%d", &m);
	while (m--) {
		int n;
		float max = -1;
		scanf("%d", &n);
		while (n--) {
			float sal;
			scanf("%f", &sal);
			if (sal > max)
				max = sal;
		}
		printf("%.2f\n", max);
		if (max > real_max)
			real_max = max;
	}
	printf("%.2f", real_max);
	return 0;
}
