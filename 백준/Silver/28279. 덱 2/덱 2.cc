#include <bits/stdc++.h>
using namespace std;

deque<int> dex;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> num;
	int count;
	for (int i = 0; i < num; i++) {
		cin >> count;
		if (count == 1) {
			int index;
			cin >> index;
			dex.push_front(index);
		}
		else if (count == 2) {
			int index;
			cin >> index;
			dex.push_back(index);
		}
		else if (count == 3) {
			if (dex.size() == 0) cout << -1 << '\n';
			else {
				cout << dex.front() << '\n';
				dex.pop_front();
			}
		}
		else if (count == 4) {
			if (dex.size() == 0) cout << -1 << '\n';
			else {
				cout << dex.back() << '\n';
				dex.pop_back();
			}
		}
		else if (count == 5) {
			cout << dex.size() << '\n';
		}
		else if (count == 6) {
			if (dex.empty()) cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (count == 7) {
			if (dex.empty()) cout << -1 << '\n';
			else
				cout << dex.front() << '\n';
		}
		else {
			if (dex.empty()) cout << -1 << '\n';
			else
				cout << dex.back() << '\n';
		}
	}
}
