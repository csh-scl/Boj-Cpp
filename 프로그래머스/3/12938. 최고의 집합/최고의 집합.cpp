#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    long long result = -1;
    
    
    if(n > s){
        answer.push_back(-1);
        return answer;
    }
    
    int mod = s/n;
    int err = s%n;
    
    for(int i =0; i<n; i++){
        answer.push_back(mod);
    }
    
    
    for(int i =0; i<err; i++){
        answer[i] +=1;
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}