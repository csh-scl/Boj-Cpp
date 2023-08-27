#include <bits/stdc++.h>
using namespace std;

int n, m;
int board1[8][8];
int board2[8][8];

vector<pair<int, int>> cctv;
int count2 = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
 
void upd(int x, int y, int dir) {
	dir %= 4;
	while (true) {
		x = x + dx[dir];
		y = y + dy[dir];
		if (x < 0 || x >= n || y < 0 || y >= m) return;
		if (board1[x][y] == 6) return;
		if (board2[x][y] != 0) continue;
		board2[x][y] = 7;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int mn = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board1[i][j];
			if (board1[i][j] != 0 && board1[i][j] != 6) {
				cctv.push_back({ i,j });
			}
			if (board1[i][j] == 0) mn++;
		}
	}
	int count = cctv.size();
	int num = 1; // 64
	for (int i = 0; i < count; i++) num *= 4;
	for (int i = 0; i < num; i++) {
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				board2[x][y] = board1[x][y];
			}
		}
		int temp = i;
		for (int x = 0; x < count; x++) {
			int dir = temp % 4;
			temp = temp / 4;
			int nx = cctv[x].first;
			int ny = cctv[x].second;
			if (board1[nx][ny] == 1) {
				upd(nx, ny, dir);
			}
			if (board1[nx][ny] == 2) {
				upd(nx, ny, dir);
				upd(nx, ny, dir + 2);
			}
			if (board1[nx][ny] == 3) {
				upd(nx, ny, dir);
				upd(nx, ny, dir + 1);
			}
			if (board1[nx][ny] == 4) {
				upd(nx, ny, dir);
				upd(nx, ny, dir + 1);
				upd(nx, ny, dir + 2);
			}
			if (board1[nx][ny] == 5) {
				upd(nx, ny, dir);
				upd(nx, ny, dir + 1);
				upd(nx, ny, dir + 2);
				upd(nx, ny, dir + 3);
			}
		}
		int val = 0;
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < m; b++) {
				if (board2[a][b] == 0) val++;
			}
		}
		mn = min(val, mn);
	}
	cout << mn;
}

