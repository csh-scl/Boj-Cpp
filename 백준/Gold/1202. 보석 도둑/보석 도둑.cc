#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(0); // cin과 cout의 묶음 해제

    multimap<int, int> k;
    multiset<int> cr;
    int n, m;
    cin >> n >> m;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> y >> x;
        k.insert({ x,y });
    }

    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;
        cr.insert(val);
    }

    while (!cr.empty() && !k.empty()) {
        int v, w;
        v = (*k.rbegin()).first;
        w = (*k.rbegin()).second;

        auto iter = cr.lower_bound(w);
        if (iter == cr.end()) {
            k.erase(prev(k.end()));
            continue;
        }
        cr.erase(iter);
        ans += v;

        k.erase(prev(k.end()));
    }

    cout << ans;
}