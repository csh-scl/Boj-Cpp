#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int number;
	cin >> number;
	int count = 0;
	while (number--) {
		string s;
		cin >> s;
		stack <char> st;
		for(auto k : s){
			if (st.empty()) {
				st.push(k);
			}
			else {
				if (st.top() == k) {
					st.pop();
				}
				else {
					st.push(k);
				}
			}
		}
		if (st.empty()) count++;
	}
	cout << count;
}