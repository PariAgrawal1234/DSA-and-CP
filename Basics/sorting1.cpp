#include <bits/stdc++.h>
using namespace std;
void selectionsort(int arr[],int n){
    for(int i = 0; i< n-1; i++){
        int mini = i;
        for(int j = i; j< n; j++){
            if(arr[j]<arr[mini]) mini = j;
        }
        swap(arr[i],arr[mini]);
    }
    for(int i = 0; i< n; i++){
        cout << arr[i] << " , ";
    }
}
void bubblesort(int arr[],int n){
    
    for(int i = n-1; i>0; i--){
        int ifswap = 0;
        for(int j = 1; j<= i; j++ ){
            if(arr[j-1]>arr[j]){ swap(arr[j-1],arr[j]);
            ifswap = 1;
        }}
        cout <<"runs"<< endl;
        if(ifswap==0) break;
    }
    for(int i = 0; i<n; i++){
        cout << arr[i]<< " ";
    }
}
void insertionsort(int arr[],int n){
    for(int i = 0; i< n; i++){
        int ifswap = 0;
        for(int j =i; j>0; j--){
            if(arr[j]<arr[j-1]) {swap(arr[j-1],arr[j]); ifswap = 1;}
        }
        cout << "i" << endl;
        if(!ifswap) break;
    }
    for(int i = 0; i<n ; i++){
        cout << arr[i]<< " ";
    }
}

int main(){
    int arr[] = {13,46,24,52,20,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    insertionsort(arr,n);
}