#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

pair<int, int> k[3000003];

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(0); // cin과 cout의 묶음 해제
    
    
    multiset<int> cr;
    int n, m;
    cin >> n >> m;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> y >> x;
        k[i].first = x;
        k[i].second = y;
    }

    sort(k, k + n);


    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;
        cr.insert(val);
    }

    for (int i = n - 1; i>=0; i--) {
        int v, w;
        tie(v, w) = k[i];
        auto iter = cr.lower_bound(w);
        if (iter == cr.end()) continue;
        cr.erase(iter);
        ans += v;
    }

    cout << ans;
}