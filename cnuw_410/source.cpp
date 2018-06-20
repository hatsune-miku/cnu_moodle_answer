#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	"miku!";
	int m, d, y;
	char months[12][10] = { "January","February","March","April","May","June","July","August","September","October","November","December"};
	char daysign[4][3] = { "st","nd","rd","th" };
	scanf("%d%*c%d%*c%d", &m, &d, &y);
	int num = d % 10, p;
	switch (num) {
	case 1:
		p = 0; break;
	case 2:
		p = 1; break;
	case 3:
		p = 2; break;
	default:
		p = 3; break;
	}
	printf("Dated this %d%s day of %s,20%02d", d, daysign[p], months[m-1], y);
	return 0;
}