#include <bits/stdc++.h>
using namespace std;

// 사람수 
int sr[1001];

// 그래프 연결 관계
vector<int> res[1001];
// 결과저장
vector<int> v;
// 위상정렬 위한 q
queue<int> q;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    // 입력처리
    while (m--) {
        int x;
        cin >> x;
        vector<int> temp(x);
        cin >> temp[0];
        int cur = temp[0];
        for (int i = 1; i < x; i++) {
            cin >> temp[i];
            sr[temp[i]]++;
            res[cur].push_back(temp[i]);
            cur = temp[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (sr[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        v.push_back(cur);
        for (auto nxt : res[cur]) {
            sr[nxt]--;
            if (sr[nxt] == 0) q.push(nxt);
        }
    }

    if (v.size() != n) {
        cout << 0;
    }else {
        for (auto k : v) {
            cout << k << '\n';
        }
    }
}