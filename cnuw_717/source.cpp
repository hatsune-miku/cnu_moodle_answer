#define _CRT_SECURE_NO_WARNINGS
#define size 8
#define solvings 92
#include <stdio.h>
int count_ = 0;
int raw[size];
int pattern[92][8];
int abs(int x) {
	return x < 0 ? -x : x;
}
void place(int x, int y) {
	raw[y] = x;
}
int canplace(int y) {
	for (int i = 0; i < y; i++) {
		if (
			raw[y] == raw[i]
			|| abs(raw[y] - raw[i]) == abs(y - i)
			|| raw[y] + y == raw[i] + i)
			return 0;
	}
	return 1;
}
void solving(int y) {
	if (y == size) {
		for (int i = 0; i < size; i++)
			pattern[count_][i] = raw[i] + 1;
		count_++;
	}
	else {
		for (int x = 0; x < size; x++) {
			place(x, y);
			if (canplace(y)) solving(y + 1);
		}
	}
}
int solve() {
	solving(0);
	return count_;
}

int main() {
	int n;
	solve();
	scanf("%d", &n);
	while (n--) {
		int b;
		scanf("%d", &b);
		for (int i = 0; i < size; i++) {
			printf("%d", pattern[b-1][i]);
		}
		putchar('\n');
	}
	return 0;
}
