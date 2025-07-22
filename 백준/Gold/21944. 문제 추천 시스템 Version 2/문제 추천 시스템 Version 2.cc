#include <bits/stdc++.h>
using namespace std;

set<int> matterGL[102][102];
set<int> matterL[102];

pair<int, int> mtda[100002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    // x 문제번호, y 난이도, z 알고리즘
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        matterGL[z][y].insert(x);
        matterL[y].insert(x);
        mtda[x] = make_pair(y,z);
    }


    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (s == "add") {
            int x, y, z;
            cin >> x >> y >> z;
            matterGL[z][y].insert(x);
            matterL[y].insert(x);
            mtda[x] = make_pair(y, z);
        }
        else if (s == "recommend") {
            int x, y;
            cin >> x >> y;
            if (y == 1) {
                for (int i = 100; i > 0; i--) {
                    if (matterGL[x][i].empty()) continue;
                    else {
                        cout << *prev(matterGL[x][i].end()) << '\n';
                        break;
                    }
                }
            }
            else {
                for (int i = 1; i <= 100; i++) {
                    if (matterGL[x][i].empty()) continue;
                    else {
                        cout << *matterGL[x][i].begin() << '\n';
                        break;
                    }
                }
            }
        }
        else if (s == "recommend2") {
            int x;
            cin >> x;
            if (x == 1) {
                for (int i = 100; i > 0; i--) {
                    if (matterL[i].empty()) continue;
                    else {
                        cout << *matterL[i].rbegin() << '\n';
                        break;
                    }
                }
            }
            else {
                for (int i = 1; i <= 100; i++) {
                    if (matterL[i].empty()) continue;
                    else {
                        cout << *matterL[i].begin() << '\n';
                        break;
                    }
                }
            }
        }
        else if (s == "recommend3") {
            int x, y;
            cin >> x >> y;
            int ans = -1;
            if (x == 1) {
                for (int i = y; i <= 100; i++) {
                    if (matterL[i].empty()) continue;
                    else {
                        ans = *matterL[i].begin();
                        break;
                    }
                }
            }
            else {
                for (int i = y-1; i > 0; i--) {
                    if (matterL[i].empty()) continue;
                    else {
                        ans = *matterL[i].rbegin();
                        break;
                    }
                }
            }

            cout << ans << '\n';
        }
        else if (s == "solved") {
            int pb;
            cin >> pb;
            int level, algo;
            level = mtda[pb].first;
            algo = mtda[pb].second;

            matterL[level].erase(pb);
            matterGL[algo][level].erase(pb);
        }
    }
    
}
