#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int st, en;
    cin >> st >> en;
    vector<bool> v(en+1, true); // true 소수
    v[1] = false;
    for (int i = 2; i*i <= en; i++) {
        if (!v[i]) continue;
        for (int j = i * i; j <= en; j += i) {
            v[j] = false;
        }
    }
    for (int i = st; i <= en; i++) {
        if (v[i] == true) cout << i << '\n';
   }
}
