#include <bits/stdc++.h>
using namespace std;

vector<int> st[501];
bool vis[501];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int node, cnt;
    cin >> node >> cnt;
    
    // 간선 정보 지인 네트워크 저장
    for (int i = 1; i <= cnt; i++) {
        int fr, to;
        cin >> fr >> to;

        st[fr].push_back(to);
        st[to].push_back(fr);
    }

    queue<int> q;
    vis[1] = true;

    int total = 0;

    for (auto nxt : st[1]) {
        if (vis[nxt]) continue;
        q.push(nxt);
        vis[nxt] = true;
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        total++;
        for (auto nxt : st[cur]) {
            if (vis[nxt]) continue;
            vis[nxt] = true;
            total++;
        }
    }

    cout << total;
}   