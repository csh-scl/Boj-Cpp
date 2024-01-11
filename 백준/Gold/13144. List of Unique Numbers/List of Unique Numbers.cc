#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
   
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<bool>vis(100002, false);
    
    long long cnt = 0;
    int st = 0, en = 0;
    
    for (st = 0; st < n; st++) {
        while (en < n && !vis[v[en]]) {
            vis[v[en]] = true;
            en++;
        }
        cnt += en - st;
        vis[v[st]] = false;
    }
    cout << cnt;
}