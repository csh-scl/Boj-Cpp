#include <bits/stdc++.h>
using namespace std;

int dp[100002];
vector<int> adj[100002];



void bfs(int n) {
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto k : adj[cur]) {
			if (dp[cur] == k) continue;
			q.push(k);
			dp[k] = cur;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);


	int num;
	cin >> num;
	for (int i = 0; i < num-1; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	bfs(1);

	for (int i = 2; i <= num; i++) {
		cout << dp[i] << '\n';
	}
}


