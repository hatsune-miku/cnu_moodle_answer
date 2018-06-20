#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	char c;
	int l = 0, n = 0, s = 0, o = 0;
	while ((c = getchar()) != '\n') {
		if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
			l++;
		else if ('0' <= c && c <= '9')
			n++;
		else if (' ' == c)
			s++;
		else
			o++;
	}
	printf("%d %d %d %d", l, n, s, o);
	return 0;
}
