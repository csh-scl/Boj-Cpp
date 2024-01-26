	#include <bits/stdc++.h>
	using namespace std;



	int main(void) {
		ios::sync_with_stdio(0);
		cin.tie(0);

		int total;
		cin >> total;

		while (total--) {
			int x;
			cin >> x;
			map<string, int> pw;
			for (int i = 0; i < x; i++) {
				string e, k;
				cin >> e >> k;
				if (pw.find(k) == pw.end()) {
					pw[k] = 1;
				}
				else {
					pw[k]++;
				}
			}
			int ans = 1;
			vector<pair<string, int>> v(pw.begin(), pw.end());
			for (auto k : v) {
				ans *= (k.second + 1);
			}
			cout << ans - 1 << '\n';
		}
	
	}