#include <bits/stdc++.h>
using namespace std;

map<string, string> pw;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		string x, y;
		cin >> x >> y;
		pw[x] = y;
	}

	for (int i = 0; i < b; i++) {
		string st;
		cin >> st;
		cout << pw[st] << '\n';
	}
}