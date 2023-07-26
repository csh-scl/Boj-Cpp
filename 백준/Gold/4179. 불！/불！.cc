#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int fire[1002][1002];
char board[1002][1002]; 
int val[1002][1002];
// 이 토마토 문제는 BFS 각자 돌리면서 이동시키면서 채워주는 문제 이 친구는 한 놈의 한놈에게 영향을 주는 상황
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '#') continue;
			else if (board[i][j] == 'J') {
				val[i][j] = -1;
			}
			else if (board[i][j] == 'F') {
				q1.push({ i,j });
			}
			else {
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
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (val[nx][ny] >= 0) continue;
			val[nx][ny] = val[cur.X][cur.Y] + 1;
			q1.push({ nx,ny });
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '#') continue;
			else if (board[i][j] == 'J') {
				q2.push({ i,j });
				continue;
			}
			else if (board[i][j] == 'F') {
				continue;
			}
			else {
				fire[i][j] = -1;
			}
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << val[i][j] << ' ';
		}
	}
	cout << '\n';*/
	
	while (!q2.empty()) {
		pair<int, int> cur = q2.front();
		q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				cout << fire[cur.X][cur.Y] + 1;
				return 0;
 			}
			if (fire[nx][ny] >= 0) continue;
			if (val[nx][ny] != -1 &&  fire[cur.X][cur.Y] + 1 >= val[nx][ny]) continue;
			q2.push({ nx, ny });
			fire[nx][ny] = fire[cur.X][cur.Y] + 1;
		}
	}

	cout << "IMPOSSIBLE";
	
}
