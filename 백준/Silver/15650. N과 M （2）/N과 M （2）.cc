#include <bits/stdc++.h>
using namespace std;

int n, m;
 // 값을 저장해 출력하는 배열 index 0에서 부터
 // 각각의 원소를 사용했는 지 안했는지를 나타내는 배열
int arr[10];
bool state[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int st = 1;
	if (k != 0) st = arr[k - 1] + 1;
	for (int i = st; i <= n; i++) {
		if (!state[i]) {
			
			arr[k] = i;
			state[i] = 1;
			func(k + 1);
			state[i] = 0;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0);	
}