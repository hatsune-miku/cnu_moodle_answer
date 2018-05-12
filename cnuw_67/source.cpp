#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int pow(int x, int y) {
	int ret = 1;
	while (y--) ret *= x;
	return ret;
}
int main() {
	while (1) {
		int num[30];
		int digit = 0;
		int factors[10];
		char c;
		memset(factors, 0, sizeof(factors));
		do {
			c = getchar();
			if (c == '-') return 0;
			num[digit++] = (int)(c - '0');
		} while (c!=10);
		digit--;
		// 2 5
		switch (num[digit - 1]) {
		case 0:
			factors[2] = 1;
			factors[5] = 1;
			break;
		case 2:case 4:case 6:case 8:
			factors[2] = 1;
			break;
		case 5:
			factors[5] = 1;
		}

		// 3 9
		int sum = 0;
		for (int i = 0; i < digit; i++)
			sum += num[i];
		if (sum % 3 == 0)
			factors[3] = 1;
		if (sum % 9 == 0)
			factors[9] = 1;

		// 4 8
		if (digit < 4) {
			int num_raw = 0;
			for (int i = 0; i < digit; i++) {
				num_raw += num[i] * pow(10, digit - i - 1);
			}
			if (num_raw % 4 == 0)
				factors[4] = 1;
			if (num_raw % 8 == 0)
				factors[8] = 1;
		}
		else {
			int last2 = num[digit - 1] + num[digit - 2];
			if (last2 % 4 == 0)
				factors[4] = 1;
			if ((last2 + num[digit - 3]) % 8 == 0)
				factors[8] = 1;
		}

		// 6
		if (factors[2] == 1 && factors[3] == 1)
			factors[6] = 1;
		
		// shit 7
		

		int none = 1;
		for (int i = 0; i < 10; i++) {
			if (factors[i] == 1) {
				none = 0;
				printf("%d ", i);
			}
		}
		if (none) printf("none");
		printf("\n");
	}
	return 0;
}