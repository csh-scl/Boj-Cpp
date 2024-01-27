	#include <bits/stdc++.h>
	using namespace std;

	


	int main(void) {
		ios::sync_with_stdio(0);
		cin.tie(0);
		map<string, string> mem; // 팀원이름, 그룹
		map<string, vector<string>> grp; // 그룹, 팀원

		int x, y;
		cin >> x >> y;
		for (int i = 0; i < x; i++) {
			string grname;
			int cnt;
			cin >> grname >> cnt;
			for (int j = 0; j < cnt; j++) {
				string memname;
				cin >> memname;
				mem[memname] = grname;
				grp[grname].push_back(memname);
			}
			sort(grp[grname].begin(), grp[grname].end());
		}

		


		for (int i = 0; i < y; i++) {
			string st;
			int no;
			cin >> st >> no;
			if (no == 1) {
				cout << mem[st] << '\n';
			}
			else {
				for (auto k : grp[st]) {
					cout << k << '\n';
				}
			}
		}
	}