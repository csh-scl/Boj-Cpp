#include <bits/stdc++.h>
using namespace std;

long long sum;
int arr[80001];

int main(void) {
	stack<int> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		while (!s.empty() && s.top() <= arr[i]) {
			s.pop();
		}

		sum += s.size();
		s.push(arr[i]);
	}

	cout << sum;
}