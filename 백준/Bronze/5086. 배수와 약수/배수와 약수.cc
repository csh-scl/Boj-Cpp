#include <bits/stdc++.h>
using namespace std;
// 0과 1의 갯수를 저장하는 배열 생성


int arr[100];


int main(void){
	
	while (true) {
		int x, y;
		cin >> x >> y;
		if (x == 0 && y == 0) break;
		if (y % x == 0) cout << "factor" << '\n';
		else if (x % y == 0) cout << "multiple" << '\n';
		else
			cout << "neither" << '\n';
	}
	
} 