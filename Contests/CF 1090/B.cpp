#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int mxnum = -67;
        int sum = 0;
        for(int i = 0; i< 7; i++){
            int x;
            cin >> x;
            mxnum = max(mxnum,x);
            sum+= x;
        }
        cout << 2*mxnum - sum << endl;
    }

    return 0;
}
