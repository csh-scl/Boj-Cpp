#include <bits/stdc++.h>
using namespace std;

// dp[i] 길이가 i원을 만드는데 드는 동전의 개수
int dp[1000001];
int arr[101];

int main(void) {
	int n;
	cin >> n;
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 15746;
	}

	cout << dp[n];
}