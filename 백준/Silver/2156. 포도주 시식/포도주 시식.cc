#include <bits/stdc++.h>
using namespace std;

int m[10001][3]; // map[i][j] i번째가 되었을 때 마신 술의 최댓값, j :  0 : 안 마신 경우, 1 : 최초 한잔 : 2 : 연속 두잔
int st[10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt;
    cin >> cnt;
    for (int i = 1; i <= cnt; i++) {
        cin >> st[i];
    }

    m[1][1] = st[1];
    
    m[2][1] = st[2];
    m[2][2] = st[1] + st[2];
    m[2][0] = st[1];

    for (int i = 3; i <= cnt; i++) {
        m[i][0] = max({ m[i - 1][2], m[i - 1][1], m[i - 1][0] });
        m[i][1] = m[i - 1][0] + st[i];
        m[i][2] = m[i - 1][1] + st[i];
    }

    cout << max({ m[cnt][0], m[cnt][1], m[cnt][2] });
}