#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int arrsum(int* arr, int l, int r) {
	int sum = 0;
	while (l <= r) sum += arr[l++];
	return sum;
}
int isLeapYear(int y) {
	if (y % 100 == 0) 
		return (y % 400 == 0);
	return (y % 4 == 0);
}
int main() {
	int day_of_month[] = { 31,0,31,30,31,30,31,31,30,31,30,31 };
	int y, m, d;
	scanf("%d%*c%d%*c%d", &y, &m, &d);
	int leapyear = isLeapYear(y);
	day_of_month[1] = leapyear ? 29 : 28;
	if(m < 1 || m > 12 || d < 1 || d > day_of_month[m-1])
		printf("0");
	else {
		printf("1\n");
		printf("%d\n", leapyear ? 366 : 365);
		printf("%d", (m == 1 ? 0 : arrsum(day_of_month, 0, m - 2)) + d);
	}
	return 0;
}
