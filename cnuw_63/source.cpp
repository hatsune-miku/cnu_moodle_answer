#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define size 10
#define buffer 1024
void strcpy(char* dst, char* src) {
	while (*src != '\0')
		*dst++ = *src++;
	*dst = '\0';
}
void swap(char* a, char* b) {
	char c[buffer];
	strcpy(c, a);
	strcpy(a, b);
	strcpy(b, c);
}
int compare(char* a, char* b) {
	int deep = 0;
	char _a, _b;
	do {
		_a = *(a + deep);
		_b = *(b + deep);
		if (_a > _b) return 1;
		else if (_a < _b) return 0;
		deep++;
	} while (_a != '\0' && _b != '\0');
}
void bubblesort(char arr[size][buffer], int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (compare(arr[j],arr[j + 1]))
				swap(arr[j], arr[j + 1]);
}
int main() {
	char arr[size][buffer] = { '\0' };
	for (int i = 0; i < size; i++)
		scanf("%s", arr[i]);
	bubblesort(arr, size);
	for (int i = 0; i < size; i++)
		printf("%s\n", arr[i]);
	return 0;
}
