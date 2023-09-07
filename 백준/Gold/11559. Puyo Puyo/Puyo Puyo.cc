#include <bits/stdc++.h>
//#include <iostream> // <iostream> 추가
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int N;
bool array321[12][6];
string board[12];
// 밑으로 내려갈 수 있으면, 내려가게 한다. 그 칸의 y좌표(행번호) 값을 리턴한다.
queue<pair<int, int>> q;
vector<pair<int, int>> v;
bool possible;

int isBottombot(int x, int y) {
	int tempY = -1;
	for (int i = x; i < N; i++) {
		if (board[i][y] == '.') tempY = i;
	}
	return tempY;
}

void bfs(int x, int y) {
	q.push({ x,y });
	v.push_back({ x,y });

	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		array321[nx][ny] = 1;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int tx = nx + dx[dir];
			int ty = ny + dy[dir];

			if (tx < 0 || tx >= 12 || ty < 0 || ty >= 12) continue;
			if (board[tx][ty] == '.') continue;
			if (array321[tx][ty] || board[nx][ny] != board[tx][ty]) continue;
			q.push({ tx,ty });
			v.push_back({ tx ,ty });
			array321[tx][ty] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int crash = 0, tempY = -1;
	N = 12;

	

	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	while (true) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 6; j++) {
				if (board[i][j] != '.' && array321[i][j] != 1) bfs(i, j);
				if (v.size() >= 4) possible = true;
				if (v.size() < 4) {
					for (int i = 0; i < v.size(); i++) {
						array321[v[i].first][v[i].second] = 0;
					}
				}
				v.clear();
			}
		}
		if (possible == false) {
			break;
		}
		else {
			crash++;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < 6; j++) {
					if (array321[i][j] == 1) {
						board[i][j] = '.';
					}
				}
			}

			for (int i = 0; i < 6; i++) {
				for (int j = N - 2; j >= 0; j--) {
					tempY = -1;
					if (board[j][i] != '.') {
						tempY = isBottombot(j, i);
					}
					if (tempY != -1) {
						board[tempY][i] = board[j][i];
						board[j][i] = '.';
					}
				}
			}
		}

		possible = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 6; j++) {
				array321[i][j] = 0;
			}
		}
	}
	cout << crash;
}