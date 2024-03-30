#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[105];
int val[105];
int deg[105];
bool ismid[105];
int result[105];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 완제품의 수
    int n;
    cin >> n;

    queue<int> q;

    int tt;
    cin >> tt;

    while (tt--) {
        // 제품번호, 필요 부품, 개수
        int x, y, z;
        cin >> x >> y >> z;
        
        adj[x].push_back({ y,z });
        ismid[x] = true;
        deg[y]++;
    }

    /*for (int i = 1; i <= n; i++) {
        if (deg != 0) {
            q.push(i);
        }
    }*/

    q.push(n);
    val[n] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto k : adj[cur]) {
            val[k.first] += k.second * val[cur];
            deg[k.first]--;
            if (deg[k.first] == 0) q.push(k.first);
        }
    }

    for (int i = 1; i < n; i++) {
        if (ismid[i] == false) {
            cout << i << ' ' << val[i] << '\n';
        }
    }
}
