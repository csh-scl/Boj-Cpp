#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


int n[100002];

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(0); // cin과 cout의 묶음 해제
    unordered_map<int, bool> ms;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n+m; i++) {
        int val;
        cin >> val;
        if (ms.find(val) != ms.end()) {
            ms[val] = false;
        }
        else {
            ms[val] = true;
        }
    }
    int cnt = 0;
    for (auto pair : ms) {
        if (pair.second == true) {
            cnt++;
        }
    }
    cout << cnt;
}