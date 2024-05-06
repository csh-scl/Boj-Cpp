#include <bits/stdc++.h>
using namespace std;

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
bool vis[100005];
// 도착위치, 비용
vector<pair<int, int>> v[100005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int st, en, cost;
		cin >> st >> en >> cost;
		v[st].push_back({ en,cost });
		v[en].push_back({ st,cost });
	}

	vis[1] = true;

	int ans = 0;
	int cnt = 0;

	int maxCost = 0;

	for (auto k : v[1]) {
		pq.push({ k.second, 1, k.first });
	}

	while (cnt < n - 1) {
		int cost, st, en;
		tie(cost, st, en) = pq.top(), pq.pop();

		if (vis[en]) continue;
		cnt++;
		ans += cost;
		vis[en] = true;

		maxCost = max(maxCost, cost);

		for (auto k : v[en]) {
			if(!vis[k.first])
			pq.push({ k.second, en, k.first });
		}

		
	}

	cout << ans - maxCost;
}