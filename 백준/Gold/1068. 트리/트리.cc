#include <bits/stdc++.h>
using namespace std;

vector<int> child[55];
int node;
int k;
int sz;


bool vis[55];

void bfs(int start) {
   
    queue<int> q;
    
    vis[start] = true;

    q.push(start);
    while (!q.empty()) {
        int ps = 0;
        int cur = q.front();
        q.pop();

        
        for (auto nxt : child[cur]) {
            if (!vis[nxt]) {
                ps++;
                vis[nxt] = true;
                q.push(nxt);
            }
        }

        if (ps == 0) sz++;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        // x 조상에 대한 정보
        if (x == -1) {
            node = i;
            continue;
        }

        child[x].push_back(i);
    }

    cin >> k;
    vis[k] = true;

    if(!vis[node]) bfs(node);
    
    cout << sz;
}
