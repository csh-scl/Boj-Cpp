#include <bits/stdc++.h>
using namespace std;
int a[10005];

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int sum = a[0];
	int cnt = 0;
	int en = 0;

	for (int i = 0; i < n; i++) {
		while(en < n && sum < k) {
			en++;
			if (en != n) sum += a[en];
		}
		if (en == n) break;
		if (sum == k) cnt++;
		sum -= a[i];
	}
	cout << cnt;
}