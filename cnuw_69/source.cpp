#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define buf 10240
int main() {
	int buffer[buf];
	for (int i = 0; i < buf; buffer[i++] = 0);
	buffer[0] = 1;
	
	int n;
	scanf("%d", &n);
	if (n == 0) {
		printf("1");
		return 0;
	}
	int add = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < buf; j++) {
			int mul = buffer[j] * i + add;
			buffer[j] = mul % 10;
			add = mul / 10;
		}
	}
	int len;
	for (len = buf - 1; buffer[len] == 0; len--);
	int limit = 0;
	while (len >= 0) {
		printf("%d", buffer[len--]);
		if (++limit == 40)
			printf((limit=0,"\n"));
	}
		
	return 0;
}
