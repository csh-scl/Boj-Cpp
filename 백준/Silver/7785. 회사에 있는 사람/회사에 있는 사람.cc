#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

unordered_set<string> s;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		string x,y;
		cin >> x >> y;

		if (y == "enter") {
			s.insert(x);
		}
		else {
			s.erase(x);
		}
	}

	vector<string> ans(s.begin(), s.end());
	sort(ans.begin(), ans.end(), greater<string>());
		
	for (auto x : ans) cout << x << '\n';
}