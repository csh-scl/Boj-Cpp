#include <bits/stdc++.h>
using namespace std;


int p[100002];
vector<int> adj[100002];

void dfs(int cur) {
    for (auto nxt : adj[cur]) {
        if (p[cur] == nxt) continue;
        p[nxt] = cur;
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);
    for (int i = 2; i <= n; i++) cout << p[i] << '\n';
}
