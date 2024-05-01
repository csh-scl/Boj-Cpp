#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int sum = 0;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		q.push(val);
	}

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		x = q.top();
		q.pop();
		y = q.top();
		q.pop();
		int result = x + y;
		sum += result;
		q.push(result);
	}

	cout << sum;
}