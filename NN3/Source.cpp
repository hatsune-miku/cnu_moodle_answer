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
				// ����ṹ�彻����raw������ָ�룬û�����ַ������ƣ����ص���Ч��
			}
	for (int i = size - 1; i > size - wanted - 1; i--)
		printf("%s\n", str[i].raw);
	return 0;
}
