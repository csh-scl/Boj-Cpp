#include <bits/stdc++.h>
using namespace std;

int sum;

int main(void) {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		else {
			sum++;
			vector<vector<int>> arr(n, vector<int>(3,0));
			vector<vector<int>> dp(n, vector<int>(3,0));
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < 3; j++) {
					cin >> arr[i][j];
				}
			}

			dp[0][0] = 100000;
			dp[0][1] = arr[0][1];
			dp[0][2] = arr[0][1] + arr[0][2];


			for (int i = 1; i < n; i++) {
				dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][0];
				dp[i][1] = min({ dp[i - 1][1], dp[i][0], dp[i - 1][2], dp[i - 1][0] }) + arr[i][1];
				dp[i][2] = min({ dp[i - 1][1], dp[i][1], dp[i-1][2]}) + arr[i][2];
			}
			cout << sum << ". " << dp[n - 1][1] << "\n";
		}
	}
}