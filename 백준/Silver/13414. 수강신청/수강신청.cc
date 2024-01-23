#include <bits/stdc++.h>
using namespace std;

map<string, int> ap;

typedef pair<string, int> ll;


bool comp(ll a, ll b) {
	return a.second < b.second;
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cap, tar;
	cin >> tar >> cap;


	for (int i = 0; i < cap; i++) {
		string s;
		cin >> s;
		if (ap.find(s) == ap.end()) {
			ap[s] = i;
		}
		else {
			ap.erase(s);
			ap[s] = i;
		}
	}
	

	vector<ll> iter(ap.begin(), ap.end());
	sort(iter.begin(), iter.end(), comp);
	
	int size = iter.size();

	for (int i = 0; i < min(tar,size); i++) {
		// cout << iter[i].first << ' ' << iter[i].second << '\n';
		cout << iter[i].first << '\n';
	}
}