#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	char map[128];
	char hand[] = { '2','3','4','5','6','7','8','9','1','J','Q','K','A' };
	char c;
	while ((c = getchar()) != '\n') {
		if (c != ',' && c != '0')
			map[c] = 1;
	}
	for (int i = 0; i < 13; i++)
		if (map[hand[i]] != 1) {
			putchar(hand[i]);
			if (hand[i] == '1')
				putchar('0');
			break;
		}
	return 0;
}