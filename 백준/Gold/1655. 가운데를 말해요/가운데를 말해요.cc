#include <bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int, vector<int>, cmp> minheap;
    priority_queue<int> maxheap;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        if (maxheap.size() <= minheap.size()) {
            maxheap.push(val);
        }
        else {
            minheap.push(val);
        }

        if (!minheap.empty() && maxheap.top() > minheap.top()) {
            maxheap.push(minheap.top());
            minheap.pop();
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        cout << maxheap.top() << '\n';  
    }
    
}
