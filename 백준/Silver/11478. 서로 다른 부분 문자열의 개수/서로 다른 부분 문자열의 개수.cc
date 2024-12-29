#include <bits/stdc++.h>
using namespace std;

int main() {
    set<string> st;

    string s;
    cin >> s;

    int size = s.size();

    for (int i = 0; i < size; ++i) {
        for (int j = 1; j <= size - i; j++) {
            string str = s.substr(i, j);
            st.insert(str);
        }
    }
    
    cout << st.size();
}
