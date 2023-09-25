#include <bits/stdc++.h>
using namespace std;

int arr[300][3];
int stairs[300];
int num;

int main()
{
	cin >> num;
	for (int i = 1; i <= num; i++) {
		cin >> stairs[i];
	}
	arr[1][1] = stairs[1];
	arr[2][1] = stairs[2];
	arr[2][2] = stairs[1] + stairs[2];

	for (int i = 3; i <= num; i++) {
		arr[i][1] = max(arr[i - 2][2], arr[i - 2][1]) + stairs[i];
		arr[i][2] = arr[i - 1][1] + stairs[i];
	}

	cout << max(arr[num][1], arr[num][2]);
}
