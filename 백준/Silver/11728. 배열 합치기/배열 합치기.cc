#include <bits/stdc++.h>
using namespace std;

int arr1[1000000];
int arr2[1000000];
int arr3[2000005];

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
		if (idx1 == a) arr3[i] = (arr2[idx2++]);
		else if (idx2 == b) arr3[i] = (arr1[idx1++]);
		else if (arr1[idx1] < arr2[idx2]) {
			arr3[i] = (arr1[idx1]);
			idx1++;
		}
		else {
			arr3[i] =(arr2[idx2]);
			idx2++;
		}
	}
	for (int i = 0; i < a+b; i++) {
		cout << arr3[i] << ' ';
	
	}
}
