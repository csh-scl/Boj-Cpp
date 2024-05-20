#include <bits/stdc++.h>
using namespace std;

int result = 100000000;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    result = x * a + y * b;

    if (a > 2 * c || b > 2 * c) {
        int price = max(x, y) * 2 * c;
        result = min(result, price);
    }

    int m = min(x, y); // 3인 경우

    for (int i = 2; i <= 2 * m; i+=2) {
        
        int price = i * c + a * (x - i / 2) + b * (y - i / 2);
        // cout << "current value : " << i << ' ' << price << '\n';

        result = min(price, result);
    }
    cout << result;
}