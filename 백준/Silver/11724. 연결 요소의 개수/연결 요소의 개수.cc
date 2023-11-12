#include <bits/stdc++.h>
using namespace std;

vector<int> st[1001];
bool vis[1001];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int totalgrp = 0;
    int node, ts;
    cin >> node >> ts;

    queue<int> q;
    // 간선 정보 추가
    for (int i = 1; i <= ts; i++) {
        int x, y;
        cin >> x >> y;

        st[x].push_back(y);
        st[y].push_back(x);
    }
    
    

    for (int i = 1; i <= node; i++) {
        if (vis[i]) continue;
        q.push(i);
        totalgrp++;
   
        vis[i] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto nxt : st[cur]) {
                if (vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }
    cout << totalgrp;
}   