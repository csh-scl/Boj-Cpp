#include <bits/stdc++.h>
using namespace std;
int maxvalue = 0;
int arr[1000][5];
vector<pair<int, int>> v;

bool comp(pair<int, int> v1, pair<int, int> v2) {
	if (v1.second == v2.second) {
		return v1.first > v2.first;
	}
	else {
		return v1.second > v2.second;
	}
}

int main(void){
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	vector<int> temp{ 0,0,1,1,1 };
	for (int i = 0; i < num; i++) {
		maxvalue = 0;
		do {
			int result = 0;
			for (int j = 0; j < 5; j++) {
				if (temp[j] == 1) {
					result += arr[i][j];
				}
			}
			if (result % 10 >= maxvalue % 10) {
				maxvalue = result % 10;
			}
		} while (next_permutation(temp.begin(), temp.end()));
		v.push_back({ i, maxvalue });
	}

	sort(v.begin(), v.end(), comp);
	cout << v[0].first + 1;
} 