#include <bits/stdc++.h>
using namespace std;

int arr[16];

int weight[102];
int value[102];



int res[102][100002];

// dp[i][j] i번째 물건까지 고려해 무게가 j일때 만들 수 있는 최대 가치 

int main() {
    
    // 개수, 무게
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (weight[i] <= j) {
                res[i][j] = max(res[i - 1][j], res[i - 1][j - weight[i]] + value[i]);
            }
            else {
                res[i][j] = res[i - 1][j];
            }
        }
   }

    cout << res[n][m];
}
