#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y;
    cin >> x >> y;
    map<string, int> m;
    for (int i = 0; i < x; i++) {
        string s;
        cin >> s;
        m.insert({ s, 1 });
    }

    for (int i = 0; i < y; i++) {
        string s;
        cin >> s;
        auto it = m.find(s);
        if (it != m.end()) {
            it->second += 1;
        }
        else {
            continue;
        }
    }

    vector<string> s;

    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second == 2) {
            s.push_back(iter->first);
        }
    }

    cout << s.size() << '\n';
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << '\n';
    }
   
}
