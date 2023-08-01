#include <bits/stdc++.h>
using namespace std;


#define X first
#define Y second

int val[1002][1002];
int board[1002][1002];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> num;
	while (num--) {
		bool state = true;
		int a, b;
		cin >> b >> a;
		for (int i = 0; i < b; i++) {
			fill(board[i], board[i] + a, 0);
			fill(val[i], val[i] + a, 0);
		}
		queue<pair<int, int>> q1;
		queue<pair<int, int>> q2;
		for (int i = 0; i < a; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < b; j++) {
				if (s[j] == '#') {
					continue;
				}
				else if (s[j] == '*') {
					q1.push({ i,j });
				}
				else if (s[j] == '@') {
					q2.push({ i,j });
					board[i][j] = -1;
				}
				else {
					board[i][j] = -1;
					val[i][j] = -1;
				}
			}
		}
		while (!q1.empty()) {
			pair<int, int> cur = q1.front();
			q1.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= a || ny < 0 || ny >= b) continue;
				if (board[nx][ny] >= 0) continue;
				q1.push({ nx,ny });
				board[nx][ny] = board[cur.X][cur.Y] + 1;
			}
		}

		while (!q2.empty() && state) {
			pair<int, int> cur = q2.front();
			q2.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= a || ny < 0 || ny >= b) {
					cout << val[cur.X][cur.Y]+1 << '\n';
					state = false;
					break;
				}
				if (val[nx][ny] >= 0) {
					continue;
				}
				if (board[nx][ny] == -1) {
					q2.push({ nx,ny });
					val[nx][ny] = val[cur.X][cur.Y] + 1;
				}
				if (board[nx][ny] > val[cur.X][cur.Y]+1) {
					q2.push({ nx,ny });
					val[nx][ny] = val[cur.X][cur.Y] + 1;
				}
			}
		}
		if (state == true) {
			cout << "IMPOSSIBLE" << '\n';
		}
	}
}