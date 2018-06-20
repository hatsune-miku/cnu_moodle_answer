#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct info {
	double score;
	int id;
} info;

void swap(info* a, info* b) {
	int tmpid = a->id;
	int tmpsc = a->score;
	a->id = b->id;
	a->score = b->score;
	b->id = tmpid;
	b->score = tmpsc;
}

void sort(info* arr, int n) {
	for (int i = 0; i < n; i++) {
		bool exchanged = false;
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j].score < arr[j + 1].score) {
				swap(&arr[j], &arr[j + 1]);
				exchanged = true;
			}
		if (!exchanged)
			break;
	}
}
int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	info* sc = (info*)calloc(m, sizeof(info));
	for (int i = 0; i < m; i++) {
		int min = 2147483647, max = -2147483647 - 1;
		int sum = 0;
		for (int j = 0; j < n; j++) {
			int k = 0;
			scanf("%d", &k);
			sum += k;
			if (k < min)
				min = k;
			if (k > max)
				max = k;
		}
		sum -= min;
		sum -= max;
		sc[i].score = sum;// / (n);
		sc[i].id = i + 1;
	}
	sort(sc, m);
	for (int i = 0; i < m; i++)
		printf("%3d", sc[i].id);
	free(sc);
	sc = NULL;
	return 0;
}
