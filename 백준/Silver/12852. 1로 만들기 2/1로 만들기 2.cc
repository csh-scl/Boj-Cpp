#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
// sum[x] x번째 까지의 합의 최소
// 배열 하나 더 쓰면 이전 값 저장까지 가능
int num[1000005];
int pre[1000005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	num[1] = 0;

	cin >> k;
	for (int i = 2; i <= k; i++) {
		num[i] = num[i - 1] + 1;
		pre[i] = i - 1;
		if (i % 2 == 0 && num[i] >= num[i / 2] + 1) {
			pre[i] = i / 2;
			num[i] = num[i / 2] + 1;
		}
		if (i % 3 == 0 && num[i] >= num[i / 3] + 1) {
			num[i] = num[i / 3] + 1;
			pre[i] = i / 3;
		}
	}
	cout << num[k] << '\n';
	int cur = k;
	while (true) {
		cout << cur << ' ';	
		if (cur == 1) break;
		cur = pre[cur];
	}

}