#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char rankOf(int score) {
	if (95 <= score)
		return 'A';
	else if (81 <= score)
		return 'B';
	else if (70 <= score)
		return 'C';
	else if (60 <= score)
		return 'D';
	else
		return 'E';
}
int main() {
	int score;
	scanf("%d", &score);
	putchar(rankOf(score));
	return 0;
}