#include <bits/stdc++.h>
using namespace std;
// 0과 1의 갯수를 저장하는 배열 생성

int arr[505][505];

int main(void){
	int n;
	cin >> n;
	cin >> arr[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				arr[i][1] = arr[i - 1][1] + arr[i][1];
			}
			else if (j == i) {
				arr[i][j] = arr[i - 1][j-1] + arr[i][j];
			}
			else {
				arr[i][j] = max(arr[i - 1][j - 1], arr[i - 1][j]) + arr[i][j];
			}
		}
	}
	int result = *max_element(arr[n], arr[n]+n+1);
	cout << result;
}