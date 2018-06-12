#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define STAT_UP 0
#define STAT_DOWN 1
#define STAT_NONE 2
int main() {
	int num, last = 0;
	int stat = STAT_NONE;
	scanf("%d", &last);
	while (true) {
		scanf("%d", &num);
		if (-1 == num)
			break;
		if (num > last) {
			if (stat == STAT_NONE || stat == STAT_UP)
				stat = STAT_UP;
			else {
				stat = STAT_NONE;
				break;
			}
		}
		else if (num < last) {
			if (stat == STAT_NONE || stat == STAT_DOWN)
				stat = STAT_DOWN;
			else {
				stat = STAT_NONE;
				break;
			}
		}
		else {
			stat = STAT_NONE;
			break;
		}
		last = num;
	}
	switch (stat) {
	case STAT_NONE:
		printf("NO");
		break;
	case STAT_UP:
		printf("ASC");
		break;
	default:
		printf("DES");
		break;
	}
	return 0;
}
