#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[52][52];
int val[52][52];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int number;



int main(void) {
	queue<pair<int, int>> q;
	ios::sync_with_stdio(0);
	cin >> number;
	int n, m, k;
	while (number--) {
		int count = 0;
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> y >> x;
			board[x][y] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 1 && val[i][j] != 1) {
					count++;
					q.push({ i,j });
					val[i][j] = 1;
					while (!q.empty()) {
						pair<int, int> cur = q.front();
						q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
							if (board[nx][ny] != 1 || val[nx][ny] == 1) continue;
							q.push({ nx,ny });
							val[nx][ny] = 1;
						}
					}
				}
			}
		}
		cout << count << '\n';
		for (int i = 0; i < n; i++) fill(board[i], board[i] + m, 0);
		for (int i = 0; i < n; i++) fill(val[i], val[i] + m, 0);
	}
}