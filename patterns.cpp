#include <bits/stdc++.h>
using namespace std;

void pattern1(int n){
    for(int i= 0; i< n; i++){
        for(int j = 0; j< i; j++)
        cout << " " ;
        for(int j = i ; j < 2*n -i -1; j++)
        cout << "*" ;
        cout << endl;
    }
}
void pattern2(int n){
    for(int i= 0; i<= n/2 +1; i++){
        for(int j = 0; j< i; j++)
        cout << "*" ;
        cout << endl;
    }
    for(int k= 0; k< n/2; k++){
        for(int j = n/2 - k ;j>0;j--)
        cout << "*";
        cout << endl;
    }
}
void pattern3(int n){
    int start;
    for(int i= 0; i<n; i++){
        if(i%2 == 0) start = 1;
        else start = 0;
        for(int j = 0; j<= i; j++){
        cout << start ;
        start = 1- start;
        }
        cout << endl;
    }
}
void pattern4(int n){
    for(int i= 1; i<=n; i++){
        for(int j = 1; j<=i; j++)
        cout << j;
        for(int k = 1; k<= 2*(n-i);k++)
        cout << " ";
        for (int l = i; l>0;l-- )
        cout << l;
    cout << endl;
    }
}
void pattern5(int n){
    int count = 1;
    for(int i= 0; i<n; i++){
        for(int j = 0; j<=i; j++){
            cout << count << " ";
            count ++;
        }
        cout << endl;
    }
}
void pattern6(int n){
 for(int i= 0; i<n; i++){
    for(int j= 0; j<=i;j++)
    cout << char(65+j);
cout << endl;
 }
}
void pattern7(int n){
    for(int i= 0; i<n; i++){
        for(int j=0; j< n-i;j++)
        cout << char(65+j);
    cout << endl;
     } 
}
void pattern8(int n){
    for(int i= 0; i<n; i++){
        for(int j=0; j<= i;j++)
        cout << char(65+i);
    cout << endl;
     } 
}
void pattern9(int n){
    for(int i =0; i<n; i++){
        for(int j =0; j< n-i-1; j++)
        cout << " ";
        for(int k = 0; k< i+1; k++)
        cout << char(65+k);
        for(int l = i-1; l >=0; l--)
        cout << char(65+l);
    cout << endl;
    }
}
void pattern10(int n){
    for(int i =0; i<n; i++){
        for(int j = n-i;j>0;j--)
        cout << "*";
        for(int j=0;j<2*i;j++)
        cout << " ";
        for(int j=n-i;j>0;j--)
        cout << "*";
    cout <<endl;
    }
    for(int i =1; i< n; i++){
        for(int j = 0;j<=i;j++)
        cout << "*";
        for(int j=2*(n-i-1);j>0;j--)
        cout << " ";
        for(int j=0;j<=i;j++)
        cout << "*";
    cout <<endl;
    }
}
void pattern11(int n){
    for(int i= 0; i<n; i++){
        for(int j= n-i-1;j<n;j++)
        cout << char(j+65);
    cout << endl;
    }
}
void pattern12(int n){
    for(int i =1; i<=n ; i++){
        for(int j = 1; j<=n; j++){
            if(i==1||j==1||i==n||j==n) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
}
void pattern13(int n){
    for(int i = 0; i<n; i++){
        for(int j =0;j<n; j++){
            
        }
    }
}

int main(){
    int n;
    cin >> n;
    pattern13(n);
}