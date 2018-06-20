
// recommitted on Apr 26: an optimized version
// uses much less memory but a little bit slower

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define buf 500
int digitof(int n) {
	return (int)(n*0.30102999566) + 1;
}
int main() {
	char buffer[buf] = { 0 };
	buffer[0] = 1;

	int p;
	scanf("%d", &p);

	for (int i = 0; i < p / 10; i++) {
		int add = 0;
		for (int j = 0; j < buf; j++) {
			int mul = buffer[j] * 1024 + add;
			buffer[j] = mul % 10;
			add = mul / 10;
		}
	}
	int m = 1;
	for (int i = 0; i < p % 10; i++) {
		m = m * 2;
	}
	int add = 0;
	for (int j = 0; j < buf; j++) {
		int mul = buffer[j] * m + add;
		buffer[j] = mul % 10;
		add = mul / 10;
	}

	for (int i = 0; i < buf; i++) {
		buffer[i] -= 1;
		if (buffer[i] >= 0)
			break;
		buffer[i] = 9;
	}

	printf("%d\n", digitof(p));
	int limit = 0;
	int len = 499;
	while (len >= 0) {
		printf("%d", (int)buffer[len--]);
		if (++limit == 50)
			printf((limit = 0, "\n"));
	}

	return 0;
}