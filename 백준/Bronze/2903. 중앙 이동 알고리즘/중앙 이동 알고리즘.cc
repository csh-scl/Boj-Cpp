#include <bits/stdc++.h>
using namespace std;

int arr[16];



int main() {
    

    int n;
    cin >> n;
    arr[0] = 2;
    for (int i = 1; i < 16; i++) {
        arr[i] = arr[i - 1] * 2 - 1;
    }

    cout << arr[n] * arr[n];
}
