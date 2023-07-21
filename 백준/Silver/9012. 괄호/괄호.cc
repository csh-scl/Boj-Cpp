#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int number;
	cin >> number;
	cin.ignore();
	int count = 0;
	while (number--) {
		bool state = true;
		string s;
		getline(cin, s);
		stack <char> st;
		for (auto k : s) {
			if (k == '(') {
				st.push(k);
			}
			else if (k == ')') {
				if (!st.empty() && st.top() == '(') {
					st.pop();
				}
				else {
					state = false;
					break;
				}
			}
		}
		if (!st.empty()) state = false;
		if (state == true) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
}
