#include <bits/stdc++.h>
using namespace std;
// arr 배열은 해당 당일의 할 수 있는 일 1. 당일일은 하거나 2. 하루 미루기
int num;
long long dp[101][10]; // dp : 자릿수, 숫자일때 올 수 있는 값
int main(void){
	
	cin >> num;
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= num; i++) {
		for (int j = 1; j < 9; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
		dp[i][9] = dp[i - 1][8] % 1000000000;
		dp[i][0] = dp[i - 1][1] % 1000000000;
	}
	long long sum = 0;
	for (int i = 1; i < 10; i++) {
		sum += dp[num][i] % 1000000000;
	}
	cout << sum % 1000000000;
} 