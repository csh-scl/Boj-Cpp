#include <bits/stdc++.h>
using namespace std;




int vis[20002];
vector<int> adj[20002];
int no, eg;

bool bfs() {
    fill(vis, vis + no+1 , -1);
    queue<int> q;
    for (int i = 1; i <= no; i++) {
        if (vis[i] != -1) {
            continue;
        }
        else {
            q.push(i);
            vis[i] = 0;

            while (!q.empty()) {
                int cur = q.front(); // 3번
                q.pop();
                for (auto k : adj[cur]) {
                    if (vis[k] != -1) {
                        if (vis[k] == vis[cur]) {
                            return false;
                        }
                        else {
                            continue;
                        }
                    }
                    else {
                        vis[k] = (vis[cur] + 1) % 2;
                        q.push(k);
                    }
                }
            }
        }
    }

    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;
    while (k--) {

        cin >> no >> eg;

        for (int i = 1; i <= no; i++)
            adj[i].clear();

        for (int i = 0; i < eg; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        if (bfs()) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }


}
