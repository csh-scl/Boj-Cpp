#include <bits/stdc++.h>
using namespace std;

queue<int> q;
stack<int> st;

void pos() {
	while (!st.empty()) {
		if (st.top() == q.size()) {
			q.push(st.top());
			st.pop();
			continue;
		}
		return;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> num;
	q.push(1);
	while (num--) {
		int target = q.size();
		int number;
		cin >> number;
		if (number == target) {
			q.push(number);
			pos();
			continue;
		}
		st.push(number);
		
	}
	if (st.empty() == true) {
		cout << "Nice";
	}
	else
		cout << "Sad";
	
	
}
