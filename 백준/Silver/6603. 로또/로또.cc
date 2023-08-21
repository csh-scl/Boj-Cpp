#include <bits/stdc++.h>
using namespace std;

int val[15];
bool vis[15];
int arr[15];
int n = 0;

void pr(int k) {
	if (k == 6) {
		for (int i = 0; i < 6; i++) {
			cout << val[arr[i]] << ' ';
		}
		cout << '\n';
		return;
	}

	int st = 0;
	if (k != 0) st = arr[k - 1] + 1;

	for (int i = st; i < n; i++) {
		if (!vis[i]) {
			arr[k] = i;
			vis[i] = 1;
			pr(k + 1);
			vis[i] = 0;
		}
	}
	
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true) {
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> val[i];
		}
		sort(val, val + n);
		pr(0);
		cout << '\n';
	}
}
