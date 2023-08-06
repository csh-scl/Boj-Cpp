#include <bits/stdc++.h>
using namespace std;

// 배열 두개 선언 입력 받는 배열과 방문 배열선언해서 돌면서 BFS 가능 횟수 count 해준다.
int board[102][102];
bool state[102][102];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int maxlimit, n, maxcnt;

void bfs(int i, int j, int limit) {
	queue<pair<int, int>> q;
	state[i][j] = true;
	q.push({ i,j });
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue; 
			if (!state[nx][ny] && board[nx][ny] > limit) {  
				state[nx][ny] = true;
				q.push({ nx, ny }); // 푸시
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			maxlimit = max(maxlimit, board[i][j]);
		}
	}
	
	
	for (int limit = 0; limit <= maxlimit; limit++) {
		for (int i = 0; i < n; i++) {
			fill(state[i], state[i] + n, false);
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] > limit && state[i][j] == 0) {
					bfs(i, j, limit);
					cnt++;
				}
			}
		}
		maxcnt = max(cnt, maxcnt);
	}

	cout << maxcnt;
}