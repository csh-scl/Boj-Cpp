#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
// sum[x] x번째 까지의 합
int sum[100000];
int n, m;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	vector<int> v;
	int i, j;
	v.push_back(0);
	for (int i = 1; i <= n; i++) {
		int val;
		cin >> val;
		v.push_back(val);
	}
	sum[0] = 0;
	sum[1] = v[1];

	for (int i = 2; i <= n; i++) {
		sum[i] = sum[i - 1] + v[i];
	}

	
	while (m--) {
		int st, en;
		cin >> st >> en;
		int result =  sum[en] - sum[st - 1];
		cout << result << '\n';
	}
}