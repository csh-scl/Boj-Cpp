#include <bits/stdc++.h>
using namespace std;

long long arr[1001][1001];

int main(void) {
	int n, k;
	cin >> n >> k;
	arr[1][0] = 1;
	arr[1][1] = 1;
	for (int i = 2; i <= 1000; i++) {
		arr[i][0] = 1;
		for (int j = 1; j < i; j++) {
			arr[i][j] = (arr[i - 1][j] % 10007 + arr[i - 1][j - 1] % 10007) % 10007;
		}
		arr[i][i] = 1;
	}

	cout << arr[n][k];
}