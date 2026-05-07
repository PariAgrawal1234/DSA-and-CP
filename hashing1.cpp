#include <bits/stdc++.h>
using namespace std;
int main(){

    int arr[] = {2,2,3,4,4,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    unordered_map <int,int> mpp;
    for(int i = 0; i<n; i++){
        mpp[arr[i]]++;
    }
    int max = 0; int min = n;
    for(auto it : mpp){
        if(max < it.second) max = it.second;
        if(min > it.second) min = it.second;
    }
    cout << max << " " << min << endl;
}