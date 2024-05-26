#include <bits/stdc++.h>
using namespace std;

int dp[1005];
int st[1005];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    fill(dp, dp + 1005, 20000000);
    for (int i = 1; i <= n; i++) {
        char s;
        cin >> s;
        if (s == 'B') {
            st[i] = 0;
        }
        else if (s == 'O') {
            st[i] = 1;
        }
        else {
            st[i] = 2;
        }
    }

    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = i - 1; j >= 1; j--) {
            if((st[j] + 1) % 3 == st[i])
            dp[i] = min(dp[j] + (i - j) * (i - j), dp[i]);
        }
    }

    if (dp[n] == 20000000) {
        cout << -1 << '\n';
    }
    else {
        cout << dp[n];
    }
}