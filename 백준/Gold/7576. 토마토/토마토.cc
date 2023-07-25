#include <bits/stdc++.h>
using namespace std;

#define X first 
#define Y second

int arr[1002][1002]; // 토마토 상태를 입력받는 배열
int val[1002][1002]; //요일은 카운트 해주는 배열

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, n;
	cin >> m >> n;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) q.push({ i,j });
			if (arr[i][j] == 0) val[i][j] = -1;
		}
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (val[nx][ny] >= 0) continue;
			val[nx][ny] = val[cur.X][cur.Y]+1;
			q.push({ nx, ny });
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (val[i][j] == -1) {
				cout << -1;
				return 0;
			}
			ans = max(val[i][j], ans);
		}
	}
	cout << ans;
}
