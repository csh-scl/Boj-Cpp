#include <bits/stdc++.h>
using namespace std;

int n, m;
char arr[20];
int st[20];

void pr(int k, int alpa, int deta) {
	if (k == n) {
		if (alpa >= 1 && deta >= 2) {
			for (int i = 0; i < n; i++) {
				cout << arr[st[i]];
			}
			cout << '\n';
		}
		
		return;
	}

	int index = 0;
	if (k != 0) index = st[k - 1] + 1;
	for (int i = index; i < m; i++) {
		st[k] = i;
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'u' || arr[i] == 'o') {
			pr(k + 1, alpa + 1, deta);
		}
		else {
			pr(k + 1, alpa, deta+1);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + m);
	pr(0,0,0);
}
