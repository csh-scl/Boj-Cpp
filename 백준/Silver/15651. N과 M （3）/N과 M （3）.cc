#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool state[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (state[i] != 2) {
			arr[k] = i;
			state[i] = state[i] + 1;
			func(k + 1); 
			state[i] = state[i] - 1;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0);
}