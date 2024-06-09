#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> v[100005];
int up[100005];
int dp[100005];

void cur(int val) {
    if (up[val] != -1) {
        dp[val] += dp[up[val]];
    }
    for (auto nxt : v[val]) {
        cur(nxt);
    }
}


int main() {
    
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    // 조상 넘겨받기
    // i 내가 4번일때 엄마가 3번이야.
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == -1) {
            up[i] = -1;
        }
        else {
            v[x].push_back(i);
            up[i] = x;
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        dp[x] += y;
    }

    cur(1);

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << ' ';
    }
}