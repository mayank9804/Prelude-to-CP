#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(int v){
        val = v;
        next = NULL;
    }
};
void insertNode(Node *&head,Node *newNode){
    if(!head){
        head = newNode;
        head->next = head;
    }else{
        newNode->next = head->next;
        head->next = newNode;
        head = newNode;
    }
}
void display(Node *head){
    if(!head){
        cout<<"Empty Circular Linked List\n";
        return ;
    }
    Node *PTR = head;
    do{
        cout<<PTR->val<<" ";
        PTR = PTR->next;
    }while(PTR!=head);
    cout<<"\n";
}
int main(int argc, char const *argv[]){
    
    Node *head = NULL;
    for(int i=0;i<9;i++){
        insertNode(head,new Node(i+1));
    }
    display(head);
    return 0;
}
