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

void printLL(Node*head){
  Node *temp = head;
  while(temp){
    cout << temp->data << " ";
    temp = temp -> next;
  }
}

void dlthead(Node* head){
  Node* temp = head;
  head = head-> next;
  delete temp;
  cout << head->data;
}

void dltTail(Node* head){
  if(head-> next == NULL || head == NULL) cout << "NULL";
  Node* temp = head;
  while(temp -> next -> next != NULL){
    temp = temp-> next;
  }
  delete temp-> next;
  temp-> next = nullptr;
  printLL(head);
}

Node* dltelement(Node* head, int k){
  if(head == NULL) return head;
  if(k == 1){
    Node* temp = head;
    head = head-> next;
    free(temp);
    return head;
  }
  int cnt = 1;
  Node* prev = NULL;
  Node* temp = head;
  while(temp){
    if(cnt == k){
      prev -> next = prev -> next -> next;
      free(temp);
      break;
    }
    cnt++;
    prev = temp;
    temp = temp-> next;
  }
  return head;
}

Node* insertHead(Node* head, int val){
  Node* temp = new Node(val);
  temp-> next = head;
  return temp;
}

Node* insertLast(Node* head, int val){
  Node* temp = head;
  while(temp -> next != NULL){
    temp = temp-> next;
  }
  temp -> next = new Node(val);
  return head;
}

Node* insertAtK(Node* head, int val, int k){
  if(head == NULL) return new Node(val);
  Node* temp= head;
  if(k==1){
    return new Node(val,head);
  }
  int i = 2;
  while(temp-> next != NULL){
    if(i == k){
      temp -> next = new Node(val, temp-> next);
      return head;
    }
    i++;
    temp = temp-> next;
  }
  temp -> next = new Node(val);
  return head;
}

Node* insertBeforeVal(Node* head, int val, int n){
  if(head == NULL) return new Node ( val);
  Node* temp = head;
  if(head -> data == n){
    return new Node(val, head);
  }
  while(temp -> next != NULL){
    if(temp-> next-> data == n){
      Node* newn = new Node(val, temp-> next);
      temp -> next = newn;
      return head;
    }
    temp = temp -> next;
  }
  return head;
}

int main(){
    vector <int> arr = {8,9,4,6,5};
    
    //Convert it into a LL
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i <arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    
    //update Head
    head = insertBeforeVal(head,100,6);
    
    //Print
    printLL(head);
}