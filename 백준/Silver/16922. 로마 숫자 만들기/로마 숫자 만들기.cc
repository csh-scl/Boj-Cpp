#include <bits/stdc++.h>
using namespace std;

bool result[1001];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            for (int k = 0; k <= n - i - j; k++) {
                int l = n - i - j - k;
                int sum = 1 * i + 5 * j + 10 * k + 50 * l;
                result[sum] = true;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= 50 * n; i++) {
        if (result[i]) cnt++;
    }

    cout << cnt;
}