#include <bits/stdc++.h>
using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	set<int> check; // 명소가 무엇인지 판단해 주는 곳
	set<pair<int, bool>> st; // 명소 인지 아닌지 저장하는 곳

	int n, t;
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x == 1) {
			st.insert({ i, true });
			check.insert(i);
		}
		else {
			st.insert({ i, false });
		}
	}
	int pos = 1;


	while (t--) {
		int num;
		cin >> num;
		/* cout << "현재 위치는 " << pos << "입니다" << "\n"; */
		if (num == 1) {
			int x;
			cin >> x;
			// 못 찾은 경우
			if(check.find(x) == check.end()) {
				auto it = st.find({x, false});
				pair<int, bool> temp = {x, true};
				st.erase(it);
				st.insert(temp);
				check.insert(x);
			}
			// 찾은 경우
			else {
				auto it = st.find({ x, true});
				pair<int, bool> temp = { x, false};
				st.erase(it);
				st.insert(temp);
				check.erase(x);
			}
		}
		else if (num == 2) {
			int x;
			cin >> x;
			if (pos + x > n) {
				if ((pos + x) % n == 0) pos = n;
				else
					pos = (pos + x) % n;
			}
			else
				pos += x;
		}
		else {
			if (check.empty()) {
				cout << -1 << '\n';
			}
			else {
				auto it = check.lower_bound(pos);

				int diff;

				if (it != check.end()) {
					diff = *it - pos;
				}
				else {
					diff = n - pos + *check.begin();
				}
			
				cout << diff << '\n';
			}
		}
	}


	
}