	#include <bits/stdc++.h>
	using namespace std;

	int board[1005][1005];
	int dp[1005][1005]; // dp[x][y] : x,y을 하단 꼭짓점으로 가지는 정사각형의 한 변의 길이


	int main(void) {
		ios::sync_with_stdio(0);
		cin.tie(0);
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			string s;
			cin >> s;
			for (int j = 1; j <= m; j++) {
				board[i][j] = s[j - 1] - '0';
			}
		}

		int max_width = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (board[i][j]) {
					dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
					max_width = max(max_width, dp[i][j]);
				}
			}
		}

		cout << max_width * max_width;
	}