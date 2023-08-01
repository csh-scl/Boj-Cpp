#include <bits/stdc++.h>
using namespace std;


#define X first
#define Y second

int val[302][302];

int dx[8] = { -2,-2,2,2,1,1,-1,-1 };
int dy[8] = { -1,1,1,-1,2,-2,2,-2 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> num;
	while (num--) {
		queue < pair<int, int>> q;
		int limit;
		cin >> limit;
		for (int i = 0; i < limit; i++) {
			fill(val[i], val[i] + limit, -1);
		}
		int a, b;
		cin >> a >> b;
		q.push({ a,b });
		val[a][b] = 0;
		int x, y;
		cin >> x >> y;
		while (val[x][y] == -1) {
			pair<int, int> cur = q.front();
			q.pop();
			for (int dir = 0; dir < 8; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || nx >= limit || ny < 0 || ny >= limit) continue;
				if (val[nx][ny] != -1) continue;
				q.push({ nx, ny });
				val[nx][ny] = val[cur.X][cur.Y] + 1;
			}
		}
		cout << val[x][y] << '\n';
	}
}