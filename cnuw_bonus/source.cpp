#include <iostream>
#include <string>
#include <vector>
using namespace std;

class queen_board {
private:
	int count_;
	vector<string> graphlist;
	void solving(int y) {
		if (y == size) {
			count_++; // 每个抵达终点的solving都代表一种解法
			graphlist.push_back(makegraph());
		}
		else {
			for (int x = 0; x < size; x++) {
				place(x, y);
				if (canplace(y)) solving(y + 1);
				// 递归中的函数保持着先后顺序，不会异步执行，
				// 配合先覆盖后判断的机制，可以放心的共用一个raw
			}
		}
	}
public:
	int* raw;
	int size;
	void printgraphf() { // 一行显示5张图的格式化输出
		int n = graphlist.size();
		if (n == 0) return;
		const int max_in_line = 5;
		cout << "================================================================================\n";
		int part_1 = n / max_in_line, part_2 = n % max_in_line;
		for (int k = 0, first = 1; k < part_1; k++) {
			if (first) first = 0;
			else cout << endl;
			for (int j = 0; j < size; j++) {
				for (int i = 0; i < max_in_line; i++) {
					string output = graphlist[max_in_line * k + i].substr(j*(size * 2 + 1), size * 2);
					cout << output << "  ";
				}
				cout << endl;
			}
		}
		if (part_1 != 0 && part_2 != 0) cout << endl;
		int finished;
		for (int j = 0; j < size; j++) {
			finished = 1;
			for (int i = 0; i < part_2; i++) {
				cout << graphlist[n - part_2 + i].substr(j*(size * 2 + 1), size * 2) << "  ";
				finished = 0;
			}
			if (!finished) cout << endl;
		}
		cout << "================================================================================\n";
	}
	string makegraph() {
		string ret;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < raw[i]; j++)
				ret += "o ";
			ret += "x ";
			for (int j = raw[i] + 1; j < size; j++)
				ret += "o ";
			ret += '\n';
		}
		return ret;
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
	int solve() {
		solving(0);
		return count_;
	}
	queen_board(int size) {
		this->size = size;
		raw = new int[size];
	}
	~queen_board() {
		delete[] raw;
		raw = NULL;
	}
};

int main() {
	while (1) {
		int nqueen, nsolutions;
		cout << "Number of queen: ";
		cin >> nqueen;
		queen_board b(nqueen);
		nsolutions = b.solve();
		b.printgraphf();
		cout << "Number of solutions = " << nsolutions << endl << endl;
	}
	return 0;
}
