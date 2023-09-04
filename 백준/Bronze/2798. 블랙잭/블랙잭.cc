#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[100];
int maxvalue;
int val[100];

void dfs(int k) {
    if (k == 3) {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += arr[val[i]];
        }
        if (maxvalue < sum && sum <= m) maxvalue = sum;
        return;
    }

    int sz = 0;
    if (k != 0) sz = val[k - 1] + 1;
    for (int i = sz; i < n; i++) {
        val[k] = i;
        dfs(k + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dfs(0);
    cout << maxvalue;
}
