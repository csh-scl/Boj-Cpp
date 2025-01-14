#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
string s[105];
bool m[105][105];

int wcnt;
int bcnt;

int main() {
	int x, y;
	cin >> y >> x;
	// y 가로,  x 세로
	for (int i = 0; i < x; i++) {
		cin >> s[i];
	}
	// 입력 처리
	queue<pair<int,int>> b;
	queue<pair<int, int>> w;
	// x 세로, y 가로
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (s[i][j] == 'W' && m[i][j] == 0) {
				int cnt = 1;
				w.push({ i,j });
				m[i][j] = true;
				while (!w.empty()) {
					auto cur = w.front(); w.pop();
					for (int i = 0; i < 4; i++) {
						int nx = cur.first + dx[i];
						int ny = cur.second + dy[i];
						if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
						if (m[nx][ny] == 0 && s[nx][ny] == 'W') {
							w.push({ nx,ny });
							m[nx][ny] = true;
							cnt++;
						}
					}
				}
				wcnt += cnt * cnt;
			}

			if (s[i][j] == 'B' && m[i][j] == 0) {
				int cnt = 1;
				b.push({ i,j });
				m[i][j] = true;
				while (!b.empty()) {
					auto cur = b.front(); b.pop();
					for (int i = 0; i < 4; i++) {
						int nx = cur.first + dx[i];
						int ny = cur.second + dy[i];
						if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
						if (m[nx][ny] == 0 && s[nx][ny] == 'B') {
							b.push({ nx,ny });
							m[nx][ny] = true;
							cnt++;
						}
					}
				}
				bcnt += cnt * cnt;
			}
		}
	}

	cout << wcnt << ' ' << bcnt;

}
