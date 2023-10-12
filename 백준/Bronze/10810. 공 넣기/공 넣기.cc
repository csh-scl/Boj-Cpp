#include <bits/stdc++.h>
using namespace std;
// 0과 1의 갯수를 저장하는 배열 생성

int arr[1003];




int main(void){
	int n, m;
	cin >> n >> m;
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		for (int i = x; i <= y; i++) {
			arr[i] = z;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << ' ';
	}
} 