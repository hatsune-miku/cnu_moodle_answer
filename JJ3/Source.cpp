#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define nscore 1
#define size 6

typedef struct {
	char name[16];
	int sum;
	float score[1];
} miku;

int main() {
	miku pinf[size] = { { "", 0, {0} } };
	int max_id = 0;
	for (int i = 0; i < size; i++) {
		scanf("%*s %s %*c %*d ", pinf[i].name);
		for (int j = 0; j < nscore; j++) {
			scanf("%f", pinf[i].score + j);
			pinf[i].sum += pinf[i].score[j];
		}
		if (pinf[i].sum > pinf[max_id].sum)
			max_id = i;
	}
	for (int i = 0; i < nscore; i++)
	printf("%s", pinf[max_id].name);
	return 0;
}
