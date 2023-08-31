#include <bits/stdc++.h>
using namespace std;


int arr[3];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 3; i++) cin >> arr[i];

    sort(arr, arr + 3);
    int max = arr[2];

    while (max >= arr[0] + arr[1]) {
        max--;
    }
    cout << max + arr[0] + arr[1];
}