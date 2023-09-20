#include <bits/stdc++.h>
using namespace std;

queue<int> q;
vector<int> v;

void print() {
	cout << '<';
	int k = v.size();
	for (int i = 0; i < k-1; i++) {
		cout << v[i] << ", ";
	}
	cout << v[k - 1] << '>';
}

void clear(int k) {
	while (!q.empty()) {
		for (int i = 0; i < k-1; i++) {
			q.push(q.front());
			q.pop();
		}
		v.push_back(q.front());
		q.pop();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		q.push(i);
	}
	clear(b);
	print();
}
