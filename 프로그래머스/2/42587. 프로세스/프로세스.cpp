#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int,int>> q;
    for(int i =0; i<priorities.size(); i++){
        q.push({priorities[i], i});
    }
    
    int answer = 0;
    
    sort(priorities.begin(), priorities.end(), greater<int>());
    int i = 0;
    
    while(!q.empty()){
        auto cur = q.front();
        if(cur.first == priorities[i]){
            if(cur.second == location){
                answer++;
                break;
            }
            q.pop();
            answer++;
            i++;
        } else{
            q.pop();
            q.push({cur.first, cur.second});
        }
    }
   
    
    
    return answer;
}