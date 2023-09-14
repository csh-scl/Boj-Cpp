#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[500001];
vector<int> checked;

bool binarySearch(int k) {
	int right = n - 1;
	int left = 0;
	while (left <= right) {
		int mid = (right + left) / 2;
		if (arr[mid] == k) {
			return true;
		}
		else if (arr[mid] > k) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return false;
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		checked.push_back(num);
	}


	for (int i = 0; i < checked.size(); i++) {
		bool k = binarySearch(checked[i]);
		if (k == true) checked[i] = 1;
		else
			checked[i] = 0;
	}

	for (int i = 0; i < checked.size(); i++) {
		cout << checked[i] << ' ';
	}
}
