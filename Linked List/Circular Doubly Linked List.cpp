#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *prev;
    Node *next;
    Node(int v){
        val = v;
        prev = NULL;
        next = NULL;
    }
};
void insert(Node *&head,Node* newNode){
    if(!head){
        head = newNode;
        head->next = head;
        head->prev = head;
    }else{
        newNode->prev = head;
        newNode->next = head->next;
        head->next->prev = newNode;
        head->next = newNode;
    }
}
void display(Node* h1){
    if(!h1){
        cout<<"Empty List\n";
        return;
    }
    Node *PTR = h1;
    do{
        cout<<PTR->val<<' ';
        PTR=PTR->next;
    }while(PTR!=h1);
    cout<<"\n";
}
int main(int argc, char const *argv[]){
    
    Node *head = NULL;
    for(int i=0;i<9;i++)
        insert(head,new Node(i+1));
    display(head);
    return 0;
}
