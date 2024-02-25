#include <bits/stdc++.h>
using namespace std;

int l[30];
int r[30];

void v1(int k) {
	cout << char(k + 'A' - 1);
	if(l[k] != 0) v1(l[k]);
	if(r[k] != 0) v1(r[k]);
}


void v2(int k) {
	if (l[k] != 0) v2(l[k]);
	cout << char(k + 'A' - 1);
	if (r[k] != 0) v2(r[k]);
}

void v3(int k) {
	if (l[k] != 0) v3(l[k]);
	if (r[k] != 0) v3(r[k]);
	cout << char(k + 'A' - 1);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	char x, y, z;

	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		if (y != '.') l[x - 'A' + 1] = y - 'A' + 1;
		if (z != '.') r[x - 'A' + 1] = z - 'A' + 1;
	}

	v1(1);
	cout << '\n';
	v2(1);
	cout << '\n';
	v3(1);
}


