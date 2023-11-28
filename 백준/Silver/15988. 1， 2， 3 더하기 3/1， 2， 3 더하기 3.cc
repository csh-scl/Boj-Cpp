#include <bits/stdc++.h>
using namespace std;

long long m[1000005]; // m[i]는 i값을 1,2,3으로 나타낼 수 있는 방법의 수



int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num;
    cin >> num;

    m[0] = 0;
    m[1] = 1;
    m[2] = 2;
    m[3] = 4;

    for (int i = 4; i <= 1000000; i++) {
        m[i] = (m[i - 1] + m[i - 2] + m[i-3]) % 1000000009;
    }

    while (num--) {
        int idx;
        cin >> idx;
        cout << m[idx] << '\n';
    }
}