#include <bits/stdc++.h>
using namespace std;

int val;

int main() {
    deque<pair<int,int>> dk; // 값, 인덱스
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> val;
        dk.push_back(make_pair(val, i + 1));
    }
    
    while(dk.size() !=0) {
        int cnt = dk.front().first;
        cout << dk.front().second << " ";
        dk.pop_front();

        if (dk.empty()) break;

        if (cnt <= 0) {
            for (int i = cnt; i < 0; i++) {
                dk.push_front(dk.back());
                dk.pop_back();
            }
        }
        else {
            for (int i = 0; i < cnt-1; i++) {
                dk.push_back(dk.front());
                dk.pop_front();
            }
        }
    }
}
