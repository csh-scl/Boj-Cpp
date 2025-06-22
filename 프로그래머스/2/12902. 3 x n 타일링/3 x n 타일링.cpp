#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    const int MOD = 1000000007;
    int answer = 0;
    long long arr[2510] = { 0, };
    arr[1] = 3;
    arr[2] = 11;
    for(int i = 3; i <= n/2; i++){
        arr[i] = (arr[i-1] * 3) % MOD;  // 모듈러 적용
        
        for(int j = i-2; j > 0; j--){
            arr[i] = (arr[i] + arr[j] * 2) % MOD;  // 모듈러 적용
        }
        arr[i] = (arr[i] + 2) % MOD;  // 모듈러 적용
    }
    
    return arr[n/2];
 
}