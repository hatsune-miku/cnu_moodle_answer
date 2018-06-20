#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
bool paradrome(char* s, int n) {
	for (int i = 0; i < n / 2; i++)
		if (s[i] != s[n - i - 1])
			return false;
	return true;
}
bool prime(int x) {
	if (x < 2)
		return false;
	for (int i = 2; i < x; i++)
		if (x % i == 0)
			return false;
	return true;
}
int main() {
	int n;
	scanf("%d", &n);
	char str[8];
	while (n--) {
		scanf("%s", str);
		int val;
		sscanf(str, "%x", &val);
		if (paradrome(str, strlen(str))
			&& prime(val))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
