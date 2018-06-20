#include <iostream>
#include <cmath>
using namespace std;
int explode(int x) {
	int ans = 0;
	while (x) {
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

bool smith(int x) {
	int lsum = 0, rsum = 0, cnt = 0, sqr = 0;
	rsum = x;
	while (x % 2 == 0) {
		lsum += 2;
		x /= 2;
		cnt++;
	}
	sqr = sqrt(x);
	for (int i = 3; i <= sqr; ) {
		if (x % i == 0) {
			lsum += explode(i);
			x /= i;
			cnt++;
		}
		else
			i += 2;
	}
	if (cnt < 1)
		return false;
	if(x != 1)
		lsum += explode(x);
	rsum = explode(rsum);
	return lsum == rsum;
}
int main() {
	int num;
	while (cin >> num) {
		if (num == 0)
			break;
		while (true) {
			num++;
			if (smith(num)) {
				cout << num << endl;
				break;
			}
		}
	}
	return 0;
}
