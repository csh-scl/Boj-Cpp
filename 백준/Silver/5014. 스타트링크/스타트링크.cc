#include <bits/stdc++.h>
using namespace std;

// a,b,c,d,e  a가 총 개수 b가 시작층 c가 도착층 d 위로 올라가는 개수 e 가 내려오는 개수
// 종료조건은 현재상태가 c가 되면 되겠다 그전까지는 bfs를 돌리는데 최고 가서 u 터지리고 지하 뚤어도 터트리고 
int tower[1000002];
bool val[1000002];

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	queue<int> q;
	q.push(b);
	val[b] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto k : { d, -e }) {
			if (cur + k > a || cur + k <= 0 || val[cur + k] == 1) continue;
			tower[cur + k] = tower[cur] + 1;
			val[cur + k] = true;
			q.push(cur + k);
		}
	}
	if (val[c] != 0) cout << tower[c];
	else cout << "use the stairs";
}