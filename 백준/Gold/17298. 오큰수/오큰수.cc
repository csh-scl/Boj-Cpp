#include <bits/stdc++.h>
using namespace std;

int arr[1000005];
int ans[1000005];

int main(void) {
	int n;
	cin >> n;

	stack<int> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	s.push(1000005);
	for (int i = n - 1; i >= 0; i--) {

		while (!s.empty() && s.top() <= arr[i]) {
			s.pop();
		}

		if (s.top() == 1000005) {
			ans[i] = -1;
		}
		else {
			ans[i] = s.top();
		}
		s.push(arr[i]);
	}


	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
}