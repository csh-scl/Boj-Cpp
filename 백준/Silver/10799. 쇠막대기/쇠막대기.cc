#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	stack <char> st;
	string s;
	cin >> s;
	int count = 0;
	for(int i = 0; i<s.size(); i++) {
		if (s[i] == '(') {
			st.push(s[i]);
		}
		else if (s[i] == ')' && s[i-1] == '(') {
			st.pop();
			count += st.size();
		}
		else {
			st.pop();
			count++;
		}
	}
	cout << count;
}
