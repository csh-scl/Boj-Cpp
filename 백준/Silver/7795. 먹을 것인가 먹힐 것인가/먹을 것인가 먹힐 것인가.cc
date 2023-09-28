#include <bits/stdc++.h>
using namespace std;


int num;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> num;
	while(num--) {
		vector<pair<int, char>> v;
		int a, b;
		int count = 0;
		int cnt = 0;
		cin >> a >> b;
		while (a--) {
			int value;
			cin >> value;
			v.push_back(make_pair(value, 'A'));
		}
		while (b--) {
			int idx;
			cin >> idx;
			v.push_back(make_pair(idx, 'B'));
		}
		sort(v.begin(), v.end());
		int length = v.size();
		for (int i = 0; i < length; i++) {
			if (v[i].second == 'A')
				count += cnt;
			else
				cnt++;
		}
		cout << count << '\n';
	}
}
