#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int val(char c) {
	if ('0' <= c && c <= '9')
		return (int)(c - '0');
	return -1;
}
int main() {
	char c;
	int sum = 0, tsum = 0, cnt = 0, v = 0;
	bool num = false;
	while (true) {
		c = getchar();
		if (c == 13 || c == 10 || c == -1) {
			if (v != -1) {
				cnt++;
				sum += tsum;
			}
			break;
		}
		v = val(c);
		if (v == -1) {
			if (num)
				cnt++;
			num = false;
			sum += tsum;
			tsum = 0;
			continue;
		}
		num = true;
		tsum *= 10;
		tsum += v;
	}
	printf("%d\n%d", cnt, sum);
	return 0;
}
