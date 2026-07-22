#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    stack <char> st;
    bool balanced = true;
    
    if(s[0] != '(') {
        cout << -1;
        return 0;
    }
    for(char ch : s){
        if(ch == '('){
            st.push(ch);
        }

        else {
            if(st.empty()) {
                balanced = false;
                break;
            }
            st.pop();
        }
    }

    if(!st.empty()){
        balanced = false;
    }
    if(balanced) {
        cout << "TRUE";
    }
    else {
        cout << "FALSE";
    }

    return 0;
}