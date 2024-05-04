#include <bits/stdc++.h>
using namespace std;

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
bool vis[1005];
// 도착위치, 비용
vector<pair<int, int>> v[1005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int cost;
			cin >> cost;
			if (i <= j) continue;
			v[i].push_back({ j, cost });
			v[j].push_back({ i, cost });
		}
	}

	vis[1] = true;
	for (auto k : v[1]) {
		pq.push({ k.second, 1, k.first });
	}
	int cnt = 0;
	long long  ans = 0;
	while (cnt < n - 1) {
		int cost, st, en;
		tie(cost, st, en) = pq.top(), pq.pop();
		if (vis[en]) continue;
		vis[en] = true;
		
		ans += cost;
		cnt++;
		for (auto k : v[en]) {
			pq.push({k.second, en, k.first});
		}
	}

	cout << ans;
}