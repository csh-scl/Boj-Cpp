#include <bits/stdc++.h>
using namespace std;

int weight[102], value[102];
int res[100001]; // 1차원 DP 배열 (무게 j까지 담을 때 최대 가치)

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }

    // 1차원 DP 최적화 (거꾸로 순회)
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= weight[i]; j--) { 
            res[j] = max(res[j], res[j - weight[i]] + value[i]);
        }
    }

    cout << res[m]; // 최대 가치 출력
}