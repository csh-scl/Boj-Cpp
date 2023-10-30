#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int>& x, pair<int, int>& y) {
    if (x.second != y.second) {
        return x.second < y.second;
    }
    return x.first < y.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num;
    cin >> num;
    vector<pair<int, int>> v(num);
    for (int i = 0; i < num; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), comp);

    int ans = 0;
    int t = 0;

    for (int i = 0; i < num; i++) {
        if(t <= v[i].first){
            t = v[i].second;
            ans++;
        }
    }
    cout << ans;
}
