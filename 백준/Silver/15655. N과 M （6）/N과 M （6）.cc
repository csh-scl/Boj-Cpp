#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool state[10];
int val[10];

void pr(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << val[arr[i]] << ' ';
		}
		cout << '\n';
		return;
	}

	int st = 0;
	if(k != 0) st = arr[k - 1] + 1;


	for (int i = st; i < n; i++) {
		if (!state[i]) {
			arr[k] = i;
			state[i] = 1;
			pr(k + 1);
			state[i] = 0;
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
	sort(val, val+n);
	pr(0);
}