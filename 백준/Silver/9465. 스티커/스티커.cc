#include <bits/stdc++.h>
using namespace std;

int dp[100000][2];

int main(void) {
	int n;
	cin >> n;
	while (n--) {
		int k;
		cin >> k;
		
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < k; j++) {
				cin >> dp[j][i];
			}
		}

		// arr[j][i]는 j, i 번째 값을 골랐을 때 최댓값
		vector<vector<int>> arr(k, vector<int>(2));
		arr[0][0] = dp[0][0];
		arr[0][1] = dp[0][1];
		if (k > 1) {
			arr[1][0] = arr[0][1] + dp[1][0];
			arr[1][1] = arr[0][0] + dp[1][1];
		}
		

		for (int i = 2; i < k; i++) {
			for (int j = 0; j < 2; j++) {
				if (j == 0) {
					arr[i][j] = dp[i][j] + max(arr[i - 1][1], arr[i - 2][1]);
				}
				else {
					arr[i][j] = dp[i][j] + max(arr[i - 1][0], arr[i - 2][0]);
				}
				
			}
		}

		int result = max(arr[k - 1][1], arr[k - 1][0]);
		cout << result << '\n';
	}
}