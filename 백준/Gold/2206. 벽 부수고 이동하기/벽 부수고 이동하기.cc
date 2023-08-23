#include <bits/stdc++.h>
using namespace std;


int arr[1002][1002][2];
bool vis[1002][1002];

int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = { 0,1,0,-1 };

int bfs(int x, int y) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j][0] = arr[i][j][1] = -1;
		}
	}
	arr[0][0][0] = 1;
	arr[0][0][1] = 1;
	queue<tuple<int, int,int>> q;
	q.push({ x,y,0 });
	while (!q.empty()) {
		tuple<int, int,int> cur = q.front();
		q.pop();
		int x, y, broken;
		tie(x, y, broken) = cur;
		int nextIndex = arr[x][y][broken] + 1;
		if (x == n - 1 && y == m - 1) return arr[x][y][broken];
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] == 0 && arr[nx][ny][broken] == -1) {
				arr[nx][ny][broken] = nextIndex;
				q.push({ nx,ny,broken });
			}
			if (!broken && vis[nx][ny] == 1 && arr[nx][ny][1] == -1) {
				arr[nx][ny][1] = nextIndex;
				q.push({ nx,ny,1});
			}
		}
	}
	return -1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '0') vis[i][j] = 0;
			else vis[i][j] = s[j];
		}
	}
	cout << bfs(0, 0);
}
