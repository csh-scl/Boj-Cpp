#include <bits/stdc++.h>
using namespace std;

// 비용, 출발, 도착지
priority_queue < tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

int n;
// 도착지, 비용
vector<pair<int, int>> v[100000];
bool vis[100000];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	// 자작 비용
	for (int i = 1; i <= n; i++) {
		int val;
		cin >> val;
		v[i].push_back({ n + 1, val });
		v[n+1].push_back({i, val });
	}

	// 연결 비용
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int cost;
			cin >> cost;
			if (i >= j) continue;
			v[i].push_back({ j, cost });
			v[j].push_back({ i, cost });
		}
	}

	int ans = 0;
	int cnt = 0;

	vis[1] = true;
	for (auto k : v[1]) {
		pq.push({ k.second, 1, k.first });
	}

	while (cnt < n) {
		int cost, a, b;
		tie(cost, a, b) = pq.top(), pq.pop();
		if (vis[b]) continue;
		ans += cost;
		cnt++;
		vis[b] = true;
		for (auto k : v[b]) {
			pq.push({ k.second, b, k.first });
		}
	}

	cout << ans;
}