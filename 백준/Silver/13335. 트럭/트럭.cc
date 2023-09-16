#include <bits/stdc++.h>
using namespace std;


int n, w, l;

queue<int> q;

int ans = 0;
int bridge[101];


bool isempty() {
	for (int i = 0; i < w; i++) {
		if (bridge[i] != 0) return false;
	}
	return true;
}

int calculate() {
	int sum = 0;
	for (int i = 0; i < w; i++) {
		sum += bridge[i];
	}
	return sum;
}

void go() {
	for (int i = w-1; i > 0; i--) {
		bridge[i] = bridge[i - 1];
	}
	bridge[0] = 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> w >> l;
	while (n--) {
		int i;
		cin >> i;
		q.push(i);
	}

	do {
		int num = calculate();
		if (num <= l) {
			num -= bridge[w - 1];
			go();
			

			if (!q.empty() && (num + q.front() <= l)) {
				bridge[0] = q.front();
				q.pop();
			}
		}
		ans++;
	} while (!isempty());

	cout << ans;
}
