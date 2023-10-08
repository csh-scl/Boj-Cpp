#include <bits/stdc++.h>
using namespace std;
// 0과 1의 갯수를 저장하는 배열 생성

long long value[100][100];

int main(void){
	int n;
	cin >> n;
	value[0][0] = 0;
	value[1][0] = 1;
	value[1][1] = 1;
	value[2][1] = 1;
	value[2][0] = 2;

	for (int i = 3; i <= n; i++) {
		value[i][1] = value[i - 1][0];
		value[i][0] = value[i - 1][0] + value[i - 1][1];
	}
	cout << value[n][1];
}