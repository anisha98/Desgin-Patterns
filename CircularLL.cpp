#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node * next;
        Node(int x){
            this->val = x;
            this->next = NULL;
        }
};

void displayLinkedList(Node * &head){
    cout << "Here" << endl;
    Node * dummy = head;
    cout << head->val << endl;
    while(dummy->next != head){
        cout << dummy->val << "->";
        dummy=dummy->next;
    }
    
    cout << "NULL" << endl;
}

void insertAtHead(Node * &head, int x){

    Node * newNode = new Node(x);
    Node * dummy = head; // Find the last node

    if(head == NULL){
        cout << "We are here \n";
        newNode->next = newNode;
        head = newNode;
        return;
    };
    while(dummy->next != head){
        dummy = dummy->next;
    }
    dummy -> next  = newNode ;// Insert at end of list and make it circular.
    newNode->next = head;
    head = newNode;
    
}

void insertAtTail(Node * &head, int x){
    Node * newNode = new Node(x);
    Node * dummy = head; // Find the last node

    if(head == NULL){ // Empty LinkedList
        insertAtHead(head, x);
        return;
    }  
    while(dummy->next != head){
        dummy = dummy->next;
    }
    dummy->next  = newNode;
    newNode->next = head;
}

int main(){
    Node * node = NULL;
    for(int i = 0; i < 5;i++){
        insertAtTail(node, i);
    }
    displayLinkedList(node);

    
    for(int i = 0; i < 5;i++){
        insertAtHead(node, i);
    }
    displayLinkedList(node);

    return 0;
}