	#include <bits/stdc++.h>
	//#include <iostream> // <iostream> 추가
	using namespace std;

	char s[50][50];
	int n, m;

	char white_arr[8][8] = {
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W'
	};

	char black_arr[8][8] = {
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B'
	};

	int white_count(int x, int y) {
		int result = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (s[x + i][y + j] != white_arr[i][j])
					result++;
			}
		}
		return result;
	}

	int black_count(int x, int y) {
		int result = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (s[x + i][y + j] != black_arr[i][j])
					result++;
			}
		}
		return result;
	}
	


	int main() {
		ios::sync_with_stdio(0);
		cin.tie(0);
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> s[i][j];
			}
		}

		int white, black;
		int result = 99999;
		for (int i = 0; i <= n - 8; i++) {
			for (int j = 0; j <= m - 8; j++) {
				white = white_count(i, j);
				black = black_count(i, j);
				if (white < black)
					result = (white < result) ? white : result;
				else
					result = black < result ? black : result;
			}
		}
		cout << result;
	}