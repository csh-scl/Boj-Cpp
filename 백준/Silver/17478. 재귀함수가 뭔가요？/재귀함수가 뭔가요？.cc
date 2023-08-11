#include <bits/stdc++.h>
using namespace std;

// 그냥 n번 순회하면서 n회 비교하면 시간 복잡도 (n^2) 실패 but stack 을 이용하면 O(N) 풀이가능

// a 출발 1번 b 도착 3번

int a;

void call(int n) {
	
	if (n == a) {
		for (int i = 0; i < n; i++) {
			cout << "____";
		}
		cout << "\"재귀함수가 뭔가요?\"\n";
		for (int i = 0; i < n; i++) {
			cout << "____";
		}
		cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
		for (int i = 0; i < n; i++) {
			cout << "____";
		}
		cout << "라고 답변하였지.\n";
		return;
	}

	for (int i = 0; i < n; i++) cout << "____";
	cout << "\"재귀함수가 뭔가요?\"\n";
	for (int i = 0; i < n; i++) cout << "____";
	cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
	for (int i = 0; i < n; i++) cout << "____";
	cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
	for (int i = 0; i < n; i++) cout << "____";
	cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
	
	call(n+1);

	for (int i = 0; i < n; i++) cout << "____";
	cout << "라고 답변하였지.\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a;
	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << '\n';
	call(0);
}