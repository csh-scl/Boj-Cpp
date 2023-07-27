#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second


int vis[100002];
// 이 토마토 문제는 BFS 각자 돌리면서 이동시키면서 채워주는 문제 이 친구는 한 놈의 한놈에게 영향을 주는 상황
int dx[3] = { 1,-1,0 };


int main(void) {
	ios::sync_with_stdio(0);
	fill(vis, vis + 100001, -1);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	queue<int> q;
	q.push(n);
	vis[n] = 0;
	while (vis[m] == -1) {
		int cur = q.front();
		q.pop();
		for (int dir = 0; dir < 3; dir++) {
			if (dx[dir] == 0) {
				int nx = cur * 2;
				if (nx < 0 || nx > 100000) continue;
				if (vis[nx] >= 0) continue;
				q.push(nx);
				vis[nx] = vis[cur]+1;
			}
			else {
				int nx = cur + dx[dir];
				
				if (nx < 0 || nx > 100000) continue;
				if (vis[nx] >= 0) continue;
				q.push(nx);
				vis[nx] = vis[cur] + 1;
			}
		}
	}
	cout << vis[m];
}
