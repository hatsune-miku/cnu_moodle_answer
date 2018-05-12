#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int dom[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int w, m = 0,d = 1;
	scanf("%d", &w);
	while (m < 12) {
		if (++d == dom[m] + 1) {
			m++;
			d = 1;
		}
		if (++w == 8) w = 1;
		if (w == 5 && d == 13)
			printf("%d\n", m + 1);
	}
	return 0;
}
