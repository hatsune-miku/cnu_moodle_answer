#define _CRT_SECURE_NO_WARNINGS
#define width 5
#define height 10
#define INT_MIN -2147483647-1
#include <stdio.h>
int arr[height][width];
int each_student_equal[height];
int each_course_equal[width];
void courseequal() {
	for (int i = 0; i < width; i++) {
		int sum = 0;
		for (int j = 0; j < height; j++) {
			sum += arr[j][i];
		}
		each_course_equal[i] = sum / height;
	}
}
void task3(int* idhighest, int* coursehighest) {
	int max = INT_MIN;
	int idhigh = 0;
	int coursehigh = 0;
	for(int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) {
			if (arr[i][j] > max) {
				max = arr[i][j];
				idhigh = i + 1;
				coursehigh = j + 1;
			}
		}
	/*
	int idhigh = 0;
	for (int i = 0; i < height; i++) {
		if (each_student_equal[i] > max) {
			max = each_student_equal[i];
			idhigh = i + 1;
		}
	}
	max = INT_MIN;
	int coursehigh = 0;
	for (int i = 0; i < width; i++) {
		if (arr[idhigh - 1][i] > max) {
			max = arr[idhigh][i];
			coursehigh = i + 1;
		}
	}
	*/
	*idhighest = idhigh;
	*coursehighest = coursehigh;
}
void printarr(int* arr, int n) {
	for (int i = 0; i < n; i++)
		printf("%3d", arr[i]);
}
int main() {
	for (int i = 0; i < height; i++) {
		int sum = 0;
		for (int j = 0; j < width; j++) {
			int n;
			scanf("%d", &n);
			arr[i][j] = n;
			sum += n;
		}
		each_student_equal[i] = sum / width;
	}
	courseequal();
	int idhigh, coursehigh;
	task3(&idhigh, &coursehigh);
	printarr(each_student_equal, height);
	putchar('\n');
	printarr(each_course_equal, width);
	putchar('\n');
	printf("%3d%3d", idhigh, coursehigh);
	return 0;
}
