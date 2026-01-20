#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<pair<int, int>> q;  // 시간, 무게
    
    int size = truck_weights.size();
    int n = 0;
    int time = 0;
    
    int cur_weight = 0;
    
    while(n < size){
        
        if(!q.empty() && time >= q.front().first){
            cur_weight -= q.front().second;
            q.pop();
        }
        
        if(cur_weight + truck_weights[n] <= weight){
            cur_weight += truck_weights[n];
            q.push({time + bridge_length, truck_weights[n]});
            n++;
        }        
        
        time++;
    }
    
    answer = q.back().first + 1;
    
    return answer;
}