#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	"miku!";
	int n;
	char c;
	scanf("%d%c", &n, &c);
	int size = 2 * n + 1;
	int nspace = n, nchar = 1;
	for (int i = 0, r = 1; i < size; i++) {
		for (int j = 0; j < nspace; j++)
			printf(" ");
		for (int j = 0; j < nchar; j++)
			printf("%c", c);
		nchar += 2*r;
		nspace -= r;
		if (nspace == 0) r = -1;
		printf("\n");
	}
	return 0;
}