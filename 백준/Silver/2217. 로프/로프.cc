#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num;
    cin >> num;
    vector<int> lp(num);
    for (int i = 0; i < num; i++) {
        cin >> lp[i];
    }

    sort(lp.begin(), lp.end(), greater<int>());
    int max = 0;
    for (int i = 0; i < num; i++) {
        int result = 0;
        result = lp[i] * (i + 1);
        if (max < result) max = result;
    }
    cout << max;
}
