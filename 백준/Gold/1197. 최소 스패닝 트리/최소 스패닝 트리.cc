#include <bits/stdc++.h>
using namespace std;

// 비용, 출발, 도착지
priority_queue < tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

int n, m;
vector<pair<int, int>> v[10005];
bool vis[10005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		// 도착지, 비용 정보 추가
		v[x].push_back({ y,z });
		v[y].push_back({ x,z });
	}

	int cnt = 0;
	vis[1] = 1;

	for (auto k : v[1]) {
		int des = k.first;
		int pri = k.second;
		pq.push({ pri, 1, des});
	}

	int ans = 0;

	// 간선이 n-1개가 될 때 까지 반복한다.
	while (cnt < n - 1) {
		int cost, st, en;
		tie(cost, st, en) = pq.top(); pq.pop();
		if (vis[en]) continue;
		ans += cost;
		vis[en] = 1;
		cnt++;
		for (auto nxt : v[en]) {
			pq.push({ nxt.second, en, nxt.first});
		}
	}

	cout << ans;
}