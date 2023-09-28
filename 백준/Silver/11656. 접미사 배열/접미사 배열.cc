#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<string> v;
	string s;
	cin >> s;
	int size = s.length();
	for (int i = 0; i < size; i++) {
		v.push_back(s.substr(i, size));
	}
	sort(v.begin(), v.end());
	for (auto k : v) cout << k << '\n';
}
