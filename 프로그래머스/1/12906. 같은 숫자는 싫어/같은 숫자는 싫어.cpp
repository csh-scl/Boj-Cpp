#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    
    stack<int> st;
    
    st.push(arr[0]);
    
    for(int i =1; i<arr.size(); i++){
        int cur = arr[i];
        if(st.top() == arr[i]){
            continue;
        }
        
        else{
            st.push(arr[i]);
        }
    }
    
    int size = st.size() - 1;
    vector<int> answer(st.size(), 0);
    
    while(!st.empty()){
        int cur = st.top();
        st.pop();
        answer[size] = cur;
        size--;
    }
    
    return answer;
}