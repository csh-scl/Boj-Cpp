#include <bits/stdc++.h>
using namespace std;

// dp[i] vip를 없다고 생각하고 i번째 앉는 방법의 수 

int st[32001];
queue<int> q;
vector<int> result;
vector<int> res[32001];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int x, y;
    while (m--) {
        cin >> x >> y;
        st[y]++;
        res[y].push_back(x);
        res[x].push_back(y);
    }
    
    for (int i = 1; i <= n; i++) {
        if (st[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        result.push_back(cur);
        for (auto nxt : res[cur]) {
            st[nxt]--;
            if (st[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
    if (result.size() != n) {
        cout << "Is there a cylic graph";
    }
    else {
        for (auto k : result) cout << k << ' ';
    }
}