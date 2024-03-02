#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool vis[1005];
int m[1005][1005];
int dp[1005][1005];


int root;
int tar;


void dfs(int prev, int cur, int nxt) {
	
	dp[root][cur] = m[prev][cur] + nxt;
	for (auto k : adj[cur]) {
		if (vis[k]) continue;
		vis[k] = true;
		/*if (k == tar) {
			break;
		}*/
		if (prev == 0) {
			dfs(cur, k, 0); // 
		}
		else {
			dfs(cur, k, dp[root][cur]);
		}
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int x, y, z; // x , z 노드 , z 비용
		cin >> x >> y >> z;
		adj[x].push_back(y);
		adj[y].push_back(x);
		m[x][y] = z;
		m[y][x] = z;
	}


	for (int i = 0; i < k; i++) {

		cin >> root >> tar;
		memset(vis, false, sizeof(vis));
		vis[root] = true;
		dfs(0, root, 0);
		cout <<dp[root][tar] << '\n';
	}

}


