#include <bits/stdc++.h>
using namespace std;

int bfs[1005][1005];
bool vis[1005][1005];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int x, y;

int main() {
    queue<pair<int, int>> q;
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int value;
            cin >> value;
            if (value == 1) {
                vis[i][j] = false;
            }
            else if (value == 2) {
                x = i;
                y = j;
                vis[i][j] = true;
            }
            else {
                vis[i][j] = true;
            }
        }
    }

    q.push({ x,y });
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int curX = cur.first;
        int curY = cur.second;
        for (int i = 0; i < 4; i++) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if (nextY < 1 || nextX < 1 || nextX > n || nextY > m) continue;
            if (vis[nextX][nextY]) continue;
            q.push({ nextX, nextY });
            bfs[nextX][nextY] = bfs[curX][curY] + 1;
            vis[nextX][nextY] = true;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j]) {
                cout << -1 << ' ';
                continue;
            }
            else {
                cout << bfs[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}