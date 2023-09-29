#include <bits/stdc++.h>
using namespace std;

// arr[i][k] i번째에 k 번째 색을 더한 값

int st[1005][4];
int arr[1005][4];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> st[i][j];
		}
	}
	arr[1][1] = st[1][1];
	arr[1][2] = st[1][2];
	arr[1][3] = st[1][3];

	for (int i = 2; i <= num; i++) {
		arr[i][1] = min(arr[i-1][2], arr[i-1][3]) + st[i][1];
		arr[i][2] = min(arr[i-1][1], arr[i-1][3]) + st[i][2];
		arr[i][3] = min(arr[i-1][1], arr[i-1][2]) + st[i][3];
	}

	cout << min({ arr[num][1], arr[num][2], arr[num][3] }) ;
}
