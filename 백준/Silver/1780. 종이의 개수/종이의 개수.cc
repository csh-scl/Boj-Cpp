#include <bits/stdc++.h>
using namespace std;

// 그냥 n번 순회하면서 n회 비교하면 시간 복잡도 (n^2) 실패 but stack 을 이용하면 O(N) 풀이가능

// a 출발 1번 b 도착 3번

int st[2200][2200];

int a = 0;
int b = 0; 
int c = 0;

bool isPaper(int i, int j, int width) {
	int pivot = st[i][j];
	for (int x = i; x < i + width; x++) {
		for (int y = j; y < j + width; y++) {
			if (pivot != st[x][y]) {
				return 0;
			}
		}
	}
	return 1;
}

void search(int i , int j, int n) {
	if (!isPaper(i,j,n)) {  // base condition 종료 조건이네
		search(i, j, n / 3);
		search(i, j+n/3, n/3);
		search(i, j+ n/3*2, n / 3);

		search(i+ n/3, j, n / 3);
		search(i + n / 3, j  + n/3, n / 3);
		search(i + n / 3 , j + n/3 * 2, n / 3);

		search(i + n/3*2, j, n / 3);
		search(i + n / 3 * 2, j + n / 3 , n / 3);
		search(i + n / 3 * 2, j + n / 3 * 2, n / 3);
	}
	else {
		if (st[i][j] == 0) b++;
		else if (st[i][j] == 1) c++;
		else a++;
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cin >> st[i][j];
		}
	}
	search(0, 0, num);
	cout << a << "\n" << b << "\n" << c;
	
}