#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

set<int> pl;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int now = 1;

    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        if (val == 1) pl.insert(i);
    }

    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;
        if (val == 1) {
            int tar;
            cin >> tar;
            if (pl.find(tar) != pl.end()) {
                pl.erase(tar);
            }
            else {
                pl.insert(tar);
            }
        }
        else if (val == 2) {
            int move;
            cin >> move;
            int result = now + move;
            if (result % n == 0) {
                now = n;
            }
            else {
                now = (now + move) % n;
            }
        }
        else if (val == 3) {
            int ans = -1;
            if (!pl.empty()) {
                auto it = pl.lower_bound(now);
                if (it != pl.end()) {
                    ans = *it - now;
                }
                else {
                    ans = *pl.begin() + n - now;
                }
            }
            cout << ans << '\n';
        }
    }
}
