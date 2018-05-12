#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int n,cnt=0;
	scanf("%d%*c", &n);
	while (n--) {
		char str[201];
		char* p = str;
		scanf("%[^\n]", p);
		getchar();
		while (*p != '\0') {
			if (*p == '?' || *p == '.' || *p == '!')
				cnt++;
		p++;
		}
	}
	printf("%d", cnt);
	return 0;
}