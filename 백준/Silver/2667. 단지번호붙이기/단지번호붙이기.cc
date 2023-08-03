#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int val[27][27];
int board[27][27];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < num; j++) {
			board[i][j] = s[j];
			if (board[i][j] == '1') {
				val[i][j] = 1;
			}
		}
	}

	vector<int> vs;
	queue<pair<int, int>> q;
	int count = 0;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (val[i][j] == 1) {
				count++;
				int index = 1;
				q.push({ i,j });
				val[i][j] = 0;
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= num || ny < 0 || ny >= num) continue;
						if (val[nx][ny] != 1) continue;
						q.push({ nx,ny });
						val[nx][ny] = 0;
						index++;
					}
				}
				vs.push_back(index);
			}
		}
	}
	cout << count << '\n';

	sort(vs.begin(), vs.end());

	for (auto k : vs) {
		cout << k << '\n';
	}
}