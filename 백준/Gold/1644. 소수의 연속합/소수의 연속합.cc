#include <bits/stdc++.h>
using namespace std;

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	if (n == 1) cout << 0;
	else {
		vector<int> prime(n + 1, false);
		prime[0] = true;
		prime[1] = true;
		for (int i = 2; i * i <= n; i++) {
			for (int j = i * i; j <= n; j += i) {
				prime[j] = true;
			}
		}

		vector<int> result;
		for (int i = 2; i <= n; i++) {
			if (prime[i]) continue;
			result.push_back(i);
		}

		//for (auto k : result) cout << k << ' ';
		int sz = result.size();
		int count = 0;
		int en = 0;
		int sum = result[0];

		for (int i = 0; i < sz; i++) {
			while (en < sz && sum < n) {
				en++;
				if (en != sz) sum += result[en];
			}
			if (en == sz) break;
			if (sum == n) count++;
			sum -= result[i];
		}

		cout << count;
	}
}