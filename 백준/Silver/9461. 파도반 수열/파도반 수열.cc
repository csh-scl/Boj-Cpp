#include <bits/stdc++.h>
using namespace std;
// 0과 1의 갯수를 저장하는 배열 생성

long long arr[103];



int main(void){
	int num;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	for (int i = 6; i <= 100; i++) {
		arr[i] = arr[i - 1] + arr[i - 5];
	}
	cin >> num;
	while (num--) {
		int x;
		cin >> x;
		cout << arr[x] << '\n';
	}
} 