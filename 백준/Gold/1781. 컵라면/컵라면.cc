#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>> q;
vector<vector<int>> vec(200001);
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int x,y;
		cin >> x >> y;
		vec[x].push_back(y);
	}
	
	int sum = 0;
	
	for (int i = 200000; i >= 1; i--) {
		for (auto k : vec[i]) {
			q.push(k);
		}

		if (q.empty()) continue;
		int val = q.top();
		sum += val;
		q.pop();
	}
	

	cout << sum;
}