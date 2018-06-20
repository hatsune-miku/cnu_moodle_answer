#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define nscore 3
#define size 10

typedef struct {
	char name[16];
	char id[8];
	float score[nscore];
	float sum;
} miku;

typedef struct {
	float sum;
	int nfail;
} course;

int main() {
	miku pinf[size] = { {"","",{0},0} };
	course cinf[nscore] = { {0, 0} };
	int max_id = 0;
	for (int i = 0; i < size; i++) {
		scanf("%s %s ", pinf[i].name, pinf[i].id);
		for (int j = 0; j < nscore; j++) {
			scanf("%f", pinf[i].score + j);
			pinf[i].sum += pinf[i].score[j];
			cinf[j].sum += pinf[i].score[j];
			if (pinf[i].score[j] < 60)
				cinf[j].nfail++;
		}
		if (pinf[i].sum > pinf[max_id].sum)
			max_id = i;
	}
	for (int i = 0; i < nscore; i++)
		printf("%.2f,%d\n", cinf[i].sum / size,
			cinf[i].nfail);
	printf("%s", pinf[max_id].name);
	return 0;
}
