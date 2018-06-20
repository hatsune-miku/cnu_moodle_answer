#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define size 6
#define wanted 6
typedef struct {
	char raw[128];
	int len;
	int val;
} string;
int main() {
	string str[size] = { { "", 0, 0 } };
	for (int i = 0; i < size; i++) {
		char c;
		int min = 127;
		while ((c = getchar()) != 10 && c != 13 && c != -1) {
			str[i].raw[str[i].len++] = c;
			if ((int)c < min)
				min = (int)c;
		}
		str[i].val = min;
	}
	for (int i = 0; i < wanted; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (str[j].val > str[j + 1].val) {
				string tmp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = tmp;
			}
	for (int i = 0; i < wanted; i++)
		printf("%s\n", str[i].raw);
	return 0;
}
