#include <bits/stdc++.h>
using namespace std;

stack <int> st;
int num;
int value;

void push(int k) {
	st.push(k);
	return;
}

void print() {
	if (st.size() != 0) {
		cout << st.top() << '\n';
		st.pop();
	}
	else
		cout << -1 << '\n';
}

void count() {
	cout << st.size() << '\n';
}

void empty() {
	if (st.size() == 0) {
		cout << 1 << '\n';
	}
	else
		cout << 0 << '\n';
}

void print2() {
	if (!st.empty()) {
		cout << st.top() << '\n';
	}
	else {
		cout << -1 << '\n';
	}
}

void determine(int index) {
	switch (index) {
	case 2:
		print();
		break;
	case 3:
		count();
		break;
	case 4:
		empty();
		break;
	case 5:
		print2();
		break;
	default:
			return;
	}
}

void start() {
	for (int i = 0; i < num; i++) {
		int index;
		cin >> index;
		if (index == 1) {
			cin >> value;
			push(value);
		}
		else {
			determine(index);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> num;
	start();
}
