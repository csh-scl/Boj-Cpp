#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[25];
bool st[25];
int val[25];
int index3 = 0;


void pr(int k, int sum) {
	if (sum == m && k!=0) {
		index3++;
	}

	int number = 0;
	
	if (k != 0) number = arr[k - 1] + 1;
	for (int i = number; i < n; i++) {
		if (!st[i]) {
			arr[k] = i;

			sum += val[i];
			st[i] = 1;
			pr(k + 1, sum);
			sum -= val[i];
			st[i] = 0;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> val[i];
	}
	pr(0, 0);
	cout << index3;
}
