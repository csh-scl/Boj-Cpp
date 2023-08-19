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

	int stand = 0;
	if (k != 0) stand = arr[k - 1];

	for (int i = stand; i < n; i++) {
		arr[k] = i;
		st[i] = 1;
		pr(k + 1);
		st[i] = 0;
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