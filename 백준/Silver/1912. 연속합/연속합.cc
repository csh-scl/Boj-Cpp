#include <bits/stdc++.h>
using namespace std;
// 0과 1의 갯수를 저장하는 배열 생성

int arr[100003];
int sum[100003];

bool notminus = false;

int main(void){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> sum[i];
	}
	for (int i = 1; i <= n; i++) {
		if (sum[i] > 0) {
			notminus = true;
			break;
		}
	}
	if (notminus) {
		if (sum[1] < 0) arr[1] = 0;
		else
			arr[1] = sum[1];
		for (int i = 2; i <= n; i++) {
			arr[i] = arr[i - 1] + sum[i];
			if (arr[i] < 0) arr[i] = 0;
		}
		/*for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
		cout << '\n'; */
		int result = *max_element(&arr[1], &arr[n] + 1);
		cout << result;
	}
	else {
		sort(sum, sum + n + 1);
		cout << sum[n - 1];
	}
} 