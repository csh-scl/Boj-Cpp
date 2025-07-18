
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end(), greater<int>());
    
    int len = score.size();
    for(int i = m-1; i<len; i+=m){
        answer += score[i] * m;
    }
    return answer;
}