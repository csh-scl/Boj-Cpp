#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
int n;

bool compare(pair<int, int> a, pair<int, int> b) {
	if(a.first != b.first)
		return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	stable_sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) cout << v[i].first << " " << v[i].second << '\n';
}
