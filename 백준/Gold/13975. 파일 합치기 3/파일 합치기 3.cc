#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        priority_queue<long long, vector<long long>, greater<long long>> q;
        for (int i = 0; i < m; i++) {
            long long val;
            cin >> val;
            q.push(val);
        }

        long long answer = 0;
        while (q.size() > 1) {
            // 가장 작은 2개 꺼냄
            long a = q.top();
            q.pop();
            long long b = q.top();
            q.pop();
            
            answer += a + b;
            
            q.push(a+b);
        }
        cout << answer << '\n';
    }
}
