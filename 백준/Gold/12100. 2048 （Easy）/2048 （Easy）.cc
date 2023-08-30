#include <bits/stdc++.h>
using namespace std;

int num;
int table[20][20];
int Max = 0;
int research();
void push();
// 미는 함수 옆으로 미는 왼쪽 밀기 이걸를 4방향 구현하는 것은 멍충이겠고

void rotation(int dir) {
    while (dir--) {
        int temp[20][20];
        memcpy(temp, table, sizeof(table));
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++) {
                table[i][j] = temp[num - j - 1][i];
            }
        }
    }
}

void start(int k) {
    if (k == 5) {
        int value = research();
        if (Max < value) Max = value;
        return;
    }

        int copy[20][20];
        memcpy(copy, table, sizeof(table)); 
        for (int i = 0; i < 4; i++) {
            if (i == 0) {
                push();
                start(k + 1);
                memcpy(table, copy, sizeof(copy));
            }
            if (i == 1) {
                rotation(i);
                push();
                start(k + 1);
                memcpy(table, copy, sizeof(copy));
            }
            if (i == 2) {
                rotation(i);
                push();
                start(k + 1);
                memcpy(table, copy, sizeof(copy));
            }
            if (i == 3) {
                rotation(i);
                push();
                start(k + 1);
                memcpy(table, copy, sizeof(copy));
            }
        }
}

void push() {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (table[i][j] != 0) {
                for (int k = 0; k < j; k++) {
                    if (table[i][k] == 0) {
                        table[i][k] = table[i][j];
                        table[i][j] = 0;
                        break;
                    }
                }
            }
        }
        for (int j = 0; j < num - 1; j++) {
            if(table[i][j] == table[i][j+1]){
                table[i][j] *= 2;
                table[i][j + 1] = 0;
            }
        }

        for (int j = 0; j < num; j++) {
            if (table[i][j] != 0) {
                for (int k = 0; k < j; k++) {
                    if (table[i][k] == 0) {
                        table[i][k] = table[i][j];
                        table[i][j] = 0;
                        break;
                    }
                }
            }
        }
    }
}

int research() {
    int value = 0;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (value < table[i][j]) value = table[i][j];
        }
    }
    return value;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> num;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cin >> table[i][j];
        }
    }

    start(0);
    
    /*for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cout << table[i][j] << ' ';
        }
        cout << '\n';
    }*/
    // 남은거는 5번 실행 돌리기 ㅅㅂ 이걸 어케함 ㅇㅇㅇㅇㅇㅇㅇㅇㅇㅇ
    // 5번 실행을 하면서 카운트를 해주어야 하네?
    // 제일 쉬운 check 라는 함수
    
    cout << Max;
}