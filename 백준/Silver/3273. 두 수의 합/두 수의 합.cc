#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int cons[1000001];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int number;
	cin >> number;
	int x;
	int ans = 0;
	for (int i = 0; i < number; i++) {
		cin >> arr[i];
	}
	cin >> x;

	for (int i = 0; i < number; i++) {
		if (x - arr[i] > 0 && cons[x - arr[i]] == 1) {
			ans++;
		}
		cons[arr[i]] = 1;
	}
	cout << ans;
}