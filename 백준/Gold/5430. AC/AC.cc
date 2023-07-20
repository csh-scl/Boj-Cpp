#include <bits/stdc++.h>
using namespace std;

void push_deque(deque<int> &q, string&tmp){
	string k = "";
	for (auto c : tmp) {
		if (c == ',' || c==']') {
			if (!k.empty()) {
				q.push_back(stoi(k));
				k = "";
			}
		}
		else {
			if ((c == '[')) continue;
			k += c;
		}
	}
}

void print(deque<int>& q, bool state) {
	if (state == true) {
		cout << '[';
		int index = q.size();
		for (int i = 0; i < index; i++) {
			cout << q[i];
			if (index - 1 == i) break;
			cout << ',';
		}
		cout << ']' << "\n";
	}
	else {
		cout << '[';
		int index = q.size();
		for (int i = index-1; i>=0; i--) {
			cout << q[i];
			if (i == 0) break;
			cout << ',';
		}
		cout << ']' << "\n";
	}
}

int main(void) {
	deque<int> q;
	bool state = false;
	int number;
	cin >> number;
	while (number--) {
		deque<int> q;
		bool state = true;
		bool isWrong = false;
		string s,a;
		cin >> s;
		int n;
		cin >> n;
		cin >> a;
		push_deque(q, a);
		
		for (auto fuc : s) {
			if (q.empty()) {
				if (fuc == 'D') {
					isWrong = true;
					break;
				}
			}
			else {
				if (fuc == 'R') {
					state = !state;
				}
				if (fuc == 'D') {
					if (state == true) {
						q.pop_front();
					}
					else {
						q.pop_back();
					}
				}
			}
		}
		if (!isWrong) {
			print(q, state);
		}
		else {
			cout << "error" << "\n";
		}
	}
}
