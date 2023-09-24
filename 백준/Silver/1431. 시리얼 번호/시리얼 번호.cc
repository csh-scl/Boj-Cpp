#include <bits/stdc++.h>
using namespace std;

int n;

bool compare(string &a, string &b) {
	int asize = a.length();
	int bsize = b.length();
	int anum = 0;
	int bnum = 0;
	if (a.length() != b.length()) return a.length() < b.length();
	
	else {
		for (int i = 0; i < asize; i++) {
			if (isdigit(a[i])) anum += (a[i] - '0');
		}
		for (int i = 0; i < bsize; i++) {
			if (isdigit(b[i])) bnum += (b[i]-'0');
		}
		if (anum == bnum) return a < b;
		return anum < bnum;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << v[i] << '\n';
	}
}
