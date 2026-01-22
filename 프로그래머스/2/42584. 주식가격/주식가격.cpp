#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<pair<int,int>> s;    // 값, 인덱스
    
    int size = prices.size() - 1; // 5
    for(int i = 0; i<= size; i++){
        
        while(!s.empty() && prices[i] < s.top().first){
            int idx = s.top().second;
            answer[idx] = i-idx;
            s.pop();
        }
         s.push({prices[i], i});
    }
    
    while(!s.empty()){
        int cur = s.top().second;
        answer[cur] = size - cur;
        s.pop();
    }
    
    
    return answer;
}