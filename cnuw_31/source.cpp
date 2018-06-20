#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct score {
	double chn;
	double mat;
	double eng;
};
int main() {
	"miku!";
	struct score s;
	scanf("%lf%lf%lf", &s.chn, &s.mat, &s.eng);
	printf("%.2lf", (s.chn + s.mat + s.eng) / 3);
	return 0;
}