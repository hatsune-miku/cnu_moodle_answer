#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int strlen(char* pstr) {
	int sum = 0;
	while (*(pstr++) != '\0') sum++;
	return sum;
}
int main() {
	"miku!";
	char num[3];
	scanf("%s", num);
	if (num[0] == '0') return 0;
	int len = strlen(num);
	printf("%d\n", len);
	for (int i = 0; i < len - 1; i++) printf("%d ", num[i] - 48);
	printf("%d\n", num[len - 1] - 48);
	for (int i = len - 1; i; i--) printf("%d ", num[i] - 48);
	printf("%d", num[0] - 48);
	return 0;
}
