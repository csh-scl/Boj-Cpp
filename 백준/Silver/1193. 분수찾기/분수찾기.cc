#include <bits/stdc++.h>
using namespace std;

int findindex(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
		if (sum >= n) {
			return i;
		}
	}
}

int main(void) {
	int n;
	cin >> n;
	int low = findindex(n);
	
	int sum = 1;
	for (int i = 1; i < low; i++) {
		sum += i;
	}

	if (low % 2 != 0) {
		int a = low;
		int b = 1;
		for (int i = sum; i < n; i++) {
			a--, b++;
		}
		cout << a << '/' << b;
	}
	else {
		int a = 1;
		int b = low;
		for (int i = sum; i < n; i++) {
			a++, b--;
		}
		cout << a << '/' << b;
	}

}