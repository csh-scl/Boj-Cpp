#include <bits/stdc++.h>
using namespace std;

int n, m;
int length;
int state[51][51];
int arr[14];
int board[51][51];
vector<pair<int, int>> arr1;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int maxium = 999999;
int bfs() {
    queue < pair<int, int>> q;
    for (int i = 0; i < m; i++) {
        pair<int, int> cur = arr1[arr[i]];
        q.push({ cur.first, cur.second});
        board[cur.first][cur.second] = 0;
    }
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[nx][ny] != -1) continue;
            board[nx][ny] = board[cur.first][cur.second] + 1;
            q.push({nx,ny});
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (state[i][j] == 1) {
                count += board[i][j];
            }
        }
    }
    return count;
}

void select(int k) {
    if (k == m) {
        int copy[51][51];
        for (int i = 0; i < n; i++) fill(board[i], board[i] + n, -1);
        // arr 저장확인 숫자 잘 넘어갔음 cout << arr[0] << ' ' << arr[1] << '\n';
        memcpy(copy, board, sizeof(board));
        // 될 때 마다 배열에는 가능한 리스트 목록들이 발생하겠네 그럼 다시 재귀적으로 함수를 호출하자
        int count = bfs();
        if (maxium > count) maxium = count;
        memcpy(board, copy, sizeof(board));
        return;
    }

    int sz = 0;
    if (k != 0) sz = arr[k - 1] + 1;
    for (int i = sz; i < length; i++) {
        arr[k] = i;
        select(k + 1);
    }

}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> state[i][j];
            if (state[i][j] == 2) {
                arr1.push_back({ i,j });
            }
        }
    }
    length = arr1.size();
    select(0);
    cout << maxium;

}
