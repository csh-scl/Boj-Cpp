#include <bits/stdc++.h>
using namespace std;

int arr[4];

void divide(int val) {
    int value = val;
    while (value != 0) {
        if (value / 25 != 0) {
            int quotient = value / 25;
            arr[0] = quotient;
            value = value % 25;

        }
        else if (value / 10 != 0) {
            int quotient = value / 10;
            arr[1] = quotient;
            value = value % 10;
        }
        else if (value / 5 != 0) {
            int quotient = value / 5;
            arr[2] = quotient;
            value = value % 5;
        }
        else {
            arr[3] = value;
            return;
        }
    }
}


int main() {
    

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        divide(x);

        for (int i = 0; i < 4; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';

        fill(arr, arr + 4, 0);
    }
}
