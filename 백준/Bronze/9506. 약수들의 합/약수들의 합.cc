#include <bits/stdc++.h>
using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true){
        int x;
        int count = 0;
        cin >> x;
        if (x == -1) break;
        int sum = 0;
        vector<int> cur;
        for (int i = 1; i < x; i++) {
            if (x % i == 0) {
                sum += i;
                cur.push_back(i);
            }
        }
        int max = cur.size();
        if (sum == x) {
            cout << x << " = ";
            for (int i = 0; i < max; i++) {
                if (i == max - 1) {
                    cout << cur[i];
                    break;
                };
                cout << cur[i] << " + ";
            }
            cout << '\n';
        }
        else {
            cout << x << " is NOT perfect." << '\n';
        }
    }
}
