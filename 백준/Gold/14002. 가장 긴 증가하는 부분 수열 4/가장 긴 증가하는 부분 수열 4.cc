#include <bits/stdc++.h>
using namespace std;

int arr[1001];
vector<pair<int, int>> v;
vector<int> lis;


int binarySearch(int value) {
    int left = 0;
    int right = lis.size() - 1;


    while (left <= right) {
        int mid = (left + right) / 2;
        if (value == lis[mid]) return mid;
        else if (value > lis[mid]) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
   // if (right + 1 == left) left = left - 1;
    return left;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    v.push_back({ 1, arr[0] });
    lis.push_back(arr[0]);

    for (int i = 1; i < n; i++) {

        if (arr[i] > lis[lis.size() - 1]) {
            v.push_back({ lis.size() + 1, arr[i] });
            lis.push_back(arr[i]);
        }
        else {
            int pos = binarySearch(arr[i]);
            if (lis[pos] != arr[i])  lis[pos] = arr[i];
          
            v.push_back({ pos + 1, arr[i] });
        }
    }


    stack<int> q;

    int temp = lis.size();

    int st = v.size() - 1;
    for (int i = st; i >= 0; i--) {
        if (v[i].first == temp) {
            q.push(v[i].second);
            temp -= 1;
        }
    }

    
    /*for (auto k : v) {
        cout << k.first << ' ' << k.second << '\n';
    }

    for (auto k : lis) {
        cout << k << ' ';
    }*/

    cout << q.size() << '\n';

    while (!q.empty()) {
        cout << q.top() << ' ';
        q.pop();
    }
}