#include <bits/stdc++.h>
using namespace std;

bool tmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first > b.first;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<pair<int, int>> arr;
	int x, y;
	cin >> x >> y;
	for (int i = 0; i < x; i++) {
		int a;
		cin >> a;
		bool check = false;;
		for (auto& k : arr) {
			if (k.second == a) {
				check = true;
				k.first++;
				break;
			}
		}
		if (!check) arr.push_back({ 1,a });
	}

	stable_sort(arr.begin(), arr.end(), tmp);
	for (auto b : arr) {
		while (b.first--) cout << b.second << ' ';
	}
}
