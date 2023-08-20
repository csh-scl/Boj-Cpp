#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool st[10];
int val[10];

void pr(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << val[arr[i]] << ' ';
		}
		cout << '\n';
		return;
	}

	int tmp = 0;

	for (int i = 0; i < n; i++) {
		if (!st[i] && tmp != val[i]) {
			arr[k] = i;
			tmp = val[arr[k]];
			st[i] = 1;

			// cout << "Setting tmp: " << tmp << endl; // tmp 값을 출력

			pr(k + 1);
			st[i] = 0;
		}
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> val[i];
	}
	sort(val, val + n);
	pr(0);
}
