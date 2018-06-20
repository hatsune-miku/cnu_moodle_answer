#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
bool isleapyear(int year) {
	if (year % 100 == 0)
		return year % 400 == 0;
	return year % 4 == 0;
}
int arrsum(int* arr, int l, int r) {
	int sum = 0;
	for (int i = l; i < r; i++)
		sum += arr[i];
	return sum;
}
int main() {
	int day_of_month[] = {31,0,31,30,31,30,31,31,30,31,30,31};
	int y, m, d;
	scanf("%d,%d,%d", &y, &m, &d);
	day_of_month[1] = isleapyear(y) ? 29 : 28;
	printf("%d", (m == 0 ? 0 : arrsum(day_of_month, 0, m - 1)) + d);
	return 0;
}
