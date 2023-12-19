#include <bits/stdc++.h>
using namespace std;

int dp[502];

int find(int x) {
	int count = 0;
	while (x % 5 == 0) {
		if (x == 0) {
			return count;
		}
		x /= 5;
		count++;
	}
	return count;
}

int main(void) {
	dp[5] = 1;
	for (int i = 6; i <= 500; i++) {
		int result = 0;
		if (i % 5 == 0) {
			 result = find(i);
		}
		dp[i] = dp[i - 1] + result;
	}

	int num;
	cin >> num;
	cout << dp[num];
}