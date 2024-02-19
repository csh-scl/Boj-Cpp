#include <bits/stdc++.h>
using namespace std;



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int tt;
	cin >> tt;

	for (int i = 0; i < tt; i++) {
		int no, ed;
		cin >> no >> ed;
		vector<int> grp[20002];
		int vis[20002];
		queue<int> q;
		fill(vis, vis + 20002, -1);
		
		bool isTrue = true;

		for (int i = 0; i < ed; i++) {
			int x, y;
			cin >> x >> y;
			grp[x].push_back(y);
			grp[y].push_back(x);
		}

		for (int i = 1; i < no; i++) {
			if (vis[i] == -1) {
				q.push(i);
				vis[i] = 1;
				while (!q.empty()) {
					int cur = q.front();
					q.pop();
					for (auto k : grp[cur]) {
						if (vis[k] == -1) {
							q.push(k);
							if (vis[cur] == 1) {
								vis[k] = 0;
							}
							else {
								vis[k] = 1;
							}
						}
						else {
							if (vis[k] == vis[cur]) {
								cout << "NO" << '\n';
								isTrue = false;
								break;
							}
						}
					}
					if (!isTrue) {
						break;
					}
				}
				if (!isTrue) {
					break;
				}
			}
		}
		if (isTrue) {
			cout << "YES" << '\n';
		}
	}
}