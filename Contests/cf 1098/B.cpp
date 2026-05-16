#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    if(cin >> t){
        while(t--){
            long long n, x1, x2, k;
            cin >> n >> x1 >> x2 >> k;

            if(n <= 3) cout << 1 << endl;
            else{    
                long long diff = abs(x1 - x2);
                long long d = min(diff, n - diff);
                cout << d+k << endl;
            }
        }
    }
    return 0;
}