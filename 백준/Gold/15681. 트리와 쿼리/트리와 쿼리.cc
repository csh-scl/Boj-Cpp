#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int dp[100005];
bool vis[100005];


int dfs(int m) {
	vis[m] = true;
	for (auto k : adj[m]) {
		if (vis[k] == true) continue;
		dp[m] += dfs(k);
	}

	dp[m]++;
	return dp[m];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, z;
	cin >> n >> m >> z;

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	
	dfs(m);





	for (int i = 0; i < z; i++) {
		int k;
		cin >> k;
		cout << dp[k] << '\n';
	}
}


