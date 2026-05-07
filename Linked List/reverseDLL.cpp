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

Node* convertArr2DLL(vector <int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i< arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev-> next = temp;
        prev = temp;
    }
    return head;
}
void printDLL(Node* head){
    while(head != NULL){
        cout << head-> data;
        if(head-> next != NULL) cout << " ";
        head = head-> next;
    }
    return;
}

Node* reverseDLL1(Node* head){

    //time complexity = o(2n), space complexity = O(n)//

    Node* temp = head;
    stack <int> st;
    while(temp != NULL){
        st.push(temp-> data);
        temp = temp-> next;
    }
    temp = head;
    while(temp != NULL){
        temp-> data = st.top();
        st.pop();
        temp = temp-> next;
    }
    return head;
}

Node* reverseDLL2(Node* head){
    if(head == NULL || head-> next == NULL) return head;
    Node* prev = NULL;
    Node* current = head;
    while(current != NULL){
        prev = current-> back;
        current-> back = current-> next;
        current-> next = prev;
        
        current = current-> back;
    }
    return prev-> back;
}

int main(){
    vector <int> arr= {2,4,7,8,1};
    Node* head = convertArr2DLL(arr);
    head = reverseDLL2(head);
    printDLL(head);
    return 0;
}