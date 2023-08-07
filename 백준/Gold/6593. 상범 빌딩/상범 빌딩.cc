#include <bits/stdc++.h>
using namespace std;

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {0, 0, 0, 0, 1, -1};
int dz[6] = {1, -1, 0, 0, 0, 0};

char board[32][32][32];
int val[32][32][32];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        
        if (a == 0 && b == 0 && c == 0)
            break;

        queue<tuple<int, int, int>> q;
        bool state = false;

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                fill(val[i][j], val[i][j] + c, 0); // Initialize val with 0
            }
        }

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                string s;
                cin >> s;
                for (int k = 0; k < c; k++) {
                    board[i][j][k] = s[k];
                    if (s[k] == 'S') {
                        q.push({i, j, k});
                        val[i][j][k] = 0; // Start from 0
                    }
                }
            }
        }

        while (!q.empty()) {
            if (state) break;
            auto cur = q.front();
            int curH, curX, curY;
            q.pop();
            tie(curH, curX, curY) = cur;

            for (int dir = 0; dir < 6; dir++) {
                int nh = curH + dz[dir];
                int nx = curX + dx[dir];
                int ny = curY + dy[dir];

                if (nh < 0 || nh >= a || nx < 0 || nx >= b || ny < 0 || ny >= c)
                    continue;

                if (val[nh][nx][ny] > 0 || board[nh][nx][ny] == '#')
                    continue;

                q.push({nh, nx, ny});
                val[nh][nx][ny] = val[curH][curX][curY] + 1;

                if (board[nh][nx][ny] == 'E') {
                    cout << "Escaped in " << val[nh][nx][ny] << " minute(s).\n";
                    state = true;
                    break;
                }
            }
        }

        if (!state)
            cout << "Trapped!\n";
    }

    return 0;
}
