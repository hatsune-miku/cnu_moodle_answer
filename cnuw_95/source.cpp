#define _CRT_SECURE_NO_WARNINGS
#define size 2048
#include <stdio.h>
// find the position of str2 in str1.
int mystrstr(char* str1, char* str2) {
	while (*str1 != '\0') {
		int p = 0;
		while (*(str1 + p) == *(str2 + p)) {
			p++;
			if (*(str2 + p) == '\0')
				return p;
			if (*(str1 + p) == '\0')
				break;
		}
		str1++;
	}
	return -1;
}
int main() {
	char str1[size] = {'\0'};
	char str2[size] = {'\0'};
	scanf("%[^\n]", str1);
	getchar();
	scanf("%[^\n]", str2);
	if (mystrstr(str1, str2) == -1 && mystrstr(str2, str1) == -1)
	//if(strstr(str1,str2) == 0 && strstr(str2,str1) == 0)
		printf("NO");
	else
		printf("YES");

	return 0;
}
