#include <bits/stdc++.h>
using namespace std;

bool isprime(long long x){
     if (x < 2) return false;

    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }

    return true;
    
return false;
}

int main(){

    int t;
    cin >> t;
    
    vector<long long> primes;
        long long i = 2;
        while(primes.size() <= 10001){
            if(isprime(i)) primes.push_back(i);
            i++;
        }

    while(t--){
        int n;
        cin >> n;

        for(int j = 0; j< n; j++){
            cout << primes[j]*primes[j+1] << " ";
        }
        cout << endl;
    }

    return 0;
}
