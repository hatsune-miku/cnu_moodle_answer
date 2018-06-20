#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int l, r, sum = 0;
	scanf("%d%d", &l, &r);
	if (l / 2 * 2 == l) l++;
	while (true) {
		if (l > r)
			break;
		sum += l;
		l += 2;
	}
	printf("%d", sum);
	return 0;
}
