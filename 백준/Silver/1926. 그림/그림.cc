#include <bits/stdc++.h>
using namespace std;


int board[502][502];
bool vis[502][502];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int n, m;

queue<pair<int, int>> q;

int bfs(int x, int y) {
    int count = 1;
    q.push({ x,y });
    vis[x][y] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] == 1 || board[nx][ny] != 1) continue;
            q.push({ nx,ny });
            count++;
            vis[nx][ny] = 1;
        }
    }
    return count;
}

int main() {
    int max_cnt = 0;
    int value = 0;
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] != 1 && board[i][j] == 1) {
                value++;
                max_cnt = max(max_cnt,bfs(i, j));
            }
        }
    }

    cout << value << '\n' << max_cnt;
    
    

}