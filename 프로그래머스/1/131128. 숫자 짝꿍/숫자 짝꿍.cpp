#include <string>
#include <vector>


using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int a[10] = {0};
    int b[10] = {0};
    
    
    for(auto k : X){
        int val = k - '0';
        a[val]++;
    }
    
    for(auto k : Y){
        int val = k- '0';
        b[val]++;
    }
    
    for(int i = 9; i>=0; i--){
        while(a[i] != 0 && b[i] != 0){
            answer += to_string(i);
            a[i] -= 1;
            b[i] -= 1;
        }
    }
    
    if(answer == ""){
        answer = "-1";
    }
    
    if(answer[0] == '0'){
        answer = "0";
    }
    
    return answer;
}