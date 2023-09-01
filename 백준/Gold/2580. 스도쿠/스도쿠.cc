#include <bits/stdc++.h>
using namespace std;


int state[10][10];
bool v1[10][10];
bool v2[10][10];
bool v3[10][10];

int transfer(int x, int y) {
    return (x / 3) * 3 + (y / 3);
}

bool bfs(int k) {
    if (k == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << state[i][j] << ' ';
            }
            cout << '\n';
        }
        return true;
    }
    int nx = k / 9;
    int ny = k % 9;

    if (state[nx][ny] != 0) {
        return bfs(k + 1);
    }

    if (state[nx][ny] == 0) {
        for (int i = 1; i <= 9; i++) {
            if (!v1[nx][i] && !v2[ny][i] && !v3[transfer(nx, ny)][i]) {
                v1[nx][i] = true;
                v2[ny][i] = true;
                v3[transfer(nx, ny)][i] = true;
                state[nx][ny] = i;
                if (bfs(k + 1)) {
                    return true;
                }
                v1[nx][i] = false;
                v2[ny][i] = false;
                v3[transfer(nx, ny)][i] = false;
                state[nx][ny] = 0;
            }
        }
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> state[i][j];
            if (state[i][j] != 0) {
                v1[i][state[i][j]] = true;
                v2[j][state[i][j]] = true;
                v3[transfer(i, j)][state[i][j]] = true;
            }
        }
    }
    bfs(0);
}