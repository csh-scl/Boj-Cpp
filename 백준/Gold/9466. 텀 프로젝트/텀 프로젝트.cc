#include <bits/stdc++.h>
using namespace std;

int n;
int st[100005];
int arr[100005];

const int is_defined = -1;
const int visited = 0;

void bfs(int x) {
	int cur = x;
	while (true) {
		st[cur] = x;
		cur = arr[cur];
		if (st[cur] == x) {
			while (st[cur] != is_defined) {
				st[cur] = is_defined;
				cur = arr[cur];
			}
			return;
		}
		else if (st[cur] != 0) return;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	while (n--) {
		int x;
		int ans = 0;
		cin >> x;
		fill(st + 1, st + x + 1, 0);
		for (int i = 1; i <= x; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i <= x; i++) {
			if (st[i] == 0) bfs(i);
		}
		for (int i = 1; i <= x; i++) {
			if (st[i] != is_defined) ans++;
		}
		cout << ans << "\n";
	}
}
