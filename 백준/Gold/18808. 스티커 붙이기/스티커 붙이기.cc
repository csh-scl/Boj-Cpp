#include <iostream>

using namespace std;

int laptop[42][42];
int sticker[12][12], tmp[12][12];
int n, m, k, r, c, cnt;
bool isput;

void validate(int i, int j){ // 스티커를 붙일 수 있는지 판별
    for(int k = 0; k < r; k++){
        for(int l = 0; l < c; l++){
            if(laptop[i+k][j+l] == 1 && sticker[k][l] == 1) return; // 스티커끼리 겹치는 부분이 있다면 붙이는 것이 불가능
        }
    }
    // 붙이기가 가능할 경우에는 laptop에 반영
    for(int k = 0; k < r; k++){
        for(int l = 0; l < c; l++){
            if(sticker[k][l] == 1){
                laptop[i+k][j+l] = 1;
            } 
        }
    }
    isput = true; // 붙였음을 표시
}

bool checknput(){ // 스티커를 붙일 수 있다면 laptop에 반영하고 true를 아니라면 false를 반환
    isput = false; // 스티커를 붙일 수 있는지 여부
    if(n-r < 0 || m-c < 0) return false;
    for(int i = 0; i <= n-r; i++){
        for(int j = 0; j <= m-c; j++){
            if(isput) return true; // 스티커를 붙일 수 있었다면 true를 반환
            validate(i, j); // 스티커를 붙일 수 있을지 판별하고 가능하다면 반영
        }
    }
    if(isput) return true; // 혹시 for문의 제일 마지막 경우에 스티커를 붙일 수 있었을 경우를 위함
    else return false; // 붙일 수 없는 경우
}

void rotate(){ // 스티커를 90도 회전 시키는 메서드
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            tmp[i][j] = sticker[i][j];
        }
    }
    // n번째 열은 n번째 행으로, m번째 행은 (회전 전 스티커의 행의 개수 - 1) - m 열로
    for(int i = 0; i < c; i++){
        for(int j = 0; j < r; j++){
            sticker[i][j] = tmp[r-1-j][i];
        }
    }
    // 행과 열을 변경
    swap(r,c);
}

void putsticker(){
    if(checknput()) return; // 0도 회전 시 체크 후 붙일 수 있다면 붙이기 
    rotate(); // 90도
    if(checknput()) return; // 90도 회전 시 체크 후 붙일 수 있다면 붙이기 
    rotate(); // 180도
    if(checknput()) return; // 180도 회전 시 체크 후 붙일 수 있다면 붙이기 
    rotate(); // 270도
    checknput(); // 270도 회전 시 체크 후 붙일 수 있다면 붙이기
}


int main() {
    ios::sync_with_stdio(0);  
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    while(k--){
        cin >> r >> c;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){ // 스티커 입력 받기
                cin >> sticker[i][j];
            }
        }
        putsticker(); // 스티커를 붙이기
    }
    for(int i = 0; i < n; i++){ // 스티커가 붙은 부분 cnt
        for(int j = 0; j < m; j++){
            if(laptop[i][j] == 1) cnt++;
        }
    }
    cout << cnt;
}