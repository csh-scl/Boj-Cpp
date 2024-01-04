#include <bits/stdc++.h>
using namespace std;

int mn = 1e9+1;
int a[100005];

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int en = 0;
	int sum = a[0];
	bool minus = false;
	for (int i = 0; i < n; i++) {
		while (en < n && sum < s) {
			en++;
			if (en != n) sum += a[en];
		}
		if (en == n) break;
		mn = min(mn, en- i +1);
		sum -= a[i];
	}
	if (mn == 1e9 + 1) {
		cout << 0;
	}
	else cout << mn;
} 