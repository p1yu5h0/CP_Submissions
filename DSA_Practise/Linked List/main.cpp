#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = nullptr;
    }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next=head;
    head=n;
}

void insertAtTail(node* &head, int val){
    node* n = new node(val);

    if(head==nullptr){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next=n;
}

void displayLinkedList(node* head){
    node* temp = head;
    while(temp->next!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}

bool searchInLL(node* head, int key){
    node* temp = head;
    while(temp->next!=nullptr){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void deleteAtHead(node* &head){
    node* todelete= head;
    head=head->next;
    delete todelete;
}
void deleteNode(node* head, int val){
    if(head== nullptr){
        return;
    }
    if(head->next==nullptr){
        deleteAtHead(head);
        return;
    }
    node* temp = head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

node* reverseLLIterative(node* &head){
    node* prevptr = nullptr;
    node* currptr = head;
    node* nextptr;
    while(currptr!=nullptr){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}

node* reverseLLRecursive(node* &head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    node* newhead = reverseLLRecursive(head->next);
    head->next->next=head;
    head->next=nullptr;
    return newhead;
}

int main() {
    node* head = nullptr;
    for(int i=0;i<=10;i++){
        insertAtTail(head, i+1);
    }
    displayLinkedList(head);
    cout<<searchInLL(head, 99)<<endl;
    insertAtHead(head, 99);
    displayLinkedList(head);
    cout<<searchInLL(head, 99)<<endl;
    deleteNode(head, 5);
    displayLinkedList(head);
    deleteAtHead(head);
    displayLinkedList(head);

    node* newhead = reverseLLIterative(head);
    displayLinkedList(newhead);

    node* newhead1 = reverseLLRecursive(head);
    displayLinkedList(newhead1);
    return 0;
}
