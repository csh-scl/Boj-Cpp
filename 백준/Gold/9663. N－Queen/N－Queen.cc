#include <bits/stdc++.h>
using namespace std;

int n;

bool st1[40];
bool st2[40];
bool st3[40];
int index3 = 0;

void pr(int k) {
	if (k == n) {
		index3++;
		return;
	}
	

	for (int i = 0; i < n; i++) {
		if (!st1[i] && !st2[k + i] && !st3[k - i + n - 1]) {
			st1[i] = 1;
			st2[k + i] = 1;
			st3[k - i + n - 1] = 1;
			pr(k + 1);
			st1[i] = 0;
			st2[i + k] = 0;
			st3[k - i + n - 1] = 0;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	pr(0);
	cout << index3;
}
