#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    vector<int> ans;
    queue<pair<int,int>> q;
    
    int size = speeds.size();
    int time = 0;
    
    for(int i =0; i<size; i++){
    q.push({progresses[i], speeds[i]}); // 작업상태, 속도
    }
    
    while(!q.empty()){
        if(q.front().first + q.front().second * time >= 100){
            int cnt = 1;
            q.pop();
            while(true){
                if(q.front().first + q.front().second * time >= 100){
                    cnt++;
                    q.pop();
                } else{
                    ans.push_back(cnt);
                    break;
                }
            }
        }
        
        
        time++;
    }
    
    return ans;
}