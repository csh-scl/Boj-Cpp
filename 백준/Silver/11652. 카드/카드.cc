#include <bits/stdc++.h>
using namespace std;

long long arr[100001];
long long value = 0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+num);
	int maxcnt = 0;
	int cnt = 1;
	for (int i = 1; i < num; i++) {
		if (arr[i - 1] == arr[i]) cnt++;
		else {
			if (maxcnt < cnt) {
				maxcnt = cnt;
				value = arr[i-1];
			}
			cnt = 1;
		}
	}
	if (maxcnt < cnt) value = arr[num - 1];
	cout << value;
}
