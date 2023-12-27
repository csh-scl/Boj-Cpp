#include <bits/stdc++.h>
using namespace std;

// dp[i] 길이가 i원을 만드는데 드는 동전의 개수
int dp[10001];
int arr[101];

int main(void) {
	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= k; j++) {
			dp[j] = dp[j] + dp[j - arr[i]];
		}
	}


	cout << dp[k];
}