#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int c0 = 0, c1 =0,c2 = 0;

        for(int i = 0; i<n; i++){
            int w;
            cin >> w;

            if(w==0) c0 ++;
            else if (w == 1 ) c1++;
            else if(w == 2)c2++;
        }
        int ans = c0;
        int pairs = min(c1,c2);
        ans += pairs;
        c1-= pairs;
        c2 -= pairs;

        ans += c1/3;
        ans += c2/3;

        cout << ans << endl;
    }

    return 0;
}