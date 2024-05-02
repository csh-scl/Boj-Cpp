#include <bits/stdc++.h>
using namespace std;

multiset<int> st;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	n--;
	
	int x;
	cin >> x;
	st.insert(x);
	auto cur = st.begin();
	cout << *cur << '\n';

	while (n--) {
		int val;
		cin >> val;
		st.insert(val);
		if (st.size() % 2 == 0 && val >= *cur) {
			cout << *cur << '\n';
		}
		else if (st.size() % 2 == 0 && val < *cur) {
			cur--;
			cout << *cur << '\n';
		}
		else if (st.size() % 2 == 1 && val < *cur) {
			cout << *cur << '\n';
		}
		else {
			cur++;
			cout << *cur << '\n';
		}

	}
	
}