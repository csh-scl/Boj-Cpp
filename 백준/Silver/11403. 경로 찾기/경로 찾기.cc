#include <bits/stdc++.h>
using namespace std;

int arr[100][100];
vector<int> st[100];

bool vis[100];
int node;
void arrprint() {
    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

void bfs(queue<int> q, int node) {
    for (int i = 0; i < node; i++) {
        fill(vis, vis + node + 1, 0);
        q.push(i);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto nxt : st[cur]) {
                if (vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
                arr[i][nxt] = 1;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> node;

    // N^2 으로 간선 정보 저장
    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                st[i].push_back(j);
            }
        }
    }

    // 노드 순회하기
    queue<int> q;
    
    bfs(q, node);
    arrprint();
}   