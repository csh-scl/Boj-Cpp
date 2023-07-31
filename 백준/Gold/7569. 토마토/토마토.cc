#include <bits/stdc++.h>
using namespace std;

int board[102][102][102];
int state[102][102][102];

int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { 1,-1,0,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	bool st = true;
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < b; j++) {
			for (int k = 0; k < a; k++) {
				cin >> board[j][k][i];
			}
		}
	}
	
	int val = 0;
	queue<tuple<int, int, int>> q;
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < b; j++) {
			for (int k = 0; k < a; k++) {
				if (board[j][k][i] == 1 && state[j][k][i] == 0) {
					q.push({ j,k,i });
					state[j][k][i] = 1;
				}
			}
		}
	}
	
	while (!q.empty()) {
		tuple<int,int,int> cur = q.front();
		q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nx = get<0>(cur) + dx[dir];
			int ny = get<1>(cur) + dy[dir];
			int nz = get<2>(cur) + dz[dir];
			if (nx < 0 || nx >= b || ny < 0 || ny >= a || nz < 0 || nz >= c) continue;
			if (board[nx][ny][nz] == -1 || state[nx][ny][nz] >=1) continue;
			q.push({ nx,ny,nz });
			st = false;
			state[nx][ny][nz] = state[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
		}
	}
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < a; j++) {
			for (int k = 0; k < c; k++) {
				if (state[i][j][k] == 0 && board[i][j][k] != -1) {
					cout << -1;
					return 0;
				}
				if(st == false)
				val = max(val, state[i][j][k]);
			}
		}
	}
	if (st == false) cout << val - 1;
	else cout << val;

}