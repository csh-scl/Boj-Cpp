#include <bits/stdc++.h>
using namespace std;

int arr1[1000000];
int arr2[1000000];
queue<int> q;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < a; i++) cin >> arr1[i];
	for (int i = 0; i < b; i++) cin >> arr2[i];

	int idx1 = 0;
	int idx2 = 0;
	for (int i = 0; i < a + b; i++) {
		if (idx1 == a) q.push(arr2[idx2++]);
		else if (idx2 == b) q.push(arr1[idx1++]);
		else if (arr1[idx1] < arr2[idx2]) {
			q.push(arr1[idx1]);
			idx1++;
		}
		else {
			q.push(arr2[idx2]);
			idx2++;
		}
	}
	int count = q.size();
	for (int i = 0; i < count; i++) {
		cout << q.front() << ' ';
		q.pop();
	}
}
