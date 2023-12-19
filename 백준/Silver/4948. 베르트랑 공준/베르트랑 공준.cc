#include <bits/stdc++.h>
using namespace std;

bool vis[250000];


int main(void) {
	vis[1] = true;
	for (int i = 2; i * i <= 250000; i++) {
		if (vis[i]) continue;
			for (int j = 2*i; j <= 250000; j += i) {
				if (vis[j]) continue;
				vis[j] = true;
			}
	}

	

	while (true) {
		int x; 
		int count = 0;
		cin >> x;
		if (x == 0) break;
		else {
			for (int i = x+1; i <= 2 * x; i++) {
				if (!vis[i]) count++;
			}
		}
		cout << count << '\n';
	}


}