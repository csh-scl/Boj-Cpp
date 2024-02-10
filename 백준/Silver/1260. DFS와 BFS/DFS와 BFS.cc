#include <bits/stdc++.h>
using namespace std;

vector<int> st[1001];
bool vis[1001];

int node, ts, stpoint;

void dfs(int num) {
    cout << num << ' ';
    vis[num] = true;
    for (auto nxt : st[num]) {
        if (vis[nxt]) continue;
        dfs(nxt);
    }
}

void bfs() {
    queue<int> q;
    q.push(stpoint);
    vis[stpoint] = true;
    cout << stpoint << ' ';
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (auto nxt : st[cur]) {
            if (vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
            cout << nxt << ' ';
        }
    }
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> node >> ts >> stpoint;    
    // 간선 정보 추가
    for (int i = 1; i <= ts; i++) {
        int x, y;
        cin >> x >> y;

        st[x].push_back(y);
        st[y].push_back(x);
    }
    
    for (int i = 1; i <= node; i++) {
        sort(st[i].begin(), st[i].end());
    }

    dfs(stpoint);
    cout << '\n';
    fill(vis, vis + node+1, 0);
    bfs();
}   