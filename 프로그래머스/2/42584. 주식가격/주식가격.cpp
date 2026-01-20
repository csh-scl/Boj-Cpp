#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<pair<int,int>> s;    // 값, 인덱스
    
    for(int i = 0; i<prices.size(); i++){
    
        while(!s.empty() && s.top().first > prices[i]){
            int idx = s.top().first;
            int val = s.top().second;
            
            answer[val] = i - val;
            s.pop();
        }
        
        s.push({prices[i],i});
    }
    
    while(!s.empty()){
        int idx = s.top().first;
        int val = s.top().second;
        
        answer[val] = prices.size() - val - 1;
        s.pop();
    }
    
    
    return answer;
}