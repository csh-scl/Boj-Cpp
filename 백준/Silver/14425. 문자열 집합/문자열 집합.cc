#include <bits/stdc++.h>
using namespace std;
// 0과 1의 갯수를 저장하는 배열 생성


vector<string> sentence;
int incre = 0;
int size3;

void bysearch(string k, int st, int en) {
	if (st > en) return;
	int m = (st + en) / 2;

	if (sentence[m] == k) {
		incre++;
		return;
	}
	else {
		if (sentence[m] > k) {
			bysearch(k, st, m - 1);
		}
		else
			bysearch(k, m + 1, en);
	}
}

int main(void){

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		sentence.push_back(x);
	}

	sort(sentence.begin(), sentence.end());
	size3 = sentence.size();

	for (int i = 0; i < m; i++) {
		string vec;
		cin >> vec;
		bysearch(vec,0, size3-1);
	}
	cout << incre;
} 