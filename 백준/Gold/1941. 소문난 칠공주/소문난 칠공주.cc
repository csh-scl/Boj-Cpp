#include <bits/stdc++.h>
using namespace std;
// 해결해야 할 문제 1. 25 중복포함하지 않고 7명 고르기 (성공) 2. 인접한 자리인지 확인(실패)
// 3. BFS 돌리면서 확인하기(성공)
int counter = 0;
char pos[5][5];
int arr[7];

int val[5][5];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs() {
	for (int i = 0; i < 5; i++) {
		fill(val[i], val[i] + 5, 0);
	}

	int num = 0;

	queue<pair<int, int>> q;

	int lee = 0; // S
	int da = 0; // Y
	/*if (arr[0] == 5 && arr[1] == 6 && arr[2] == 7 && arr[3] == 8 && arr[4]) {
		for (int i = 0; i < 7; i++) cout << arr[i]<< ' ';
		cout << '\n';
	}*/
	for (int i = 0; i < 7; i++) {
		int num = arr[i];
		int x = num / 5;
		int y = num % 5;
		val[x][y] = 1;	
		if (i == 0) {
			q.push({ x,y });
			val[x][y] = 0;
			if (pos[x][y] == 'S') lee++;
			else da++;		
		}
	}
	
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		num++;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
			if (val[nx][ny] == 0) continue;
			q.push({ nx,ny });
			val[nx][ny] = 0;
			if (pos[nx][ny] == 'S') lee++;
			else da++;
		}
	}


	if (lee > da && num == 7) {
		counter++;
		return;
	}
}


void check(int n) {
	if (n == 7) {
		bfs();
		return;
		/*if (arr[0] == 5 && arr[1] == 6 && arr[2] == 7 && arr[3] == 8) {
		   for (int i = 0; i < 7; i++) cout << arr[i] << ' ';
		   cout << '\n';
	   }*/
	}

	int st = 0;
	if (n != 0) st = arr[n - 1] + 1;
	for (int i = st; i < 25; i++) {
		arr[n] = i;
		check(n + 1);
	}
	
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 5; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 5; j++) {
			pos[i][j] = s[j];
		}
	}
	check(0);
	cout << counter;
}
