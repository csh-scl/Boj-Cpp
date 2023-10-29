#include <bits/stdc++.h>
using namespace std;


int st[1000005];
int ch[1000005];
int result;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st[x]++;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ch[x]++;
    }

    for (int i = 0; i < 1000005; i++) {
        if (st[i] == ch[i]) continue;
        else if (st[i] > ch[i]) result += st[i] - ch[i];
    }
    cout << result;
}

