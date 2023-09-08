#include <bits/stdc++.h>
//#include <iostream> // <iostream> 추가
using namespace std;

int arr[10];

int num;

int search(int k) {
	int t = k;
	while (k > 0) {
		t += k % 10;
		k /= 10;
	}

	return t;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> num;
	for (int i = 0; i < num; i++) {
		int value = search(i);
		if (num == value) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
}