#include <bits/stdc++.h>
using namespace std;

int x, y, z;

bool finish(int a, int b, int c) {
    if (a ==0 && b == 0 && c==0) return true;
    return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
#include <iostream>

    using namespace std;

    
        while (1) {
            int a, b, c;
            cin >> a >> b >> c;

            if (a == 0 && b == 0 && c == 0) {
                break;
            }
            if (a == b && b == c && c == a) {
                printf("Equilateral\n");
            }
            else if (a >= b + c || b >= c + a || c >= a + b) {
                printf("Invalid\n");
            }
            else if (a == b || b == c || c == a) {
                printf("Isosceles\n");
            }
            else if (a != b && b != c && c != a) {
                printf("Scalene\n");
            }
        }
        return 0;
   

}