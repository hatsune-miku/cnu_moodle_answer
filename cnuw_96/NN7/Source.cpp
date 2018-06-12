#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main() {
	char num[41];
	while (true) {
		scanf("%s", num);
		if (num[0] == '0')
			break;
		int len = strlen(num);
		for (int i = 0; i < len - 2; i++) {
			if (num[i] == num[i + 2]) {
				printf("%c%c%c\n", num[i], num[i + 1], num[i + 2]);
				i += 2;
			}
		}
	}
	return 0;
}
