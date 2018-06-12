#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define size 8
#define wanted 5
typedef struct {
	char raw[128];
	int len;
	int val;
} string;
int main() {
	string str[size] = { {"", 0, 0} };
	for (int i = 0; i < size; i++) {
		char c;
		while ((c = getchar()) != 10 && c != 13 && c != -1)
			str[i].val += (int)(str[i].raw[str[i].len++] = c);
	}
	for (int i = 0; i < wanted; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (str[j].val < str[j + 1].val) {
				string tmp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = tmp;
				// 这里结构体交换，raw换的是指针，没发生字符串复制，不必担心效率
			}
	for (int i = size - 1; i > size - wanted - 1; i--)
		printf("%s\n", str[i].raw);
	return 0;
}
