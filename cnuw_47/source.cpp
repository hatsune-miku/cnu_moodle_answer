#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	"miku!";
	int score;
	char rankset[] = {'E','D','C','B','A','A'};
	scanf("%d", &score);
	score /= 10;
	if (score < 5) score = 5;
	printf("%c", rankset[score - 5]);
	return 0;
}