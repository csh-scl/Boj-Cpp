#include <bits/stdc++.h>
using namespace std;

long long dp[1001][10];

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int z = j; z <= 9; z++) {
				dp[i][j] += dp[i - 1][z];
				dp[i][j] %= 10007;
			}
		}
	}
	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += dp[n][i];
	}

	cout << sum % 10007;
}
