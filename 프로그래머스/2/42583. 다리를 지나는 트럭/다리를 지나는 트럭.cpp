#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
// 고려해야 할 요소 -> 1. 시간, 2. 무게
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    int cur_weight = 0;
    int n = truck_weights.size();
    int cur_val = 0;
    queue<pair<int,int>> q; // 시간, 무게
    
    while(cur_val < n){
        if(!q.empty() && time == q.front().first){
            cur_weight -= q.front().second;
            q.pop();
        }
        
        if(weight >= cur_weight + truck_weights[cur_val]){
            q.push({bridge_length + time, truck_weights[cur_val]});
            cur_weight += truck_weights[cur_val];
            cur_val++;
        }
            
            
        time++;    
    }
    
   return q.back().first + 1;
}