#include<iostream>
using namespace std;

int N, ans = 0, cnt = 0;

bool hasThreeSixes(int num) {
    if (num == 0) {
        return false;
    }
    
    if (num % 1000 == 666) {
        return true;
    }
    
    return hasThreeSixes(num / 10);
}

void findNthEndOfTheWorld(int currentNum) {
    if (cnt == N) {
        return;
    }
    
    if (hasThreeSixes(currentNum)) {
        cnt++;
    }
    
    ans = currentNum;
    findNthEndOfTheWorld(currentNum + 1);
}

int main() {
    cin >> N;
    
    findNthEndOfTheWorld(1);
    
    cout << ans << endl;
    
    return 0;
}
