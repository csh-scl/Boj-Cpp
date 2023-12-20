#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	else {
		return gcd(y, x % y);
	}
}

int main(void) {
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		vector<int> v(x);
		long long gcdsum = 0;
		for (int i = 0; i < x; i++) {
			cin >> v[i];
		}

		for (int i = 0; i < v.size() - 1; i++) {
			int st = i;
			int it = i+1;
			while (it <= v.size() - 1) {
				int value = gcd(v[st], v[it]);
				//cout << value << '\n';
				gcdsum += value;
				it++;
			}
		}
		cout << gcdsum << '\n';
	}
}