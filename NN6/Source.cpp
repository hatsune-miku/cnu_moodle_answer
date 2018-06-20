#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void find(char* m, char* s, int slen) {
	int pos[512] = { -1 };
	int t = 0, cnt = 0, p = 0;
	while (*m != '\0') {
		if (*s != *m) {
			m++, p++;
			s -= cnt;
			cnt = 0;
			continue;
		}
		m++, s++, p++, cnt++;
		if (cnt == slen) {
			pos[t++] = p - cnt;
			s -= cnt;
			cnt = 0;
		}
	}
	printf("%d\n", t);
	if (t > 0) {
		for (int i = 0; i < t - 1; i++)
			printf("%d ", pos[i]);
		printf("%d", pos[t - 1]);
	}

}
int main() {
	char m[1024], s[512];
	int len = 0;
	scanf("%[^\n]%*c%[^\n]", m, s);
	len = strlen(s);
/*
	while ((s[len] = getchar()) != 10 && s[len] != 13 && s[len] != -1)
		len++;
*/
	find(m, s, len);
	return 0;
}
