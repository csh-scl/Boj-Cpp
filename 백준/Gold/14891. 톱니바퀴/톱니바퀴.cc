#include <bits/stdc++.h>
//#include <iostream> // <iostream> 추가
using namespace std;

string s[4];

void nonclock(int target) {
	char temp = s[target][0];
	for (int i = 0; i < 7; i++) {
		s[target][i] = s[target][i+1];
	}
	s[target][7] = temp;
}

void getclock(int target) {
	char temp = s[target][7];
	for (int i = 7; i > 0 ; i--) {
		s[target][i] = s[target][i-1];
	}
	s[target][0] = temp;
}



// 핵심은 각각이 회전을 하는 지 안하는 지가 중요하다 상태는 -1,1,0 방향 
void bfs(int x, int dir) {
	int dirs[4] = {};
	dirs[x] = dir;
	int idx = x;
	while (idx > 0 && s[idx][6] != s[idx - 1][2]) {
		dirs[idx - 1] = -dirs[idx];
		idx--;
	}

	idx = x;

	while (idx < 3 && s[idx][2] != s[idx + 1][6]) {
		dirs[idx + 1] = -dirs[idx];
		idx++;
	}

	for (int i = 0; i < 4; i++) {
		if (dirs[i] == -1) {
			nonclock(i);
		}
		else if (dirs[i] == 1) {
			getclock(i);
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 4; i++) cin >> s[i];

	int num;
	cin >> num;
	while (num--) {
		int number, dir;
		cin >> number >> dir;
		bfs(number - 1, dir);
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (s[i][0] == '1') {
			ans += (1 << i);
		}
	}
	cout << ans;
}