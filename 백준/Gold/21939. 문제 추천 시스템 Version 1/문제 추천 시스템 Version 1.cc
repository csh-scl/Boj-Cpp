#include <bits/stdc++.h>
using namespace std;

// 문제번호 / 난이도 입력

// 너님이 해야 할 짓거리 delete 부분 구현을 해야한다.
// L, P {난이도 / 문제 번호} 순으로 구현했는데 문제 번호만 딱 주는 경우 머리가 비어 버린다....


set<int> q[100002];

// 난이도 저장
set<int> ans;

// 문제번호 / 난이도
int qnum[100002];

void rec(int x) {
	if (x == 1) {
		int max = *prev(ans.end());
		cout << *prev(q[max].end()) << '\n';
	}
	else {
		int min = *(ans.begin());
		cout << *(q[min].begin()) << '\n';
	}
}

void find(int x) {
	int diff = qnum[x];
	if (q[diff].find(x) != q[diff].end()) {
		q[diff].erase(q[diff].find(x));
		if (q[diff].size() == 0) {
			ans.erase(diff);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		q[y].insert(x);
		qnum[x] = y;
		ans.insert(y);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (s == "add") {
			int x, y;
			cin >> x >> y;
			q[y].insert(x);
			qnum[x] = y;
			ans.insert(y);
		}
		else if (s == "recommend") {
			int x;
			cin >> x;
			rec(x);
		}
		else {
			int x;
			cin >> x;
			find(x);
		}
	}
}