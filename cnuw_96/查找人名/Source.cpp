#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int strcmp(char* a, char* b) {
	while (*a != '\0' && *b != '\0') {
		if (*a != *b)
			return (*a > *b ? 1 : -1);
		a++, b++;
	}
	if (*a == '\0' && *b == '\0')
		return 0;
	else
		return (*a > *b ? 1 : -1);
}
int main() {
	char name[20][18];
	int size = 0;
	while (true) {
		scanf("%[^\n]%*c", name[size]);
		if (name[size++][0] == '-'
			&& name[size-1][1] == '1')
			break;
	}
	char one[18];
	scanf("%[^\n]", one);
	int cnt = 0;
	for (int i = 0; i < size; i++)
		if (!strcmp(name[i], one))
			cnt++;
	if (cnt > 0)
		printf("%d", cnt);
	else
		printf("no");
	return 0;
}
