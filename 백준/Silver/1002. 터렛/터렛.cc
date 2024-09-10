#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x1, x2, y1, y2, r1, r2, d, c1, c2, n;
    cin >> n;
    while (n--) {
        cin >> x1 >> y1 >> r1;
        cin >> x2 >> y2 >> r2;

        d = pow((x2 - x1), 2) + pow((y2 - y1), 2);
        c1 = pow((r1 - r2), 2);
        c2 = pow((r1 + r2), 2);

        if (d == 0) {
            if (c1 == 0) {
                cout << -1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if (d == c2 || d == c1) {
            cout << 1 << '\n';
        }
        else if ((c1 < d) && (d < c2)) {
            cout << 2 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
}
