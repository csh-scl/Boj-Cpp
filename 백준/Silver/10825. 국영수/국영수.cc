#include <bits/stdc++.h>
using namespace std;

bool comp(tuple<string, int, int, int> v1, tuple<string, int, int, int> v2) {
	if (get<1>(v1) == get<1>(v2) && get<2>(v1) == get<2>(v2) && get<3>(v1) == get<3>(v2)) return get<0>(v1) < get<0>(v2);
	if (get<1>(v1) == get<1>(v2) && get<2>(v1) == get<2>(v2)) return get<3>(v1) > get<3>(v2);
	if (get<1>(v1) == get<1>(v2)) return get<2>(v1) < get<2>(v2);
	return get<1>(v1) > get<1>(v2);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<tuple<string, int, int, int>> v;
	int idx;
	cin >> idx;
	for (int i = 0; i < idx; i++) {
		string name;
		int kor, math, eng;
		cin >> name >> kor >> eng >> math;
		v.push_back({ name,kor,eng, math });
	}
	sort(v.begin(), v.end(), comp);
	for (auto k : v) {
		cout << get<0>(k) << '\n';
	}
}
