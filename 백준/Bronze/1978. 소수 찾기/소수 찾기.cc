#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;
    vector<int> v(num);
    for (int i = 0; i < num; i++) {
        cin >> v[i];
    }

    int count = 0;
    for (auto k : v) {
        if (k == 1) continue;
        if (isPrime(k)) count++;
    }

    cout << count;
}
