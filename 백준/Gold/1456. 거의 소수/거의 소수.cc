#include <bits/stdc++.h>
using namespace std;

vector<int> chk(10000005, 0);
vector<int> result;

int cnt;

int main() {
    
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int max = 10000000;
    long long st, en;
    cin >> st >> en;
   
    for (int i = 2; i * i <= max; i++) {
        if (chk[i] == -1) continue;
        for (int j = i * i; j <= max; j += i) {
            chk[j] = -1;
        }
    }
    for (int i = 2; i < max; i++) {
        if (chk[i] == 0) result.push_back(i);
        
    }

    for (int k : result) {
        
        for (long long i = k; i <= en/k; i *= k) {
            if (i*k >= st) cnt++;

        }
    }

    cout << cnt;

}