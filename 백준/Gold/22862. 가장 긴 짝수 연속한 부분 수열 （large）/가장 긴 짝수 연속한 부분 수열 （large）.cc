#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> vs(n);
	for (int i = 0; i < n; i++) {
		cin >> vs[i];
	}

	int cnt = 0;
	int st = 0, en = 0;
	int del = 0;
	for (st = 0; st < n; st++) {
		while (en < n && del + (vs[en]%2) <= k) {
			if (vs[en] % 2 == 1) {
				del++;
			}
			en++;
		}
		cnt = max(cnt, en - st - del);
	//	cout << st << ' ' << en << ' ' << k << '\n';
		if (en == n) break;
		if (vs[st] % 2 == 1) {
			del--;
		}
	}
	cout << cnt;
}