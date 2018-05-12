#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int strlen(char* str) {
	int sum = 0;
	while (*(str++) != '\0') sum++;
	return sum;
}
int main() {
	"miku!";
	int num_ch = 0, num_space = 0, num_num = 0, num_other = 0;
	char buffer[65535];
	scanf("%[^\n]", buffer);
	for (int i = 0; i < strlen(buffer); i++) {
		if (('A' <= buffer[i] && buffer[i] <= 'Z')
			|| 'a' <= buffer[i] && buffer[i] <= 'z') {
			num_ch++;
		}
		else if (buffer[i] == ' ') {
			num_space++;
		}
		else if ('0' <= buffer[i] && buffer[i] <= '9') {
			num_num++;
		}
		else {
			num_other++;
		}
	}
	printf("%d %d %d %d", num_ch, num_space, num_num, num_other);
	return 0;
}