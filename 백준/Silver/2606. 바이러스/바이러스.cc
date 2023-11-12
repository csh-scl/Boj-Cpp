#include <bits/stdc++.h>
using namespace std;

vector<int> st[101];
bool vis[101];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, edge;
    cin >> n >> edge;

    while (edge--) {
        int x, y;
        cin >> x >> y;
        st[x].push_back(y);
        st[y].push_back(x);
    }
    int totalgrp = 0;
    queue<int> q;
 
        q.push(1);
        vis[1] = true;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
;
            for (auto nxt : st[cur]) {
                if (vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
                totalgrp++;
            }
        }
    

    cout << totalgrp;
}   