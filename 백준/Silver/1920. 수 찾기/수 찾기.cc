#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int n, k;

bool binarySearch(int t) {
	int st = 0;
	int en = n - 1;
	
	while (st <= en) {
		int mid = (st + en) / 2;
		if (arr[mid] == t) {
			return true;
		}
		else if (arr[mid] > t) {
			en = mid - 1;
		}
		else {
			st = mid + 1;
		}
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	cin >> k;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		if (binarySearch(x)) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
}