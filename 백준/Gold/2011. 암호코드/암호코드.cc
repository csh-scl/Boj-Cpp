#include <bits/stdc++.h>
using namespace std;

int dp[5002];
int a[5002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s; // 333
	int len = s.size(); // 3이겠지
	for (int i = 0; i < len; i++) {
		a[i] = s[i] - '0';
	}

	bool pos = true;

	if (a[0] > 0) {
		dp[0] = 1;
	}
	else {
		pos = false;
	}

	

	for (int i = 1; i < len; i++) {
		if (a[i] == 0) {
			if (a[i - 1] > 2 || a[i-1] == 0) {
				pos = false;
				break;
			}
			else {
				if (i == 1) {
					dp[i] = dp[i - 1] % 1000000;
				}
				else {
					dp[i] = dp[i - 2] % 1000000;
				}
			}
		}
		else {
			if (a[i - 1] != 0 && a[i - 1] * 10 + a[i] <= 26) {
				if (i == 1) dp[i] = 2;
				else {
					dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000;
				}
			}
			else {
				dp[i] = dp[i - 1] % 1000000;
			}
		}

	}

	if (pos) cout << dp[len - 1];
	else {
		cout << 0;
	}
	
}