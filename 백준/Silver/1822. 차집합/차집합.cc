#include <bits/stdc++.h>
using namespace std;



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	set<int> st;

	vector<int> ans;
	int x, y;
	cin >> x >> y;
	for (int i = 0; i < x; i++) {
		int num;
		cin >> num;
		if (st.find(num) == st.end()) {
			st.insert(num);
		}
	}

	for (int i = 0; i < y; i++) {
		int num2;
		cin >> num2;
		if (st.find(num2) != st.end()) {
			st.erase(st.find(num2));
		}
	}
	cout << st.size() << '\n';
	for (auto k : st) {
		cout << k << ' ';
	}
}


