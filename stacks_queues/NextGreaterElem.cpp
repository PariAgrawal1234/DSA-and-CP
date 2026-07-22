//keep the stack sorted if someone breaks the rule pop
#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {2, 1, 3, 4, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    stack <int> st;
    vector <int> ans(n, -1);
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }

    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}