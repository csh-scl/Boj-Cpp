#include <bits/stdc++.h>
using namespace std;

// 순전한 입력
int board[102][102];

// 마킹 
int dist[102][102];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n;

queue<pair<int, int>> q;
vector<pair<int, int>> ll;
void bfs(int x, int y, int cnt) {
    
    dist[x][y] = cnt;
    q.push({ x,y });

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        bool edge = false;
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[nx][ny] == 0) {
                edge = true;
                continue;
            }
            if (dist[nx][ny] > 0) continue;
            dist[nx][ny] = cnt;
            q.push({ nx,ny });
        }

        if (edge) ll.push_back({ cur.first,cur.second });
;   }
}


int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1 && dist[i][j] == 0) {
                bfs(i, j, cnt);
                cnt++;
            }
        }
    }

    int minds = 1000000;

    for (int i = 0; i < ll.size() - 1; i++) {
        int nx = ll[i].first;
        int ny = ll[i].second;
        for (int j = i + 1; j < ll.size(); j++) {
            int n2x = ll[j].first;
            int n2y = ll[j].second;
            if (dist[n2x][n2y] != dist[nx][ny]) {
                int val = abs(nx - n2x) + abs(ny - n2y) - 1;
               
                minds = min(minds, val);
            }
        }
    }

    cout << minds;
}
