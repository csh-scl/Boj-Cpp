#include <bits/stdc++.h>
using namespace std;

int dist[1002][1002];
int jdist[1002][1002];
string s[1002];
bool vis[1002][1002];
bool jvis[1002][1002];
int n,m;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m; // n : 높이 m >> 밑변

    for(int i =0; i<n; i++) {
        cin >> s[i];
    }

    queue<pair<int,int>> q; // 지훈
    queue<pair<int,int>> fr; // 불

    for(int i = 0; i<n; i++) {
        for(int j =0; j<m; j++) {
            if(s[i][j] == 'J') {
                q.push({i,j});
                jvis[i][j] = true;
            } else if(s[i][j] == 'F') {
                fr.push({i,j});
                vis[i][j] = true;
            } else if(s[i][j] == '#') {
                vis[i][j] = true;
                jvis[i][j] = true;
            } else {

            }
        }
    }

    while(!fr.empty()) {
        auto cur = fr.front(); fr.pop();
        for(int i =0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if(nx < 0 || nx >= n  || ny <0 || ny>=m) continue;
            if(s[nx][ny] == '#' || s[nx][ny] == 'J') continue;
            if(s[nx][ny] == '.' && vis[nx][ny] == 0) {
                fr.push({nx, ny});
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                vis[nx][ny] = true;
            }
        }
    }

    // for(int i =0; i<n; i++) {
    //     for(int j =0; j<m; j++) {
    //         cout << dist[i][j];
    //     }
    //     cout << '\n';
    // }

    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int i =0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            // 문제 코드
            if(nx < 0 || nx >= n  || ny <0 || ny>=m) {
                cout << jdist[cur.first][cur.second] + 1;
                return 0;
            }

            if(s[nx][ny] == '#' || s[nx][ny] == 'F') continue;
            if(jdist[cur.first][cur.second] + 1 >= dist[nx][ny] && dist[nx][ny] != 0) continue;

            if(s[nx][ny] == '.' && jvis[nx][ny] == 0) {
                q.push({nx, ny});
                jdist[nx][ny] = jdist[cur.first][cur.second] + 1;
                jvis[nx][ny] = true;
            }
        }
    }
    // cout << '\n' << '\n';
    // for(int i =0; i<n; i++) {
    //     for(int j =0; j<m; j++) {
    //         cout << jdist[i][j];
    //     }
    //     cout << '\n';
    // }
    cout << "IMPOSSIBLE";
}
