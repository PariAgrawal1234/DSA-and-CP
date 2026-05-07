#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* convertArr2LL (vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i< arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}

int lengthofLL(Node *head){
  int cnt = 0;
  Node* temp = head;
  while(temp){
    cnt++;
    temp = temp -> next;
  }
  return cnt;
}
void traversingLL(Node * head){
  Node *temp = head;
    while(temp){
        cout << temp-> data << " ";
        temp = temp -> next;  
    }
}

bool searchLL(Node* head, int val){
  Node * temp = head;
  while(temp){
    if(temp -> data == val) return true;
    temp = temp-> next;
  }
  return false;
}
int main(){
    vector <int> arr = {2,5,8,7,8};
    Node* head = convertArr2LL(arr);
    cout << searchLL(head, 4);
}