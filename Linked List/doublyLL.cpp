#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convert2DLL(vector <int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i< arr.size(); i++){
        Node* temp = new Node(arr[i],nullptr, prev);
        prev -> next = temp;
        prev = temp; 
    }
    return head;
}

void printDLL(Node* head){
    if(head == NULL) return ;
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* dltHead(Node* head){
  if(head == NULL || head-> next == NULL){
    return NULL;
  }
  Node* prev = head;
  head = head-> next;
  head-> back = nullptr;
  prev-> next = nullptr;
  delete prev;
  return head;
}

Node* dltTail(Node* head){
  if(head == NULL|| head-> next == NULL) return NULL;
  Node* tail = head;
  while(tail-> next != NULL){
    tail = tail-> next;
  }
  Node* prev = tail -> back;
  tail-> back = nullptr;
  prev-> next = nullptr;
  delete tail;
  return head;
}

Node* dltKth( Node* head, int k){
  Node* temp = head;
  int cnt = 1;
  while(temp -> next != NULL){
    if(cnt == k) break;
    temp = temp -> next;
    cnt++;
  }
  Node* prev = temp -> back;
  Node* front = temp -> next;
  
  if(prev == NULL && front == NULL) return NULL;
  else if(prev == NULL || temp == head) dltHead(head);
  else if(front == NULL) dltTail(head);
  else{
    prev-> next = front;
    front-> back = prev;
    temp-> next = nullptr;
    temp-> back = nullptr;
    delete temp;
  }
  return head;
}

void dltNode( Node* temp){
  Node* prev = temp-> back;
  Node* front = temp-> next;
  
  if(front == NULL){
    prev -> next = nullptr;
    temp-> back = nullptr;
    free(temp);
    return;
  }
  
  prev-> next = front;
  front-> back = prev;
  temp-> back = nullptr;
  temp-> next = nullptr;
  free(temp);
  return;
}

Node* insertHead( Node* head, int val){
  Node* newhead = new Node(val, head, nullptr);
  head-> back = newhead;
  return newhead;
}

Node* insertTail(Node*head, int val){
  if(head-> next == NULL) return insertHead(head, val);
  Node* tail = head;
  while(tail-> next != NULL ){
    tail = tail-> next;
  }
  Node* prev = tail-> back;
  Node* insrt = new Node(val, tail, prev);
  prev-> next = insrt;
  tail-> back = insrt;
  return head;
}

Node* insertBefore(Node* head, int val, int k){
  if(head-> next == NULL) return insertHead(head,val);
  Node* temp = head;
  int cnt = 1;
  while(temp != NULL){
    if(cnt == k){
      Node* prev = temp-> back;
      Node* insrt = new Node(val, temp, prev);
      prev-> next = insrt;
      temp-> back = insrt;
      return head;
    }
    cnt++;
    temp = temp-> next;
  }
  return head;
}

int main(){
    vector <int> arr= {2,5,8,4,9};
    Node* head = convert2DLL(arr);
    head = insertBefore(head, 100, 5);
    printDLL(head);
    return 0;
}