#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int val[102][102];
int board[102][102];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k; // m 이 가로 n 이 세로의 역할
	cin >> m >> n >> k;
	while (k--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				board[i][j] = 1;
			}
		}
	}
	vector<int> ans;
	queue<pair<int, int>> q;
	int count = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 1 || val[i][j] == 1) continue;
			count++;
			q.push({ i,j });
			val[i][j] = 1;
			int index = 1;
			while (!q.empty()) {
				pair<int, int> cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
					if (board[nx][ny] == 1 || val[nx][ny] ==1) continue;
					q.push({ nx, ny });
					val[nx][ny] = 1;
					index++;
				}
			}
			ans.push_back(index);
		}
	}
	sort(ans.begin(), ans.end());
	cout << count << '\n';
	for (auto k : ans) {
		cout << k << ' ';
	}
}