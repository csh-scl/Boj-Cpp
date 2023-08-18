#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool state[10000];
int q[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < k; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!state[q[i]]) {
			arr[k] = q[i];
			state[q[i]] = 1;
			func(k + 1);
			state[q[i]] = 0;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> q[i];
	}
	sort(q, q + n);
	func(0);
}