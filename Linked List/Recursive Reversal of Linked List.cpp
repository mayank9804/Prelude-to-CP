#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
void insert(Node *&head, Node *newNode){
    if(!head)
        head = newNode;
    else{
        Node *PTR = head;
        while(PTR->next)
            PTR=PTR->next;
        PTR->next = newNode;
    }
}

void recReverse(Node *&head,Node *PTR,Node *PREV){
    if(!head)
        return ;
    if(!PTR->next){
        PTR->next = PREV;
        head = PTR;
        return ;
    }
    recReverse(head,PTR->next,PTR);
    PTR->next = PREV;
}
void display(Node *head){
    if(!head)
        return ;
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}
int main(int argc, char const *argv[]){
    
    Node *head=NULL;
    for(int i=0;i<10;i++)
        insert(head,new Node(i+1));
    display(head);
    cout<<"\n";
    recReverse(head,head,NULL);
    display(head);
    return 0;
}
