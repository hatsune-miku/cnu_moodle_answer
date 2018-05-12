#define _CRT_SECURE_NO_WARNINGS
#define size 512
#include <stdio.h>
int main() {
	char str[size] = { '\0' };
	char* p = str;
	scanf("%s%*c", str);
	char c;
	int ans = 0;
	do {
		c = getchar();
		if (c == '\n' && *p != '\0') {
			ans = (int)*p;
			break;
		} else if (*p == '\0') {
			ans = (int)c;
			break;
		}
		if (c != *(p++)) {
			ans = (int)(*(p - 1) - c);
			break;
		}
	} while (c != '\n');
	printf("%d", ans);
	return 0;
}
