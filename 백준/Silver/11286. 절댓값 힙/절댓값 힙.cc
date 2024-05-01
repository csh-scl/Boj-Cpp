#include <bits/stdc++.h>
using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) {
			return a > b; // 커지는 순서로
		}
		else {
			return abs(a) > abs(b); // 절댓값이 커지는 순서로
		}
	}
};

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int, vector<int>, cmp> q;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			if (q.size() == 0) {
				cout << 0 << '\n';
			}
			else {
				cout << q.top() << '\n';
				q.pop();
			}
		}
		else {
			q.push(x);
		}
	}
	
}