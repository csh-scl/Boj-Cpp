#include <bits/stdc++.h>
using namespace std;

#define X first 
#define Y second

int arr[102][102];
bool state[102][102];
int val[102][102];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0'; // s[j]는 문자이므로 - '0'을 해서 숫자로 바꾸어 준다. + '0'은 숫자를 문자로 바꾸어줌 꿀팁
		}
	}

	
	// 원점을 기준으로 뺑뻉이 돌리기
			queue<pair<int, int>> q;
			q.push({0,0});
			state[0][0] = 1;
			val[0][0] = 1;
			
			while (!q.empty()) {
				pair<int, int> cur = q.front();
				q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (arr[nx][ny] != 1 || state[nx][ny]) continue;
					q.push({ nx,ny });
					state[nx][ny] = 1;
					val[nx][ny] = val[cur.X][cur.Y] + 1;
				}
			}
			cout << val[n - 1][m - 1];
}
