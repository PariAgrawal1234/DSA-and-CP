#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class heap{
  public:
    int arr[100];
    int size;
    
    heap(){
      arr[0] = -1;
      size= 0;
    }
    
    void insert(int val){
      size++;
      int i = size;
      arr[i] = val;
      while(i > 1){
        if(arr[i] > arr[i/2]){
          swap(arr[i], arr[i/2]);
          i = i/2;
        }
        else
          return;
      }
    }
    
    void dltRootNode(){
      if(size == 0) return;
      arr[1] = arr[size];
      size--;
      
      int i = 1;
      while(i <= size){
        int leftindx = 2*i;
        int rightindx = 2*i + 1;
        
        if(leftindx < size && arr[leftindx] > arr[i]){
          swap(arr[i], arr[leftindx]);
          i = leftindx;
        }
        else if(rightindx < size && arr[rightindx] > arr[i]){
          swap(arr[i], arr[rightindx]);
          i = rightindx;
        }
        else 
          return;
      }
      
    }
    
    void print(){
      for(int i = 1; i<=size; i++){
        cout << arr[i] << " ";
      }cout << endl;
    }
    
};

void heapify(int arr[], int n, int i){
      int largest = i;
      int lft = 2*i;
      int rgt = 2*i+ 1;
      
      if(lft <= n && arr[lft] > arr[largest]){
        largest = lft;
      }
      if(rgt <= n && arr[rgt] > arr[largest]){
        largest = rgt;
      }
      if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
      }
    }
    
void heapSort(int arr[], int n){
  // time complexity -> O(nlog(n))
  int size = n;
  while(size> 1){
    swap(arr[size], arr[1]);
    size--;
    
    heapify(arr,size,1);
  }
  
}

int main() 
{
    // heap h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.print();
    
    // h.dltRootNode();
    // h.print();
    
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2; i >0; i--){
      heapify(arr,n,i);
    }
    heapSort(arr,n);
    
    for(int i = 1; i <= n; i++) cout << arr[i] <<' ';
    cout << endl;
}