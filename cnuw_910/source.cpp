#define _CRT_SECURE_NO_WARNINGS
#define height 4
#define width 5
#include <stdio.h>
double arr[height][width];

double sumof(int id) {
	double sum = 0;
	for (int i = 0; i < width; i++) {
		sum += arr[id][i];
	}
	return sum;
}

void printarr(int h, int n) {
	for (int i = 0; i < n; i++)
		printf("%4d", (int)arr[h][i]);
}

void task1() {
	double sum = 0;
	for (int i = 0; i < height; i++) {
		sum += arr[i][0];
	}
	sum /= height;
	printf("average of score 1 is %.2lf\n", sum);
}

void task2() {
	for (int i = 0; i < height; i++) {
		int cnt = 0;
		for (int j = 0; j < width; j++) {
			if (arr[i][j] < 60)
				cnt++;
		}
		if (cnt >= 2) {
			printf("number %d failed with %d\n", i + 1, cnt);
			printf("his score is");
			printarr(i, width);
			printf("\naverage score is %.2lf\n", sumof(i) / width);
		}
	}
}

void task3() {
	for (int i = 0; i < height; i++) {
		bool sign = true;
		for (int j = 0; j < width; j++) {
			if (arr[i][j] < 85)
				sign = false;
		}
		double avg = sumof(i) / width;
		if (avg > 90)
			sign = true;
		if (sign) {
			printf("number %d is very good\n", i + 1);
			printf("his score is");
			printarr(i, width);
			printf("\naverage score is %.2lf\n", sumof(i) / width);
		}
	}
}

int main() {
	for (int i = 0; i < height; i++) {
		double* p = arr[i];
		for (int j = 0; j < width; j++)
			scanf("%lf", p++);
	}
	task1();
	task2();
	task3();
	return 0;
}
