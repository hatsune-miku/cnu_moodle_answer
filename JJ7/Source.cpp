#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
bool prime(int x) {
	if (x < 2)
		return false;
	for (int i = 2; i < x; i++)
		if (x % i == 0)
			return false;
	return true;
}
int main() {
	char num[41];
	while (true) {
		scanf("%s", num);
		if (num[0] == '0')
			break;
		int len = strlen(num), i;
		for (i = 0; i < len - 2; i++) {
			int x = (int)(num[i] - 48) * 100
				+ (int)(num[i + 1] - 48) * 10
				+ (int)(num[i + 2] - 48);
			if (prime(x)) {
				printf("%d\n", x);
				i += 2;
			}
		}
		int remain = len - i - 1;
		if (remain >= 3) {
			int x = 0, p = 1;
			for (int i = len - 1; i >= len - remain; i--) {
				x = (int)num[i] * p;
				p *= 10;
			}
			if (prime(x))
				printf("%d\n", x);
		}
	}
	return 0;
}
