#include <bits/stdc++.h>
using namespace std;

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	vector<int> two;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			two.push_back(v[i] + v[j]);
		}
	}

	sort(two.begin(), two.end());

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (binary_search(two.begin(), two.end(), v[i] - v[j])) {
				cout << v[i];
				return 0;
			}
		}
	}
}