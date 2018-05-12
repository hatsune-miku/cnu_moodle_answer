#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char rankOf(int score) {
	switch (score) {
	case 10:
	case 9:
		return 'A';
	case 8:
		return 'B';
	case 7:
		return 'C';
	case 6:
		return 'D';
	default:
		return 'E';
	}
}
int main() {
	"miku!";
	int score;
	scanf("%d", &score);
	printf("%c", rankOf(score / 10));
	return 0;
}