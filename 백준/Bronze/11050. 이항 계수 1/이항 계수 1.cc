#include <bits/stdc++.h>
using namespace std;

int arr[10][10];

int main(void) {
	int n, k;
	cin >> n >> k;
	arr[1][0] = 1;
	arr[1][1] = 1;
	for (int i = 2; i <= 10; i++) {
		arr[i][0] = 1;
		for (int j = 1; j < i; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
		arr[i][i] = 1;
	}

	cout << arr[n][k];
}