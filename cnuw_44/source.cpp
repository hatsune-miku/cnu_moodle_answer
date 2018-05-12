#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	"miku!";
	int hour, minute;
	char sign = 'A';
	scanf("%d:%d", &hour, &minute);
	if (hour >= 12) {
		hour -= 12;
		sign = 'P';
	}
	if (hour == 0) hour = 12;
	printf("%d:%02d %cM", hour, minute, sign);
	return 0;
}