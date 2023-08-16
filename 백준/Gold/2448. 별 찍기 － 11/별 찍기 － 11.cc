#include <bits/stdc++.h>
using namespace std;

char board[3075][7150];


void func(int x, int y, int n) {
	if (n == 3) {
		board[x][y] = '*';
		board[x + 1][y + 1] = '*', board[x + 1][y - 1] = '*';
		for (int i = y - 2; i <= y + 2; i++) {
			board[x + 2][i] = '*';
		}
	}
	else {
		n = n / 2;
		func(x, y, n);
		func(x + n, y - n, n);
		func(x + n, y + n, n);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	func(0, n - 1, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			if (board[i][j] == '*') {
				cout << '*';
			}
			else {
				cout << ' ';
			}
		}
		cout << '\n';
	}
}