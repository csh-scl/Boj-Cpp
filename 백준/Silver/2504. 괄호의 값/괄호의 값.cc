#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	stack<char> q;
	string s;
	cin >> s;
	int sum = 0;
	int val = 1;
	for(int i = 0; i<s.size(); i++){
		if (s[i] == '(') {
			val *= 2;
			q.push(s[i]);
		}
		else if (s[i] == '[') {
			val *= 3;
			q.push(s[i]);
		}
		else {
			if (s[i] == ')') {
				if (q.empty() || q.top() == '[') {
					cout << 0;
					return 0;
				}
				if (s[i-1] == '(') sum += val;
				q.pop();
				val /= 2;	
			}
			if (s[i] == ']') {
				if (q.empty() || q.top() == '(') {
					cout << 0;
					return 0;
				}
				if (s[i-1] == '[') sum += val;
				q.pop();
				val /= 3;	
			}
		}
	}
	if (q.empty()) cout << sum;
	else
		cout << 0;
}