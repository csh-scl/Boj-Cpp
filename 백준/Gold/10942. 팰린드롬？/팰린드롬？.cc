#include <bits/stdc++.h>
using namespace std;

bool arr[2002][2002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> bx(2002);
	int cnt;
	cin >> cnt;
	for (int i = 1; i <= cnt; i++) {
		cin >> bx[i];
	}
	
	fill(arr[0], arr[0]+ cnt, true);


	for (int i = 1; i <= cnt - 1; i++) {
		if (bx[i] == bx[i + 1])
			arr[i][i + 1] = true;
	}

	for (int i = 1; i <= cnt; i++) {
		arr[i][i] = true;
		for (int j = 1; j <= i; j++) {
			if (bx[i] == bx[j] && arr[i - 1][j + 1]) {
				arr[i][j] = true;
			}
		}
	}

	int tt;
	cin >> tt;
	while (tt--) {
		int st, en;
		cin >> st >> en;
		if (arr[en][st] == true) cout << 1 << '\n';
		else {
			cout << 0 << '\n';
		}
	}
}

