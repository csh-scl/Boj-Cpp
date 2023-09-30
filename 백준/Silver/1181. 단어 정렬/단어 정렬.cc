#include <bits/stdc++.h>
using namespace std;



bool comp(string a, string b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	return a < b;
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> num;
	vector<string> s(num);
	for (int i = 0; i < num; i++) {
		cin >> s[i];
	}
	
	sort(s.begin(), s.begin()+ num, comp);
	s.erase(unique(s.begin(), s.end()), s.end());


	for (auto k : s) {
		cout << k << '\n';
	}
}
