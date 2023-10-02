#include <bits/stdc++.h>
using namespace std;
// <비용, 정점>
vector<pair<int, int>> adj[10005];
bool vis[10005];

int v, e; // 정점 , 간선의 개수

int main()
{
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back(make_pair(w, y));
        adj[y].push_back(make_pair(w, x));
    }

    int n = 0; // 간선의 갯수
    int ans = 0;

    vis[1] = 1;
    for (auto k : adj[1]) {
        pq.push({ k.first, 1 , k.second });
    }

    while (!pq.empty()) {
        int cost,a,b;
        tie(cost, a ,b) = pq.top(); pq.pop();
        if (vis[b]) continue;
        vis[b] = 1;
        ans += cost;
        n++;
        for (auto k : adj[b]) {
            if (!vis[k.second])
                pq.push({k.first, b, k.second});
        }

    }
    cout << ans;
}

