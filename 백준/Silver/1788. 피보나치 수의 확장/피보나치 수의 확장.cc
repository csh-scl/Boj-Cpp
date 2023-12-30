#include <bits/stdc++.h>
using namespace std;

long long dp[1000002];

int main(void) {
	int n;
	cin >> n;
	
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;
	}

	if (n < 0) {
		n *= -1;
		if (n % 2 == 0) {
			cout << -1 << '\n' << dp[n];
		}
		else {
			cout << 1 << '\n' << dp[n];
		}
	}
	else if(n == 0){
		cout << 0 << '\n' << 0;
	}
	else {
		cout << 1 << '\n' << dp[n];
	}
}