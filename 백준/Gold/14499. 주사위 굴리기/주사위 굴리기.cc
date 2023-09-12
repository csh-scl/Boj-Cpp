#include <bits/stdc++.h>
using namespace std;
int command;
int N, M, x, y, k;
int Map[21][21];
queue<int> q;

int dx[5] = { 0,0,0,-1,1};
int dy[5] = { 0,1,-1,0,0};

void count();
void solve();
void turn(int num);

vector<int> dice(7);

// 굴리는 함수 구현
void rollEast() {
	dice = { 0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3] };
}

void rollWest() {
	dice = { 0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};
}

void rollNorth() {
	dice = { 0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2] };
}

void rollSouth() {
	dice = { 0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5] };
}

void solve() {
	int nx = dx[command];
	int ny = dy[command];

	if (x + nx < 0 || x + nx >= N || y + ny < 0 || y + ny >= M) return;
	
	x = x + nx;
	y = y + ny;

	turn(command);
	count();
}

void count() {
	cout << dice[1] << '\n';
	if (Map[x][y] == 0) Map[x][y] = dice[6];
	else {
		dice[6] = Map[x][y];
		Map[x][y] = 0;
	}
}

void turn(int num){
	switch (num) {
	case 1:
		rollEast();
		break;
	case 2:
		rollWest();
		break;
	case 3:
		rollNorth();
		break;
	case 4:
		rollSouth();
		break;
	default:
		break;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> x >> y >> k;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> Map[i][j];
		}
	}

	
	
	while (k--) {
		cin >> command;
		solve();
	}
}
