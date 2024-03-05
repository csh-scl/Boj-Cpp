#include <bits/stdc++.h>
using namespace std;

vector<int> child[100005];

int sz;
int cutEdge;
int parent[100005];
bool visited[100005];

void bfs(int start) {

    queue<int> q;

    visited[start] = true;
    parent[start] = -1;

    q.push(start);
    while (!q.empty()) {

        int cur = q.front();
        q.pop();

        for (auto nxt : child[cur]) {
            if (!visited[nxt]) {
                visited[nxt] = true;
                q.push(nxt);
                cutEdge++;
            }
        }
    }
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        child[a].push_back(b);
        child[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bfs(i);
            sz++;
        }
    }
    // cout << sz << '\n' << k - cutEdge << '\n';
    cout << sz - 1 + k - cutEdge;
}
