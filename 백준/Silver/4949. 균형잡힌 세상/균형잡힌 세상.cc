#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while (true) {
		bool isVaild = true;
		stack <char> stacks;
		string s;
		getline(cin, s);
		if (s == ".") break;
		for (auto k : s) {
			if (k == '[' || k == '(') {
				stacks.push(k);
			}
			else if (k == ']') {
				if (!(stacks.empty()) && stacks.top() == '[') {
					stacks.pop();
				}
				else {
					isVaild = false;
					break;
				}
			}
			else if (k == ')') {
				if (!(stacks.empty()) && stacks.top() == '(')
					stacks.pop();
				else {
					isVaild = false;
					break;
				}
			}
		}

		if (!stacks.empty()) {
			isVaild = false;
		}
		if (isVaild == false) {
			cout << "no" << "\n";
		}
		else {
			cout << "yes" << "\n";
		}
	}
}