#include <bits/stdc++.h>
using namespace std;



int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int length = s.size();
    for (int i = 0; i < length; i++) {
        if (s[i] != s[length - 1 - i]) {
            cout << 0;
            return 0;
        }
    }
    cout << 1;
    return 0;
}
