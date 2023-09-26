#include <bits/stdc++.h>
using namespace std;

long long arr[1000000];


void reverse(int i) {
	long long size = 0;
	long long num = arr[i]; 
	if (num < 10) {
		arr[i] = num;
		return;
	}
	while (num != 0) {
		size *= 10;
		size += num % 10;
		num /= 10;
	}
	arr[i] = size;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < num; i++) {
		reverse(i);
	}
	sort(arr, arr + num);
	for (int i = 0; i < num; i++) {
		cout << arr[i] << '\n';
	}
}
