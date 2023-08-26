#include <bits/stdc++.h>
using namespace std;

int n;
int st[8];
int kg[8];

int ans = 0;
int cnt = 0;

void bfs(int k) {
	if (k == n) {
		cnt = max(cnt, ans);
		return;
	}
	
	if (st[k] <= 0 || ans == n-1) {
		bfs(k + 1);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (st[i] <= 0 || i == k) continue;
		st[k] = st[k] - kg[i];
		st[i] = st[i] - kg[k];
		if (st[k] <= 0) {
			ans++;

		}
		if (st[i] <= 0) {
			ans++;

		}
		bfs(k + 1);
		if (st[k] <= 0) ans--;
		if (st[i] <= 0) ans--;
		st[k] = st[k] + kg[i];
		st[i] = st[i] + kg[k];

	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> st[i] >> kg[i];
	}

	bfs(0);
	cout << cnt;
}
