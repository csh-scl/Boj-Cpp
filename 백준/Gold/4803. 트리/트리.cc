#include <bits/stdc++.h>
using namespace std;

vector<int> adj[502];
int vis[502] = {0};

bool isTrue = true;

int dn = 1;

void setNode(int n, int e) {
	for (int i = 0; i < e; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

void dfs(int v, int parent) {
	
	for (auto k : adj[v]) {
		if (k ==  parent) continue;
		if (vis[k] != 0) {
			isTrue = false;
			continue;
		}
		vis[k] = parent;
		dfs(k, v);
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (true) {
		fill(vis, vis + 502, 0);
		for (int i = 1; i <= 501; i++) adj[i].clear();

		int x, y;
		cin >> x >> y;
		if (x == 0 && y == 0) break;
		
		int cnt = 0;
		setNode(x, y);

		for (int i = 1; i <= x; i++) {
			if (vis[i]) continue;
			isTrue = true;
			dfs(i, -1);
			if (isTrue) cnt++;
		}



		cout << "Case " << dn++;
		if (cnt == 0) {
			cout << ": No trees." << '\n';
		}
		else if (cnt == 1)
		{
			cout << ": There is one tree." << '\n';
		}
		else
		{
			cout << ": A forest of " << cnt << " trees." << '\n';
		}
	}
	
}


