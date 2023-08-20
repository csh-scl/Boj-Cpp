#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool state[10];
int num[10];

// 모든 인덱스를 출력하는 코드
void pr(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << num[arr[i]] << ' ';
		}
		cout << '\n';
		return;
	}
	int st = 0;
	int tmp = 0;
	if (k != 0) st = arr[k - 1] + 1;

	for (int i = 0; i < n; i++) {
		if (tmp != num[i]) {
			arr[k] = i;
			tmp = num[arr[k]];
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
		cin >> num[i];
	}
	sort(num, num + n);
	pr(0);
}
