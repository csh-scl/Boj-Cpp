#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string s[105];
bool m[105][105];

int wcnt;
int bcnt;
int x, y;

// BFS 함수: 시작 좌표 (sx, sy)와 목표 문자 target을 인자로 받음
int bfs(int sx, int sy, char target) {
    queue<pair<int, int>> q;
    q.push({ sx, sy });
    m[sx][sy] = true;
    int cnt = 1;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = cur.first + dx[d];
            int ny = cur.second + dy[d];
            if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
            if (!m[nx][ny] && s[nx][ny] == target) {
                q.push({ nx, ny });
                m[nx][ny] = true;
                cnt++;
            }
        }
    }
    return cnt * cnt; // 크기의 제곱 반환
}

int main() {
    
    cin >> y >> x; // y: 가로, x: 세로
    for (int i = 0; i < x; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (s[i][j] == 'W' && !m[i][j]) {
                wcnt += bfs(i, j, 'W');
            }
            else if (s[i][j] == 'B' && !m[i][j]) {
                bcnt += bfs(i, j, 'B');
            }
        }
    }

    cout << wcnt << ' ' << bcnt;
    return 0;
}
