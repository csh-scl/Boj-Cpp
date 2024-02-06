#include <bits/stdc++.h>
using namespace std;

bool oper(char c) {
	if (c == 'D') {
		return false;
	}
	else {
		return true;
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		multiset<int> st;
		int cnt;
		cin >> cnt;
		for (int i = 0; i < cnt; i++) {
			char c;
			int v;
			cin >> c >> v;
			if (oper(c)) {
				st.insert(v);
			}
			else {
				if (v == 1) {
					if (st.size()) {
						st.erase(--st.end());
					}
				}
				else {
					if (st.size()) {
						st.erase(st.begin());
					}
				}
			}
		}
		if (st.size() == 0) {
			cout << "EMPTY" << '\n';
		}
		else {
			cout << *--(st.end()) << ' ' << *st.begin() << '\n';
		}
	}
}


