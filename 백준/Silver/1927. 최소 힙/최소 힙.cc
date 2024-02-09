#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0;

void push(int x) {
	heap[++sz] = x;
	int idx = sz;
	while (idx != 1) {
		if (heap[idx] < heap[idx / 2]) {
			swap(heap[idx], heap[idx / 2]);
			idx /= 2;
		}
		else {
			break;
		}
	}
}

int top() {
	return heap[1];
}

void pop() {
	int cnt = 1;
	heap[cnt] = heap[sz--];
	while (cnt * 2 <= sz) {
		int left = cnt * 2;
		int right = cnt * 2 + 1;
		/*int min = heap[left] < heap[right] ? left : right; */
		int min = left;
		if (right <= sz && heap[left] > heap[right]) {
			min = right;
		}
		if (heap[cnt] > heap[min]) {
			swap(heap[cnt], heap[min]);
			cnt = min;
		}
		else {
			break;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			if (sz == 0) {
				cout << 0 << '\n';
			}
			else {
				cout << top() << '\n';
				pop();
			}
		}
		else {
			push(x);
		}
	}

}