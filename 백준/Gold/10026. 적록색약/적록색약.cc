#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

char str[102][102];
int val[102][102];

int n;
queue<pair<int, int>> q;



void bfs(int i, int j) {
	while (!q.empty()) {
		pair<int, int> cur;
		cur = q.front();
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || nx >= n) continue;
			if (val[nx][ny] == 1 || str[i][j] != str[nx][ny]) continue;
			q.push({ nx,ny });
			val[nx][ny] = 1;
		}
	}
}



int area() {
	int index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (val[i][j] == 1) continue;
			q.push({ i,j });
			val[i][j] = 1;
			bfs(i, j);
			index++;
		}
	}
	return index;
}

int main(void) {
	ios::sync_with_stdio(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> str[i][j];
		}
	}
	int jae_joon = area();
	
	for (int i = 0; i < n; i++) fill(val[i], val[i] + n, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (str[i][j] == 'G')
				str[i][j] = 'R';
		}
	}
	
	int Yeon_jin = area();
	cout << jae_joon << ' ' << Yeon_jin;
}