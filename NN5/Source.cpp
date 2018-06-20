#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
bool cmp(int* num, int n) {
	int half = n / 2;
	bool ret = true;
	for (int i = 0; i < half; i++)
		if (num[i] != num[half + i]) {
			printf("%3d", i);
			ret = false;
		}
	return ret;
}
int main() {
	int num[100];
	int cnt = 0;
	while(true) {
		scanf("%d", num + cnt);
		if (num[cnt++] == -1)
			break;
	}
	if (cmp(num, cnt))
		printf("same");
	return 0;
}
